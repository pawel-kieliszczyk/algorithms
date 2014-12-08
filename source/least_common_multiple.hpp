#ifndef PK_LEASTCOMMONMULTIPLE_HPP
#define PK_LEASTCOMMONMULTIPLE_HPP


#include "greatest_common_divisor.hpp"


namespace pk
{


template<class T>
T least_common_multiple(const T&a , const T& b)
{
    return (a / greatest_common_divisor(a, b)) * b;
}


} // namespace pk


#endif // PK_LEASTCOMMONMULTIPLE_HPP
