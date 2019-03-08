#ifndef QUADRATE_H
#define QUADRATE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Quadrate : public Figure{
public:
	Quadrate();
	Quadrate(std::istream &is);
	Quadrate(size_t i);
	Quadrate(const Quadrate& orig);

	double Square() override;
	void   Print() override;

	virtual ~Quadrate();
private:
	size_t side_a;
};

#endif
