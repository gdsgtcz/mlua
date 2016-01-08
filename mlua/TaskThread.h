//
//  TaskThread.h
//  hhl
//
//  Created by guodi on 15/6/7.
//
//

#ifndef __hhl__TaskThread__
#define __hhl__TaskThread__

#include "cocos2d.h"
#include "TaskQueue.h"

USING_NS_CC;

//lua调用C++的类
class TaskThread
{
public:
    TaskThread(){};
    virtual ~TaskThread(){};
    
    //开线程
    bool create(int ID, int time);
    
    //addTaskByFile
    void addTaskByFile(const char* _task);
    
    //addTaskByStr
    void addTaskByStr(const char* _taskStr);
    
    //setData,fun为回调函数句柄
    void setData(int fID, int tID, std::string _data, int fun);
    
    //向其他线程推
    void sendStr(int tID, std::string _data, int fun);
    
    //添加函数句柄到句柄队列
    int addSchedule(int fun);
    
    //移除函数句柄
    bool removeSchedule(int funID);
    
    //销毁
    void destroy();
    
    //设置sleep时间
    void setTime(int time);
    //获取sleep时间
    int getTime();
    
    //获取ID
    int getID();
    
    //线程工作
    void beginThread();
    
private:
    
    void* workThread();
    
private:
    //任务队列
    SubThreadTask* selfTask;

    //quit
    bool need_quit = false;
    //自己的ID
    int myID = 0;
    //sleep 间隔
    int t_sleep = 0;
  
};

#endif /* defined(__hhl__TaskThread__) */
