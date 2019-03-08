#include "Allocator.h"
#include <iostream>
#define PAGES 2

TAllocationBlock::TAllocationBlock(size_t size,size_t count): _size(size), _count(count) {
    _used_blocks = (uint8_t**)malloc(PAGES*sizeof(uint8_t*));
    *_used_blocks = (uint8_t*)malloc(_count*_size);
    _free_blocks.Resize(_count);

    for(size_t i=0;i<_count;i++) {
      _free_blocks[i] = *_used_blocks + i * _size;
    //  std::cout << _free_blocks[i] << '\n';
    }
      std::cout << "Allocator: Memory init" << std::endl;
}

void *TAllocationBlock::allocate() {
    void *result;
    if(_free_blocks.FreeAloc(0)){
      result = _free_blocks.GetBlock(0);
      std::cout << "Allocator: Block allocated" << '\n';
      return result;
    } else{
        int w = _free_blocks.Lenght();
        if((w / _count) % PAGES == 0){
          _used_blocks == (uint8_t**)realloc(_used_blocks, (w / _count) + PAGES);
          std::cout << "Allocator: List of Pages was incremented" << '\n';
        }
        _used_blocks[w / _count] = (uint8_t*)malloc(_count * _size);
        _free_blocks.Resize(w + _count);
        for(int i = 0; i < _count; i++){
          _free_blocks[w + i] = _used_blocks[w / _count] + i * _size;
        }
        result = _free_blocks.GetBlock(0);
        std::cout << "Allocator: Block allocated and memory buffer was incremented" << '\n';
        return result;
    }
}

void *TAllocationBlock::allocate(size_t s) {
    void *result;
    if(_free_blocks.FreeAloc(s/_size)){
      result = _free_blocks.GetBlock(s/_size);
      std::cout << "Allocator: Block allocated" << '\n';
      return result;
    } else{
      int w;
      while(!_free_blocks.FreeAloc(s/_size)){
        w = _free_blocks.Lenght();
        if((w / _count) % PAGES == 0){
          std::cout << "newsize: " << ((w / _count) + PAGES) * sizeof(uint8_t*) << '\n';
          _used_blocks == (uint8_t**)realloc(_used_blocks, ( (w / _count) + PAGES ) * sizeof(uint8_t*) );
          std::cout << "Allocator: List of Pages was incremented" << '\n';
        }
        _used_blocks[w / _count] = (uint8_t*)malloc(_count * _size);
        _free_blocks.Resize(w + _count);
        for(int i = 0; i < _count; i++){
          _free_blocks[w + i] = _used_blocks[w / _count] + i * _size;
        }
        w = _free_blocks.Lenght();
      }
        result = _free_blocks.GetBlock(s/_size);
        std::cout << "Allocator: Block allocated and memory buffer was incremented" << '\n';
        return result;
    }
}

void TAllocationBlock::deallocate(void *pointer) {
  _free_blocks.SetBlock(pointer, 1);
  std::cout << "Allocator: Block deallocated" << '\n';
  if(_free_blocks.Lenght() -  _free_blocks.Sword() > 2 * _count){
    free(_used_blocks[(_free_blocks.Lenght() / _count) - 1]);
    _free_blocks.Resize(_free_blocks.Lenght() - _count);
    std::cout << "Allocator: memory buffer was decremented" << '\n';
  }
  return;
}

void TAllocationBlock::deallocate(void *pointer, size_t o) {
  _free_blocks.SetBlock(pointer, o);
  std::cout << "Allocator: Block deallocated" << '\n';
  if(_free_blocks.Lenght() -  _free_blocks.Sword() > 2 * _count){
    free(_used_blocks[(_free_blocks.Lenght() / _count) - 1]);
    _free_blocks.Resize(_free_blocks.Lenght() - _count);
    std::cout << "Allocator: memory buffer was decremented" << '\n';
  }
  return;
}

bool TAllocationBlock::has_free_blocks() {
    return _free_blocks.FreeAloc(0);
}

TAllocationBlock::~TAllocationBlock() {
  for(int i = 0; i < _free_blocks.Lenght() / _count; i++){
    free(_used_blocks[i]);
  }
  free(_used_blocks);
}
