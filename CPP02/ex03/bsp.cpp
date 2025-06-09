#include "Point.hpp"

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
	Fixed d1 = (point.getX() - a.getX()) * (b.getY() - a.getY())
			 - (point.getY() - a.getY()) * (b.getX() - a.getX());
	Fixed d2 = (point.getX() - b.getX()) * (c.getY() - b.getY())
			 - (point.getY() - b.getY()) * (c.getX() - b.getX());
	Fixed d3 = (point.getX() - c.getX()) * (a.getY() - c.getY())
			 - (point.getY() - c.getY()) * (a.getX() - c.getX());

	return ((d1 >= Fixed(0) && d2 >= Fixed(0) && d3 >= Fixed(0)) ||
			(d1 <= Fixed(0) && d2 <= Fixed(0) && d3 <= Fixed(0)));
}
