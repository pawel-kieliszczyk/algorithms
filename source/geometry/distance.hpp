#ifndef PK_GEOMETRY_DISTANCE_HPP
#define PK_GEOMETRY_DISTANCE_HPP


#include <cmath>


namespace pk
{
namespace geometry
{


/**
 * Calculates distance between 2 points.
 * WARNING: Take possible overflow into account because of "dx*dx + dy*dy"
 */
template<class Point>
double distance(const Point& p1, const Point& p2)
{
    const typename Point::value_type dx = p1.x - p2.x;
    const typename Point::value_type dy = p1.y - p2.y;

    return sqrt(static_cast<double>(dx*dx + dy*dy));
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_DISTANCE_HPP
