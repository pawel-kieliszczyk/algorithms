#include <gtest/gtest.h>


#include "geometry/point.hpp"
#include "geometry/points_collinear.hpp"


namespace gt = testing;


namespace pk
{
namespace geometry
{
namespace testing
{


struct points_collinear_tester : public gt::Test
{
    typedef point<int> point_int_type;
    typedef point<double> point_double_type;

    template<class Point>
    void verify_all_permutations_true(const Point& p1, const Point& p2, const Point& p3)
    {
        EXPECT_TRUE(points_collinear(p1, p2, p3));
        EXPECT_TRUE(points_collinear(p1, p3, p2));
        EXPECT_TRUE(points_collinear(p2, p1, p3));
        EXPECT_TRUE(points_collinear(p2, p3, p1));
        EXPECT_TRUE(points_collinear(p3, p1, p2));
        EXPECT_TRUE(points_collinear(p3, p2, p1));
    }

    template<class Point>
    void verify_all_permutations_false(const Point& p1, const Point& p2, const Point& p3)
    {
        EXPECT_FALSE(points_collinear(p1, p2, p3));
        EXPECT_FALSE(points_collinear(p1, p3, p2));
        EXPECT_FALSE(points_collinear(p2, p1, p3));
        EXPECT_FALSE(points_collinear(p2, p3, p1));
        EXPECT_FALSE(points_collinear(p3, p1, p2));
        EXPECT_FALSE(points_collinear(p3, p2, p1));
    }
};


/**
 * P1---P2---P3
 */
TEST_F(points_collinear_tester, points_int_collinear_horizontally)
{
    // given
    point_int_type p1(1, 5);
    point_int_type p2(2, 5);
    point_int_type p3(3, 5);

    // when & then
    verify_all_permutations_true(p1, p2, p3);
}


/**
 * P1---P2---P3
 */
TEST_F(points_collinear_tester, points_double_collinear_horizontally)
{
    // given
    point_double_type p1(1.0, 5.0);
    point_double_type p2(2.0, 5.0);
    point_double_type p3(3.0, 5.0);

    // when & then
    verify_all_permutations_true(p1, p2, p3);
}


/**
 * P1
 * |
 * P2
 * |
 * P3
 */
TEST_F(points_collinear_tester, points_int_collinear_vertically)
{
    // given
    point_int_type p1(7, 11);
    point_int_type p2(7, 22);
    point_int_type p3(7, 33);

    // when & then
    verify_all_permutations_true(p1, p2, p3);
}


/**
 * P1
 * |
 * P2
 * |
 * P3
 */
TEST_F(points_collinear_tester, points_double_collinear_vertically)
{
    // given
    point_double_type p1(7.0, 11.0);
    point_double_type p2(7.0, 22.0);
    point_double_type p3(7.0, 33.0);

    // when & then
    verify_all_permutations_true(p1, p2, p3);
}


/**
 * P1
 * |
 * P2
 * |
 * P3
 */
TEST_F(points_collinear_tester, points_int_collinear_diagonally)
{
    // given
    point_int_type p1(1, 1);
    point_int_type p2(2, 3);
    point_int_type p3(3, 5);

    // when & then
    verify_all_permutations_true(p1, p2, p3);

    // given
    point_int_type p4(1, 1);
    point_int_type p5(2, -1);
    point_int_type p6(3, -3);

    // when & then
    verify_all_permutations_true(p4, p5, p6);
}


/**
 * P1
 * |
 * P2
 * |
 * P3
 */
TEST_F(points_collinear_tester, points_double_collinear_diagonally)
{
    // given
    point_double_type p1(1.0, 1.0);
    point_double_type p2(2.0, 3.0);
    point_double_type p3(3.0, 5.0);

    // when & then
    verify_all_permutations_true(p1, p2, p3);

    // given
    point_double_type p4(1.0, 1.0);
    point_double_type p5(2.0, -1.0);
    point_double_type p6(3.0, -3.0);

    // when & then
    verify_all_permutations_true(p4, p5, p6);
}


/**
 * P1
 * |
 * P2
 * |
 * P3
 */
TEST_F(points_collinear_tester, points_int_not_collinear_but_two_collinear_horizontally)
{
    // given
    point_int_type p1(1, 11);
    point_int_type p2(22, 11);
    point_int_type p3(33, 12);

    // when & then
    verify_all_permutations_false(p1, p2, p3);
}


/**
 * P1
 * |
 * P2
 * |
 * P3
 */
TEST_F(points_collinear_tester, points_double_not_collinear_but_two_collinear_horizontally)
{
    // given
    point_int_type p1(1.0, 11.0);
    point_int_type p2(22.0, 11.0);
    point_int_type p3(33.0, 12.0);

    // when & then
    verify_all_permutations_false(p1, p2, p3);
}


/**
 * P1
 * |
 * P2
 * |
 * P3
 */
TEST_F(points_collinear_tester, points_int_not_collinear_but_two_collinear_vertically)
{
    // given
    point_int_type p1(1, 11);
    point_int_type p2(1, 22);
    point_int_type p3(33, 12);

    // when & then
    verify_all_permutations_false(p1, p2, p3);
}


/**
 * P1
 * |
 * P2
 * |
 * P3
 */
TEST_F(points_collinear_tester, points_double_not_collinear_but_two_collinear_vertically)
{
    // given
    point_int_type p1(1.0, 11.0);
    point_int_type p2(1.0, 22.0);
    point_int_type p3(33.0, 12.0);

    // when & then
    verify_all_permutations_false(p1, p2, p3);
}


/**
 * P1
 * |
 * P2
 * |
 * P3
 */
TEST_F(points_collinear_tester, points_int_not_collinear)
{
    // given
    point_int_type p1(1, 1);
    point_int_type p2(2, 10001);
    point_int_type p3(3, 20000);

    // when & then
    verify_all_permutations_false(p1, p2, p3);
}


/**
 * P1
 * |
 * P2
 * |
 * P3
 */
TEST_F(points_collinear_tester, points_double_not_collinear)
{
    // given
    point_int_type p1(1.0, 1.0);
    point_int_type p2(2.0, 10001.0);
    point_int_type p3(3.0, 20000.0);

    // when & then
    verify_all_permutations_false(p1, p2, p3);
}


} // namespace testing
} // namespace geometry
} // namespace pk
