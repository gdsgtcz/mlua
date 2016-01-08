//
//  StringBuffer.h
//  hhl
//
//  Created by guodi on 15/7/7.
//
//

#ifndef __hhl__StringBuffer__
#define __hhl__StringBuffer__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

using namespace std;
USING_NS_CC;
//#include "RingBuffer.h"

////Ring Buffer object
//typedef struct{
//    unsigned int length;//size of buffer
//    unsigned int head; //index to oldest data in buffer
//    unsigned int tail; //index to next write position
//    
//    //these counters are used to check if the buffer is full and empty
//    //if read_count - write count = 0, the buffer is empty
//    //if write_count - read_count = length, the buffer is full
//    int read_count; //number of reads performed
//    int write_count;//number of writes performed
//    
//    std::string* data; //data for buffer
//}RingBuffer;

//string ringBuffer class
class StringBuffer
{
public:
    StringBuffer(int size);
    ~StringBuffer();
    
    //create
    void create(unsigned int length);
    
    //distroy
    void distroy();
    
    //is full
    bool isFull();
    
    //is empty
    bool isEmpty();
    
    //put
    bool put(std::string str);
    
    //get
    std::string get();
    
    //length
    int length();
    
    //size
    int size();
    
private:
    unsigned int len;//size of buffer
    unsigned int head; //index to oldest data in buffer
    unsigned int tail; //index to next write position
    
    //these counters are used to check if the buffer is full and empty
    //if read_count - write count = 0, the buffer is empty
    //if write_count - read_count = length, the buffer is full
    int read_count; //number of reads performed
    int write_count;//number of writes performed
    int n;
    
    std::string* data; //data for buffer

    
};



#endif /* defined(__hhl__StringBuffer__) */
