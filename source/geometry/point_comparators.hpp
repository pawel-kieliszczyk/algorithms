#ifndef PK_GEOMETRY_POINT_COMPARATORS_HPP
#define PK_GEOMETRY_POINT_COMPARATORS_HPP


#include <cmath>


namespace pk
{
namespace geometry
{


template<class Point>
class exact_point_comparator
{
public:
    bool is_same_point(const Point& p1, const Point& p2)
    {
        return ((p1.x == p2.x) && (p1.y == p2.y));
    }
};


template<class Point>
class epsilon_point_comparator
{
public:
    bool is_same_point(const Point& p1, const Point& p2, const typename Point::value_type& epsilon = 0.00001)
    {
        if(fabs(p1.x - p2.x) > epsilon)
            return false;
        if(fabs(p1.y - p2.y) > epsilon)
            return false;

        return true;
    }
};


template<class Point>
class point_comparators {};


template<>
class point_comparators< point<int> >
{
public:
    typedef exact_point_comparator< point<int> > comparator_type;
};


template<>
class point_comparators< point<double> >
{
public:
    typedef epsilon_point_comparator< point<double> > comparator_type;
};


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_POINT_COMPARATORS_HPP
