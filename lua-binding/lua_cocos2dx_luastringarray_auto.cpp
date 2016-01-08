#include "lua_cocos2dx_luastringarray_auto.hpp"
#include "LuaStringArray.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_luastringarray_LuaStringArray_insert(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringarray_LuaStringArray_insert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "LuaStringArray:insert");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringarray_LuaStringArray_insert'", nullptr);
            return 0;
        }
        cobj->insert(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringArray:insert",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringarray_LuaStringArray_insert'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringarray_LuaStringArray_removeByValue(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringarray_LuaStringArray_removeByValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "LuaStringArray:removeByValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringarray_LuaStringArray_removeByValue'", nullptr);
            return 0;
        }
        cobj->removeByValue(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringArray:removeByValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringarray_LuaStringArray_removeByValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringarray_LuaStringArray_remove(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringarray_LuaStringArray_remove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "LuaStringArray:remove");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringarray_LuaStringArray_remove'", nullptr);
            return 0;
        }
        cobj->remove(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringArray:remove",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringarray_LuaStringArray_remove'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringarray_LuaStringArray_getValue(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringarray_LuaStringArray_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "LuaStringArray:getValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringarray_LuaStringArray_getValue'", nullptr);
            return 0;
        }
        std::string ret = cobj->getValue(arg0);
        //lua_pushlstring(tolua_S,ret.c_str(), ret.length());
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringArray:getValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringarray_LuaStringArray_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringarray_LuaStringArray_removeAll(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringarray_LuaStringArray_removeAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringarray_LuaStringArray_removeAll'", nullptr);
            return 0;
        }
        cobj->removeAll();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringArray:removeAll",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringarray_LuaStringArray_removeAll'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringarray_LuaStringArray_length(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringarray_LuaStringArray_length'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringarray_LuaStringArray_length'", nullptr);
            return 0;
        }
        int ret = cobj->length();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringArray:length",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringarray_LuaStringArray_length'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringarray_LuaStringArray_getAllAndClear(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringarray_LuaStringArray_getAllAndClear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringarray_LuaStringArray_getAllAndClear'", nullptr);
            return 0;
        }
        //smh modify
        cobj->getAllAndClear(tolua_S);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringArray:getAllAndClear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringarray_LuaStringArray_getAllAndClear'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringarray_LuaStringArray_pop(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringarray_LuaStringArray_pop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringarray_LuaStringArray_pop'", nullptr);
            return 0;
        }
        cobj->pop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringArray:pop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringarray_LuaStringArray_pop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringarray_LuaStringArray_push(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringarray_LuaStringArray_push'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "LuaStringArray:push");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringarray_LuaStringArray_push'", nullptr);
            return 0;
        }
        cobj->push(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringArray:push",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringarray_LuaStringArray_push'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringarray_LuaStringArray_constructor(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringarray_LuaStringArray_constructor'", nullptr);
            return 0;
        }
        cobj = new LuaStringArray();
        tolua_pushusertype(tolua_S,(void*)cobj,"LuaStringArray");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringArray:LuaStringArray",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringarray_LuaStringArray_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_luastringarray_LuaStringArray_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (LuaStringArray)");
    return 0;
}

int lua_register_cocos2dx_luastringarray_LuaStringArray(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"LuaStringArray");
    tolua_cclass(tolua_S,"LuaStringArray","LuaStringArray","",nullptr);

    tolua_beginmodule(tolua_S,"LuaStringArray");
        tolua_function(tolua_S,"new",lua_cocos2dx_luastringarray_LuaStringArray_constructor);
        tolua_function(tolua_S,"insert",lua_cocos2dx_luastringarray_LuaStringArray_insert);
        tolua_function(tolua_S,"removeByValue",lua_cocos2dx_luastringarray_LuaStringArray_removeByValue);
        tolua_function(tolua_S,"remove",lua_cocos2dx_luastringarray_LuaStringArray_remove);
        tolua_function(tolua_S,"getValue",lua_cocos2dx_luastringarray_LuaStringArray_getValue);
        tolua_function(tolua_S,"removeAll",lua_cocos2dx_luastringarray_LuaStringArray_removeAll);
        tolua_function(tolua_S,"length",lua_cocos2dx_luastringarray_LuaStringArray_length);
        tolua_function(tolua_S,"getAllAndClear",lua_cocos2dx_luastringarray_LuaStringArray_getAllAndClear);
        tolua_function(tolua_S,"pop",lua_cocos2dx_luastringarray_LuaStringArray_pop);
        tolua_function(tolua_S,"push",lua_cocos2dx_luastringarray_LuaStringArray_push);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(LuaStringArray).name();
    g_luaType[typeName] = "LuaStringArray";
    g_typeCast["LuaStringArray"] = "LuaStringArray";
    return 1;
}
TOLUA_API int register_all_cocos2dx_luastringarray(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"mLua",0);
	tolua_beginmodule(tolua_S,"mLua");

	lua_register_cocos2dx_luastringarray_LuaStringArray(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

