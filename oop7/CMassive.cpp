#include "CMassive.h"
#include <memory>


template <class T, class TT> CMassive<T,TT>::CMassive() : CMassive(0){}

template <class T, class TT> CMassive<T,TT>::CMassive(unsigned int l) {

  len=l;
  if(len>0){
    data = new std::shared_ptr<T>[len];
  }
  for (short int i=0; i<len; i++){
    data[i] = nullptr;
  }
  std::cout << "massive 1st container created!" << std::endl;
}

template <class T, class TT> CMassive<T,TT>::CMassive(const CMassive<T,TT>& orig) {
  len=orig.len;
  data= new std::shared_ptr<T>[len];
  for(short int i=0; i<len; i++){
    data[i]=orig.data[i];
  }
  std::cout << "massive copied!" << '\n';
}

template <class T, class TT> bool CMassive<T,TT>::Empty(){
  return (len==0);
}

template <class T, class TT> std::shared_ptr<T>& CMassive<T,TT>::operator[](const int index){
  if(index >= 0 && index < len && data[index]){
    return data[index];
  } else{
    std::cout << "You havent rights for this!" << '\n';
  }
}

template <class T, class TT> int CMassive<T,TT>::Lenght(){
  return len;
}

template <class T, class TT> void CMassive<T,TT>::PushByIndex(int in1, std::shared_ptr<TT> ptr){
  int in2 = 0;
  if(data[in1]){
    in2 = data[in1]->Busy();
  }
  if(in1 >= 0 && in2 >= 0 && in1 < len && data[in1] && in2 < data[in1]->Lenght() && data[in1]->Busy() < VALUE_NEXT && in2 < VALUE_NEXT){
    data[in1]->Insert(in2, ptr);
    return ;
  } else if(in1 >= 0 && in2 >= 0 && in1 < len && in2 < VALUE_NEXT){
    data[in1] = std::make_shared<T>(VALUE_NEXT);
    data[in1]->Insert(in2, ptr);
    return;
  } else if(in1 >= 0 && in2 >= 0 && in2 < VALUE_NEXT){
    this->Resize(in1 + 1);
    data[in1] = std::make_shared<T>(VALUE_NEXT);
    data[in1]->Insert(in2, ptr);
    return;
  } else{
    std::cout << "Something wrong in inserting of elem by index!" << '\n';
    return;
  }
}

template <class T, class TT> CMassive<T,TT>::~CMassive(){
  if(len>0){
  delete[] data;
  len=0;
}
  std::cout << "Massive deleted!" << '\n';
}

template <class T, class TT> void CMassive<T, TT>::RemoveByIndex(int ii, int jj){
  if(ii < len && ii >=0 && jj >= 0 && data[ii] && jj < data[ii]->Lenght() && data[ii]->Value(jj)){
    data[ii]->Delete(jj);
    if(!data[ii]->Busy()){
      data[ii]->Resize(0);
      data[ii] = nullptr;
    }
  }else{
    std::cout << "Something wrong in deleting of element!" << '\n';
  }
  return;
}

template <class T, class TT> void CMassive<T, TT>::Push(std::shared_ptr<TT> Fig){
  int ptr = -1;
  for(int i = 0; i < len; i++){
    if(!data[i]){
      if(ptr < 0){
        ptr = i;
      }
      continue;
    }
    if(data[i]->Busy() < VALUE_NEXT){
      for(int j = 0; j < data[i]->Lenght(); j++){
        if(!data[i]->Value(j)){
          data[i]->Insert(j, Fig);
          break;
        }
      }
      return;
    }
  }
  if(ptr >= 0){
    data[ptr] = std::make_shared<T>(VALUE_NEXT);
    data[ptr]->Insert(0, Fig);
    return;
  }
    this->Resize(len + 1);
    data[len-1] = std::make_shared<T>(VALUE_NEXT);
    data[len-1]->Insert(0, Fig);
    return;
}

template <class T, class TT> void CMassive<T,TT>::Resize(int l){
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

template <class T, class TT> template <class E> void CMassive<T, TT>::RemoveByType(std::shared_ptr<E> Fig){
  for(int i = 0; i < len; i++){
    if(!data[i]){
      continue;
    }
    for(int j = 0; j < data[i]->Lenght(); j++){
      Fig = std::dynamic_pointer_cast<E>(data[i]->Value(j));
      if(Fig){
        data[i]->Delete(j);
      }
    }
    if(!data[i]->Busy()){
      data[i]->Resize(0);
      data[i] = nullptr;
    }
  }
}

template <class T, class TT> void CMassive<T, TT>::RemoveBySquare(double Fig){
  for(int i = 0; i < len; i++){
    if(!data[i]){
      continue;
    }
    for(int j = 0; j < data[i]->Lenght(); j++){
      if(data[i]->Value(j)){
      if(data[i]->Value(j)->Square() < Fig){
        data[i]->Delete(j);
      }
    }
  }
    if(!data[i]->Busy()){
      data[i]->Resize(0);
      data[i] = nullptr;
    }
  }
}

template <class A, class AA> std::ostream& operator<<(std::ostream& os, const CMassive<A, AA>& mass){
  std::cout << "Massive:" << '\n';
  std::cout << "Size:" << mass.len << '\n' << "Elements:" << std::endl;
  if(mass.len==0){
    std::cout << "Empty!" << '\n';
  }
  for(short int i=0; i<mass.len; i++){
    std::cout << "[" << i << "]" << ":";
    if(mass.data[i]!=nullptr){
    std::cout << *mass.data[i] << '\n';
    }else{
      std::cout << "empty" << '\n';
    }
  }
  return os;
}
