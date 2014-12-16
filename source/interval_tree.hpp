#ifndef PK_INTERVALTREE_HPP
#define PK_INTERVALTREE_HPP


#include <algorithm>

#include "interval_tree_size.hpp"


namespace pk
{


template<class INSERT_VALUE_TYPE, int RANGE>
class interval_tree
{
public:
    typedef INSERT_VALUE_TYPE value_type;

    interval_tree() : values(new value_type[VALUES_SIZE])
    {
        std::fill(values, values + VALUES_SIZE, value_type());
    }

    ~interval_tree()
    {
        delete[] values;
    }

    void insert(const int x, const value_type& value)
    {
        int v = M + x;
        values[v] += value;

        while(v != 1)
        {
            v /= 2;
            values[v] = values[2*v] + values[2*v+1];
        }
    }

    int count(const int a, const int b)
    {
        int va = M + a;
        int vb = M + b;

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
    static const int VALUES_SIZE = meta::interval_tree_size<RANGE-1>::value;
    static const int M = VALUES_SIZE / 2;

    interval_tree(const interval_tree&);
    interval_tree& operator=(const interval_tree&);

    value_type* values;
};


} // namespace pk


#endif // PK_INTERVALTREE_HPP
