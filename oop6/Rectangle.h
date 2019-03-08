#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
#include "Allocator.h"


class Rectangle : public Figure{
public:
	Rectangle();
	Rectangle(std::istream &is);
	Rectangle(size_t i,size_t j);
	Rectangle(const Rectangle& orig);

	double Square() override;
	void   Print() override;
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
	friend std::istream& operator>>(std::istream& is, Rectangle& obj);
	void* operator new(size_t size);
	void operator delete(void *p);

	virtual ~Rectangle();
private:
	size_t side_a;
	size_t side_b;
	static TAllocationBlock allocator;
};

#endif
