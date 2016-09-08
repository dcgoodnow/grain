#include <iostream>

#include "Vector.h"

int main(int, char**)
{
	grain::Vector<double> v(4);

	v.set(2, 3.4);

	std::cout << v.at(2);
	return 0;
}
