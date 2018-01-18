#ifndef PK_GEOMETRY_POINTS_ON_SEGMENT_HPP
#define PK_GEOMETRY_POINTS_ON_SEGMENT_HPP


#include <algorithm>

#include "geometry/points_collinear.hpp"


namespace pk
{
namespace geometry
{


/**
 * True if a given point is on a given segment.
 *
 * If the point exactly equals one of the segment's ends,
 * it is on the segment (function returns true).
 */
template<class Point, class Segment>
bool point_on_segment(const Point& point, const Segment& segment)
{
    if(!points_collinear(point, segment.get_p1(), segment.get_p2()))
        return false;

    if(std::min(segment.get_p1().get_x(), segment.get_p2().get_x()) > point.get_x())
        return false;
    if(std::max(segment.get_p1().get_x(), segment.get_p2().get_x()) < point.get_x())
        return false;

    if(std::min(segment.get_p1().get_y(), segment.get_p2().get_y()) > point.get_y())
        return false;
    if(std::max(segment.get_p1().get_y(), segment.get_p2().get_y()) < point.get_y())
        return false;

    return true;
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_POINTS_ON_SEGMENT_HPP
