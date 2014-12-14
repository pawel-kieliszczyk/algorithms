#ifndef PK_INTERVALTREE_HPP
#define PK_INTERVALTREE_HPP


#include <algorithm>


namespace pk
{
namespace detail
{


template<int N>
struct counters_size
{
    static const int value = 2 * counters_size<N / 2>::value;
};


template<>
struct counters_size<0>
{
    static const int value = 2;
};


} // namespace detail


template<int RANGE>
class interval_tree
{
public:
    interval_tree()
    {
        std::fill(counters, counters + COUNTERS_SIZE, 0);
    }

    void insert(const int x)
    {
        int v = M + x;
        ++counters[v];

        while(v != 1)
        {
            v /= 2;
            counters[v] = counters[2*v] + counters[2*v+1];
        }
    }

    int count(const int a, const int b)
    {
        int va = M + a;
        int vb = M + b;

        int result = counters[va];

        if(va != vb)
            result += counters[vb];

        while((va / 2) != (vb / 2))
        {
            if(va % 2 == 0)
                result += counters[va+1];

            if (vb % 2 == 1)
                result += counters[vb-1];

            va /= 2;
            vb /= 2;
        }

        return result;
    }

private:
    static const int COUNTERS_SIZE = detail::counters_size<RANGE-1>::value;
    static const int M = COUNTERS_SIZE / 2;

    int counters[COUNTERS_SIZE];
};


} // namespace pk


#endif // PK_INTERVALTREE_HPP
