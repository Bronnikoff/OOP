#ifndef QUADRATE_H
#define QUADRATE_H
#include <cstdlib>
#include <iostream>
#include "Allocator.h"
#include "Figure.h"

class Quadrate : public Figure{
public:
	Quadrate();
	Quadrate(std::istream &is);
	Quadrate(size_t i);
	Quadrate(const Quadrate& orig);

	double Square() override;
	void   Print() override;
	friend std::ostream& operator<<(std::ostream& os, const Quadrate& obj);
	friend std::istream& operator>>(std::istream& is, Quadrate& obj);
	void* operator new(size_t size);
	void operator delete(void *p);

	virtual ~Quadrate();
private:
	size_t side_a;
	static TAllocationBlock allocator;

};

#endif
