#ifndef PK_INTERVALTREE2D_HPP
#define PK_INTERVALTREE2D_HPP


namespace pk
{
namespace detail
{


struct range_type
{
    range_type() {}
    range_type(const int from_, const int to_) : from(from_), to(to_) {}

    int from;
    int to;
};


} // namespace detail


template<int RANGE_1, int RANGE_2>
class interval_tree_2d
{
public:
    typedef detail::range_type range_type;

    int count(const range_type& r1, const range_type& r2) { return 0; }
};


} // namespace pk


#endif // PK_INTERVALTREE2D_HPP
