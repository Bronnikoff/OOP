#include "Quadrate.h"
#include <iostream>
#include <cmath>

Quadrate::Quadrate() : Quadrate(1) {
}

Quadrate::Quadrate(size_t i) : side_a(i){
	std::cout << "Quadrate created: " << side_a << std::endl;
}

Quadrate::Quadrate(std::istream &is) {
  int a;
  is >> a;
  if(a>0){
	side_a=a;
}
else{
  std::cout << "Quadrate not created!" << '\n';
}
}

Quadrate::Quadrate(const Quadrate& orig) {
	std::cout << "Quadrate copy created" << std::endl;
	side_a = orig.side_a;
}

double Quadrate::Square() {
	return (double)(side_a*side_a);
}

void Quadrate::Print() {
	std::cout << "a=" << side_a << std::endl;

}

Quadrate::~Quadrate() {
	std::cout << "Quadrate deleted" << std::endl;
}
