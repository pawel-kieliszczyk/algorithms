#include <gtest/gtest.h>


#include "geometry/distance.hpp"
#include "geometry/point.hpp"


namespace gt = testing;


namespace pk
{
namespace geometry
{
namespace testing
{


struct distance_tester : public gt::Test
{
};


TEST_F(distance_tester, calculate_distance_between_two_same_points_int)
{
    // given
    point<int> p1(11, 22);
    point<int> p2(11, 22);

    // when & then
    EXPECT_EQ(0.0, distance(p1, p2));
}


TEST_F(distance_tester, calculate_distance_between_two_same_points_double)
{
    // given
    point<double> p1(11.1, 22.2);
    point<double> p2(11.1, 22.2);

    // when & then
    EXPECT_EQ(0.0, distance(p1, p2));
}


TEST_F(distance_tester, calculate_distance_between_two_different_points_int_with_same_x)
{
    // given
    point<int> p1(5, 7);
    point<int> p2(5, 10);

    // when & then
    EXPECT_EQ(3.0, distance(p1, p2));
}


TEST_F(distance_tester, calculate_distance_between_two_different_points_double_with_same_x)
{
    // given
    point<int> p1(5.0, 7.0);
    point<int> p2(5.0, 10.0);

    // when & then
    EXPECT_EQ(3.0, distance(p1, p2));
}


TEST_F(distance_tester, calculate_distance_between_two_different_points_int_with_same_y)
{
    // given
    point<int> p1(5, 7);
    point<int> p2(2, 7);

    // when & then
    EXPECT_EQ(3.0, distance(p1, p2));
}


TEST_F(distance_tester, calculate_distance_between_two_different_points_double_with_same_y)
{
    // given
    point<int> p1(5.0, 7.0);
    point<int> p2(2.0, 7.0);

    // when & then
    EXPECT_EQ(3.0, distance(p1, p2));
}


TEST_F(distance_tester, calculate_distance_between_two_different_points_int)
{
    // given
    point<int> p1(0, 0);
    point<int> p2(3, 4);

    // when & then
    EXPECT_EQ(5.0, distance(p1, p2));
}


TEST_F(distance_tester, calculate_distance_between_two_different_points_double)
{
    // given
    point<int> p1(0.0, 0.0);
    point<int> p2(3.0, 4.0);

    // when & then
    EXPECT_EQ(5.0, distance(p1, p2));
}


} // namespace testing
} // namespace geometry
} // namespace pk
