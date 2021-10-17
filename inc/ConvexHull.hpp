#ifndef CONVEXHULL_HPP
#define CONVEXHULL_HPP

#include <vector>
#include <algorithm>
#include "Point.hpp"
#include <tuple>

class ConvexHull
{
	public:
		class NotEnoughPointsException : public std::exception
		{
			public:
				const char* what() const noexcept override
				{
					return "Not enough points";
				}
		};

		template <class It>
		ConvexHull(It begin, It end);
		ConvexHull(const std::vector<pt::Point>& points);
		~ConvexHull();

		std::vector<pt::Point>& build();

	private:
		typedef std::vector<pt::Point>::iterator pointIt;

		std::vector<pt::Point> setOfPoints;
		std::vector<pt::Point> sortedSetOfPointsX;
		std::vector<pt::Point> sortedSetOfPointsY;

		void sortPointsXY();
		double hyperPlane(double w1, double w2, double x, double y, double b) const;
		std::tuple<double, double> normalVector(const pt::Point& p1, const pt::Point& p2) const;

		template <class It>
		std::vector<pt::Point>* searchConvexHullPoints(bool choiceSpace(const double), It begin, It end);
};

template <class It>
ConvexHull::ConvexHull(It begin, It end)
{
	std::copy(begin, end, std::back_inserter(sortedSetOfPointsX));
	if (sortedSetOfPointsX.size() < 2)
		throw NotEnoughPointsException();
	std::copy(begin, end, std::back_inserter(sortedSetOfPointsY));
	sortPointsXY();
}

template <class It>
std::vector<pt::Point>* ConvexHull::searchConvexHullPoints(bool choiceSpace(const double), It begin, It end)
{
	std::vector<pt::Point>* halfConvexHull = new std::vector<pt::Point>();
	pointIt halfConvexHullEnd;
	double b;
	double value;
	double w1;
	double w2;

	b = 0.0;
	*halfConvexHull = {sortedSetOfPointsX.front(), sortedSetOfPointsX.back()};
	halfConvexHullEnd = halfConvexHull->end();
	for (pointIt pIt = halfConvexHull->begin(); pIt != halfConvexHullEnd - 1; pIt++)
	{
		b = -pIt->x * (pIt + 1)->y + (pIt + 1)->x * pIt->y;
		std::tie(w1, w2) = normalVector(*pIt, *(pIt + 1));
		for (It it = begin; it != end; it++)
		{
			value = hyperPlane(w1, w2, it->x, it->y, b);
			if (choiceSpace(value))
			{
				halfConvexHull->insert(++pIt, *it);
				pIt = halfConvexHull->begin() - 1;
				halfConvexHullEnd = halfConvexHull->end();
				break ;
			}
		}
	}
	return halfConvexHull;
}

#endif
