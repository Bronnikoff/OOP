#include "Triangle.h"
#include <iostream>
#include <cmath>

int max(int a, int b);
int min(int a, int b);

int max(int a, int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
int min(int a, int b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}

Triangle::Triangle() : Triangle(1, 1, 1) {
}

Triangle::Triangle(size_t i, size_t j, size_t k) : side_a(i), side_b(j), side_c(k) {
	std::cout << "Triangle created: " << side_a << ", " << side_b << ", " << side_c << std::endl;
}

Triangle::Triangle(std::istream &is) {
	int a, b, c;
	is >> a;
	is >> b;
	is >> c;
	if(max(a, max(b, c)) >= min(b, c)+min(a, max(b, c))){
		std::cout << "Wrong sides! Triangle not created!" << '\n';
	}
	else if(a>0&&b>0&&c>0){
		side_a=a;
		side_b=b;
		side_c=c;
	}
	else{
		std::cout << "Wrong sizes! Triangle not created!" << '\n';
	}
}

Triangle::Triangle(const Triangle& orig) {
	std::cout << "Triangle copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
}

double Triangle::Square() {
	double p = double(side_a + side_b + side_c) / 2.0;
	return sqrt(p * (p - double(side_a))*(p - double(side_b))*(p - double(side_c)));

}

void Triangle::Print() {
	std::cout << "a=" << side_a << ", b=" << side_b << ", c=" << side_c << std::endl;

}

Triangle::~Triangle() {
	std::cout << "Triangle deleted" << std::endl;
}
