//
//  StringBuffer.cpp
//  hhl
//
//  Created by guodi on 15/7/7.
//
//

#include "StringBuffer.h"
//锁
static std::mutex _Mutex;


//StringBuffer class
StringBuffer::StringBuffer(int size)
{
    create(size);
}

StringBuffer::~StringBuffer()
{
    distroy();
//    if(buffer)
//    {
//        delete buffer;
//        buffer = NULL;
//    }
}

//create
void StringBuffer::create(unsigned int length)
{
    len = length;
    head = tail = 0;
    read_count = write_count = 0;
    //分配内存
    data = new std::string[length]();
//    memset(data, 0, sizeof(data));
}

//distroy
void StringBuffer::distroy()
{
    if (data)
    {
        free(data);
        data = NULL;
    }
    len = head = tail = 0;
    read_count = write_count = 0;
}

//is full
bool StringBuffer::isFull()
{
    return (write_count - read_count) == (int)len;
}

//is empty
bool StringBuffer::isEmpty()
{
    return (read_count - write_count) == 0;
}

//put
bool StringBuffer::put(std::string str)
{
//    printf("StringBuffer::put %s\n", str.c_str());
    if (isFull())
    {
        printf("is FULL\n");
        return false;
    }
    data[tail] = str;
    tail = (tail +1) % len;
    write_count = (write_count + 1) % len;
    return true;
    //

}

//get
std::string StringBuffer::get()
{
    if (isEmpty())
    {
        printf("is EMPTY\n");
        return "";
    }
    std::string ret = data[head];
    head = (head +1) % len;
    read_count = (read_count + 1) % len;
    return ret;
}

//length
int StringBuffer::length()
{
    return (write_count - read_count)<0 ? (write_count - read_count + len) : (write_count - read_count);
}

//size
int StringBuffer::size()
{
    return len;
}