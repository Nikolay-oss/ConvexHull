#include "ConvexHull.hpp"
#include <iostream>
#include <fstream>
#include <string>

// x = np.array([1, 2, 5, 3, 1])
// y = np.array([1, -3, 1, 4, 1])

// set_x = np.array([3, 3, 2, 2, 2.5, 4])
// set_y = np.array([2, 3, -1, 0, 1, 0])

static void writeFile(const std::string& filename, const std::vector<pt::Point>& points)
{
	std::ofstream f_out(filename);

	for (const pt::Point& p : points)
		f_out << p.x << " ";
	f_out << std::endl;
	for (const pt::Point& p : points)
		f_out << p.y << " ";
}

int main()
{
	std::vector<pt::Point> points = {pt::Point(1, 1), pt::Point(2, -3), pt::Point(5, 1),
									 pt::Point(3, 4), pt::Point(1, 1), pt::Point(3, 2),
									 pt::Point(3, 3), pt::Point(2, -1), pt::Point(2, 0),
									 pt::Point(2.5, 1), pt::Point(4, 0), pt::Point(4.5, 3),
									 pt::Point(1.5, -2), pt::Point(3.5, -2), pt::Point(1.5, 3),
									 pt::Point(1.5, -3)};

	ConvexHull convexHull(points);

	writeFile("convex_set", points);
	writeFile("convex_hull", convexHull.build());
	return 0;
}
