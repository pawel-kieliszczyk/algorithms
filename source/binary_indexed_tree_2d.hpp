#ifndef PK_BINARYINDEXEDTREE2D_HPP
#define PK_BINARYINDEXEDTREE2D_HPP


namespace pk
{
namespace detail
{


struct binary_indexed_tree_2d_entry
{
    binary_indexed_tree_2d_entry(const int x_, const int y_) : x(x_), y(y_) {}

    int x;
    int y;
};


struct binary_indexed_tree_2d_subrange
{
    binary_indexed_tree_2d_subrange(const int from_, const int to_) : from(from_), to(to_) {}

    int from;
    int to;
};


} // namespace detail


template<class ValueType, int Range1, int Range2>
class binary_indexed_tree_2d
{
public:
    typedef ValueType value_type;
    typedef detail::binary_indexed_tree_2d_entry entry;
    typedef detail::binary_indexed_tree_2d_subrange subrange;

    binary_indexed_tree_2d(const int real_range_1_, const int real_range_2_)
        : real_range_1(real_range_1_),
          real_range_2(real_range_2_)
    {
        for(int x = 0; x < real_range_1; ++x)
            for(int y = 0; y < real_range_2; ++y)
                data[x][y] = value_type();
    }

    void increase(entry e, const value_type& value)
    {
        while(e.x < real_range_1)
        {
            int y1 = e.y;
            while(y1 < real_range_2)
            {
                data[e.x][y1] += value;
                y1 |= y1 + 1;
            }

            e.x |= e.x + 1;
        }
    }

    void set(const entry& e, const value_type& value)
    {
        const value_type old_value = count_in_range(subrange(e.x, e.x), subrange(e.y, e.y));
        increase(e, value - old_value);
    }

    value_type count_less_equal(int x, int y) const
    {
        value_type sum = value_type();

        while(x >= 0)
        {
            int y1 = y;
            while(y1 >= 0)
            {
                sum += data[x][y1];
                y1 &= y1 + 1;
                --y1;
            }

            x &= x + 1;
            --x;
        }

        return sum;
    }

    value_type count_in_range(const subrange& x_subrange, const subrange& y_subrange) const
    {
        return (  count_less_equal(x_subrange.to,       y_subrange.to)
                - count_less_equal(x_subrange.to,       y_subrange.from - 1)
                - count_less_equal(x_subrange.from - 1, y_subrange.to)
                + count_less_equal(x_subrange.from - 1, y_subrange.from - 1));
    }

private:
    value_type data[Range1][Range2];

    const int real_range_1;
    const int real_range_2;
};


} // namespace pk


#endif // PK_BINARYINDEXEDTREE2D_HPP
