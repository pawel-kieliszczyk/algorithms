#ifndef PK_MAXSEGMENTTREE_HPP
#define PK_MAXSEGMENTTREE_HPP


#include <algorithm>


namespace pk
{


/**
 * Supports two operations:
 * - update value for a given range [left, right] by 'x'
 * - find maximum value for a given range [left, right]
 *
 * Valid ranges from '0' to 'RangeLimit-1'
 */
template<class ValueType, int RangeLimit>
class max_segment_tree
{
public:
    typedef ValueType value_type;

    max_segment_tree()
    {
        std::fill(val, val + INTERNAL_SIZE, value_type(0));
        std::fill(maxval, maxval + INTERNAL_SIZE, value_type(0));
    }

    void update(const int from, const int to, const value_type& value)
    {
        update(from, to + 1, value, 1, 0, RangeLimit);
    }

    value_type get_max(const int from, const int to) const
    {
        return get_max(from, to + 1, 1, 0, RangeLimit);
    }

private:
    void update(
            const int from,
            const int to,
            const value_type& value,
            const int node_idx,
            const int node_left,
            const int node_right)
    {
        if((to <= node_left) || (node_right <= from))
            return;

        if((from <= node_left) && (node_right <= to))
        {
            val[node_idx] += value;
        }
        else
        {
            const int node_mid = (node_left + node_right) / 2;
            update(from, to, value, node_idx + node_idx, node_left, node_mid);
            update(from, to, value, node_idx + node_idx + 1, node_mid, node_right);
        }

        if(node_left + 1 == node_right)
            maxval[node_idx] = val[node_idx];
        else
            maxval[node_idx] = val[node_idx] + std::max(maxval[node_idx + node_idx], maxval[node_idx + node_idx + 1]);
    }

    value_type get_max(
            const int from,
            const int to,
            const int node_idx,
            const int node_left,
            const int node_right) const
    {
        if((to <= node_left) || (node_right <= from))
            return value_type(0);

        if((from <= node_left) && (node_right <= to))
            return maxval[node_idx];

        const int node_mid = (node_left + node_right) / 2;
        int max1 = get_max(from, to, node_idx + node_idx, node_left, node_mid);
        int max2 = get_max(from, to, node_idx + node_idx + 1, node_mid, node_right);
        return (val[node_idx] + std::max(max1, max2));
    }

    static const int  INTERNAL_SIZE = 4 * RangeLimit + 9;
    value_type val[INTERNAL_SIZE];
    value_type maxval[INTERNAL_SIZE];
};


} // namespace pk


#endif // PK_MAXSEGMENTTREE_HPP
