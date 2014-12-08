#ifndef PK_GREATESTCOMMONDIVISOR_HPP
#define PK_GREATESTCOMMONDIVISOR_HPP


namespace pk
{


template<class T>
T greatest_common_divisor(T a, T b)
{
    while(b > 0)
    {
        const T tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}


} // namespace pk


#endif // PK_GREATESTCOMMONDIVISOR_HPP
