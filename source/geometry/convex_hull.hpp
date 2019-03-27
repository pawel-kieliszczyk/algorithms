#ifndef PK_GEOMETRY_CONVEXHULL_HPP
#define PK_GEOMETRY_CONVEXHULL_HPP


#include <algorithm>

#include "geometry/det.hpp"


namespace pk
{
namespace geometry
{
namespace detail
{


struct sorting_op
{
    template<class point_type>
    bool operator()(const point_type& left, const point_type& right) const
    {
        if(left.x < right.x)
            return true;
        if(left.x > right.x)
            return false;

        return (left.y < right.y);
    }
};


} // namespace detail


/**
 * WARNING #1: This function is going to modify (sort) input sequence
 * WARNING #2: Reserve few extra slots for output ie. distance(first, last) + 5
 *
 * Output sequence will NOT contain any collinear points
 * First points of the output sequence is NOT repeated at the end.
 */
template<class InputIterator, class OutputIterator>
OutputIterator convex_hull(InputIterator first, InputIterator last, OutputIterator output)
{

    std::sort(first, last, detail::sorting_op());

    int output_size = 0;
    for(InputIterator it = first; it != last; ++it)
    {
        while((output_size >= 2) && (det(*(output-2), *(output-1), *it) >= 0))
        {
            --output;
            --output_size;
        }

        *output++ = *it;
        ++output_size;
    }

    std::reverse(first, last);

    output_size = 1;
    for(InputIterator it = first; it != last; ++it)
    {
        while((output_size >= 2) && (det(*(output-2), *(output-1), *it) >= 0))
        {
            --output;
            --output_size;
        }

        *output++ = *it;
        ++output_size;
    }

    return --output;
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_CONVEXHULL_HPP
