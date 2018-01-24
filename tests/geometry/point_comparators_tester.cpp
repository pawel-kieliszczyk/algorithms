#include <gtest/gtest.h>


#include "geometry/point.hpp"
#include "geometry/point_comparators.hpp"


namespace gt = testing;


namespace pk
{
namespace geometry
{
namespace testing
{


struct point_comparators_tester : public gt::Test
{
};


TEST_F(point_comparators_tester, compares_two_points_int)
{
    // given
    typedef point<int> point_type;
    const point_type p1(11, 22);
    const point_type p2(11, 22);
    const point_type p3(11, 11);
    const point_type p4(22, 22);
    const point_type p5(22, 11);
    const point_type p6(33, 44);

    // when & then
    point_comparators<point_type>::comparator_type comparator;

    EXPECT_TRUE(comparator.is_same_point(p1, p2));
    EXPECT_FALSE(comparator.is_same_point(p1, p3));
    EXPECT_FALSE(comparator.is_same_point(p1, p4));
    EXPECT_FALSE(comparator.is_same_point(p1, p5));
    EXPECT_FALSE(comparator.is_same_point(p1, p6));
}


TEST_F(point_comparators_tester, compares_two_points_double)
{
    // given
    typedef point<double> point_type;
    const point_type p1(1.0, 2.0);
    const point_type p2(1.0, 2.0);
    const point_type p3(1.000001, 2.000001);
    const point_type p4(1.1, 2.0);
    const point_type p5(1.0, 2.1);
    const point_type p6(2.0, 1.0);
    const point_type p7(3.0, 4.0);

    // when & then
    point_comparators<point_type>::comparator_type comparator;

    EXPECT_TRUE(comparator.is_same_point(p1, p2));
    EXPECT_TRUE(comparator.is_same_point(p1, p3));
    EXPECT_FALSE(comparator.is_same_point(p1, p4));
    EXPECT_FALSE(comparator.is_same_point(p1, p5));
    EXPECT_FALSE(comparator.is_same_point(p1, p6));
    EXPECT_FALSE(comparator.is_same_point(p1, p7));
}


} // namespace testing
} // namespace geometry
} // namespace pk