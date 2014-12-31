#ifndef PK_BINARYINDEXEDTREE_HPP
#define PK_BINARYINDEXEDTREE_HPP


#include <algorithm>


namespace pk
{


template<class ValueType, int Range>
class binary_indexed_tree
{
public:
    typedef ValueType value_type;

    binary_indexed_tree()
    {
        std::fill(data, data + Range, value_type());
    }

    void increase(const int index, const value_type& value)
    {
        for(int i = index; i < Range; i |= i + 1)
            data[i] += value;
    }

    void set(const int index, const value_type& value)
    {
        const value_type old_value = count_in_range(index, index);
        increase(index, value - old_value);
    }

    int count_less_equal(int index) const
    {
        value_type sum = value_type();

        while(index >= 0)
        {
            sum += data[index];
            index &= index + 1;
            --index;
        }

        return sum;
    }

    int count_in_range(const int from, const int to) const
    {
        return (count_less_equal(to) - count_less_equal(from - 1));
    }

private:
    value_type data[Range];
};


} // namespace pk


#endif // PK_BINARYINDEXEDTREE_HPP
