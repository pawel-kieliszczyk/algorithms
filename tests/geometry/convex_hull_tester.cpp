#include <iterator>
#include <vector>

#include <gtest/gtest.h>

#include "geometry/convex_hull.hpp"
#include "geometry/point.hpp"


namespace gt = testing;


namespace pk
{
namespace geometry
{
namespace testing
{


struct convex_hull_tester : public gt::Test
{
    typedef point<int> point_type;
};


TEST_F(convex_hull_tester, tests_three_points)
{
    // given
    std::vector<point_type> points;
    points.push_back(point_type(1, 1));
    points.push_back(point_type(3, 1));
    points.push_back(point_type(2, 2));

    // when
    point_type output[10];
    point_type* output_last = convex_hull(points.begin(), points.end(), output);

    // then
    EXPECT_EQ(3, std::distance(output, output_last));

    EXPECT_EQ(point_type(1, 1), output[0]);
    EXPECT_EQ(point_type(2, 2), output[1]);
    EXPECT_EQ(point_type(3, 1), output[2]);
}


TEST_F(convex_hull_tester, tests_five_points_four_in_the_convex_hull)
{
    // given
    std::vector<point_type> points;
    points.push_back(point_type(-1, 0));
    points.push_back(point_type(0, -1));
    points.push_back(point_type(0, 1));
    points.push_back(point_type(1, 0));
    points.push_back(point_type(0, 0));

    // when
    point_type output[10];
    point_type* output_last = convex_hull(points.begin(), points.end(), output);

    // then
    EXPECT_EQ(4, std::distance(output, output_last));

    EXPECT_EQ(point_type(-1, 0), output[0]);
    EXPECT_EQ(point_type(0, 1), output[1]);
    EXPECT_EQ(point_type(1, 0), output[2]);
    EXPECT_EQ(point_type(0, -1), output[3]);
}


TEST_F(convex_hull_tester, tests_many_points)
{
    // given
    std::vector<point_type> points;
    points.push_back(point_type(1, 1));
    points.push_back(point_type(1, 2));
    points.push_back(point_type(1, 3));
    points.push_back(point_type(2, 1));
    points.push_back(point_type(2, 2));
    points.push_back(point_type(2, 3));
    points.push_back(point_type(3, 1));
    points.push_back(point_type(3, 2));
    points.push_back(point_type(3, 3));

    // when
    point_type output[9];
    point_type* output_last = convex_hull(points.begin(), points.end(), output);

    // then
    EXPECT_EQ(4, std::distance(output, output_last));

    EXPECT_EQ(point_type(1, 1), output[0]);
    EXPECT_EQ(point_type(1, 3), output[1]);
    EXPECT_EQ(point_type(3, 3), output[2]);
    EXPECT_EQ(point_type(3, 1), output[3]);
}


} // namespace testing
} // namespace geometry
} // namespace pk
