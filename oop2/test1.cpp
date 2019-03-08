#include <cstdlib>
#include <iostream>

int main() {
  while(1){
   std::cout << "Menu\n1-Print massive №1\n2-Print massive №2\n3-Print massive№3\n4-Enter triangle in №1\n5-Enter triangle in №2\n6-Print triangle in №3\n7-Resize №1\n8-Resize №2\n9-Resize №3\n0-Exit\nEnter your choise:";
   std::cin >> i;
   switch (i) {
    case 1:
      if(!mass1.Empty()){
        std::cout << mass1 << '\n';
      } else{
        std::cout << "massiv is empty!" << '\n';
      }
      break;
    case 2:
      if(!mass2.Empty()){
        std::cout << mass2 << '\n';
      }
      else{
        std::cout << "massiv is empty!" << '\n';
      }
      break;
    case 3:
      if(!mass3.Empty()){
        std::cout << mass3 << '\n';
      } else{
        std::cout << "massiv is empty!" << '\n';
      }
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
      break;
}}
}
