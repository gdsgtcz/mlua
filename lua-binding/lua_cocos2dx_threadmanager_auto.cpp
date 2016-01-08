#include "lua_cocos2dx_threadmanager_auto.hpp"
#include "ThreadManager.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_threadmanager_ThreadManager_doFile(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_doFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        const char* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ThreadManager:doFile");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "ThreadManager:doFile"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_doFile'", nullptr);
            return 0;
        }
        bool ret = cobj->doFile(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:doFile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_doFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_clean(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_clean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_clean'", nullptr);
            return 0;
        }
        bool ret = cobj->clean();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:clean",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_clean'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_destroy(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_destroy'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_destroy'", nullptr);
            return 0;
        }
        bool ret = cobj->destroy();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:destroy",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_destroy'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_sendStr(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_sendStr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        std::string arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ThreadManager:sendStr");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ThreadManager:sendStr");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "ThreadManager:sendStr");
    
        //guodi
        //ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "ThreadManager:sendStr");
        arg3=toluafix_ref_function(tolua_S, 5, 0);
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_sendStr'", nullptr);
            return 0;
        }
        bool ret = cobj->sendStr(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:sendStr",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_sendStr'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_allCount(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_allCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_allCount'", nullptr);
            return 0;
        }
        int ret = cobj->allCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:allCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_allCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_getThreadByID(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_getThreadByID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ThreadManager:getThreadByID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_getThreadByID'", nullptr);
            return 0;
        }
        TaskThread* ret = cobj->getThreadByID(arg0);
        object_to_luaval<TaskThread>(tolua_S, "TaskThread",(TaskThread*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:getThreadByID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_getThreadByID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_len(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_len'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ThreadManager:len"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_len'", nullptr);
            return 0;
        }
        int ret = cobj->len(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:len",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_len'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_getNewThread(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_getNewThread'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_getNewThread'", nullptr);
            return 0;
        }
        TaskThread* ret = cobj->getNewThread();
        object_to_luaval<TaskThread>(tolua_S, "TaskThread",(TaskThread*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:getNewThread",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_getNewThread'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_startThread(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_startThread'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ThreadManager:startThread");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ThreadManager:startThread");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_startThread'", nullptr);
            return 0;
        }
        bool ret = cobj->startThread(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:startThread",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_startThread'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_close(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_close'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ThreadManager:close");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_close'", nullptr);
            return 0;
        }
        bool ret = cobj->close(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:close",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_close'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_doStr(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_doStr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        const char* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ThreadManager:doStr");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "ThreadManager:doStr"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_doStr'", nullptr);
            return 0;
        }
        bool ret = cobj->doStr(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:doStr",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_doStr'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_workCount(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ThreadManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_threadmanager_ThreadManager_workCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_workCount'", nullptr);
            return 0;
        }
        int ret = cobj->workCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:workCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_workCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ThreadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_getInstance'", nullptr);
            return 0;
        }
        ThreadManager* ret = ThreadManager::getInstance();
        object_to_luaval<ThreadManager>(tolua_S, "ThreadManager",(ThreadManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ThreadManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_threadmanager_ThreadManager_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ThreadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_threadmanager_ThreadManager_constructor'", nullptr);
            return 0;
        }
        cobj = new ThreadManager();
        tolua_pushusertype(tolua_S,(void*)cobj,"ThreadManager");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ThreadManager:ThreadManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_threadmanager_ThreadManager_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_threadmanager_ThreadManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ThreadManager)");
    return 0;
}

int lua_register_cocos2dx_threadmanager_ThreadManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ThreadManager");
    tolua_cclass(tolua_S,"ThreadManager","ThreadManager","",nullptr);

    tolua_beginmodule(tolua_S,"ThreadManager");
        tolua_function(tolua_S,"new",lua_cocos2dx_threadmanager_ThreadManager_constructor);
        tolua_function(tolua_S,"doFile",lua_cocos2dx_threadmanager_ThreadManager_doFile);
        tolua_function(tolua_S,"clean",lua_cocos2dx_threadmanager_ThreadManager_clean);
        tolua_function(tolua_S,"destroy",lua_cocos2dx_threadmanager_ThreadManager_destroy);
        tolua_function(tolua_S,"sendStr",lua_cocos2dx_threadmanager_ThreadManager_sendStr);
        tolua_function(tolua_S,"allCount",lua_cocos2dx_threadmanager_ThreadManager_allCount);
        tolua_function(tolua_S,"getThreadByID",lua_cocos2dx_threadmanager_ThreadManager_getThreadByID);
        tolua_function(tolua_S,"len",lua_cocos2dx_threadmanager_ThreadManager_len);
        tolua_function(tolua_S,"getNewThread",lua_cocos2dx_threadmanager_ThreadManager_getNewThread);
        tolua_function(tolua_S,"startThread",lua_cocos2dx_threadmanager_ThreadManager_startThread);
        tolua_function(tolua_S,"close",lua_cocos2dx_threadmanager_ThreadManager_close);
        tolua_function(tolua_S,"doStr",lua_cocos2dx_threadmanager_ThreadManager_doStr);
        tolua_function(tolua_S,"workCount",lua_cocos2dx_threadmanager_ThreadManager_workCount);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_threadmanager_ThreadManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ThreadManager).name();
    g_luaType[typeName] = "ThreadManager";
    g_typeCast["ThreadManager"] = "ThreadManager";
    return 1;
}
TOLUA_API int register_all_cocos2dx_threadmanager(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"mLua",0);
	tolua_beginmodule(tolua_S,"mLua");

	lua_register_cocos2dx_threadmanager_ThreadManager(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

