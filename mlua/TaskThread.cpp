//
//  TaskThread.cpp
//  hhl
//
//  Created by guodi on 15/6/7.
//
//
#include <unistd.h>
#include "CCLuaEngine.h"

#include "TaskThread.h"
#include "ThreadManager.h"

//time
#include "sys/time.h"

#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
//自定义方法类
#include "LuaStringArray.h"
#include "LuaStringDict.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

//smh add

#include "network/lua_cocos2dx_network_manual.h"
#include "lua-bindings/manual/HelperFunc_luabinding.h"
#include "lua-bindings/manual/Crypto_luabinding.h"

#if __cplusplus
extern "C" {
#endif
    
    #include "lauxlib.h"
    #include "quick/lfs/lfs.h"
    #include "quick/lpack/lpack.h"
        // 2015-02-08 zrong
        // cjson in cocos2d-x/external/lua is failed on compile in C++ mode
        // I modify it in quick directory.
    #include "quick/cjson/lua_cjson.h"
    
    #include "forlua52.h"
    
//    #include "int64.h"
    //atomdict
    #include "atomdict/lua-ad.h"

#if __cplusplus
}
#endif

//guodi add
#include "lua_cocos2dx_luastringdict_auto.hpp"
#include "lua_cocos2dx_luastringarray_auto.hpp"
#include "lua_cocos2dx_maparray_auto.hpp"
#include "lua_cocos2dx_mapdict_auto.hpp"
#include "lua_cocos2dx_mapstringbuffer_auto.hpp"
#include "lua_cocos2dx_stringbuffer_auto.hpp"
#include "lua_cocos2dx_bytebuffer_auto.hpp"

#include "lua_cocos2dx_threadmanager_auto.hpp"
#include "lua_cocos2dx_taskthread_auto.hpp"

//guodi add
#include "lua_cmsgpack.h"
//snapshot
#include "snapshot.h"

//lusStack
#include "LuaStackArray.h"
//common lua
#include "lua_cocos2dx_common_auto.hpp"
//common
#include "Common.h"


static luaL_Reg lua_module_proj[] = {
    {"pack", luaopen_pack},
    //{"lfs", luaopen_lfs},
    {"cjson", luaopen_cjson_safe},
    {NULL, NULL}
};

void lua_module_register_proj1(lua_State *L)
{
    
    // load extensions
    luaL_Reg* lib = lua_module_proj;
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "preload");
    for (; lib->func; lib++)
    {
        lua_pushcfunction(L, lib->func);
        lua_setfield(L, -2, lib->name);
    }
    lua_pop(L, 2);
}

void* TaskThread::workThread()
{
    printf("============ workThread work !!! ===========\n");
    
    //获取lua虚拟机
    lua_State * my_tolua_s = LuaStackArray::getInstance()->get(myID)->getLuaState();
    
    //注册c函数
    luaopen_cmsgpack(my_tolua_s);
    
//    luaL_requiref_(my_tolua_s,"int64",luaopen_int64,1);
    //atomdict
    luaL_requiref_(my_tolua_s, "atomdict", luaopen_atomdict, 1);
    //snapshot
    luaL_requiref_(my_tolua_s, "snapshot", luaopen_snapshot, 1);
    //注册绑定函数
    if(my_tolua_s)
    {
        
        lua_getglobal(my_tolua_s, "_G");
        lua_module_register_proj1(my_tolua_s);
        
        register_network_module(my_tolua_s);
        luaopen_HelperFunc_luabinding(my_tolua_s);
        luaopen_Crypto_luabinding(my_tolua_s);
        
        register_all_cocos2dx_luastringdict(my_tolua_s);
        register_all_cocos2dx_luastringarray(my_tolua_s);
        register_all_cocos2dx_maparray(my_tolua_s);
        register_all_cocos2dx_mapdict(my_tolua_s);
        register_all_cocos2dx_mapstringbuffer(my_tolua_s);
        register_all_cocos2dx_threadmanager(my_tolua_s);
        register_all_cocos2dx_taskthread(my_tolua_s);
        register_all_cocos2dx_common(my_tolua_s);
        register_all_cocos2dx_stringbuffer(my_tolua_s);
        register_all_cocos2dx_bytebuffer(my_tolua_s);
        lua_settop(my_tolua_s, 0);
    }
    
    //c++调用lua方法
    lua_pushnumber(my_tolua_s, myID);
    lua_setglobal(my_tolua_s,"__MLUA_THREAD_ID__");
    
    //死循环
    while (true)
    {
        //判断是否退出进程
        if (need_quit)
        {
            break;
        }
        
        //do task
        selfTask->doTask();
 
        //usleep单位是微秒 1秒 ＝ 1000 毫秒 ＝ 1000000 微秒
        usleep(t_sleep*1000);
    }
    
    //关闭lua虚拟机
    lua_close(my_tolua_s);
    //my_pEngine = NULL;
    my_tolua_s = NULL;
    
    return 0;
}


//开线程
bool TaskThread::create(int ID, int time)
{
    FileUtils::getInstance()->addSearchPath("src");
    
    //ID
    myID = ID;
    t_sleep = time;
    need_quit = false;
    
    //定义lua虚拟机
    LuaStack* lua_stack = LuaStack::create();
    lua_stack->retain();
    lua_State *my_tolua_s = lua_stack->getLuaState();
    
    //保存LuaStack
    LuaStackArray::getInstance()->insert(myID, lua_stack);
    
    //全局保存state－stack
    MapStateStack::getInstance()->insert(my_tolua_s, lua_stack);
    
    //初始化任务队列
    selfTask = new SubThreadTask(myID);
    //保存任务序列到全局map
    TaskQueueArray::getInstance()->insert(myID, selfTask);
    
    return true;
}

//开线程
void TaskThread::beginThread()
{
    //开线程
    std::thread t(&TaskThread::workThread, this);  //创建 LuaEngine 开线程
    //std::thread t(workThread1);  //创建 LuaEngine 开线程
    t.detach();   //非阻塞
}


//addTaskByFile
void TaskThread::addTaskByFile(const char* _task)
{
    selfTask->addFile(_task);
}

//addTaskByStr
void TaskThread::addTaskByStr(const char* _taskStr)
{
    selfTask->addStr(_taskStr);
}

//setData
void TaskThread::setData(int fID, int tID, std::string _data, int fun)
{
    selfTask->addData(fID, tID, _data, fun);
}

//添加函数句柄到句柄队列
int TaskThread::addSchedule(int fun)
{
    int ret = selfTask->addSchedule(fun);
    return ret;
}

//移除函数句柄
bool TaskThread::removeSchedule(int funID)
{
    return selfTask->removeSchedule(funID);
}

//向其他线程推
void TaskThread::sendStr(int tID, std::string _data, int fun)
{
    ThreadManager::getInstance()->sendStr(myID, tID, _data, fun);
}

//销毁
void TaskThread::destroy()
{
    need_quit = true;
}

//设置sleep时间
void TaskThread::setTime(int time)
{
    t_sleep = time;
}

//获取sleep时间
int TaskThread::getTime()
{
    return t_sleep;
}

//获取ID
int TaskThread::getID()
{
    if (myID == 0) {
        printf("err: ID ＝ 0 !!!\n");
        return 0;
    }
    return myID;
}


