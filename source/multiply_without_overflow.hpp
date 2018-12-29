#ifndef PK_MULTIPLYWITHOUTOVERFLOW_HPP
#define PK_MULTIPLYWITHOUTOVERFLOW_HPP


namespace pk
{


/**
 * Returns a*b % m
 * Will not overflow if 2*m doesn't overflow.
 */
template<class T>
T multiply_without_overflow(T a, T b, const T m)
{ 
    T res = 0;

    a = a % m;
    while(b > 0)
    {
        if(b % 2 == 1)
            res = (res + a) % m;

        a = (a * 2) % m;
        b /= 2;
    } 

    return (res % m); 
}


} // namespace pk


#endif // PK_MULTIPLYWITHOUTOVERFLOW_HPP
