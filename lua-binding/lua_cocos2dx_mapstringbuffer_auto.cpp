#include "lua_cocos2dx_mapstringbuffer_auto.hpp"
#include "MapStringBuffer.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_mapstringbuffer_MapStringBuffer_insert(lua_State* tolua_S)
{
    int argc = 0;
    MapStringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapStringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapStringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_insert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        StringBuffer* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapStringBuffer:insert");

        ok &= luaval_to_object<StringBuffer>(tolua_S, 3, "StringBuffer",&arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_insert'", nullptr);
            return 0;
        }
        cobj->insert(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapStringBuffer:insert",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_insert'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapstringbuffer_MapStringBuffer_length(lua_State* tolua_S)
{
    int argc = 0;
    MapStringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapStringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapStringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_length'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_length'", nullptr);
            return 0;
        }
        int ret = cobj->length();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapStringBuffer:length",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_length'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapstringbuffer_MapStringBuffer_remove(lua_State* tolua_S)
{
    int argc = 0;
    MapStringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapStringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapStringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_remove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapStringBuffer:remove");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_remove'", nullptr);
            return 0;
        }
        cobj->remove(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapStringBuffer:remove",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_remove'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapstringbuffer_MapStringBuffer_getValue(lua_State* tolua_S)
{
    int argc = 0;
    MapStringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapStringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapStringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapStringBuffer:getValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_getValue'", nullptr);
            return 0;
        }
        StringBuffer* ret = cobj->getValue(arg0);
        object_to_luaval<StringBuffer>(tolua_S, "StringBuffer",(StringBuffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapStringBuffer:getValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapstringbuffer_MapStringBuffer_removeAll(lua_State* tolua_S)
{
    int argc = 0;
    MapStringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapStringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapStringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_removeAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_removeAll'", nullptr);
            return 0;
        }
        cobj->removeAll();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapStringBuffer:removeAll",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_removeAll'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapstringbuffer_MapStringBuffer_add(lua_State* tolua_S)
{
    int argc = 0;
    MapStringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapStringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapStringBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_add'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapStringBuffer:add");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapStringBuffer:add");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_add'", nullptr);
            return 0;
        }
        cobj->add(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapStringBuffer:add",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_add'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapstringbuffer_MapStringBuffer_destroy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapStringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_destroy'", nullptr);
            return 0;
        }
        MapStringBuffer::destroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapStringBuffer:destroy",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_destroy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_mapstringbuffer_MapStringBuffer_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapStringBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_getInstance'", nullptr);
            return 0;
        }
        MapStringBuffer* ret = MapStringBuffer::getInstance();
        object_to_luaval<MapStringBuffer>(tolua_S, "MapStringBuffer",(MapStringBuffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapStringBuffer:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_mapstringbuffer_MapStringBuffer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MapStringBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_constructor'", nullptr);
            return 0;
        }
        cobj = new MapStringBuffer();
        tolua_pushusertype(tolua_S,(void*)cobj,"MapStringBuffer");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapStringBuffer:MapStringBuffer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapstringbuffer_MapStringBuffer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_mapstringbuffer_MapStringBuffer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MapStringBuffer)");
    return 0;
}

int lua_register_cocos2dx_mapstringbuffer_MapStringBuffer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MapStringBuffer");
    tolua_cclass(tolua_S,"MapStringBuffer","MapStringBuffer","cc.Object",nullptr);

    tolua_beginmodule(tolua_S,"MapStringBuffer");
        tolua_function(tolua_S,"new",lua_cocos2dx_mapstringbuffer_MapStringBuffer_constructor);
        tolua_function(tolua_S,"insert",lua_cocos2dx_mapstringbuffer_MapStringBuffer_insert);
        tolua_function(tolua_S,"length",lua_cocos2dx_mapstringbuffer_MapStringBuffer_length);
        tolua_function(tolua_S,"remove",lua_cocos2dx_mapstringbuffer_MapStringBuffer_remove);
        tolua_function(tolua_S,"getValue",lua_cocos2dx_mapstringbuffer_MapStringBuffer_getValue);
        tolua_function(tolua_S,"removeAll",lua_cocos2dx_mapstringbuffer_MapStringBuffer_removeAll);
        tolua_function(tolua_S,"add",lua_cocos2dx_mapstringbuffer_MapStringBuffer_add);
        tolua_function(tolua_S,"destroy", lua_cocos2dx_mapstringbuffer_MapStringBuffer_destroy);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_mapstringbuffer_MapStringBuffer_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MapStringBuffer).name();
    g_luaType[typeName] = "MapStringBuffer";
    g_typeCast["MapStringBuffer"] = "MapStringBuffer";
    return 1;
}
TOLUA_API int register_all_cocos2dx_mapstringbuffer(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"mLua",0);
	tolua_beginmodule(tolua_S,"mLua");

	lua_register_cocos2dx_mapstringbuffer_MapStringBuffer(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

