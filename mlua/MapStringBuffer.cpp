//
//  MapStringBuffer.cpp
//  hhl
//
//  Created by guodi on 15/7/8.
//
//

#include "MapStringBuffer.h"
#include <mutex>

static std::mutex _mutex;
static std::mutex _m;

MapStringBuffer* MapStringBuffer::_instance = NULL;

MapStringBuffer* MapStringBuffer::getInstance()
{
    if(_instance == nullptr)
    {
//        _m.lock();
//        if(_instance == NULL)
//        {
            _instance = new MapStringBuffer();
//        }
//        _m.unlock();
    }
    return _instance;
}

//销毁
void MapStringBuffer::destroy()
{
    if (_instance != NULL)
    {
        delete _instance;
        _instance = NULL;
    }
}

//插入
void MapStringBuffer::add(std::string key, int size)
{
    StringBuffer* value = new StringBuffer(size);
    _mutex.lock();
    array_map.insert(u_map::value_type(key, value));
    _mutex.unlock();
}

//插入
void MapStringBuffer::insert(std::string key, StringBuffer* value)
{
    _mutex.lock();
    array_map.insert(u_map::value_type(key, value));
    _mutex.unlock();
}

//通过key获取value
StringBuffer* MapStringBuffer::getValue(std::string key)
{
    //判断是否有该键值
    if(array_map.count(key) == 0)
    {
        printf("err: MapStringBuffer::getValue() 没有此键值\n");
        return NULL;
    }
    _mutex.lock();
    u_map::const_iterator it = array_map.find(key);
    StringBuffer* ret = NULL;
    ret = it->second;
    _mutex.unlock();
    return ret;
}

//移除对应key－value
void MapStringBuffer::remove(std::string key)
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
void MapStringBuffer::removeAll()
{
    _mutex.lock();
    array_map.clear();
    _mutex.unlock();
}

//获取长度
int MapStringBuffer::length()
{
    _mutex.lock();
    return array_map.size();
    _mutex.unlock();
}
