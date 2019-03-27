#ifndef PK_GEOMETRY_DET_HPP
#define PK_GEOMETRY_DET_HPP


namespace pk
{
namespace geometry
{

/**
 * WARNING: Take possible overflow into account.
 */
template<class Point>
typename Point::value_type det(const Point& p1, const Point& p2, const Point& p3)
{
    return (p1.x * p2.y
            + p2.x * p3.y
            + p3.x * p1.y
            - p1.x * p3.y
            - p2.x * p1.y
            - p3.x * p2.y);
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_DET_HPP
