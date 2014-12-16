#ifndef PK_META_INTERVALTREESIZE_HPP
#define PK_META_INTERVALTREESIZE_HPP


namespace pk
{
namespace meta
{


template<int N>
struct interval_tree_size
{
    static const int value = 2 * interval_tree_size<N / 2>::value;
};


template<>
struct interval_tree_size<0>
{
    static const int value = 2;
};


} // namespace meta
} // namespace pk


#endif // PK_META_INTERVALTREESIZE_HPP
