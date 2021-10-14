#include "Point.hpp"

namespace pt
{
	Point::Point() : x(0), y(0)
	{ }

	Point::~Point() = default;

	Point::Point(double x, double y) : x(x), y(y)
	{ }
	
	bool Point::operator<(const Point& p) const
	{
		return this->x < p.x && this->y < p.y;
	}
	
	bool Point::operator>(const Point& p) const
	{
		return this->x > p.x && this->y > p.y;
	}
	
	bool compareX(const Point& p1, const Point& p2) 
	{
		return p1.x < p2.x;
	}
	
	bool compareY(const Point& p1, const Point& p2) 
	{
		return p1.y < p2.y;
	}
}
