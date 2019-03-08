#include "Massive.h"
#include "Triangle.h"
#include "Figure.h"
#include <iostream>
//Бронников Максим Андреевич М8О-204Б-17
//Класс контейнер: массив
//Класс фигуры: треугольник
/* Необходимо спроектировать и запрограммировать на языке C++ класс-контейнер первого уровня, содержащий одну фигуру ( колонка фигура 1), согласно вариантов задания (реализованную в ЛР1).
Классы должны удовлетворять следующим правилам:
    • Требования к классу фигуры аналогичны требованиям из лабораторной работы 1.
    • Классы фигур должны иметь переопределенный оператор вывода в поток std::ostream (<<). Оператор должен распечатывать параметры фигуры (тип фигуры, длины сторон, радиус и т.д).
    • Классы фигур должны иметь переопределенный оператор ввода фигуры из потока std::istream (>>). Оператор должен вводить основные параметры фигуры (длины сторон, радиус и т.д).
    • Классы фигур должны иметь операторы копирования (=).
    • Классы фигур должны иметь операторы сравнения с такими же фигурами (==).
    • Класс-контейнер должен соджержать объекты фигур “по значению” (не по ссылке).
    • Класс-контейнер должен иметь метод по добавлению фигуры в контейнер.
    • Класс-контейнер должен иметь методы по получению фигуры из контейнера (опеределяется структурой контейнера).
    • Класс-контейнер должен иметь метод по удалению фигуры из контейнера (опеределяется структурой контейнера).
    • Класс-контейнер должен иметь перегруженный оператор по выводу контейнера в поток std::ostream (<<).
    • Класс-контейнер должен иметь деструктор, удаляющий все элементы контейнера.
    • Классы должны быть расположенны в раздельных файлах: отдельно заголовки (.h), отдельно описание методов (.cpp).

Нельзя использовать:
    • Стандартные контейнеры std.
    • Шаблоны (template).
    • Различные варианты умных указателей (shared_ptr, weak_ptr).

Программа должна позволять:
    • Вводить произвольное количество фигур и добавлять их в контейнер.
    • Распечатывать содержимое контейнера.
    • Удалять фигуры из контейнера.*/
int main(){
  int i;
  TrMassive mass1(10);
  TrMassive mass2;
  TrMassive mass3(mass1);
  Triangle b(1, 1, 1);
  while(1){
   std::cout << "----------------------------------------------------------------------" << '\n';
   std::cout << "Menu\n1-Print massive №1\n2-Print massive №2\n3-Print massive №3\n4-Enter triangle in №1\n5-Enter triangle in №2\n6-Print triangle in №3\n7-Resize №1\n8-Resize №2\n9-Resize №3\n0-Exit\nEnter your choise:";
   std::cin >> i;
   switch (i) {
    case 1:
      std::cout << mass1 << '\n';
      break;
    case 2:
      std::cout << mass2 << '\n';
      break;
    case 3:
      std::cout << mass3 << '\n';
      break;
    case 4:
      std::cout << "Enter index:";
      std::cin >> i;
      if(0 < i < mass1.Lenght()){
        std::cout << "Enter triangle:" << '\n';
        std::cin >> mass1[i];
      } else {
        std::cout << "Wrong index!" << '\n';
      }
      break;
    case 5:
      std::cout << "Enter index:";
      std::cin >> i;
      if(0 < i < mass2.Lenght()){
        std::cout << "Enter triangle:" << '\n';
        std::cin >> mass2[i];
      } else {
        std::cout << "Wrong index!" << '\n';
      }
      break;
    case 6:
      std::cout << "Enter index:";
      std::cin >> i;
      if(0 < i < mass3.Lenght()){
        std::cout << "Enter triangle:" << '\n';
        std::cin >> mass3[i];
      } else {
        std::cout << "Wrong index!" << '\n';
      }
        break;
    case 7:
      std::cout << "Enter new size:";
      std::cin >> i;
      mass1.Resize(i);
      std::cout << "New lenght:" << mass1.Lenght() <<'\n';
      break;
    case 8:
      std::cout << "Enter new size:";
      std::cin >> i;
      mass2.Resize(i);
      std::cout << "New lenght:" << mass2.Lenght() <<'\n';
      break;
    case 9:
      std::cout << "Enter new size:";
      std::cin >> i;
      mass3.Resize(i);
      std::cout << "New lenght:" << mass3.Lenght() <<'\n';
      break;
    case 0:
      std::cout << "Exit! Made by Bronnikov(№1 M8O-204)" << '\n';
      return 0;
      break;
}}}
