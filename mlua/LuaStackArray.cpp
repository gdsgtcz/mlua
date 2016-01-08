//
//  LuaStackArray.cpp
//  hhl
//
//  Created by guodi on 15/6/25.
//
//

#include "LuaStackArray.h"

//单例
static LuaStackArray* _instance = NULL;
static std::mutex _mutex;
//单例
LuaStackArray* LuaStackArray::getInstance()
{
    if (_instance == NULL) {
        _instance = new LuaStackArray();
    }
    return _instance;
}

//插入
void LuaStackArray::insert(int ID, LuaStack* stack)
{
    _mutex.lock();
    stackMap.insert(smap::value_type(ID, stack));
    _mutex.unlock();
}

//查找
LuaStack* LuaStackArray::get(int ID)
{
    //判断是否有该键值
    if(stackMap.count(ID) == 0)
    {
        printf("err: LuaStackArray::get() 没有此键值\n");
        return NULL;
    }
    _mutex.lock();
    smap::const_iterator it = stackMap.find(ID);
    LuaStack* ret = NULL;
    ret = it->second;
    _mutex.unlock();
    return ret;
}


//Sub TaskQueue map
static std::mutex task_mutex;
//单例
TaskQueueArray* TaskQueueArray::instance = NULL;
TaskQueueArray* TaskQueueArray::getInstance()
{
    if (instance == NULL) {
        instance = new TaskQueueArray();
    }
    return instance;
}

//插入
void TaskQueueArray::insert(int ID, SubThreadTask * task)
{
    task_mutex.lock();
    taskMap.insert(smap::value_type(ID, task));
    task_mutex.unlock();
}

//查找
SubThreadTask* TaskQueueArray::get(int ID)
{
    //判断是否有该键值
    if(taskMap.count(ID) == 0)
    {
        printf("err: TaskQueueArray::get() 没有此键值\n");
        return NULL;
    }
    task_mutex.lock();
    smap::const_iterator it = taskMap.find(ID);
    SubThreadTask* ret = NULL;
    ret = it->second;
    task_mutex.unlock();
    return ret;
}


//State-Stack map
//单例
static MapStateStack* _minstance = NULL;
static std::mutex _mmutex;
//单例
MapStateStack* MapStateStack::getInstance()
{
    if (_minstance == NULL) {
        _minstance = new MapStateStack();
    }
    return  _minstance;
}

//插入
void MapStateStack::insert(lua_State* state, LuaStack* stack)
{
    _mmutex.lock();
    _map.insert(smap::value_type(state, stack));
    _mmutex.unlock();
}

//查找
LuaStack* MapStateStack::getStackByState(lua_State* state)
{
    if (_map.count(state) == 0) {
        printf("err: MapStateStack::getStackByState() 没有此键值\n");
        return NULL;
    }
    _mmutex.lock();
    smap::const_iterator it = _map.find(state);
    LuaStack* ret = it->second;
    _mmutex.unlock();
    return ret;
}

//判断是否存在该state
bool MapStateStack::isExist(lua_State* state)
{
    if (_map.count(state) == 0) {
        return false;
    }
    return true;
}

//返回长度
int MapStateStack::length()
{
    return _map.size();
}

//清空
void MapStateStack::clear()
{
    _mmutex.lock();
    _map.clear();
    _mmutex.unlock();
}

//销毁
void MapStateStack::distroy()
{
    clear();
    _minstance = NULL;
}

