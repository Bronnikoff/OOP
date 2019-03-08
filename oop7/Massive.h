#ifndef MASSIVE_H
#define MASSIVE_H
#include <memory>
#include "Iterator.h"
#include <iostream>
#include <cstdlib>

template<class T> class TrMassive {
public:

  TrMassive();
  TrMassive(unsigned int l);
  TrMassive(const TrMassive<T>& orig);

  bool Empty();
  template <class A> friend std::ostream& operator<<(std::ostream& os, const TrMassive<A>& mass);
  int Lenght();
  void Resize(int l);
  void Insert(int index, std::shared_ptr<T> Fig);
  void Delete(int index);
  std::shared_ptr<T>& Value(int index);
  int Busy();

  Iterator<std::shared_ptr<T>, T> begin();
  Iterator<std::shared_ptr<T>, T> end();

  ~TrMassive();

private:
  void Sort();
  int busy;
  std::shared_ptr<T>& operator[](const int index);
  std::shared_ptr<T>* data;
  int len;
};

#define VALUE_NEXT 5

#include "Massive.cpp"

#endif
