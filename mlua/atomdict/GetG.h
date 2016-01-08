//
//  GetG.h
//  hhl
//
//  Created by guodi on 15/8/3.
//
//

#ifndef __hhl__GetG__
#define __hhl__GetG__

#include <stdio.h>
#include "atomdict.h"
#define MAX_HANDLE (1024 * 16)

class GetG
{
public:
    GetG(){};
    ~GetG(){};
    //单例
    static GetG * getInstance();
    
    struct atomdict * get(int i);
    
public:
    struct atomdict * G[MAX_HANDLE] = {NULL};
    
private:
    //单例
    static GetG* instance;
    
};

#endif /* defined(__hhl__GetG__) */
