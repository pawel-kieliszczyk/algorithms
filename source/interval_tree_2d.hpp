#ifndef PK_INTERVALTREE2D_HPP
#define PK_INTERVALTREE2D_HPP


#include "interval_tree.hpp"
#include "interval_tree_size.hpp"


namespace pk
{
namespace detail
{


struct range_type
{
    range_type() {}
    range_type(const int from_, const int to_) : from(from_), to(to_) {}

    int from;
    int to;
};


struct entry_type
{
    entry_type() {}
    entry_type(const int x1_, const int x2_) : x1(x1_), x2(x2_) {}

    int x1;
    int x2;
};


} // namespace detail


template<int RANGE_1, int RANGE_2>
class interval_tree_2d
{
public:
    typedef detail::entry_type entry_type;
    typedef detail::range_type range_type;

    void insert(const entry_type& e)
    {
        int v = M + e.x1;
        next_dim_tree[v].insert(e.x2);

        while(v != 1)
        {
            v /= 2;
            next_dim_tree[v].insert(e.x2);
        }
    }

    int count(const range_type& r1, const range_type& r2)
    {
        int va = M + r1.from;
        int vb = M + r1.to;

        int result = next_dim_tree[va].count(r2.from, r2.to);

        if(va != vb)
            result += next_dim_tree[vb].count(r2.from, r2.to);

        while((va / 2) != (vb / 2))
        {
            if(va % 2 == 0)
                result += next_dim_tree[va+1].count(r2.from, r2.to);

            if (vb % 2 == 1)
                result += next_dim_tree[vb-1].count(r2.from, r2.to);

            va /= 2;
            vb /= 2;
        }

        return result;
    }

private:
    static const int THIS_DIM_SIZE = meta::interval_tree_size<RANGE_1 - 1>::value;
    static const int M = THIS_DIM_SIZE / 2;

    pk::interval_tree<RANGE_2> next_dim_tree[THIS_DIM_SIZE];
};


} // namespace pk


#endif // PK_INTERVALTREE2D_HPP
