#ifndef MASSIVE_H
#define MASSIVE_H
#include "Figure.h"
#include "Triangle.h"
#include <memory>

class TrMassive {
public:

  TrMassive();
  TrMassive(unsigned int l);
  TrMassive(const TrMassive& orig);

  bool Empty();
  friend std::ostream& operator<<(std::ostream& os, const TrMassive& mass);
  std::shared_ptr<Figure>& operator[](const int index);
  int Lenght();
  void Resize(int l);
  ~TrMassive();

private:
  std::shared_ptr<Figure>* data;
  int len;
};

#endif
