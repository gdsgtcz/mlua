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

	//����һ��key-value
	void setObj(const char* key, const char* pObject);
	//����ָ���ַ�������key��value
	const char* objForKey(const char* key);
	//����
	void foreach();
	//�Ƴ�ָ��key
	void removeObjForKey(const char* key);
	//�Ƴ����е�key-value
	void removeAllObj();

private:
	char * myStrcat(char *str1, char *str2);
	__Dictionary* pDict = __Dictionary::create();
	
	char Str[1024*1024];
};

#endif