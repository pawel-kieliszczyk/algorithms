#ifndef PK_INTERVALTREEDIM_HPP
#define PK_INTERVALTREEDIM_HPP


#include <algorithm>

#include "interval_tree_size.hpp"


namespace pk
{
namespace detail
{


template<int RANGE_1, int RANGE_2, int RANGE_3> struct interval_tree_dim_counter                      { static const int value = 3; };
template<int RANGE_1, int RANGE_2>              struct interval_tree_dim_counter<RANGE_1, RANGE_2, 0> { static const int value = 2; };
//template<int RANGE_1>                           struct interval_tree_dim_counter<RANGE_1, 0, 0>       { static const int value = 1; }


template<int DIM>
struct entry_type
{
    int x[DIM];
};


struct subrange_type
{
    subrange_type() {}
    subrange_type(const int from_, const int to_) : from(from_), to(to_) {}

    int from;
    int to;
};


template<int DIM>
struct range_type
{
    subrange_type subrange[DIM];
};


template<class INSERT_VALUE_TYPE, int RANGE_1, int RANGE_2, int RANGE_3>
class interval_tree_dim
{
public:
    typedef detail::subrange_type subrange_type;
    typedef INSERT_VALUE_TYPE value_type;

    interval_tree_dim() : next_dim_trees(new interval_tree_dim<value_type, RANGE_2, RANGE_3, 0>[THIS_DIM_SIZE]) {}
    ~interval_tree_dim() { delete[] next_dim_trees; }

    void insert(const int* x, const value_type& value)
    {
        int v = M + x[0];
        next_dim_trees[v].insert(x + 1, value);

        while(v != 1)
        {
            v /= 2;
            next_dim_trees[v].insert(x + 1, value);
        }
    }

    int count(const subrange_type* subrange)
    {
        int va = M + subrange->from;
        int vb = M + subrange->to;

        int result = next_dim_trees[va].count(subrange + 1);

        if(va != vb)
            result += next_dim_trees[vb].count(subrange + 1);

        while((va / 2) != (vb / 2))
        {
            if(va % 2 == 0)
                result += next_dim_trees[va+1].count(subrange + 1);

            if (vb % 2 == 1)
                result += next_dim_trees[vb-1].count(subrange + 1);

            va /= 2;
            vb /= 2;
        }

        return result;
    }

private:
    static const int THIS_DIM_SIZE = meta::interval_tree_size<RANGE_1 - 1>::value;
    static const int M = THIS_DIM_SIZE / 2;

    interval_tree_dim(const interval_tree_dim&);
    interval_tree_dim& operator=(const interval_tree_dim&);

    interval_tree_dim<int, RANGE_2, RANGE_3, 0>* next_dim_trees;
};


template<class INSERT_VALUE_TYPE, int RANGE_1>
class interval_tree_dim<INSERT_VALUE_TYPE, RANGE_1, 0, 0>
{
public:
    typedef INSERT_VALUE_TYPE value_type;

    interval_tree_dim() : values(new value_type[VALUES_SIZE])
    {
        std::fill(values, values + VALUES_SIZE, value_type());
    }

    ~interval_tree_dim()
    {
        delete[] values;
    }

    void insert(const int* x, const value_type& value)
    {
        int v = M + x[0];
        values[v] += value;

        while(v != 1)
        {
            v /= 2;
            values[v] = values[2*v] + values[2*v+1];
        }
    }

    int count(const subrange_type* subrange)
    {
        int va = M + subrange->from;
        int vb = M + subrange->to;

        int result = values[va];

        if(va != vb)
            result += values[vb];

        while((va / 2) != (vb / 2))
        {
            if(va % 2 == 0)
                result += values[va+1];

            if (vb % 2 == 1)
                result += values[vb-1];

            va /= 2;
            vb /= 2;
        }

        return result;
    }

private:
    static const int VALUES_SIZE = meta::interval_tree_size<RANGE_1 - 1>::value;
    static const int M = VALUES_SIZE / 2;

    interval_tree_dim(const interval_tree_dim&);
    interval_tree_dim& operator=(const interval_tree_dim&);

    value_type* values;
};


} // namespace detail


template<class INSERT_VALUE_TYPE, int RANGE_1, int RANGE_2, int RANGE_3 = 0>
class interval_tree_dim
{
private:
    typedef detail::interval_tree_dim<INSERT_VALUE_TYPE, RANGE_1, RANGE_2, RANGE_3> interval_tree_impl_type;

public:
    typedef detail::entry_type<detail::interval_tree_dim_counter<RANGE_1, RANGE_2, RANGE_3>::value> entry_type;
    typedef detail::range_type<detail::interval_tree_dim_counter<RANGE_1, RANGE_2, RANGE_3>::value> range_type;
    typedef typename interval_tree_impl_type::subrange_type subrange_type;
    typedef typename interval_tree_impl_type::value_type value_type;

    void insert(const entry_type& e, const value_type& value)
    {
        interval_tree_impl.insert(e.x, value);
    }

    int count(const range_type& range)
    {
        return interval_tree_impl.count(range.subrange);
    }

private:
    interval_tree_impl_type interval_tree_impl;
};


inline detail::entry_type<2> build_interval_tree_entry(const int e0, const int e1)
{
    detail::entry_type<2> entry;
    entry.x[0] = e0;
    entry.x[1] = e1;

    return entry;
}


inline detail::entry_type<3> build_interval_tree_entry(const int e0, const int e1, const int e2)
{
    detail::entry_type<3> entry;
    entry.x[0] = e0;
    entry.x[1] = e1;
    entry.x[2] = e2;

    return entry;
}


inline detail::range_type<2> build_interval_tree_range(
        const detail::subrange_type& s0,
        const detail::subrange_type& s1)
{
    detail::range_type<2> range;
    range.subrange[0] = s0;
    range.subrange[1] = s1;

    return range;
}


inline detail::range_type<3> build_interval_tree_range(
        const detail::subrange_type& s0,
        const detail::subrange_type& s1,
        const detail::subrange_type& s2)
{
    detail::range_type<3> range;
    range.subrange[0] = s0;
    range.subrange[1] = s1;
    range.subrange[2] = s2;

    return range;
}


} // namespace pk


#endif // PK_INTERVALTREEDIM_HPP
