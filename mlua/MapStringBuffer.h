//
//  MapStringBuffer.h
//  hhl
//
//  Created by guodi on 15/7/8.
//
//

#ifndef __hhl__MapStringBuffer__
#define __hhl__MapStringBuffer__

#include "cocos2d.h"
#include <thread>
#include <iostream>
#include "stdio.h"
#include "string.h"
#include "ringbuffer/StringBuffer.h"
using namespace std;

USING_NS_CC;

class MapStringBuffer
{
public:
    MapStringBuffer(){};
    ~MapStringBuffer()
    {
        if (_instance != nullptr)
        {
            delete _instance;
            _instance = nullptr;
        }
        array_map.~unordered_map();
    };
    //单例
    static MapStringBuffer* getInstance();
    //销毁
    static void destroy();
    //插入
    void add(std::string key, int size);
    //插入
    void insert(std::string key, StringBuffer* value);
    //通过key获取value
    StringBuffer* getValue(std::string key);
    //移除对应key－value
    void remove(std::string key);
    //清空
    void removeAll();
    
    //获取长度
    int length();
    
private:
    //定义数据结构
    typedef std::unordered_map<std::string, StringBuffer*> u_map;
    u_map array_map;
    
    //单例
    static MapStringBuffer* _instance;
};


#endif /* defined(__hhl__MapStringBuffer__) */
