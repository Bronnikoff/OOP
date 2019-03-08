#include <iostream>
#include <cstdlib>

template <class T> TrMassive<T>::TrMassive() : TrMassive(0){}

template <class T> TrMassive<T>::TrMassive(unsigned int l) {

  len=l;
  if(len>0){
    data = new MassiveItem<T>[len];
  }
  std::cout << "massive created!" << std::endl;
}

template <class T> TrMassive<T>::TrMassive(const TrMassive<T>& orig) {
  len=orig.len;
  data= new MassiveItem<T>[len];
  for(short int i=0; i<len; i++){
    data[i]=orig.data[i];
  }
  std::cout << "massive copied!" << '\n';
}

template <class T> bool TrMassive<T>::Empty(){
  return (len==0);
}

template <class T> std::shared_ptr<T>& TrMassive<T>::operator[](const int index){
  if(index<0){
    std::cout << "Wrong index! Returning element with index '0'!" << '\n';
    return data[0].GetValue();
  } else if (index >= len){
    this->Resize(index+1);
  }
  return data[index].GetValue();
}

template <class T> int TrMassive<T>::Lenght(){
  return len;
}

template <class T> TrMassive<T>::~TrMassive(){
  if(len>0){
  delete[] data;
  len=0;
}
  std::cout << "Massive deleted!" << '\n';
}

template <class T> Iterator<MassiveItem<T>, T> TrMassive<T>::begin(){
  return Iterator<MassiveItem<T>, T>(data, 0);
}

template <class T> Iterator<MassiveItem<T>, T> TrMassive<T>::end(){
  return Iterator<MassiveItem<T>, T>(data, len);
}

template <class T> void TrMassive<T>::Resize(int l){
  if(l<0){
    std::cout << "Wrong size!" << '\n';
    return;
  }
  MassiveItem<T>* data1;
  if(l==0){
  } else{
    data1 = new MassiveItem<T>[l];
  }
  if (l<len){
    for (short int i = 0; i < l; i++) {
      data1[i]=data[i];
    }} else{
      short int i;
      for(i=0; i < len; i++){
        data1[i]=data[i];
      }
      }
  if(len > 0){
    delete[] data;
  }
  len=l;
  data=data1;
  data1=nullptr;
  return;
}

template <class A> std::ostream& operator<<(std::ostream& os, const TrMassive<A>& mass){
  std::cout << "Massive:" << '\n';
  std::cout << "Size:" << mass.len << '\n' << "Elements:" << std::endl;
  if(mass.len==0){
    std::cout << "Empty!" << '\n';
  }
  for(short int i=0; i<mass.len; i++){
    std::cout << "[" << i << "]" << ":";
    if(mass.data[i].GetValue()!=nullptr){
      mass.data[i].GetValue()->Print();
    }else{
      std::cout << "empty" << '\n';
    }
    //std::cout << &mass.data[i] << '\n';
  }
  return os;
}


/* #include "Figure.h"
template class TrMassive<Figure>;
template std::ostream& operator<<(std::ostream& os, const TrMassive<Figure>& mass);
*/
