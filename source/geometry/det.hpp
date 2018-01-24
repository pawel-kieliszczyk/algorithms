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
    return (p1.get_x() * p2.get_y()
            + p2.get_x() * p3.get_y()
            + p3.get_x() * p1.get_y()
            - p1.get_x() * p3.get_y()
            - p2.get_x() * p1.get_y()
            - p3.get_x() * p2.get_y());
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_DET_HPP
