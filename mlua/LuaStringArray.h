#ifndef __LUASTRINGARRAY__
#define __LUASTRINGARRAY__

#include "cocos2d.h"
#include <iostream>
#include "stdio.h" 
//#include "string.h"

USING_NS_CC;

class LuaStringArray
{
public:

	LuaStringArray();
	~LuaStringArray();

	//插入指定位置
    void insert(const std::string value);
    
	//获取对应位置元素
    std::string getValue(int i);

	//遍历
	void getAllAndClear(lua_State *L);

	//移除对应位置元素
	void remove(int i);

    //移除元素
    void removeByValue(const std::string val);

	//获取长度
	int length();
    
	//入栈
    void push(const std::string str);
	//出栈
	void pop();
	//清空
	void removeAll();

private:
	//Vector<const char*> _vec;
	ValueVector _vec;
    
    //锁
    std::mutex  _Mutex;	
    
};

#endif