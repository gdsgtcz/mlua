#include "lua_cocos2dx_stringbuffer_auto.hpp"
#include "StringBuffer.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_stringbuffer_StringBuffer_get(lua_State* tolua_S)
{
    int argc = 0;
    StringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_stringbuffer_StringBuffer_get'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_stringbuffer_StringBuffer_get'", nullptr);
            return 0;
        }
        std::string ret = cobj->get();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StringBuffer:get",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_stringbuffer_StringBuffer_get'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_stringbuffer_StringBuffer_isFull(lua_State* tolua_S)
{
    int argc = 0;
    StringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_stringbuffer_StringBuffer_isFull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_stringbuffer_StringBuffer_isFull'", nullptr);
            return 0;
        }
        bool ret = cobj->isFull();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StringBuffer:isFull",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_stringbuffer_StringBuffer_isFull'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_stringbuffer_StringBuffer_create(lua_State* tolua_S)
{
    int argc = 0;
    StringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_stringbuffer_StringBuffer_create'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "StringBuffer:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_stringbuffer_StringBuffer_create'", nullptr);
            return 0;
        }
        cobj->create(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StringBuffer:create",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_stringbuffer_StringBuffer_create'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_stringbuffer_StringBuffer_length(lua_State* tolua_S)
{
    int argc = 0;
    StringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_stringbuffer_StringBuffer_length'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_stringbuffer_StringBuffer_length'", nullptr);
            return 0;
        }
        int ret = cobj->length();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StringBuffer:length",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_stringbuffer_StringBuffer_length'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_stringbuffer_StringBuffer_isEmpty(lua_State* tolua_S)
{
    int argc = 0;
    StringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_stringbuffer_StringBuffer_isEmpty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_stringbuffer_StringBuffer_isEmpty'", nullptr);
            return 0;
        }
        bool ret = cobj->isEmpty();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StringBuffer:isEmpty",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_stringbuffer_StringBuffer_isEmpty'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_stringbuffer_StringBuffer_distroy(lua_State* tolua_S)
{
    int argc = 0;
    StringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_stringbuffer_StringBuffer_distroy'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_stringbuffer_StringBuffer_distroy'", nullptr);
            return 0;
        }
        cobj->distroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StringBuffer:distroy",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_stringbuffer_StringBuffer_distroy'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_stringbuffer_StringBuffer_put(lua_State* tolua_S)
{
    int argc = 0;
    StringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_stringbuffer_StringBuffer_put'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StringBuffer:put");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_stringbuffer_StringBuffer_put'", nullptr);
            return 0;
        }
        bool ret = cobj->put(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StringBuffer:put",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_stringbuffer_StringBuffer_put'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_stringbuffer_StringBuffer_size(lua_State* tolua_S)
{
    int argc = 0;
    StringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_stringbuffer_StringBuffer_size'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_stringbuffer_StringBuffer_size'", nullptr);
            return 0;
        }
        int ret = cobj->size();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StringBuffer:size",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_stringbuffer_StringBuffer_size'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_stringbuffer_StringBuffer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    StringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "StringBuffer:StringBuffer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_stringbuffer_StringBuffer_constructor'", nullptr);
            return 0;
        }
        cobj = new StringBuffer(arg0);
        tolua_pushusertype(tolua_S,(void*)cobj,"StringBuffer");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StringBuffer:StringBuffer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_stringbuffer_StringBuffer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_stringbuffer_StringBuffer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (StringBuffer)");
    return 0;
}

int lua_register_cocos2dx_stringbuffer_StringBuffer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"StringBuffer");
    tolua_cclass(tolua_S,"StringBuffer","StringBuffer","",nullptr);

    tolua_beginmodule(tolua_S,"StringBuffer");
        tolua_function(tolua_S,"new",lua_cocos2dx_stringbuffer_StringBuffer_constructor);
        tolua_function(tolua_S,"get",lua_cocos2dx_stringbuffer_StringBuffer_get);
        tolua_function(tolua_S,"isFull",lua_cocos2dx_stringbuffer_StringBuffer_isFull);
        tolua_function(tolua_S,"create",lua_cocos2dx_stringbuffer_StringBuffer_create);
        tolua_function(tolua_S,"length",lua_cocos2dx_stringbuffer_StringBuffer_length);
        tolua_function(tolua_S,"isEmpty",lua_cocos2dx_stringbuffer_StringBuffer_isEmpty);
        tolua_function(tolua_S,"distroy",lua_cocos2dx_stringbuffer_StringBuffer_distroy);
        tolua_function(tolua_S,"put",lua_cocos2dx_stringbuffer_StringBuffer_put);
        tolua_function(tolua_S,"size",lua_cocos2dx_stringbuffer_StringBuffer_size);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(StringBuffer).name();
    g_luaType[typeName] = "StringBuffer";
    g_typeCast["StringBuffer"] = "StringBuffer";
    return 1;
}
TOLUA_API int register_all_cocos2dx_stringbuffer(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"mLua",0);
	tolua_beginmodule(tolua_S,"mLua");

	lua_register_cocos2dx_stringbuffer_StringBuffer(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

