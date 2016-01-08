//
//  MapDict.h
//  hhl
//
//  Created by guodi on 15/6/25.
//
//

#ifndef __hhl__MapDict__
#define __hhl__MapDict__

#include <stdio.h>
#include "cocos2d.h"
#include "LuaStringDict.h"

USING_NS_CC;

class MapDict : public Object
{
public:
    MapDict(){};
    ~MapDict(){};
    //单例
    static MapDict* getInstance();
    //销毁
    static void destroy();
    
    //插入
    void insert(std::string key, LuaStringDict* value);
    //通过key获取value
    LuaStringDict* getValue(std::string key);
    //移除对应key－value
    void remove(std::string key);
    //清空
    void removeAll();
    
    //获取长度
    int length();
    
private:
    //定义数据结构
    typedef std::unordered_map<std::string, LuaStringDict*> d_map;
    d_map dict_map;
    
};


#endif /* defined(__hhl__MapDict__) */
