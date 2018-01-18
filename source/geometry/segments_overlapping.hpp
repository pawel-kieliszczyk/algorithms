#ifndef PK_GEOMETRY_SEGMENTS_OVERLAPPING_HPP
#define PK_GEOMETRY_SEGMENTS_OVERLAPPING_HPP


#include "geometry/det.hpp"
#include "geometry/point_on_segment.hpp"


namespace pk
{
namespace geometry
{


template<class Segment>
double segments_overlapping(const Segment& s1, const Segment& s2)
{
    if(point_on_segment(s1.get_p1(), s2) || point_on_segment(s1.get_p2(), s2))
        return true;

    if(point_on_segment(s2.get_p1(), s1) || point_on_segment(s2.get_p2(), s1))
        return true;

    typedef typename Segment::point_type::value_type value_type;

    value_type d1 = det(s1.get_p1(), s1.get_p2(), s2.get_p1());
    value_type d2 = det(s1.get_p1(), s1.get_p2(), s2.get_p2());

    if((d1 < value_type(0)) && (d2 < value_type(0)))
        return false;
    if((d1 > value_type(0)) && (d2 > value_type(0)))
        return false;

    d1 = det(s2.get_p1(), s2.get_p2(), s1.get_p1());
    d2 = det(s2.get_p1(), s2.get_p2(), s1.get_p2());

    if((d1 < value_type(0)) && (d2 < value_type(0)))
        return false;
    if((d1 > value_type(0)) && (d2 > value_type(0)))
        return false;

    return true;
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_SEGMENTS_OVERLAPPING_HPP
