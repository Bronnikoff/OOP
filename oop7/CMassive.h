#ifndef CMASSIVE_H
#define CMASSIVE_H
#include "Massive.h"


template <class T, class TT> class CMassive {
public:
 //конструкторы:
  CMassive();
  CMassive(unsigned int l);
  CMassive(const CMassive<T, TT>& orig);

  bool Empty();
  template <class A, class AA> friend std::ostream& operator<<(std::ostream& os, const CMassive<A, AA>& mass);
  std::shared_ptr<T>& operator[](const int index); //взятие элемента по индексу
  int Lenght();
  void Resize(int l);
  void Push(std::shared_ptr<TT> Fig); //поместить элемент в структуру по умолчанию
  void PushByIndex(int in, std::shared_ptr<TT> Fig); //поместить по индексам массивов 1-го и 2-го уровня
  template <class E> void RemoveByType(std::shared_ptr<E> typeem); //удаление по типу
  void RemoveBySquare(double sq); //удаление по значению площади, меньше заданной
  void RemoveByIndex(int ii, int jj); //удаление по индексам
  ~CMassive();

private:
  std::shared_ptr<T>* data; //массив с массивами по 5 элементов
  int len; //длина массива
};

#include "CMassive.cpp"

#endif
