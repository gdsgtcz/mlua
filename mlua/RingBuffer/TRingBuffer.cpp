////
////  RingBuffer.cpp
////  hhl
////
////  Created by guodi on 15/7/6.
////
////
//
//#include "RingBuffer.h"
//
//template <class T> RingBuffer<T>::RingBuffer()
//{
//    
//}
//
//template <class T> RingBuffer<T>::~RingBuffer()
//{
//    _buffer = NULL;
//}
//
//template <class T> void RingBuffer<T>::init(int size)
//{
//    _iput = 0;
//    _iget = 0;
//    _n = 0;
//    _max_size = size;
//    _buffer = new T[size]();
//}
//
////put
//template <class T> void RingBuffer<T>::put(T str)
//{
//    _buffer[_iput] = str;
//    _iput = (_iput + 1) % _max_size;
//    _n++;
//    printf("insert0.length:%d, %d\n",_iput, _n);
//}
//
////get
//template <class T> T RingBuffer<T>::get()
//{
//    printf("getValue1.length:%d, %d\n", _iget, _n);
//    if (_n > 0) {
//        int pos = _iget;
//        _iget = (_iget +1) % _max_size;
//        _n--;
//        T ret = _buffer[pos];
//        return ret;
//    } else {
//        return NULL;
//    }
//}
//
//
