#include "Massive.h"
#include <memory>

template <class T> TrMassive<T>::TrMassive() : TrMassive(0){}

template <class T> TrMassive<T>::TrMassive(unsigned int l) {

  len=l;
  if(len>0){
    data = new std::shared_ptr<T>[len];
  }
  for (short int i=0; i<len; i++){
    data[i]=nullptr;
  }
  std::cout << "massive 2nd container created!" << std::endl;
}

template <class T> TrMassive<T>::TrMassive(const TrMassive<T>& orig) {
  len=orig.len;
  data= new std::shared_ptr<T>[len];
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
    return data[0];
  } else if (index >= len){
    this->Resize(index+VALUE_NEXT);
  }
  return data[index];
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

template <class T> Iterator<std::shared_ptr<T>, T> TrMassive<T>::begin(){
  return Iterator<std::shared_ptr<T>, T>(data, 0);
}

template <class T> Iterator<std::shared_ptr<T>, T> TrMassive<T>::end(){
  return Iterator<std::shared_ptr<T>, T>(data, len);
}

template <class T> void TrMassive<T>::Resize(int l){
  if(l<0){
    std::cout << "Wrong size!" << '\n';
    return;
  }
  std::shared_ptr<T>* data1;
  if(l==0){
  } else{
    data1 = new std::shared_ptr<T>[l];
  }
  if (l<len){
    for (short int i = 0; i < l; i++) {
      data1[i]=data[i];
    }} else{
      short int i=0;
      for(i=0; i < len; i++){
        data1[i]=data[i];
      }
      while(i<l){
        data1[i]=nullptr;
        ++i;
      }}
  if(len > 0){
    delete[] data;
  }
  len=l;
  data=data1;
  data1=nullptr;
  return;
}

template <class T> void TrMassive<T>::Insert(int index, std::shared_ptr<T> Fig){
  if(index < len && index >= 0){
    data[index] = Fig;
    ++busy;
  } else{
    std::cout << "Error of insert!" << '\n';
  }
  this->Sort();
  return;
}

template <class T> void TrMassive<T>::Delete(int index){
  if(index >= 0 && index < len){
    data[index] = nullptr;
    --busy;
  }else{
    std::cout << "Error of delete!" << '\n';
  }
}
template <class T> std::shared_ptr<T>& TrMassive<T>::Value(int index){
  if(index >= 0 && index < len){
    return data[index];
  } else {
    std::cout << "Error of get value!" << '\n';
  }
}

template <class T> int TrMassive<T>::Busy(){
  return busy;
}

template <class T> void TrMassive<T>::Sort(){
    int j = 0;
    std::shared_ptr<T> tmp;
    for(int i=0; i<len; i++){
      j = i;
      for(int k = i; k < len; k++){
        if(!data[k]){
          continue;
        }else if((data[k] && !data[j] ) || data[j]->Square() > data[k]->Square()){
          j = k;
        }
      }
      tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
    }
}

template <class A> std::ostream& operator<<(std::ostream& os, const TrMassive<A>& mass){
  std::cout << "\tMassive:" << '\n';
  std::cout << "\tSize:" << mass.len << '\n' << "\tElements:" << std::endl;
  if(mass.len==0){
    std::cout << "\tEmpty!" << '\n';
  }
  for(short int i=0; i<mass.len; i++){
    std::cout << "\t[" << i << "]" << ":";
    if(mass.data[i]!=nullptr){
      mass.data[i]->Print();
    }else{
      std::cout << "empty" << '\n';
    }
  }
  return os;
}


/* #include "Figure.h"
template class TrMassive<Figure>;
template std::ostream& operator<<(std::ostream& os, const TrMassive<Figure>& mass);
*/
