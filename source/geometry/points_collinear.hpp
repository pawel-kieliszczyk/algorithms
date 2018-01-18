#ifndef PK_GEOMETRY_POINTS_COLLINEAR_HPP
#define PK_GEOMETRY_POINTS_COLLINEAR_HPP


#include "geometry/det.hpp"
#include "geometry/value_comparators.hpp"


namespace pk
{
namespace geometry
{


template<class Point>
double points_collinear(const Point& p1, const Point& p2, const Point& p3)
{
    typename value_comparators<typename Point::value_type>::comparator_type comp;
    return comp.equal(det(p1, p2, p3), typename Point::value_type(0));
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_POINTS_COLLINEAR_HPP
