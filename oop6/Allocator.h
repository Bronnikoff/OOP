#ifndef ALLOCATOR_H
#define	ALLOCATOR_H

#include "SMassive.h"
#include <cstdlib>
#include <stdint.h>

class TAllocationBlock {
public:
    TAllocationBlock(size_t size,size_t count);
    void *allocate(size_t size);
    void *allocate();
    void deallocate(void *pointer);
    void deallocate(void *pointer, size_t o);
    bool has_free_blocks();

    virtual ~TAllocationBlock();
private:
    size_t _size; 
    size_t _count;
    uint8_t** _used_blocks; // для того, чтобы избежать дорогостоящего копирования сделвем целый массив из блоков
    SMassive _free_blocks; // сделлаем ссылкой, чтобы потом объявить один раз при new, а не вызывать resize для пустого вектора
};

#define OPT_NUM 2

#endif
