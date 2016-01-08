//
//  ByteBuffer.cpp
//  hhl
//
//  Created by guodi on 15/7/7.
//
//

#include "ByteBuffer.h"
//锁
static std::mutex _Mutex;


//ByteBuffer class
ByteBuffer::ByteBuffer(int size)
{
    init(size);
}

ByteBuffer::~ByteBuffer()
{
    if(buffer)
    {
        buffer->clear();
        delete buffer;
        buffer = nullptr;
    }
}

//init
void ByteBuffer::init(int size)
{
    buffer = new RingBuffer((uint32)size);
}

//put
bool ByteBuffer::put(std::string str)
{
    const char * tmp = str.c_str();
    int l = str.length() + 1;
    
    if (buffer->write((uint32)l, (uint8 *)tmp) == 0)
        return true;
    else
        return false;
}

//get
std::string ByteBuffer::get()
{
    std::string str;
    char * ret = (char *)str.c_str();
    buffer->read((uint8 *)ret);
    return ret;
}

//length
int ByteBuffer::length()
{
    return (int)(buffer->getWritedSpace());
}

//size
int ByteBuffer::size()
{
    return (int)(buffer->getSize());
}