#include "LuaStringDict.h"

//单例
static LuaStringDict* _instance = NULL;

LuaStringDict::LuaStringDict()
{
	memset(Str, 0, sizeof(Str));
}


LuaStringDict::~LuaStringDict()
{
}

//单例
LuaStringDict* LuaStringDict::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new LuaStringDict();
	}
	return _instance;
}

void LuaStringDict::destroy()
{
	if (_instance)
	{
		_instance->release();
	}
}

//插入
void LuaStringDict::insert(const char* key, const char* value)
{
	_Mutex.lock();
	_map.insert(umap::value_type(key, value));
	_Mutex.unlock();
}

//通过key获取value
const char* LuaStringDict::getValue(const char* key)
{
    _Mutex.lock();
    const char* ret = _map.at(key).c_str();
	_Mutex.unlock();
	return ret;
	
}

//遍历
void LuaStringDict::foreach()
{
	_Mutex.lock();
	for (umap::iterator iter = _map.begin(); iter != _map.end(); iter++)
	{
		std::cout << "key = " << iter->first.c_str() << "\t" << "value =" << iter->second.c_str() << endl;
	}
	_Mutex.unlock();
}

//移除
void LuaStringDict::remove(const char* key)
{
	_Mutex.lock();
	_map.erase(key);
	_Mutex.unlock();
}

//清空
void LuaStringDict::removeAll()
{
	_Mutex.lock();
	//_map.empty();
	_map.clear();
	_Mutex.unlock();
}

//获取长度
int LuaStringDict::length()
{
    _Mutex.lock();
    int ret = _map.size();
    _Mutex.unlock();
    return ret;
}