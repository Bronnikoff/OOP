#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() : Rectangle(0, 0) {
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {
	std::cout << "Rectangle created: " << side_a << ", " << side_b << std::endl;
}

Rectangle::Rectangle(std::istream &is) {
  int a, b;
	is >> a;
	is >> b;
  if(a>0&&b>0){
    side_a=a;
    side_b=b;
  }
  else{
    std::cout << "Rectangle not created!" << '\n';
  }
}

Rectangle::Rectangle(const Rectangle& orig) {
	std::cout << "Rectangle copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
}

double Rectangle::Square() {
	return (double)(side_a*side_b);
}

void Rectangle::Print() {
	std::cout << "a=" << side_a << ", b=" << side_b << std::endl;

}

Rectangle::~Rectangle() {
	std::cout << "Rectangle deleted" << std::endl;
}
