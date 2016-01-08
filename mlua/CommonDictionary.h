#ifndef _COMMONDICTIONARY_
#define _COMMONDICTIONARY_

#include "cocos2d.h"
#include <thread>
#include <iostream>
#include "stdio.h" 
#include "string.h"
using namespace std;

USING_NS_CC;
class CommonDictionary : public CCObject
{
public:
	CommonDictionary();
	~CommonDictionary();

	static CommonDictionary* getInstance();
	static void destroy();

	//插入一个key-value
	void setObj(const char* key, const char* pObject);
	//返回指定字符串类型key的value
	const char* objForKey(const char* key);
	//遍历
	void foreach();
	//移除指定key
	void removeObjForKey(const char* key);
	//移除所有的key-value
	void removeAllObj();

private:
	char * myStrcat(char *str1, char *str2);
	__Dictionary* pDict = __Dictionary::create();
	
	char Str[1024*1024];
};

#endif