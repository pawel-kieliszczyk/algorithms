#ifndef PK_MODULARINVERSE_HPP
#define PK_MODULARINVERSE_HPP


namespace pk
{


/**
 * Returns x such that a*x == 1 (mod p)
 */
template<class T>
T modular_inverse(const T a, const T p)
{
    T q;

    T u = T(1);
    T w = a;
    T x = T(0);
    T z = p;

    while(w)
    {
        if(w < z)
        {
            q = u; u = x; x = q;
            q = w; w = z; z = q;
        }
        q = w / z;
        u -= q * x;
        w -= q * z;
    }

    if(x < T(0))
        x += p;

    return x;
}


} // namespace pk


#endif // PK_MODULARINVERSE_HPP
