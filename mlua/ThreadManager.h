//
//  ThreadManager.h
//  hhl
//
//  Created by guodi on 15/6/7.
//
//

#ifndef __hhl__ThreadManager__
#define __hhl__ThreadManager__

#include "cocos2d.h"

#include "TaskThread.h"

USING_NS_CC;

class ThreadManager
{
public:
    ThreadManager(){};
    ~ThreadManager(){};
    
    //单例
    static ThreadManager* getInstance();
    
    //开线程,时间间隔单位为毫秒
    bool startThread(int count, int time);
    
    //打开一个新线程,返回TaskThread*
    TaskThread* getNewThread();
    
    //通过ID返回线程
    TaskThread* getThreadByID(int ID);
    
    //调用线程执行lua脚本,
    bool doFile(int _ID, const char* _filename);
    
    //调用线程执行lua语句,
    bool doStr(int _ID, const char* _str);
    
    //给线程推数据,fun为回调函数句柄
    bool sendStr(int _fID, int _tID, std::string _data, int fun);
    
    //    //给线程推数据
    //    bool sendStr(int _fID, int _tID, const char* _data);
    
    //返回工作线程数目
    int workCount();
    
    //返回总线程数目
    int allCount();
    
    //关闭一个线程
    bool close(int _ID);
    
    //关闭所有工作线程
    bool clean();
    
    //清空线程池并销毁
    bool destroy();
    
    int len(const char* a);
    //    //通过线程ID获取LuaStack
    //    LuaStack* getLuaStackByID(int ID);
    
private:
    typedef std::unordered_map<int, TaskThread*> umap;
    //线程池
    umap waitPool;
    umap workPool;
    
};

#endif /* defined(__hhl__ThreadManager__) */
