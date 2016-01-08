//
//  MapArray.h
//  hhl
//
//  Created by guodi on 15/6/23.
//
//

#ifndef __hhl__MapArray__
#define __hhl__MapArray__

#include "cocos2d.h"
#include <thread>
#include <iostream>
#include "stdio.h"
#include "string.h"
#include "LuaStringArray.h"
using namespace std;

USING_NS_CC;

class MapArray
{
public:
    MapArray(){};
    ~MapArray(){};
    //单例
    static MapArray* getInstance();
    //销毁
    static void destroy();
    
    //插入
    void insert(std::string key, LuaStringArray* value);
    //通过key获取value
    LuaStringArray* getValue(std::string key);
    //移除对应key－value
    void remove(std::string key);
    //清空
    void removeAll();
    
    //获取长度
    int length();
    
private:
    //定义数据结构
    typedef std::unordered_map<std::string, LuaStringArray*> u_map;
    u_map array_map;
    
    std::mutex _mutex;

    //单例
    static MapArray* _instance;
};


#endif /* defined(__hhl__MapArray__) */
