#ifndef PK_GEOMETRY_POINT_HPP
#define PK_GEOMETRY_POINT_HPP


namespace pk
{
namespace geometry
{


template<class T>
struct point
{
    typedef T value_type;

    point() {}
    point(const T& xx, const T& yy) : x(xx), y(yy) {}

    T x;
    T y;
};


template<class T>
bool operator==(const point<T>& left, const point<T>& right)
{
    return ((left.x == right.x) && (left.y == right.y));
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_POINT_HPP
