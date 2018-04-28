#ifndef PK_META_GREATESTCOMMONDIVISOR_HPP
#define PK_META_GREATESTCOMMONDIVISOR_HPP


namespace pk
{
namespace meta
{


template<int A, int B>
struct greatest_common_divisor
{
    static const int value = greatest_common_divisor<B, A % B>::value;
};


template<int A>
struct greatest_common_divisor<A, 0>
{
    static const int value = A;
};


} // namespace meta
} // namespace pk


#endif // PK_META_GREATESTCOMMONDIVISOR_HPP
