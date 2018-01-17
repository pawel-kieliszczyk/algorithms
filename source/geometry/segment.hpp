#ifndef PK_GEOMETRY_SEGMENT_HPP
#define PK_GEOMETRY_SEGMENT_HPP


namespace pk
{
namespace geometry
{


template<class Point>
class segment
{
public:
    segment() {}
    segment(const Point& p1_, const Point& p2_) : p1(p1_), p2(p2_) {}

    void set_p1(const Point& p1_) { p1 = p1_; }
    void set_p2(const Point& p2_) { p2 = p2_; }

    const Point& get_p1() const { return p1; }
    const Point& get_p2() const { return p2; }

private:
    Point p1, p2;
};


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_SEGMENT_HPP
