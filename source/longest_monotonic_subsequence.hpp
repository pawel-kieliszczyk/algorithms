#ifndef PK_LONGESTMONOTONICSUBSEQUENCE_HPP
#define PK_LONGESTMONOTONICSUBSEQUENCE_HPP


#include <algorithm>
#include <iterator>
#include <limits>


namespace pk
{


template<int MAX_SEQUENCE_SIZE>
class longest_monotonic_subsequence
{
public:
    template<class Iterator>
    static int weakly_increasing(Iterator first, Iterator last)
    {
        typedef typename std::iterator_traits<Iterator>::value_type value_type;
        const value_type infinity = std::numeric_limits<value_type>::max();
        const int sequence_size = std::distance(first, last);
        const int layers_size = sequence_size + 2;

        value_type layers[MAX_SEQUENCE_SIZE+2];

        std::fill(layers, layers + layers_size, infinity);
        layers[0] = value_type();

        while(first != last)
        {
            value_type* t = std::upper_bound(layers, layers + layers_size, *first);
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
