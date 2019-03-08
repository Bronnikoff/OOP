#include "Massive.h"
#include "Triangle.h"
#include "Figure.h"
#include <memory>
#include <iostream>
#include <cstdlib>
#include "Rectangle.h"
#include "Quadrate.h"
#include "Allocator.h"
//Лабораторная работа №8
//Бронников Максим Андреевич М8О-204Б-17
//Класс контейнер 1-го уровня: массив
//Класс контейнер 2-го уровня: массив
//Классы фигур: треугольник, прямоугольник, квадрат
/* Используя структуры данных, разработанные для лабораторной работы №6 (контейнер первого уровня и классы-фигуры) необходимо разработать:
    • Контейнер второго уровня с использованием шаблонов.
    • Реализовать с помощью лямбда-выражений набор команд, совершающих операции над контенйром 1-го уровня:
        ◦ Генерация фигур со случайным значением параметров;
        ◦ Печать контейнера на экран;
        ◦ Удаление элементов со значением площади меньше определенного числа;
    • В контенер второго уровня поместить цепочку команд.
    • Реализовать цикл, который проходит по всем командам в контенере второго уровня и выполняет их, применяя к контейнеру первого уровня.


Для создания потоков использовать механизмы:
    • future
    • packaged_task/async

Для обеспечения потоко-безопасности структур данных использовать:
    • mutex

Нельзя использовать:
    • Стандартные контейнеры std.

*/

int main(){
  short int i, j;
  std::shared_ptr<Figure> abc = nullptr;
  TrMassive<Figure> mass1(10);
  TrMassive<Figure> mass2;
  TrMassive<Figure> mass3(mass1);
  while(1){
   std::cout << "______________________________________________________________" << '\n';
   std::cout << "Menu\n1-Print massive №1\n2-Print massive №2\n3-Print massive №3\n4-Enter figure in №1\n5-Enter figure in №2\n6-Enter figure in №3\n7-Resize №1\n8-Resize №2\n9-Resize №3\n10-Make Itterations\n11-Sort Massive\n0-Exit\nEnter your choise:";
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
    case 11:
      std::cout << "Enter:\n1|If you want sort by thread sort!\n2|If you want sort by base sort!" << '\n';
      std::cin >> j;
      if(j == 1){
        std::cout << "Enter\n1|For sort massive №1\n2|For sort massive №2\n3|For sort massive №3" << '\n';
        std::cin >> i;
        if(i == 1){
          std::cout << "Sorting massive ..." << '\n';
          mass1.thread_sort();
          std::cout << "Massive sorted" << '\n';
        } else if(i == 2){
          std::cout << "Sorting massive ..." << '\n';
          mass2.thread_sort();
          std::cout << "Massive sorted" << '\n';
        } else if(i == 3){
          std::cout << "Sorting massive ..." << '\n';
          mass3.thread_sort();
          std::cout << "Massive sorted" << '\n';
        }
      } else   if(j == 2){
          std::cout << "Enter\n1|For sort massive №1\n2|For sort massive №2\n3|For sort massive №3" << '\n';
          std::cin >> i;
          if(i == 1){
            std::cout << "Sorting massive ..." << '\n';
            mass1.sort();
            std::cout << "Massive sorted" << '\n';
          } else if(i == 2){
            std::cout << "Sorting massive ..." << '\n';
            mass2.sort();
            std::cout << "Massive sorted" << '\n';
          } else if(i == 3){
            std::cout << "Sorting massive ..." << '\n';
            mass3.sort();
            std::cout << "Massive sorted" << '\n';
          }
        }
      break;

    case 0:
      std::cout << "Made by Bronnikov Max(#1) M80-204" << '\n';
      std::cout << "______________________________________________________________" << std::endl;
      return 0;
      break;
}}}
