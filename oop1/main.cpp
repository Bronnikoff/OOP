#include <cstdlib>
#include <iostream>
#include "Triangle.h"
#include "Quadrate.h"
#include "Rectangle.h"
//Бронников Максим №1 по списку М80-204Б-17
//Лабораторгая работа №1
/*Необходимо спроектировать и запрограммировать на языке C++ классы фигур,
согласно вариантов задания.
Классы должны иметь виртуальные метод вывода и метод подсчета площадию
Фигуры: Треугольник, Квадрат, Прямоугольник
*/
int main(int argc, char** argv) {
  int i;
  Figure what;
  printf("Here!\n");
  Figure *tr = new Triangle();
  Figure *quadr =new Quadrate();
  Figure *rect = new Rectangle();
  while(1){
    std::cout << "Menu\n1-cr tr\n2-cr quadr\n3-cr rect\n4-print tr\n5-prnt quadr\n6-prnt rect\n7-prnt sq tr\n8-prnt sq quadr\n9-prnt sq rect\n0-exit\nEnter your choise:";
    std::cin >> i;
  if(i==1){
    delete tr;
    tr = new Triangle(std::cin);
  }else if(i==2){
    quadr =new Quadrate(std::cin);
  }else if(i==3){
    rect = new Rectangle(std::cin);
  }else if(i==4){
	  tr->Print();
  }else if(i==6){
    rect->Print();
  }else if(i==5){
    quadr->Print();
  }else if(i==7){
	  std::cout << tr->Square() << std::endl;
  }else if(i==8){
    std::cout << quadr->Square() << std::endl;
  }else if(i==9){
    std::cout << rect->Square() << std::endl;
  }else if(i==0){
	  delete tr;
    delete quadr;
    delete rect;
    std::cout << "Exit!" << '\n';
    return 0;
}
}
}
