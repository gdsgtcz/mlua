#include "lua_cocos2dx_bytebuffer_auto.hpp"
#include "ByteBuffer.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_bytebuffer_ByteBuffer_get(lua_State* tolua_S)
{
    int argc = 0;
    ByteBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_bytebuffer_ByteBuffer_get'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_bytebuffer_ByteBuffer_get'", nullptr);
            return 0;
        }
        std::string ret = cobj->get();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteBuffer:get",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_bytebuffer_ByteBuffer_get'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_bytebuffer_ByteBuffer_length(lua_State* tolua_S)
{
    int argc = 0;
    ByteBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_bytebuffer_ByteBuffer_length'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_bytebuffer_ByteBuffer_length'", nullptr);
            return 0;
        }
        int ret = cobj->length();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteBuffer:length",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_bytebuffer_ByteBuffer_length'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_bytebuffer_ByteBuffer_init(lua_State* tolua_S)
{
    int argc = 0;
    ByteBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_bytebuffer_ByteBuffer_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ByteBuffer:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_bytebuffer_ByteBuffer_init'", nullptr);
            return 0;
        }
        cobj->init(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteBuffer:init",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_bytebuffer_ByteBuffer_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_bytebuffer_ByteBuffer_put(lua_State* tolua_S)
{
    int argc = 0;
    ByteBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_bytebuffer_ByteBuffer_put'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ByteBuffer:put");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_bytebuffer_ByteBuffer_put'", nullptr);
            return 0;
        }
        bool ret = cobj->put(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteBuffer:put",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_bytebuffer_ByteBuffer_put'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_bytebuffer_ByteBuffer_size(lua_State* tolua_S)
{
    int argc = 0;
    ByteBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_bytebuffer_ByteBuffer_size'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_bytebuffer_ByteBuffer_size'", nullptr);
            return 0;
        }
        int ret = cobj->size();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteBuffer:size",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_bytebuffer_ByteBuffer_size'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_bytebuffer_ByteBuffer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ByteBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ByteBuffer:ByteBuffer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_bytebuffer_ByteBuffer_constructor'", nullptr);
            return 0;
        }
        cobj = new ByteBuffer(arg0);
        tolua_pushusertype(tolua_S,(void*)cobj,"ByteBuffer");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteBuffer:ByteBuffer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_bytebuffer_ByteBuffer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_bytebuffer_ByteBuffer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ByteBuffer)");
    return 0;
}

int lua_register_cocos2dx_bytebuffer_ByteBuffer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ByteBuffer");
    tolua_cclass(tolua_S,"ByteBuffer","ByteBuffer","",nullptr);

    tolua_beginmodule(tolua_S,"ByteBuffer");
        tolua_function(tolua_S,"new",lua_cocos2dx_bytebuffer_ByteBuffer_constructor);
        tolua_function(tolua_S,"get",lua_cocos2dx_bytebuffer_ByteBuffer_get);
        tolua_function(tolua_S,"length",lua_cocos2dx_bytebuffer_ByteBuffer_length);
        tolua_function(tolua_S,"init",lua_cocos2dx_bytebuffer_ByteBuffer_init);
        tolua_function(tolua_S,"put",lua_cocos2dx_bytebuffer_ByteBuffer_put);
        tolua_function(tolua_S,"size",lua_cocos2dx_bytebuffer_ByteBuffer_size);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ByteBuffer).name();
    g_luaType[typeName] = "ByteBuffer";
    g_typeCast["ByteBuffer"] = "ByteBuffer";
    return 1;
}
TOLUA_API int register_all_cocos2dx_bytebuffer(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"mLua",0);
	tolua_beginmodule(tolua_S,"mLua");

	lua_register_cocos2dx_bytebuffer_ByteBuffer(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

