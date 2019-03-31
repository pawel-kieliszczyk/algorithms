#ifndef PK_GEOMETRY_POINT_ON_LINE_SEGMENT_HPP
#define PK_GEOMETRY_POINT_ON_LINE_SEGMENT_HPP


#include <algorithm>

#include "geometry/points_collinear.hpp"


namespace pk
{
namespace geometry
{


/**
 * True if a given point is on a given line segment.
 *
 * If the point exactly equals one of the line segment's ends,
 * it is on the line segment (function returns true).
 */
template<class Point, class LineSegment>
bool point_on_line_segment(const Point& p, const LineSegment& ls)
{
    if(!points_collinear(p, ls.p1, ls.p2))
        return false;

    if(std::min(ls.p1.x, ls.p2.x) > p.x)
        return false;
    if(std::max(ls.p1.x, ls.p2.x) < p.x)
        return false;

    if(std::min(ls.p1.y, ls.p2.y) > p.y)
        return false;
    if(std::max(ls.p1.y, ls.p2.y) < p.y)
        return false;

    return true;
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_POINT_ON_LINE_SEGMENT_HPP
