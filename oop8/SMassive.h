#ifndef SMASSIVE_H
#define SMASSIVE_H
#include <stdbool.h>
#include <cstdlib>

class SMassive{
public:

   SMassive();
   SMassive(size_t l);

  bool Empty();
  bool FreeAloc(size_t s);
  void* &operator[](const size_t index);
  size_t Lenght();
  void Resize(size_t l);
  void* GetBlock(size_t s);
  void SetBlock(void* pointer, size_t o);
  size_t Sword();

  ~SMassive();

private:
  void **data;
  size_t len;
  size_t sword;

};

#endif
