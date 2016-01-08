//
//  TaskQueue.cpp
//  hhl
//
//  Created by guodi on 15/8/6.
//
//

#include "TaskQueue.h"
#include "Common.h"
#include "LuaStackArray.h"
#include "CCLuaEngine.h"

//add task
void TaskQueue::addFile(const char* filename)
{
    //type = 1
    DataStruct datastruct = {1, filename, 0, 0, 0, {}};
    data_mutex.lock();
    data_queue.insert(data_queue.begin(), datastruct);
    data_mutex.unlock();
}

void TaskQueue::addStr(std::string str)
{
    //type = 2
    DataStruct datastruct = {2, str, 0, 0, 0, {}};
    data_mutex.lock();
    data_queue.insert(data_queue.begin(), datastruct);
    data_mutex.unlock();
}

void TaskQueue::addData(int fID, int tID, std::string _data, int fun)
{
    //type = 3
    DataStruct datastruct = {3, _data, fID, tID, fun, {}};
    data_mutex.lock();
    data_queue.insert(data_queue.begin(), datastruct);
    data_mutex.unlock();
}

void TaskQueue::addHandle(int handle, const char* ret, size_t len)
{
    //type = 4
    std::string sret = std::string(ret, len);
    DataStruct datastruct = {4, sret, 0, 0, 0, handle};
    data_mutex.lock();
    data_queue.insert(data_queue.begin(), datastruct);
    data_mutex.unlock();
}

int TaskQueue::addSchedule(int fun)
{
    if (fun == 0) {
        return 0;
    }
    
    ScheduleFunID++;
    ScheduleStruct schedulestruct = {fun, ScheduleFunID};
    schedule_mutex.lock();
    schedule_queue.insert(schedule_queue.begin(), schedulestruct);
    schedule_mutex.unlock();
    return ScheduleFunID;
}

bool TaskQueue::removeSchedule(int funID)
{
    std::vector<ScheduleStruct>::iterator it;
    schedule_mutex.lock();
    for (it = schedule_queue.begin(); it != schedule_queue.end();) {
        if ((*it).funid == funID ) {
            schedule_queue.erase(it);
            schedule_mutex.unlock();
            return true;
        }
        ++it;
    }
    schedule_mutex.unlock();
    return false;
}

void TaskQueue::clear()
{
    
}

void TaskQueue::distroy()
{
    
}

bool TaskQueue::doTask()
{
    //执行lua函数句柄数组
    if (!schedule_queue.empty()) {
        int handle = 0;
        for (int i = schedule_queue.size()-1; i >= 0; i--) {
            handle = schedule_queue[i].fun;
            if (handle != 0) {
                double t = Common::getInstance()->getTime();
                lua_pushnumber(selfState, t);
                int callret = selfStack->executeFunctionByHandler(handle, 1);
                if(callret != 0)
                {
                    printf("err: schedule 失败，ret ＝ %d\n", callret);
                }
            }
        }
    }
    
    //判断类型
    //执行任务队列
    DataStruct _data = {};
    while(!data_queue.empty())
    {
        data_mutex.lock();
        _data = data_queue.back();
        data_queue.pop_back();
        data_mutex.unlock();
        
        //判断
        if(_data.type != 4 && _data.data.c_str() == NULL)
        {
            printf("err: 数据为空 \n");
            continue;
        }
        switch(_data.type)
        {
            case 1:
            {
                //执行lua脚本
                std::string my_path = FileUtils::getInstance()->fullPathForFilename(_data.data);
                //int ret = luaL_dofile(my_tolua_s, my_path.c_str());  //ok
                int ret = selfStack->executeScriptFile(my_path.c_str());
                selfStack->clean();
                if(ret != 0)
                    printf("err1: workThread dofile: ret = %d\n", ret);
            }
                break;
            case 2:
            {
                //执行lua语句
                int doret = selfStack->executeString(_data.data.c_str());
                selfStack->clean();
                if(doret != 0)
                    printf("err2: workThread doString: ret = %d\n", doret);
            }
                break;
            case 3:
            {
                //向线程推数据
                //c++调用lua方法
                lua_getglobal(selfState, "__MLUA_RECEIVE__");
                //参数
                lua_pushinteger(selfState, _data.fID); //fromID
                lua_pushinteger(selfState, _data.tID); //toID
                lua_pushlstring(selfState, _data.data.c_str(), _data.data.length());
                
                
                int functionIndex = -(3+1);
                int traceback = 0;
                lua_getglobal(selfState, "__G__TRACKBACK__"); //L: ... func arg1 arg2 ... G
                if (!lua_isfunction(selfState, -1))
                {
                    lua_pop(selfState, 1);                    // L: ... func arg1 arg2 ...
                }
                else
                {
                    lua_insert(selfState, functionIndex - 1);// L: ... G func arg1 arg2 ...
                    traceback = functionIndex - 1;
                }
                
                //调用函数
                int ret = lua_pcall(selfState, 3, 1, traceback); // 执行函数. lua_pcall(状态指针, 参数个数, 返回值个数, 出错处理函数). 成功返回 0.
                if (ret != 0)
                {
                    printf("err3: C++调用lua函数失败，ret ＝ %d\n", ret);
                }
                
                if(_data.callback != 0)
                {
                    size_t len;
                    const char* getret = lua_tolstring(selfState, -1,&len);
                    lua_pop(selfState, 1);
                    
                    //调用lua回调函数
                    if (_data.fID == 1) {
                        //主线程调用
                        MainThreadTask::getInstance()->addHandle(_data.callback, getret, len);
                    }
                    else
                    {
                        //其他子线程回调
                        SubThreadTask* subtask = TaskQueueArray::getInstance()->get(_data.fID);
                        subtask->addHandle(_data.callback, getret, len);
                    }
                }
            }
                break;
            case 4:
            {
                selfStack->pushString(_data.data.c_str(), _data.data.length());
                int callret = selfStack->executeFunctionByHandler(_data.handle, 1);
                selfStack->clean();
                if(callret != 0)
                {
                    printf("err4: C++回调lua函数失败，ret ＝ %d\n", callret);
                }
            }
                break;
            default:
            {
                printf("err:type 类型错误\n");
            }
                break;
        }
    }
    
    return true;
}


////////////////////////////////////////////////////////////////////////////
//MainThreadTask

MainThreadTask::MainThreadTask()
{
    selfStack = LuaEngine::getInstance()->getLuaStack();
    selfState = selfStack->getLuaState();
}

MainThreadTask::~MainThreadTask()
{
    
}

MainThreadTask* MainThreadTask::instance = NULL;
//单例
MainThreadTask* MainThreadTask::getInstance()
{
    if (instance == NULL) {
        instance = new MainThreadTask();
    }
    return instance;
}


////////////////////////////////////////////////////////////////////////////
//SubThreadTask

SubThreadTask::SubThreadTask(int _id)
{
    ID = _id;
    selfStack = LuaStackArray::getInstance()->get(ID);
    selfState = selfStack->getLuaState();
}

SubThreadTask::~SubThreadTask()
{
    
}

