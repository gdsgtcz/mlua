//
//  LuaStackArray.h
//  hhl
//
//  Created by guodi on 15/6/25.
//
//

#ifndef __hhl__LuaStackArray__
#define __hhl__LuaStackArray__

#include <stdio.h>
#include "cocos2d.h"
#include "CCLuaStack.h"
#include "TaskQueue.h"
#include <mutex>
USING_NS_CC;

//ID-Stack map
class LuaStackArray
{
public:
    LuaStackArray(){};
    ~LuaStackArray(){};
    
    //单例
    static LuaStackArray* getInstance();
    
    //插入
    void insert(int ID, LuaStack* stack);
    
    //查找
    LuaStack* get(int ID);
    
private:
    typedef std::unordered_map<int, LuaStack*> smap;
    smap stackMap;
    
    
};

//ID-TaskQueue (sub) map
class TaskQueueArray
{
public:
    TaskQueueArray(){};
    ~TaskQueueArray(){};
    
    //单例
    static TaskQueueArray* getInstance();
    
    //插入
    void insert(int ID, SubThreadTask * task);
    
    //查找
    SubThreadTask* get(int ID);
    
private:
    static TaskQueueArray* instance;
    typedef std::unordered_map<int, SubThreadTask*> smap;
    smap taskMap;
    
};

//State-Stack map
class MapStateStack
{
public:
    MapStateStack(){};
    ~MapStateStack(){};
    
    //单例
    static MapStateStack* getInstance();
    
    //插入
    void insert(lua_State* state, LuaStack* stack);
    
    //查找
    LuaStack* getStackByState(lua_State* state);
    
    //判断是否存在该state
    bool isExist(lua_State* state);
    
    //返回长度
    int length();
    
    //清空
    void clear();
    
    //销毁
    void distroy();
    
private:
    typedef std::unordered_map<lua_State*, LuaStack*> smap;
    smap _map;
    
};


#endif /* defined(__hhl__LuaStackArray__) */
