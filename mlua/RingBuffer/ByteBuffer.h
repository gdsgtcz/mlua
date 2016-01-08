//
//  ByteBuffer.h
//  hhl
//
//  Created by guodi on 15/7/7.
//
//

#ifndef __hhl__ByteBuffer__
#define __hhl__ByteBuffer__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"


using namespace std;
USING_NS_CC;
#include "RingBuffer.h"


//string ringBuffer class
class ByteBuffer
{
public:
    ByteBuffer(int size);
    ~ByteBuffer();
    
    //init
    void init(int size);
    
    //put
    bool put(std::string str);
    
    //get
    std::string get();
    
    //length
    int length();
    
    //size
    int size();
    
private:
    RingBuffer* buffer;

};



#endif /* defined(__hhl__ByteBuffer__) */
