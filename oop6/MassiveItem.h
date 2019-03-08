#ifndef MASSIVEITEM_H
#define MASSIVEITEM_H

#include "Allocator.h"

template <class T> class MassiveItem {
public:
  MassiveItem();
  std::shared_ptr<T>& GetValue();
  void SetValue(std::shared_ptr<T>& n);
  MassiveItem<T>& operator=(const MassiveItem<T>& right);
  // void* operator new[](size_t size);
  // void operator delete[](void *p);

private:
  std::shared_ptr<T> item;
 //static TAllocationBlock allocator;
};

#include "MassiveItem.cpp"

#endif
