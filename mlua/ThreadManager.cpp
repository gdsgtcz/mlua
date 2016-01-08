//
//  ThreadManager.cpp
//  hhl
//
//  Created by guodi on 15/6/7.
//
//
#include <unistd.h>
#include "CCLuaEngine.h"

#include "ThreadManager.h"

#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
//自定义方法类
#include "LuaStringArray.h"
#include "LuaStringDict.h"

//guodi add
#include "lua_cmsgpack.h"
//LuaStack
#include "LuaStackArray.h"
//
#include "TaskQueue.h"


//ID
static int WAIT_ID = 1;
//number
//static int all_number = 0;
//static int work_number = 0;

//mutex
static std::mutex work_mutex;
static std::mutex wait_mutex;

//
static ThreadManager* _instance = NULL;
//单例
ThreadManager* ThreadManager::getInstance()
{
    if(_instance == NULL)
    {
        _instance = new ThreadManager();
    }
    return _instance;
}

//创建线程
bool ThreadManager::startThread(int count, int time)
{
    int i = 0;
    for(i = 1; i <= count; i++)
    {
        WAIT_ID++;  //从2开始
        
        TaskThread* thread = new TaskThread();
        if(thread->create(WAIT_ID, time))
        {
            wait_mutex.lock();
            waitPool.insert(umap::value_type(WAIT_ID, thread));
            wait_mutex.unlock();
        }
        else
        {
            printf("错误: startThread id = %d\n", i);
            return false;
        }
        //all_number++;
    }
    
    return true;
}

//打开一个新线程,返回TaskThread*
TaskThread* ThreadManager::getNewThread()
{
    //判断线程池内线程数目
    if (waitPool.size() <= 0)
    {
        printf("err: 线程池已空，请创建新线程\n");
        return NULL;
    }
    
    //从waitpool取出一个线程
    wait_mutex.lock();
    umap::const_iterator it = waitPool.begin();
    //线程工作
    it->second->beginThread();
    waitPool.erase(it->first);
    wait_mutex.unlock();
    
    //加入工作线程
    work_mutex.lock();
    workPool.insert(umap::value_type(it->first, it->second));
    work_mutex.unlock();
    
    
    
    //work_number++;
    return it->second;
}

//通过ID返回线程
TaskThread* ThreadManager::getThreadByID(int ID)
{
    //判断是否有此ID
    if(workPool.count(ID) == 0)
    {
        printf("err: ThreadManager::getThreadByID() not found\n");
        return NULL;
    }
    work_mutex.lock();
    umap::const_iterator it = workPool.find(ID);
    TaskThread* thread = it->second;
    work_mutex.unlock();
    return thread;
}

//doFile
bool ThreadManager::doFile(int _ID, const char* _filename)
{
    //判断是否有此ID
    if(workPool.count(_ID) == 0)
    {
        printf("err: ThreadManager::doFile() not found\n");
        return false;
    }
    work_mutex.lock();
    umap::const_iterator it = workPool.find(_ID);
    TaskThread* thread = it->second;
    //推送数据
    thread->addTaskByFile(_filename);
    work_mutex.unlock();
    return true;
}

//doStr
bool ThreadManager::doStr(int _ID, const char* _str)
{
    //判断是否有此ID
    if(workPool.count(_ID) == 0)
    {
        printf("err: ThreadManager::doStr() not found\n");
        return false;
    }
    work_mutex.lock();
    umap::const_iterator it = workPool.find(_ID);
    TaskThread* thread = it->second;
    //推送数据
    thread->addTaskByStr(_str);
    work_mutex.unlock();
    return true;
}

int ThreadManager::len(const char* a)
{
    if(*a == '\0')
    {
        return 0;
    }
    else
    {
        return len(++a) + 1;
    }
}

//发送数据
bool ThreadManager::sendStr(int _fID, int _tID, std::string _data, int fun)
{
    printf("%lu\n", _data.length());
    //判断是否推向主线程
    if (_tID == 1) {
        MainThreadTask::getInstance()->addData(_fID, _tID, _data, fun);
        return true;
    }
    else
    {
        work_mutex.lock();
        //判断是否有此ID
        if(workPool.count(_tID) == 0)
        {
            printf("err: ThreadManager::sendStr() not found\n");
            return false;
        }
        
        umap::const_iterator it = workPool.find(_tID);
        TaskThread* thread = it->second;
        //推送数据
        thread->setData(_fID, _tID, _data, fun);
        work_mutex.unlock();
        return true;
    }
}


//返回工作线程数目
int ThreadManager::workCount()
{
    work_mutex.lock();
    int ret = workPool.size();
    work_mutex.unlock();
    return ret;
}

//返回总线程数目
int ThreadManager::allCount()
{
    wait_mutex.lock();
    int ret =waitPool.size();
    wait_mutex.unlock();
    return ret;
}

//关闭一个线程
bool ThreadManager::close(int _ID)
{
    //判断是否有此ID
    if(workPool.count(_ID) == 0)
    {
        printf("err: ThreadManager::close() not found\n");
        return false;
    }
    work_mutex.lock();
    umap::const_iterator it = workPool.find(_ID);
    TaskThread* thread = it->second;
    thread->destroy();
    workPool.erase(_ID);
    work_mutex.unlock();
    //all_number--;
    //work_number--;
    return true;
}

//关闭所有工作线程
bool ThreadManager::clean()
{
    work_mutex.lock();
    workPool.clear();
    work_mutex.unlock();
    //all_number = all_number - work_number;
    //work_number = 0;
    return true;
}

//清空线程池并销毁
bool ThreadManager::destroy()
{
    //清空,销毁
    clean();
    wait_mutex.lock();
    waitPool.clear();
    wait_mutex.unlock();
    //all_number=0;
    delete _instance;
    _instance = NULL;
    return true;
}

////通过线程ID获取LuaStack
//LuaStack* ThreadManager::getLuaStackByID(int ID)
//{
//    //判断是否有此ID
//    if(workPool.count(ID) == 0)
//    {
//        printf("err: ThreadManager::getLuaStackByID() not found\n");
//        return NULL;
//    }
//    work_mutex.lock();
//    umap::const_iterator it = workPool.find(ID);
//    TaskThread* thread = it->second;
//    return thread->getLuaStack();
//    work_mutex.unlock();
//}

