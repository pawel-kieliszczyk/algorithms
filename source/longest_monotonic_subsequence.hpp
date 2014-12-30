#ifndef PK_LONGESTMONOTONICSUBSEQUENCE_HPP
#define PK_LONGESTMONOTONICSUBSEQUENCE_HPP


#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>


namespace pk
{


template<int MAX_SEQUENCE_SIZE>
class longest_monotonic_subsequence
{
public:
    template<class ForwardIterator>
    static int strictly_decreasing(ForwardIterator first, ForwardIterator last)
    {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;

        return run(
                first,
                last,
                std::numeric_limits<value_type>::min(),
                std::numeric_limits<value_type>::max(),
                std::greater<value_type>());
    }

    template<class ForwardIterator>
    static int strictly_increasing(ForwardIterator first, ForwardIterator last)
    {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;

        return run(
                first,
                last,
                std::numeric_limits<value_type>::max(),
                std::numeric_limits<value_type>::min(),
                std::less<value_type>());
    }

    template<class ForwardIterator>
    static int weakly_decreasing(ForwardIterator first, ForwardIterator last)
    {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;

        return run(
                first,
                last,
                std::numeric_limits<value_type>::min(),
                std::numeric_limits<value_type>::max(),
                std::greater_equal<value_type>());
    }

    template<class ForwardIterator>
    static int weakly_increasing(ForwardIterator first, ForwardIterator last)
    {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;

        return run(
                first,
                last,
                std::numeric_limits<value_type>::max(),
                std::numeric_limits<value_type>::min(),
                std::less_equal<value_type>());
    }

private:
    template<class ForwardIterator, class BoundCompare>
    static int run(
            ForwardIterator first,
            ForwardIterator last,
            const typename std::iterator_traits<ForwardIterator>::value_type& infinity,
            const typename std::iterator_traits<ForwardIterator>::value_type& layers_zero_elements,
            BoundCompare bound_compare)
    {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
        const int sequence_size = std::distance(first, last);
        const int layers_size = sequence_size + 2;

        value_type layers[MAX_SEQUENCE_SIZE+2];

        std::fill(layers, layers + layers_size, infinity);
        layers[0] = layers_zero_elements;

        while(first != last)
        {
            value_type* t = std::lower_bound(layers, layers + layers_size, *first, bound_compare);
            *t = *first++;
        }

        int longest = 0;
        while(layers[longest] != infinity)
            ++longest;

        return (longest - 1);
    }
};


} // namespace pk


#endif // PK_LONGESTMONOTONICSUBSEQUENCE_HPP
