//
//  RingBuffer.h
//  hhl
//
//  Created by guodi on 15/7/28.
//
//

#ifndef __hhl__RingBuffer__
#define __hhl__RingBuffer__

#include <stdio.h>

//自定义类型
typedef signed char int8;
typedef signed short int16;
typedef signed long int32;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

class RingBuffer
{
    /*
     * definition ----------------------------------
     */
    /*
     * Method ----------------------------------
     */
    public :
    RingBuffer() {}
    RingBuffer(uint32 size);
    ~RingBuffer();
    int8 init(uint32 size);
    int8 write(uint32 size, uint8 * data);
    int8 read(uint8 *data);
    void clear();
    uint32 getWritePoint();
    uint32 getReadPoint();
    void dumpBuffer();
    //获取已写 未写空间
    uint32 getFreeSpace();
    uint32 getWritedSpace();
    uint32 getSize() {return this->m_size;};
    
    private :
    
    uint32 readBuffer(uint32 size, uint32 rp, uint8 *dat);
    uint32 writeBuffer(uint32 size, uint32 wp, uint8 * dat);
    int8 checkReadData();
    int8 checkWriteData(uint32 size);
    void setReadPoint(uint32 rp) {this->m_rp = rp;}
    void setWritePoint(uint32 wp) {this->m_wp = wp;}
    /*
     * Member ----------------------------------
     */
    private :
    //读写的坐标位置
    uint32 m_wp;
    uint32 m_rp;
    uint32 m_size;
    uint8 *m_buffer = nullptr;
};

#endif /* defined(__hhl__RingBuffer__) */
