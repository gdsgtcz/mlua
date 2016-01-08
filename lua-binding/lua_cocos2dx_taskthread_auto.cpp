#include "lua_cocos2dx_taskthread_auto.hpp"
#include "TaskThread.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_taskthread_TaskThread_getTime(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_getTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_getTime'", nullptr);
            return 0;
        }
        int ret = cobj->getTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:getTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_getTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_create(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_create'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TaskThread:create");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "TaskThread:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_create'", nullptr);
            return 0;
        }
        bool ret = cobj->create(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:create",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_create'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_sendStr(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_sendStr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        std::string arg1;
        int arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TaskThread:sendStr");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "TaskThread:sendStr");

        //guodi
        //ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "TaskThread:sendStr");
        arg2=toluafix_ref_function(tolua_S, 4, 0);
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_sendStr'", nullptr);
            return 0;
        }
        cobj->sendStr(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:sendStr",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_sendStr'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_getID(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_getID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_getID'", nullptr);
            return 0;
        }
        int ret = cobj->getID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:getID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_getID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_destroy(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_destroy'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_destroy'", nullptr);
            return 0;
        }
        cobj->destroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:destroy",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_destroy'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_setTime(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_setTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TaskThread:setTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_setTime'", nullptr);
            return 0;
        }
        cobj->setTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:setTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_setTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_addSchedule(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_addSchedule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        //guodi
        //ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TaskThread:addSchedule");
        arg0=toluafix_ref_function(tolua_S, 2, 0);
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_addSchedule'", nullptr);
            return 0;
        }
        int ret = cobj->addSchedule(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:addSchedule",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_addSchedule'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_removeSchedule(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_removeSchedule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TaskThread:removeSchedule");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_removeSchedule'", nullptr);
            return 0;
        }
        bool ret = cobj->removeSchedule(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:removeSchedule",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_removeSchedule'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_addTaskByStr(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_addTaskByStr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "TaskThread:addTaskByStr"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_addTaskByStr'", nullptr);
            return 0;
        }
        cobj->addTaskByStr(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:addTaskByStr",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_addTaskByStr'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_addTaskByFile(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_addTaskByFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "TaskThread:addTaskByFile"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_addTaskByFile'", nullptr);
            return 0;
        }
        cobj->addTaskByFile(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:addTaskByFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_addTaskByFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_setData(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TaskThread",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TaskThread*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_taskthread_TaskThread_setData'", nullptr);
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

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TaskThread:setData");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "TaskThread:setData");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "TaskThread:setData");

        //guodi
        //ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "TaskThread:setData");
        arg3=toluafix_ref_function(tolua_S, 5, 0);
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_setData'", nullptr);
            return 0;
        }
        cobj->setData(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:setData",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_setData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_taskthread_TaskThread_constructor(lua_State* tolua_S)
{
    int argc = 0;
    TaskThread* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_taskthread_TaskThread_constructor'", nullptr);
            return 0;
        }
        cobj = new TaskThread();
        tolua_pushusertype(tolua_S,(void*)cobj,"TaskThread");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TaskThread:TaskThread",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_taskthread_TaskThread_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_taskthread_TaskThread_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TaskThread)");
    return 0;
}

int lua_register_cocos2dx_taskthread_TaskThread(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TaskThread");
    tolua_cclass(tolua_S,"TaskThread","TaskThread","",nullptr);

    tolua_beginmodule(tolua_S,"TaskThread");
        tolua_function(tolua_S,"new",lua_cocos2dx_taskthread_TaskThread_constructor);
        tolua_function(tolua_S,"getTime",lua_cocos2dx_taskthread_TaskThread_getTime);
        tolua_function(tolua_S,"create",lua_cocos2dx_taskthread_TaskThread_create);
        tolua_function(tolua_S,"sendStr",lua_cocos2dx_taskthread_TaskThread_sendStr);
        tolua_function(tolua_S,"getID",lua_cocos2dx_taskthread_TaskThread_getID);
        tolua_function(tolua_S,"destroy",lua_cocos2dx_taskthread_TaskThread_destroy);
        tolua_function(tolua_S,"setTime",lua_cocos2dx_taskthread_TaskThread_setTime);
        tolua_function(tolua_S,"addSchedule",lua_cocos2dx_taskthread_TaskThread_addSchedule);
        tolua_function(tolua_S,"removeSchedule",lua_cocos2dx_taskthread_TaskThread_removeSchedule);
        tolua_function(tolua_S,"addTaskByStr",lua_cocos2dx_taskthread_TaskThread_addTaskByStr);
        tolua_function(tolua_S,"addTaskByFile",lua_cocos2dx_taskthread_TaskThread_addTaskByFile);
        tolua_function(tolua_S,"setData",lua_cocos2dx_taskthread_TaskThread_setData);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TaskThread).name();
    g_luaType[typeName] = "TaskThread";
    g_typeCast["TaskThread"] = "TaskThread";
    return 1;
}
TOLUA_API int register_all_cocos2dx_taskthread(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"mLua",0);
	tolua_beginmodule(tolua_S,"mLua");

	lua_register_cocos2dx_taskthread_TaskThread(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

