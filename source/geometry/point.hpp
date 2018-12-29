#ifndef PK_GEOMETRY_POINT_HPP
#define PK_GEOMETRY_POINT_HPP


namespace pk
{
namespace geometry
{


template<class T>
class point
{
public:
    typedef T value_type;

    point() {}
    point(const T& xx, const T& yy) : x(xx), y(yy) {}

    void set_x(const T& xx) { x = xx; }
    void set_y(const T& yy) { y = yy; }

    const T& get_x() const { return x; }
    const T& get_y() const { return y; }

private:
    T x;
    T y;
};


template<class T>
bool operator==(const point<T>& left, const point<T>& right)
{
    return ((left.get_x() == right.get_x()) && (left.get_y() == right.get_y()));
}


} // namespace geometry
} // namespace pk


#endif // PK_GEOMETRY_POINT_HPP
