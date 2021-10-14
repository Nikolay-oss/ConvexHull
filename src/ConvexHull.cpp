#include "ConvexHull.hpp"

static bool upperSpaceHandler(const double value)
{
	return value < 0.0;
}

static bool bottomSpaceHandler(const double value)
{
	return value > 0.0;
}

ConvexHull::ConvexHull(const std::vector<pt::Point>& points) :
	sortedSetOfPointsX(points),
	sortedSetOfPointsY(points)
{
	sortPointsXY();
}

ConvexHull::~ConvexHull() = default;

std::vector<pt::Point>& ConvexHull::build()
{
	std::vector<pt::Point>* halfConvexHullUpper;
	std::vector<pt::Point>* halfConvexHullBottom;

	halfConvexHullUpper = searchConvexHullPoints(upperSpaceHandler, sortedSetOfPointsY.rbegin(), sortedSetOfPointsY.rend());
	halfConvexHullBottom = searchConvexHullPoints(bottomSpaceHandler, sortedSetOfPointsY.begin(), sortedSetOfPointsY.end());
	setOfPoints = *halfConvexHullUpper;
	std::copy(halfConvexHullBottom->rbegin() + 1, halfConvexHullBottom->rend(), std::back_inserter(setOfPoints));
	delete halfConvexHullUpper;
	delete halfConvexHullBottom;
	return setOfPoints;
}

void ConvexHull::sortPointsXY()
{
	std::sort(sortedSetOfPointsX.begin(), sortedSetOfPointsX.end(), pt::compareX);
	std::sort(sortedSetOfPointsY.begin(), sortedSetOfPointsY.end(), pt::compareY);
}

double ConvexHull::hyperPlane(double w1, double w2, double x, double y, double b)
{
	return w1 * x + w2 * y + b;
}

std::tuple<double, double> ConvexHull::normalVector(const pt::Point& p1, const pt::Point& p2) const
{
	return std::make_tuple(p2.y - p1.y, p1.x - p2.x);
}
