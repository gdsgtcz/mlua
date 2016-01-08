#include "CommonDictionary.h"

//单例
static CommonDictionary* s_instance = NULL;
// 线程锁
static std::mutex  pDict_Mutex;

CommonDictionary::CommonDictionary()
{
	pDict->retain();
	// 初始化线程锁
	//pthread_mutex_init(&pDict_Mutex, NULL);
	memset(Str, 0 , sizeof(Str));
}

CommonDictionary::~CommonDictionary()
{
}  

CommonDictionary* CommonDictionary::getInstance(){
	if (s_instance == NULL)
	{
		s_instance = new CommonDictionary();
	}
	return s_instance;
}

void CommonDictionary::destroy(){
	if (s_instance)
	{
		s_instance->release();
	}
}

//插入一个key-value
void CommonDictionary::setObj(const char* key, const char* pObject)
{
	pDict_Mutex.lock();
	pDict->setObject((String*)pObject, key);
	//CCLog("key ===== %s ,pDict ===== %s", key, pObject);
	pDict_Mutex.unlock();
}

//返回指定字符串类型key的value
const char* CommonDictionary::objForKey(const char* key)
{
	pDict_Mutex.lock();
	const char* ret = (const char*)pDict->objectForKey(key);
	//CCLog("return !!! key ===== %s ,pDict ===== %s", key, ret);
	pDict_Mutex.unlock();
	return ret;
}

//遍历
void CommonDictionary::foreach()
{
	DictElement * pElement;
	CCDICT_FOREACH(pDict, pElement) 
	{
		const char * key = pElement->getStrKey();

		const char* value = (const char*)pDict->objectForKey(key);

		printf("CommonDictionary ---> key = %s, value = %s\n", key, value);

		//CCLog(key);
		//CCLog(value);
		//myStrcat(Str, value);
 		//CCLog(Str);
	}
}

//移除指定key
void CommonDictionary::removeObjForKey(const char* key)
{
	pDict->removeObjectForKey(key);
}

//移除所有的key-value
void CommonDictionary::removeAllObj()
{
	pDict->removeAllObjects();
}

char * CommonDictionary::myStrcat(char *str1, char *str2)
{
	if ((str1 == NULL) || (str2 == NULL)) throw "Invalide arguments!";
	char *pt = str1;
	while (*str1 != '\0') str1++;
	while (*str2 != '\0') *str1++ = *str2++;
	*str1 = '\0';
	return pt;
}