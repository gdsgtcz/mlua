//
//  RingBuffer.h
//  hhl
//
//  Created by guodi on 15/7/6.
//
//

#ifndef __hhl__RingBuffer__
#define __hhl__RingBuffer__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

using namespace std;
USING_NS_CC;


//模版类，ringbuffer模版
template <class T>
class RingBuffer
{
public:
    RingBuffer(){};
    ~RingBuffer(){_buffer = NULL;};
    
    void init(int size)
    {
        _iput = 0;
        _iget = 0;
        _n = 0;
        _max_size = size;
        _buffer = new T[size]();
    }
    
    //put
    void put(T str)
    {
        _buffer[_iput] = str;
        _iput = (_iput + 1) % _max_size;
        _n++;
        printf("insert0.length:%d, %d\n",_iput, _n);
    }
    
    //get
    T get()
    {
        printf("getValue1.length:%d, %d\n", _iget, _n);
        if (_n > 0) {
            int pos = _iget;
            _iget = (_iget +1) % _max_size;
            _n--;
            T ret = _buffer[pos];
            return ret;
        } else {
            return NULL;
        }
    }
    
    //length
    int length()
    {
        return _n;
    }
    
    //size
    int size()
    {
        return _max_size;
    }

private:
    
     int _iput;
     int _iget;
     int _n;
     int _max_size;
     T* _buffer;

};


#endif /* defined(__hhl__RingBuffer__) */
