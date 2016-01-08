extern "C" {
#include "lua.h"
}

#include "LuaStringArray.h"


LuaStringArray::LuaStringArray()
{
}

LuaStringArray::~LuaStringArray()
{
    
}

//插入
void LuaStringArray::insert(const std::string value)
{
	_Mutex.lock();
    _vec.push_back(Value(value));
	_Mutex.unlock();
}

//获取给定位置的元素
std::string LuaStringArray::getValue(int i)
{
    if (i < _vec.size())
    {
        _Mutex.lock();

        printf("getValue0.length:%lu\n", _vec.size());
        std::string str = _vec.at(i).asString();
        printf("getValue1.length:%lu\n", _vec.size());

        _Mutex.unlock();

        return str;
    }
    return "";
}


//遍历
void LuaStringArray::getAllAndClear(lua_State* L)
{
    if (NULL  == L)
        return;
    
    if ( _vec.empty()) {
        lua_pushnil(L);           /* L: table key value*/
        return;
    }
    
    lua_newtable(L);                                    /* L: table */

	int i = 1;
	_Mutex.lock();
	for (ValueVector::iterator iter = _vec.begin(); iter != _vec.end(); iter++)
	{
        //std::cout << "第 " << i << " 个元素 value = " << iter->asString() << std::endl;

        std::string v = iter->asString();

        lua_pushnumber(L, (lua_Number) i);           /* L: table key value*/
        lua_pushlstring(L, v.c_str(), v.length());                  /* L: table key */
        lua_rawset(L, -3);                           /* table[key] = value, L: table */
        
		i++;
	}

    _vec.clear();
    
	_Mutex.unlock();

}

//移除
void LuaStringArray::remove(int i)
{
    if (i>=_vec.size()) return ;
    
	_Mutex.lock();

    printf("remove0.length:%lu\n", _vec.size());
    std::string val = _vec.at(i).asString();
    auto star_iter = std::find(_vec.begin(), _vec.end(), Value(val));
    _vec.erase(star_iter);
    printf("remove1.length:%lu\n", _vec.size());
	_Mutex.unlock();

}

//移除元素
void LuaStringArray::removeByValue(const std::string val)
{
    _Mutex.lock();
    auto star_iter = std::find(_vec.begin(), _vec.end(), Value(val));
    _vec.erase(star_iter);
    _Mutex.unlock();
}

//获取长度
int LuaStringArray::length()
{
    /*
	int i = 0;
	_Mutex.lock();
	for (ValueVector::iterator iter = _vec.begin(); iter != _vec.end(); iter++)
	{
		i++;
	}
	_Mutex.unlock();
	return i;
     */
    
    return _vec.size();
}

//入栈
void LuaStringArray::push(const std::string str)
{
	_Mutex.lock();
	_vec.push_back(Value(str));
	_Mutex.unlock();
}

//出栈
void LuaStringArray::pop()
{
	_Mutex.lock();
    //直接删除最后一个
	_vec.pop_back();
	_Mutex.unlock();
}

//清空
void LuaStringArray::removeAll()
{
	_Mutex.lock();
	_vec.clear();
	_Mutex.unlock();
}
