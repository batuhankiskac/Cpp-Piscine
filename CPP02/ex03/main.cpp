#include "Point.hpp"
#include <iostream>

static void test(const Point& a,
				 const Point& b,
				 const Point& c,
				 const Point& p)
{
	std::cout << (bsp(a,b,c,p) ? "Inside\n" : "Outside\n");
}

int main() {
	Point a(0,0), b(10,0), c(0,10);

	test(a,b,c, Point(5,5));
	test(a,b,c, Point(10,0));
	test(a,b,c, Point(-1,5));
	return 0;
}
