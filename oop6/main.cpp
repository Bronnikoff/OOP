#include "Massive.h"
#include "Triangle.h"
#include "Figure.h"
#include <memory>
#include <iostream>
#include <cstdlib>
#include "Rectangle.h"
#include "Quadrate.h"
#include "Allocator.h"
//Лабораторная работа №6
//Бронников Максим Андреевич М8О-204Б-17
//Класс контейнер 1-го уровня: массив
//Класс контейнер 2-го уровня: массив
//Классы фигур: треугольник, прямоугольник, квадрат
/* Используя структуры данных, разработанные для лабораторной работы ЛР№5 спроектировать и разработать аллокатор памяти для динамической структуры данных.

Цель построения аллокатора – минимизация вызова операции malloc. Аллокатор должен выделять большие блоки памяти для хранения фигур и при создании новых фигур-объектов выделять место под объекты в этой памяти.
Алокатор должен хранить списки использованных/свободных блоков. Для хранения списка свободных блоков нужно применять динамическую структуру данных (контейнер 2-го уровня).
Для вызова аллокатора должны быть переопределены оператор new и delete у классов-фигур.

Нельзя использовать:
    • Стандартные контейнеры std.

Программа должна позволять:
    • Вводить произвольное количество фигур и добавлять их в контейнер.
    • Распечатывать содержимое контейнера.
    • Удалять фигуры из контейнера.
*/

int main(){
  short int i, j;
  std::shared_ptr<Figure> abc = nullptr;
  TrMassive<Figure> mass1(10);
  TrMassive<Figure> mass2;
  TrMassive<Figure> mass3(mass1);
  while(1){
   std::cout << "______________________________________________________________" << '\n';
   std::cout << "Menu\n1-Print massive №1\n2-Print massive №2\n3-Print massive №3\n4-Enter figure in №1\n5-Enter figure in №2\n6-Enter figure in №3\n7-Resize №1\n8-Resize №2\n9-Resize №3\n10-Make Itterations\n0-Exit\nEnter your choise:";
   std::cin >> i;
   std::cout << "______________________________________________________________" << '\n';
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
      if(i<0){
        std::cout << "Wrong index!" << '\n';
        break;
      }
        std::cout << "Enter:\n1-If want to add triangle\n2-If want to add quadrate\n3-If want to add rectangle" << '\n';
        std::cout << "Your choice:";
        std::cin >> j;
        if(j==1){
          std::cout << "Enter triangle:" << '\n';
          abc.reset(new Triangle(std::cin));
          mass1[i] = abc;
        }
        else if(j==2){
          std::cout << "Enter quadrate:" << '\n';
          abc.reset(new Quadrate(std::cin));
          mass1[i] = abc;
        }
        else if(j==3){
          std::cout << "Enter rectangle:" << '\n';
          abc.reset(new Rectangle(std::cin));
          mass1[i] = abc;
        } else{
            std::cout << "Wrong choice!" << '\n';
         }
      break;
    case 5:
      std::cout << "Enter index:";
      std::cin >> i;
      if(i<0){
        std::cout << "Wrong index!" << '\n';
        break;
      }
        std::cout << "Enter:\n1-If want to add triangle\n2-If want to add quadrate\n3-If want to add rectangle" << '\n';
        std::cout << "Your choice:";
        std::cin >> j;
        if(j==1){
          std::cout << "Enter triangle:" << '\n';
          abc.reset(new Triangle(std::cin));
          mass2[i] = abc;
        }
        else if(j==2){
          std::cout << "Enter quadrate:" << '\n';
          abc.reset(new Quadrate(std::cin));
          mass2[i] = abc;
        }
        else if(j==3){
          std::cout << "Enter rectangle:" << '\n';
          abc.reset(new Rectangle(std::cin));
          mass2[i] = abc;
        } else{
            std::cout << "Wrong choice!" << '\n';
         }
      break;
    case 6:
      std::cout << "Enter index:";
      std::cin >> i;
      if(i<0){
        std::cout << "Wrong index!" << '\n';
        break;
      }
        std::cout << "Enter:\n1-If want to add triangle\n2-If want to add quadrate\n3-If want to add rectangle" << '\n';
        std::cout << "Your choice:";
        std::cin >> j;
        if(j==1){
          std::cout << "Enter triangle:" << '\n';
          abc.reset(new Triangle(std::cin));
          mass3[i] = abc;
        }
        else if(j==2){
          std::cout << "Enter quadrate:" << '\n';
          abc.reset(new Quadrate(std::cin));
          mass3[i] = abc;
        }
        else if(j==3){
          std::cout << "Enter rectangle:" << '\n';
          abc.reset(new Rectangle(std::cin));
          mass3[i] = abc;
        } else{
            std::cout << "Wrong choice!" << '\n';
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
    case 10:
    std::cout << "Enter:\n1-If want to itterate massive №1\n2-If want to itterate massive №2\n3-If want to itterate massive №3" << '\n';
    std::cout << "Your choice:";
    std::cin >> j;
    if(j==1){
      for(auto it : mass1) std::cout << *it << std::endl;
    }
    else if(j==2){
      for(auto it : mass2) std::cout << *it << std::endl;
    }
    else if(j==3){
      for(auto it : mass3) std::cout << *it << std::endl;

    } else{
        std::cout << "Wrong choice!" << '\n';
     }
      break;
    case 0:
      std::cout << "Made by Bronnikov Max(#1) M80-204" << '\n';
      std::cout << "______________________________________________________________" << std::endl;
      return 0;
      break;
}}}
