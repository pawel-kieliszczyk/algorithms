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
    if(!points_collinear(p, ls.get_p1(), ls.get_p2()))
        return false;

    if(std::min(ls.get_p1().get_x(), ls.get_p2().get_x()) > p.get_x())
        return false;
    if(std::max(ls.get_p1().get_x(), ls.get_p2().get_x()) < p.get_x())
        return false;

    if(std::min(ls.get_p1().get_y(), ls.get_p2().get_y()) > p.get_y())
        return false;
    if(std::max(ls.get_p1().get_y(), ls.get_p2().get_y()) < p.get_y())
        return false;

    return true;
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_POINT_ON_LINE_SEGMENT_HPP
