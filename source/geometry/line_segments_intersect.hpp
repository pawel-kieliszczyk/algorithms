#ifndef PK_GEOMETRY_LINE_SEGMENTS_INTERSECT_HPP
#define PK_GEOMETRY_LINE_SEGMENTS_INTERSECT_HPP


#include "geometry/det.hpp"
#include "geometry/point_on_line_segment.hpp"


namespace pk
{
namespace geometry
{


template<class LineSegment>
double line_segments_intersect(const LineSegment& ls1, const LineSegment& ls2)
{
    if(point_on_line_segment(ls1.get_p1(), ls2) || point_on_line_segment(ls1.get_p2(), ls2))
        return true;

    if(point_on_line_segment(ls2.get_p1(), ls1) || point_on_line_segment(ls2.get_p2(), ls1))
        return true;

    typedef typename LineSegment::point_type::value_type value_type;

    value_type d1 = det(ls1.get_p1(), ls1.get_p2(), ls2.get_p1());
    value_type d2 = det(ls1.get_p1(), ls1.get_p2(), ls2.get_p2());

    if((d1 < value_type(0)) && (d2 < value_type(0)))
        return false;
    if((d1 > value_type(0)) && (d2 > value_type(0)))
        return false;

    d1 = det(ls2.get_p1(), ls2.get_p2(), ls1.get_p1());
    d2 = det(ls2.get_p1(), ls2.get_p2(), ls1.get_p2());

    if((d1 < value_type(0)) && (d2 < value_type(0)))
        return false;
    if((d1 > value_type(0)) && (d2 > value_type(0)))
        return false;

    return true;
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_LINE_SEGMENTS_INTERSECT_HPP
