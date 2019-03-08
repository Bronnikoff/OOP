#include "CMassive.h"
#include "Triangle.h"
#include "Figure.h"
#include <memory>
#include <iostream>
#include <cstdlib>
#include "Rectangle.h"
#include "Quadrate.h"
//Лабораторная работа №7
//Бронников Максим Андреевич М8О-204Б-17
//Класс контейнер 1-го уровня: массив
//Класс контейнер 2-го уровня:массив
//Классы фигур: треугольник, прямоугольник, квадрат
// Целью лабораторной работы является:
//     • Создание сложных динамических структур данных.
//     • Закрепление принципа OCP.
/* Необходимо реализовать динамическую структуру данных – «Хранилище объектов»
и алгоритм работы с ней. «Хранилище объектов» представляет собой контейнер 1-го уровня:

•Массив

Каждым элементом контейнера, в свою, является динамической контейнером 2-го уровня:

•Массив

Объекты в контейнерах второго уровня должны быть отсортированы по возрастанию площади объекта (в том числе и для деревьев).
При этом должно выполняться правило, что количество объектов в контейнере второго уровня не больше 5.
Т.е. если нужно хранить больше 5 объектов, то создается еще один контейнер второго уровня.

При удалении объектов должно выполняться правило, что контейнер второго уровня не должен быть пустым. Т.е. если он становится пустым, то он должен удалится.

Нельзя использовать:
    • Стандартные контейнеры std.

Программа должна позволять:
    • Вводить произвольное количество фигур и добавлять их в контейнер.
    • Распечатывать содержимое контейнера (1-го и 2-го уровня).
    • Удалять фигуры из контейнера по критериям:
        ◦ По типу.
        ◦ По площади.
*/

int main(){
  short int i, j, k;
  CMassive<TrMassive<Figure>, Figure> mass1(10);
  CMassive<TrMassive<Figure>, Figure> mass2;
  CMassive<TrMassive<Figure>, Figure> mass3(mass1);
  std::shared_ptr<Figure> abc;
  while(1){
   std::cout << "______________________________________________________________" << '\n';
   std::cout << "Menu\n1-Print massive №1\n2-Print massive №2\n3-Print massive №3\n4-Enter figure in №1\n5-Enter figure in №2\n6-Print figure in №3\n7-Resize №1\n8-Resize №2\n9-Resize №3\n10-Remove Elements from massive\n11-Push elements in massive\n0-Exit\nEnter your choise:";
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
      std::cout << "\tEnter index of conteiner #1:";
      std::cin >> i;
      if(i<0){
        std::cout << "\tWrong index!" << '\n';
        break;
      }
        std::cout << "\t\tEnter:\n\t\t1-If want to add triangle\n\t\t2-If want to add quadrate\n\t\t3-If want to add rectangle" << '\n';
        std::cout << "\t\tYour choice:";
        std::cin >> j;
        if(j==1){
          std::cout << "\t\t\tEnter triangle:" << '\n' <<"\t\t\t";
          abc = std::make_shared<Triangle>(std::cin);
          mass1.PushByIndex(i, abc);
        }
        else if(j==2){
          std::cout << "\t\t\tEnter quadrate:" << '\n' << "\t\t\t";
          abc = std::make_shared<Quadrate>(std::cin);
          mass1.PushByIndex(i, abc);
        }
        else if(j==3){
          std::cout << "\t\t\tEnter rectangle:" << '\n' << "\t\t\t";
          abc=std::make_shared<Rectangle>(std::cin);
          mass1.PushByIndex(i, abc);
        } else{
            std::cout << "\t\t\tWrong choice!" << '\n';
         }
      break;
    case 5:
    std::cout << "\tEnter index of conteiner #1:";
    std::cin >> i;
    if(i<0){
      std::cout << "\tWrong index!" << '\n';
      break;
    }
      std::cout << "\t\tEnter:\n\t\t1-If want to add triangle\n\t\t2-If want to add quadrate\n\t\t3-If want to add rectangle" << '\n';
      std::cout << "\t\tYour choice:";
      std::cin >> j;
      if(j==1){
        std::cout << "\t\t\tEnter triangle:" << '\n' << "\t\t\t";
        abc = std::make_shared<Triangle>(std::cin);
        mass2.PushByIndex(i, abc);
      }
      else if(j==2){
        std::cout << "\t\t\tEnter quadrate:" << '\n' << "\t\t\t";
        abc = std::make_shared<Quadrate>(std::cin);
        mass2.PushByIndex(i, abc);
      }
      else if(j==3){
        std::cout << "\t\t\tEnter rectangle:" << '\n' << "\t\t\t";
        abc=std::make_shared<Rectangle>(std::cin);
        mass2.PushByIndex(i, abc);
      } else{
          std::cout << "\t\t\tWrong choice!" << '\n';
       }
    break;
    case 6:
    std::cout << "\tEnter index of conteiner #1:";
    std::cin >> i;
    if(i<0){
      std::cout << "\tWrong index!" << '\n';
      break;
    }
      std::cout << "\t\tEnter:\n\t\t1-If want to add triangle\n\t\t2-If want to add quadrate\n\t\t3-If want to add rectangle" << '\n';
      std::cout << "\t\tYour choice:";
      std::cin >> j;
      if(j==1){
        std::cout << "\t\t\tEnter triangle:  ";
        abc = std::make_shared<Triangle>(std::cin);
        mass3.PushByIndex(i, abc);
      }
      else if(j==2){
        std::cout << "\t\t\tEnter quadrate: ";
        abc = std::make_shared<Quadrate>(std::cin);
        mass3.PushByIndex(i, abc);
      }
      else if(j==3){
        std::cout << "\t\t\tEnter rectangle: ";
        abc=std::make_shared<Rectangle>(std::cin);
        mass3.PushByIndex(i, abc);
      } else{
          std::cout << "\t\t\tWrong choice!" << '\n';
       }
    break;
    case 7:
      std::cout << "\tEnter new size: ";
      std::cin >> i;
      mass1.Resize(i);
      std::cout << "\tNew lenght:" << mass1.Lenght() <<'\n';
      break;
    case 8:
      std::cout << "\tEnter new size: ";
      std::cin >> i;
      mass2.Resize(i);
      std::cout << "\tNew lenght:" << mass2.Lenght() <<'\n';
      break;
    case 9:
      std::cout << "\tEnter new size: ";
      std::cin >> i;
      mass3.Resize(i);
      std::cout << "\tNew lenght:" << mass3.Lenght() <<'\n';
      break;
    case 10:
      {
        std::cout << "\tEnter:\n\t1|If you want remove from Massive #1\n\t2|If you want remove from Massive #2" << '\n';
        std::cout << "\t3|If you want remove from Massive #3" << '\n' << "\t";
        std::cin >> i;
        if(i < 0 || i > 3){
          std::cout << "\twrong check" << '\n';
          break;
        }
        std::cout << "\t\tEnter:\n\t1|If you want remove by Value" << '\n';
        std::cout << "\t\t2|If you want remove by Type" << '\n';
        std::cout << "\t\t3|If you want remove by Index" << '\n' <<"\t\t";
        std::cin >> j;
        if(j == 1){
          double square;
          std::cout << "\t\t\tEnter value of square: ";
          std::cin >> square;
          if(i == 1){
            mass1.RemoveBySquare(square);
            break;
          }else if(i == 2){
            mass2.RemoveBySquare(square);
            break;
          }else if(i == 3){
            mass3.RemoveBySquare(square);
          }
        } else if(j == 2){
          std::cout << "\t\t\tEnter:" << '\n';
          std::cout << "\t\t\t1|If want remove triangles" << '\n';
          std::cout << "\t\t\t2|If want remove rectangles" << '\n';
          std::cout << "\t\t\t3|If want remove quadreates" << '\n' << "\t\t\t";
          std::cin >> k;
          if(k == 1){
            std::shared_ptr<Triangle> tr;
            if(i == 1){
              mass1.RemoveByType(tr);
            }
            else if(i == 2){
              mass2.RemoveByType(tr);
            }
            else if(i == 3){
              mass3.RemoveByType(tr);
            }
          }
          else if(k == 2){
            std::shared_ptr<Rectangle> tr;
            if(i == 1){
              mass1.RemoveByType(tr);
            }
            else if(i == 2){
              mass2.RemoveByType(tr);
            }
            else if(i == 3){
              mass3.RemoveByType(tr);
            }
          }
          else if(k == 3){
            std::shared_ptr<Quadrate> tr;
            if(i == 1){
              mass1.RemoveByType(tr);
            }
            else if(i == 2){
              mass2.RemoveByType(tr);
            }
            else if(i == 3){
              mass3.RemoveByType(tr);
            }
          }
          break;
        } else if(j == 3){
          std::cout << "\t\t\tEnter index of container #1" << '\n' << "\t\t\t";
          std::cin >> j;
          std::cout << "\t\t\tEnter index of container #2" << '\n' << "\t\t\t";
          std::cin >> k;
          if(i == 1){
            mass1.RemoveByIndex(j, k);
          }else if(i == 2){
            mass2.RemoveByIndex(j, k);
          }else if(i == 3){
            mass3.RemoveByIndex(j, k);
          }
          break;
        }
        break;
      }
    case 11:
      std::cout << "\tEnter:" << '\n';
      std::cout << "\t1|If you want push in massive #1" << '\n';
      std::cout << "\t2|If you want push in massive #2" << '\n';
      std::cout << "\t3|If you want push in massive #3" << '\n' << "\t";
      std::cin >> j;
      if(j == 1){
        std::cout << "\t\tEnter:" << '\n';
        std::cout << "\t\t1|If you want push triangle" << '\n';
        std::cout << "\t\t2|If you want push rectangle" << '\n';
        std::cout << "\t\t3|If you want push quadrate" << '\n' << "\t\t";
        std::cin >> k;
        if(k == 1){
          std::cout << "\t\t\tEnter triangle: ";
          abc = std::make_shared<Triangle>(std::cin);
          mass1.Push(abc);
        } else if(k == 2){
          std::cout << "\t\t\tEnter rectangle: ";
          abc = std::make_shared<Rectangle>(std::cin);
          mass1.Push(abc);
        } else if(k == 3){
          std::cout << "\t\t\tEnter quadrate: ";
          abc = std::make_shared<Quadrate>(std::cin);
          mass1.Push(abc);
        }
      }else if(j == 2){
        std::cout << "\t\tEnter:" << '\n';
        std::cout << "\t\t1|If you want push triangle" << '\n';
        std::cout << "\t\t2|If you want push rectangle" << '\n';
        std::cout << "\t\t3|If you want push quadrate" << '\n' << "\t\t";
        std::cin >> k;
        if(k == 1){
          std::cout << "\t\t\tEnter triangle: ";
          abc = std::make_shared<Triangle>(std::cin);
          mass2.Push(abc);
        } else if(k == 2){
          std::cout << "\t\t\tEnter rectangle: ";
          abc = std::make_shared<Rectangle>(std::cin);
          mass2.Push(abc);
        } else if(k == 3){
          std::cout << "\t\t\tEnter quadrate: ";
          abc = std::make_shared<Quadrate>(std::cin);
          mass2.Push(abc);
        }
      }else if(j == 3){
        std::cout << "\t\tEnter:" << '\n';
        std::cout << "\t\t1|If you want push triangle" << '\n';
        std::cout << "\t\t2|If you want push rectangle" << '\n';
        std::cout << "\t\t3|If you want push quadrate" << '\n' << "\t\t";
        std::cin >> k;
        if(k == 1){
          std::cout << "\t\t\tEnter triangle: ";
          abc = std::make_shared<Triangle>(std::cin);
          mass3.Push(abc);
        } else if(k == 2){
          std::cout << "\t\t\tEnter rectangle: ";
          abc = std::make_shared<Rectangle>(std::cin);
          mass3.Push(abc);
        } else if(k == 3){
          std::cout << "\t\t\tEnter quadrate: ";
          abc = std::make_shared<Quadrate>(std::cin);
          mass3.Push(abc);
        }
      }
      break;

    case 0:
      std::cout << "Made by Bronnikov Max(#1) M80-204" << '\n';
      std::cout << "______________________________________________________________" << std::endl;
      return 0;
      break;
}}}
