#ifndef PK_META_GREATESTCOMMONDIVISOR_HPP
#define PK_META_GREATESTCOMMONDIVISOR_HPP


namespace pk
{
namespace meta
{
namespace detail
{


template<bool BGreaterThanZero, int A, int B>
struct greatest_common_divisor
{
    static const int value = A;
};


template<int A, int B>
struct greatest_common_divisor<true, A, B>
{
private:
    static const int AA = B;
    static const int BB = A % B;

public:
    static const int value = greatest_common_divisor<(BB > 0), AA, BB>::value;
};


} // namespace detail


template<int A, int B>
struct greatest_common_divisor
{
    static const int value = detail::greatest_common_divisor<(B > 0), A, B>::value;
};


} // namespace meta
} // namespace pk


#endif // PK_META_GREATESTCOMMONDIVISOR_HPP
