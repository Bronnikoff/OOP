#ifndef MASSIVE_H
#define MASSIVE_H
#include <memory>
#include "Iterator.h"
#include "MassiveItem.h"
#include <future>
#include <mutex>
#include <functional>

template<class T> class TrMassive {
public:

  TrMassive();
  TrMassive(unsigned int l);
  TrMassive(const TrMassive<T>& orig);

  bool Empty();
  template <class A> friend std::ostream& operator<<(std::ostream& os, const TrMassive<A>& mass);
  std::shared_ptr<T>& operator[](const int index);
  int Lenght();
  void Resize(int l);
  void sort();
  void thread_sort();

 Iterator<MassiveItem<T>, T> begin();
 Iterator<MassiveItem<T>, T> end();

  ~TrMassive();

private:
  void sort_parallel(int a, int b);
  std::future<void> sort_in_background(int a, int b);
  void qs(int a, int b);
  MassiveItem<T>* data;
  int len;
};


#include "Massive.cpp"

#endif
