#ifndef PK_META_STATICASSERTION_HPP
#define PK_META_STATICASSERTION_HPP


namespace pk
{
namespace meta
{


template<bool>
struct static_assertion;


template<>
struct static_assertion<true> {};


} // namespace meta
} // namespace pk


#define STATIC_ASSERTION(A) pk::meta::static_assertion<(A)>()


#endif // PK_META_STATICASSERTION_HPP
