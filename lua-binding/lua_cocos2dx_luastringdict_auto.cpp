#include "lua_cocos2dx_luastringdict_auto.hpp"
#include "LuaStringDict.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_luastringdict_LuaStringDict_insert(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringdict_LuaStringDict_insert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "LuaStringDict:insert"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "LuaStringDict:insert"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringdict_LuaStringDict_insert'", nullptr);
            return 0;
        }
        cobj->insert(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringDict:insert",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringdict_LuaStringDict_insert'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringdict_LuaStringDict_remove(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringdict_LuaStringDict_remove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "LuaStringDict:remove"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringdict_LuaStringDict_remove'", nullptr);
            return 0;
        }
        cobj->remove(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringDict:remove",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringdict_LuaStringDict_remove'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringdict_LuaStringDict_getValue(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringdict_LuaStringDict_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "LuaStringDict:getValue"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringdict_LuaStringDict_getValue'", nullptr);
            return 0;
        }
        const char* ret = cobj->getValue(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringDict:getValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringdict_LuaStringDict_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringdict_LuaStringDict_removeAll(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringdict_LuaStringDict_removeAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringdict_LuaStringDict_removeAll'", nullptr);
            return 0;
        }
        cobj->removeAll();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringDict:removeAll",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringdict_LuaStringDict_removeAll'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringdict_LuaStringDict_length(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringdict_LuaStringDict_length'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringdict_LuaStringDict_length'", nullptr);
            return 0;
        }
        int ret = cobj->length();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringDict:length",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringdict_LuaStringDict_length'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringdict_LuaStringDict_foreach(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaStringDict",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaStringDict*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_luastringdict_LuaStringDict_foreach'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringdict_LuaStringDict_foreach'", nullptr);
            return 0;
        }
        cobj->foreach();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringDict:foreach",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringdict_LuaStringDict_foreach'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_luastringdict_LuaStringDict_destroy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LuaStringDict",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringdict_LuaStringDict_destroy'", nullptr);
            return 0;
        }
        LuaStringDict::destroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "LuaStringDict:destroy",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringdict_LuaStringDict_destroy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_luastringdict_LuaStringDict_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LuaStringDict",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringdict_LuaStringDict_getInstance'", nullptr);
            return 0;
        }
        LuaStringDict* ret = LuaStringDict::getInstance();
        object_to_luaval<LuaStringDict>(tolua_S, "LuaStringDict",(LuaStringDict*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "LuaStringDict:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringdict_LuaStringDict_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_luastringdict_LuaStringDict_constructor(lua_State* tolua_S)
{
    int argc = 0;
    LuaStringDict* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_luastringdict_LuaStringDict_constructor'", nullptr);
            return 0;
        }
        cobj = new LuaStringDict();
        tolua_pushusertype(tolua_S,(void*)cobj,"LuaStringDict");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaStringDict:LuaStringDict",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_luastringdict_LuaStringDict_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_luastringdict_LuaStringDict_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (LuaStringDict)");
    return 0;
}

int lua_register_cocos2dx_luastringdict_LuaStringDict(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"LuaStringDict");
    tolua_cclass(tolua_S,"LuaStringDict","LuaStringDict","cc.Object",nullptr);

    tolua_beginmodule(tolua_S,"LuaStringDict");
        tolua_function(tolua_S,"new",lua_cocos2dx_luastringdict_LuaStringDict_constructor);
        tolua_function(tolua_S,"insert",lua_cocos2dx_luastringdict_LuaStringDict_insert);
        tolua_function(tolua_S,"remove",lua_cocos2dx_luastringdict_LuaStringDict_remove);
        tolua_function(tolua_S,"getValue",lua_cocos2dx_luastringdict_LuaStringDict_getValue);
        tolua_function(tolua_S,"removeAll",lua_cocos2dx_luastringdict_LuaStringDict_removeAll);
        tolua_function(tolua_S,"length",lua_cocos2dx_luastringdict_LuaStringDict_length);
        tolua_function(tolua_S,"foreach",lua_cocos2dx_luastringdict_LuaStringDict_foreach);
        tolua_function(tolua_S,"destroy", lua_cocos2dx_luastringdict_LuaStringDict_destroy);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_luastringdict_LuaStringDict_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(LuaStringDict).name();
    g_luaType[typeName] = "LuaStringDict";
    g_typeCast["LuaStringDict"] = "LuaStringDict";
    return 1;
}
TOLUA_API int register_all_cocos2dx_luastringdict(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"mLua",0);
	tolua_beginmodule(tolua_S,"mLua");

	lua_register_cocos2dx_luastringdict_LuaStringDict(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

