#ifndef MASSIVE_H
#define MASSIVE_H
#include "Figure.h"
#include "Triangle.h"

class TrMassive {
public:

  TrMassive();
  TrMassive(unsigned int l);
  TrMassive(const TrMassive& orig);

  bool Empty();
  void Destroy(int i);
  friend std::ostream& operator<<(std::ostream& os, const TrMassive& mass);
  Triangle& operator[](const int index);
  int Lenght();
  void Resize(int l);
  ~TrMassive();

private:
  Triangle* data;
  int len;
};

#endif
