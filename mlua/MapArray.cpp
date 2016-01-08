//
//  MapArray.cpp
//  hhl
//
//  Created by guodi on 15/6/23.
//
//

#include "MapArray.h"
#include <mutex>


//单例
MapArray* MapArray::_instance = NULL;

MapArray* MapArray::getInstance()
{
    if(_instance == NULL)
    {
        _instance = new MapArray();
    }
    return _instance;
}

//销毁
void MapArray::destroy()
{
    if (_instance != NULL)
    {
        delete _instance;
        _instance = NULL;
    }
}

//插入
void MapArray::insert(std::string key, LuaStringArray* value)
{
    _mutex.lock();
    array_map.insert(u_map::value_type(key, value));
    _mutex.unlock();
}

//通过key获取value
LuaStringArray* MapArray::getValue(std::string key)
{
    //判断是否有该键值
    if(array_map.count(key) == 0)
    {
        printf("err: MapArray::getValue() 没有此键值\n");
        return NULL;
    }
    _mutex.lock();
    u_map::const_iterator it = array_map.find(key);
    LuaStringArray* ret = NULL;
    ret = it->second;
    _mutex.unlock();
    return ret;
}

//移除对应key－value
void MapArray::remove(std::string key)
{
    //判断是否有此ID
    if(array_map.count(key) == 0)
    {
        printf("err: MapArray::remove() 没有此键值\n");
        return;
    }
    _mutex.lock();
//    u_map::const_iterator it = array_map.find(key);
//    LuaStringArray* arr = it->second;
//    arr = NULL;
    array_map.erase(key);
    _mutex.unlock();
}

//清空
void MapArray::removeAll()
{
    _mutex.lock();
    array_map.clear();
    _mutex.unlock();
}

//获取长度
int MapArray::length()
{
    _mutex.lock();
    return array_map.size();
    _mutex.unlock();
}
