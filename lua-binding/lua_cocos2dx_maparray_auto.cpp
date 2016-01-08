#include "lua_cocos2dx_maparray_auto.hpp"
#include "MapArray.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_maparray_MapArray_insert(lua_State* tolua_S)
{
    int argc = 0;
    MapArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_maparray_MapArray_insert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        LuaStringArray* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapArray:insert");

        ok &= luaval_to_object<LuaStringArray>(tolua_S, 3, "LuaStringArray",&arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_maparray_MapArray_insert'", nullptr);
            return 0;
        }
        cobj->insert(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapArray:insert",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_maparray_MapArray_insert'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_maparray_MapArray_remove(lua_State* tolua_S)
{
    int argc = 0;
    MapArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_maparray_MapArray_remove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapArray:remove");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_maparray_MapArray_remove'", nullptr);
            return 0;
        }
        cobj->remove(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapArray:remove",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_maparray_MapArray_remove'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_maparray_MapArray_getValue(lua_State* tolua_S)
{
    int argc = 0;
    MapArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_maparray_MapArray_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapArray:getValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_maparray_MapArray_getValue'", nullptr);
            return 0;
        }
        LuaStringArray* ret = cobj->getValue(arg0);
        object_to_luaval<LuaStringArray>(tolua_S, "LuaStringArray",(LuaStringArray*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapArray:getValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_maparray_MapArray_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_maparray_MapArray_removeAll(lua_State* tolua_S)
{
    int argc = 0;
    MapArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_maparray_MapArray_removeAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_maparray_MapArray_removeAll'", nullptr);
            return 0;
        }
        cobj->removeAll();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapArray:removeAll",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_maparray_MapArray_removeAll'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_maparray_MapArray_length(lua_State* tolua_S)
{
    int argc = 0;
    MapArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_maparray_MapArray_length'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_maparray_MapArray_length'", nullptr);
            return 0;
        }
        int ret = cobj->length();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapArray:length",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_maparray_MapArray_length'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_maparray_MapArray_destroy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapArray",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_maparray_MapArray_destroy'", nullptr);
            return 0;
        }
        MapArray::destroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapArray:destroy",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_maparray_MapArray_destroy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_maparray_MapArray_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapArray",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_maparray_MapArray_getInstance'", nullptr);
            return 0;
        }
        MapArray* ret = MapArray::getInstance();
        object_to_luaval<MapArray>(tolua_S, "MapArray",(MapArray*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapArray:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_maparray_MapArray_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_maparray_MapArray_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MapArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_maparray_MapArray_constructor'", nullptr);
            return 0;
        }
        cobj = new MapArray();
        tolua_pushusertype(tolua_S,(void*)cobj,"MapArray");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapArray:MapArray",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_maparray_MapArray_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_maparray_MapArray_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MapArray)");
    return 0;
}

int lua_register_cocos2dx_maparray_MapArray(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MapArray");
    tolua_cclass(tolua_S,"MapArray","MapArray","",nullptr);

    tolua_beginmodule(tolua_S,"MapArray");
        tolua_function(tolua_S,"new",lua_cocos2dx_maparray_MapArray_constructor);
        tolua_function(tolua_S,"insert",lua_cocos2dx_maparray_MapArray_insert);
        tolua_function(tolua_S,"remove",lua_cocos2dx_maparray_MapArray_remove);
        tolua_function(tolua_S,"getValue",lua_cocos2dx_maparray_MapArray_getValue);
        tolua_function(tolua_S,"removeAll",lua_cocos2dx_maparray_MapArray_removeAll);
        tolua_function(tolua_S,"length",lua_cocos2dx_maparray_MapArray_length);
        tolua_function(tolua_S,"destroy", lua_cocos2dx_maparray_MapArray_destroy);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_maparray_MapArray_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MapArray).name();
    g_luaType[typeName] = "MapArray";
    g_typeCast["MapArray"] = "MapArray";
    return 1;
}
TOLUA_API int register_all_cocos2dx_maparray(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"mLua",0);
	tolua_beginmodule(tolua_S,"mLua");

	lua_register_cocos2dx_maparray_MapArray(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

