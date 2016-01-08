//
//  MapDict.cpp
//  hhl
//
//  Created by guodi on 15/6/25.
//
//

#include "MapDict.h"
#include <mutex>

std::mutex _mutex;

static MapDict* _instense = NULL;
//单例
MapDict* MapDict::getInstance()
{
    if (_instense == NULL) {
        _instense = new MapDict();
        _instense->retain();
    }
    return _instense;
}

//销毁
void MapDict::destroy()
{
    if (_instense) {
        _instense->release();
        _instense = NULL;
    }
}

//插入
void MapDict::insert(std::string key, LuaStringDict* value)
{
    _mutex.lock();
    dict_map.insert(d_map::value_type(key, value));
    _mutex.unlock();
}

//通过key获取value
LuaStringDict* MapDict::getValue(std::string key)
{
    //判断是否有该键值
    if(dict_map.count(key) == 0)
    {
        printf("err: MapDict::getValue() 没有此键值\n");
        return NULL;
    }
    _mutex.lock();
    d_map::const_iterator it = dict_map.find(key);
    LuaStringDict* ret = NULL;
    ret = it->second;
    _mutex.unlock();
    return ret;
}

//移除对应key－value
void MapDict::remove(std::string key)
{
    //判断是否有此ID
    if(dict_map.count(key) == 0)
    {
        printf("err: MapDict::remove() 没有此键值\n");
        return;
    }
    _mutex.lock();
    dict_map.erase(key);
    _mutex.unlock();
}

//清空
void MapDict::removeAll()
{
    _mutex.lock();
    dict_map.clear();
    _mutex.unlock();
}

//获取长度
int MapDict::length()
{
    _mutex.lock();
    int ret = dict_map.size();
    _mutex.unlock();
    return ret;
    
}

