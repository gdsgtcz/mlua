//
//  TaskQueue.h
//  hhl
//
//  Created by guodi on 15/8/6.
//
//

#ifndef __hhl__TaskQueue__
#define __hhl__TaskQueue__

#include "cocos2d.h"
#include "CCLuaStack.h"
USING_NS_CC;

class TaskQueue
{
public:
    TaskQueue(){};
    ~TaskQueue(){};
    
    //add task
    void addFile(const char* filename);
    void addStr(std::string str);
    void addData(int fID, int tID, std::string _data, int fun);
    void addHandle(int handle, const char* ret, size_t len);
    int  addSchedule(int fun);
    bool removeSchedule(int funid);
    
    void clear();
    void distroy();
    
    //执行
    bool doTask();
    
protected:
    //dataStruct
    struct DataStruct
    {
        int type;   //类型，1:执行文件，2:执行代码语句，3:推packed，4:回调handle
        std::string data;   //文件名｜｜代码语句｜｜packed
        int fID;    //推数据，fromID
        int tID;    //推数据，toID
        int callback;  //callback
        //HandleStruct handle; //fun handle
        int handle;
    };
    //scheduleStruct
    struct ScheduleStruct
    {
        int fun;
        int funid;
    };
    
    //funID
    int ScheduleFunID = 0;
    //mutex
    std::mutex data_mutex;
    std::mutex schedule_mutex;
    //queue
    std::vector<DataStruct> data_queue;
    std::vector<ScheduleStruct> schedule_queue;
    
    //luaStack luaState
    LuaStack* selfStack;
    lua_State* selfState;
    
};

//MainThreadTask
class MainThreadTask : public TaskQueue
{
public:
    MainThreadTask();
    ~MainThreadTask();
    
    //单例
    static MainThreadTask* getInstance();
    
private:
    static MainThreadTask* instance;
    
};

//SubThreadTask
class SubThreadTask : public TaskQueue
{
public:
    SubThreadTask(int _id);
    ~SubThreadTask();
    
private:
    //thread id
    int ID;
    
};


#endif /* defined(__hhl__TaskQueue__) */
