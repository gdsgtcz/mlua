#include "lua_cocos2dx_mapdict_auto.hpp"
#include "MapDict.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_mapdict_MapDict_insert(lua_State* tolua_S)
{
    int argc = 0;
    MapDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapdict_MapDict_insert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        LuaStringDict* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapDict:insert");

        ok &= luaval_to_object<LuaStringDict>(tolua_S, 3, "LuaStringDict",&arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapdict_MapDict_insert'", nullptr);
            return 0;
        }
        cobj->insert(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapDict:insert",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapdict_MapDict_insert'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapdict_MapDict_remove(lua_State* tolua_S)
{
    int argc = 0;
    MapDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapdict_MapDict_remove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapDict:remove");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapdict_MapDict_remove'", nullptr);
            return 0;
        }
        cobj->remove(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapDict:remove",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapdict_MapDict_remove'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapdict_MapDict_getValue(lua_State* tolua_S)
{
    int argc = 0;
    MapDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapdict_MapDict_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapDict:getValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapdict_MapDict_getValue'", nullptr);
            return 0;
        }
        LuaStringDict* ret = cobj->getValue(arg0);
        object_to_luaval<LuaStringDict>(tolua_S, "LuaStringDict",(LuaStringDict*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapDict:getValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapdict_MapDict_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapdict_MapDict_removeAll(lua_State* tolua_S)
{
    int argc = 0;
    MapDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapdict_MapDict_removeAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapdict_MapDict_removeAll'", nullptr);
            return 0;
        }
        cobj->removeAll();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapDict:removeAll",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapdict_MapDict_removeAll'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapdict_MapDict_length(lua_State* tolua_S)
{
    int argc = 0;
    MapDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_mapdict_MapDict_length'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapdict_MapDict_length'", nullptr);
            return 0;
        }
        int ret = cobj->length();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapDict:length",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapdict_MapDict_length'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_mapdict_MapDict_destroy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapDict",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapdict_MapDict_destroy'", nullptr);
            return 0;
        }
        MapDict::destroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapDict:destroy",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapdict_MapDict_destroy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_mapdict_MapDict_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapDict",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapdict_MapDict_getInstance'", nullptr);
            return 0;
        }
        MapDict* ret = MapDict::getInstance();
        object_to_luaval<MapDict>(tolua_S, "MapDict",(MapDict*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapDict:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapdict_MapDict_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_mapdict_MapDict_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MapDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_mapdict_MapDict_constructor'", nullptr);
            return 0;
        }
        cobj = new MapDict();
        tolua_pushusertype(tolua_S,(void*)cobj,"MapDict");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapDict:MapDict",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_mapdict_MapDict_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_mapdict_MapDict_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MapDict)");
    return 0;
}

int lua_register_cocos2dx_mapdict_MapDict(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MapDict");
    tolua_cclass(tolua_S,"MapDict","MapDict","cc.Object",nullptr);

    tolua_beginmodule(tolua_S,"MapDict");
        tolua_function(tolua_S,"new",lua_cocos2dx_mapdict_MapDict_constructor);
        tolua_function(tolua_S,"insert",lua_cocos2dx_mapdict_MapDict_insert);
        tolua_function(tolua_S,"remove",lua_cocos2dx_mapdict_MapDict_remove);
        tolua_function(tolua_S,"getValue",lua_cocos2dx_mapdict_MapDict_getValue);
        tolua_function(tolua_S,"removeAll",lua_cocos2dx_mapdict_MapDict_removeAll);
        tolua_function(tolua_S,"length",lua_cocos2dx_mapdict_MapDict_length);
        tolua_function(tolua_S,"destroy", lua_cocos2dx_mapdict_MapDict_destroy);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_mapdict_MapDict_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MapDict).name();
    g_luaType[typeName] = "MapDict";
    g_typeCast["MapDict"] = "MapDict";
    return 1;
}
TOLUA_API int register_all_cocos2dx_mapdict(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"mLua",0);
	tolua_beginmodule(tolua_S,"mLua");

	lua_register_cocos2dx_mapdict_MapDict(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

