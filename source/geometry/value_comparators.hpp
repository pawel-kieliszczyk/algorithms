#ifndef PK_GEOMETRY_VALUE_COMPARATORS_HPP
#define PK_GEOMETRY_VALUE_COMPARATORS_HPP


#include <cmath>


namespace pk
{
namespace geometry
{


template<class T>
class exact_value_comparator
{
public:
    bool equal(const T& v1, const T& v2)
    {
        return (v1 == v2);
    }
};


template<class T>
class epsilon_value_comparator
{
public:
    bool equal(const T& v1, const T& v2, const T& epsilon = 0.00001)
    {
        return (fabs(v1 - v2) < epsilon);
    }
};


template<class T>
class value_comparators {};


template<>
class value_comparators<int>
{
public:
    typedef exact_value_comparator<int> comparator_type;
};


template<>
class value_comparators<double>
{
public:
    typedef epsilon_value_comparator<double> comparator_type;
};


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_VALUE_COMPARATORS_HPP
