#include "SMassive.h"
#include <iostream>
#include <cstdlib>

 SMassive :: SMassive() :  SMassive(0){}

 SMassive :: SMassive(size_t l){
  sword = 0;
  len=l;
  if(len>0){
    data = (void**)malloc(sizeof(void*)*len);
  }
  std::cout << "Massive of free blocks created!" << std::endl;
}

bool  SMassive::Empty(){
  return (len==0);
}

void* &SMassive::operator[](const size_t index){
  return data[index];
}

void* SMassive::GetBlock(size_t s){
  size_t res = sword;
  if(res + s < len){
    sword = res + s + 1;
    return data[res];
  } else{
    std::cout << "Full Allocator!" << '\n';
    return nullptr;
  }
}

void SMassive::SetBlock(void* pointer, size_t o){
  sword - o;
  data[sword] = pointer;
  return;
}

size_t SMassive::Sword(){
  return sword;
}

size_t SMassive::Lenght(){
  return len;
}

bool SMassive::FreeAloc(size_t s){
  return (sword + s < len);
}

 SMassive::~ SMassive(){
  if(len>0){
  free(data);
  len=0;
}
  std::cout << "Massive of free blocks deleted!" << '\n';
}

  void  SMassive ::Resize(size_t l){
  if(l<0){
    std::cout << "Wrong size!" << '\n';
    return;
  }
  void** data1;
  if(l==0){
  } else{
    data1 = (void**)malloc(l*sizeof(void*));
  }
  if (l<len){
    for ( size_t i = 0; i < l; i++) {
      data1[i]=data[i];
    }} else{
       size_t i;
      for(i=0; i < len; i++){
        data1[i]=data[i];
      }}
  if(len > 0){
    free(data);
  }
  len=l;
  data=data1;
  data1=nullptr;
  return;
}
