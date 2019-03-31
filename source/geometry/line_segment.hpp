#ifndef PK_GEOMETRY_LINE_SEGMENT_HPP
#define PK_GEOMETRY_LINE_SEGMENT_HPP


namespace pk
{
namespace geometry
{


template<class Point>
struct line_segment
{
    typedef Point point_type;

    line_segment() {}
    line_segment(const Point& p1_, const Point& p2_) : p1(p1_), p2(p2_) {}

    Point p1, p2;
};


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_LINE_SEGMENT_HPP
