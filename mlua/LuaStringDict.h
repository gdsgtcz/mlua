#ifndef __LUASTRINGDICT
#define __LUASTRINGDICT
//Õ®”√¥ µ‰£¨Map µœ÷

#include "cocos2d.h"
#include <thread>
#include <iostream>
#include "stdio.h" 
#include "string.h"
using namespace std;

USING_NS_CC;

class LuaStringDict : public Object
{
public:
	LuaStringDict();
	~LuaStringDict();

	static LuaStringDict* getInstance();
	static void destroy();

	//插入
	void insert(const char* key, const char* value);
	//通过key获取value
	const char* getValue(const char* key);
	//遍历
	void foreach();
	//移除
	void remove(const char* key);
	//清空
	void removeAll();
    
    //获取长度
    int length();

private:
	//cocos2d::Map<std::string, Sprite*> _map;
	typedef std::unordered_map<std::string, std::string> umap;
	umap _map;
	//typedef std::pair<std::string, std::string> TStrStrPair;
	char * myStrcat(char *str1, char *str2);
	char* Str[1024];
    
    //互斥锁
    std::mutex  _Mutex;
};

#endif