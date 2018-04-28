#ifndef PK_MAJORITYELEMENT_HPP
#define PK_MAJORITYELEMENT_HPP


#include <iterator>


namespace pk
{


template<class ForwardIterator>
ForwardIterator majority_element(const ForwardIterator first, const ForwardIterator last)
{
    ForwardIterator candidate;
    int counter = 0;

    for(ForwardIterator it = first; it != last; ++it)
    {
        if(counter == 0)
        {
            candidate = it;
            counter = 1;

            continue;
        }

        if(*it == *candidate)
            ++counter;
        else
            --counter;
    }

    if(counter == 0)
        return last;

    counter = 0;
    for(ForwardIterator it = first; it != last; ++it)
    {
        if(*it == *candidate)
            ++counter;
    }

    const int n = std::distance(first, last);

    if(counter > (n / 2))
        return candidate;

    return last;
}


} // namespace pk


#endif // PK_MAJORITYELEMENT_HPP
