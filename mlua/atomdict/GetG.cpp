//
//  GetG.cpp
//  hhl
//
//  Created by guodi on 15/8/3.
//
//

#include "GetG.h"

//单例
GetG* GetG::instance = NULL;
GetG* GetG::getInstance()
{
    if (instance == NULL) {
        instance = new GetG();
    }
    return instance;
}

//get
struct atomdict * GetG::get(int i)
{
    struct atomdict* ret = G[i];
    return ret;
}