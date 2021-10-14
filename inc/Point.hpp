#ifndef POINT_HPP
#define POINT_HPP

namespace pt
{
	class Point
	{
		public:
			Point();
			Point(double x, double y);
			~Point();

			bool operator<(const Point& p) const;
			bool operator>(const Point& p) const;

			double x;
			double y;
	};

	bool compareX(const Point& p1, const Point& p2);
	bool compareY(const Point& p1, const Point& p2);
}

#endif
