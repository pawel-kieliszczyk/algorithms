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

        return run< std::greater<value_type> >(
                first,
                last,
                std::numeric_limits<value_type>::min(),
                std::numeric_limits<value_type>::max());
    }

    template<class ForwardIterator>
    static int strictly_increasing(ForwardIterator first, ForwardIterator last)
    {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;

        return run< std::less<value_type> >(
                first,
                last,
                std::numeric_limits<value_type>::max(),
                std::numeric_limits<value_type>::min());
    }

    template<class ForwardIterator>
    static int weakly_decreasing(ForwardIterator first, ForwardIterator last)
    {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;

        return run< std::greater_equal<value_type> >(
                first,
                last,
                std::numeric_limits<value_type>::min(),
                std::numeric_limits<value_type>::max());
    }

    template<class ForwardIterator>
    static int weakly_increasing(ForwardIterator first, ForwardIterator last)
    {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;

        return run< std::less_equal<value_type> >(
                first,
                last,
                std::numeric_limits<value_type>::max(),
                std::numeric_limits<value_type>::min());
    }

private:
    template<class BoundCompare, class ForwardIterator>
    static int run(
            ForwardIterator first,
            ForwardIterator last,
            const typename std::iterator_traits<ForwardIterator>::value_type& infinity,
            const typename std::iterator_traits<ForwardIterator>::value_type& layers_zero_elements)
    {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
        const int sequence_size = std::distance(first, last);
        const int layers_size = sequence_size + 2;

        value_type layers[MAX_SEQUENCE_SIZE+2];

        std::fill(layers, layers + layers_size, infinity);
        layers[0] = layers_zero_elements;

        while(first != last)
        {
            value_type* t = std::lower_bound(layers, layers + layers_size, *first, BoundCompare());
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
