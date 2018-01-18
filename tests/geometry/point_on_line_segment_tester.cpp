#include <gtest/gtest.h>


#include "geometry/point.hpp"
#include "geometry/point_on_line_segment.hpp"
#include "geometry/line_segment.hpp"


namespace gt = testing;


namespace pk
{
namespace geometry
{
namespace testing
{


struct point_on_line_segment_tester : public gt::Test
{
    typedef point<int> point_type;
    typedef line_segment<point_type> line_segment_type;
};


TEST_F(point_on_line_segment_tester, check_different_points_against_horizontal_line_segment)
{
    // given
    const line_segment_type seg(point_type(1, 1), point_type(5, 1));

    // when & then
    EXPECT_TRUE(point_on_line_segment(point_type(1, 1), seg));
    EXPECT_TRUE(point_on_line_segment(point_type(2, 1), seg));
    EXPECT_TRUE(point_on_line_segment(point_type(3, 1), seg));
    EXPECT_TRUE(point_on_line_segment(point_type(4, 1), seg));
    EXPECT_TRUE(point_on_line_segment(point_type(5, 1), seg));

    EXPECT_FALSE(point_on_line_segment(point_type(0, 1), seg));
    EXPECT_FALSE(point_on_line_segment(point_type(6, 1), seg));
    EXPECT_FALSE(point_on_line_segment(point_type(0, 2), seg));
    EXPECT_FALSE(point_on_line_segment(point_type(2, 2), seg));
}


TEST_F(point_on_line_segment_tester, check_different_points_against_vertical_line_segment)
{
    // given
    const line_segment_type seg(point_type(1, 1), point_type(1, 5));

    // when & then
    EXPECT_TRUE(point_on_line_segment(point_type(1, 1), seg));
    EXPECT_TRUE(point_on_line_segment(point_type(1, 2), seg));
    EXPECT_TRUE(point_on_line_segment(point_type(1, 3), seg));
    EXPECT_TRUE(point_on_line_segment(point_type(1, 4), seg));
    EXPECT_TRUE(point_on_line_segment(point_type(1, 5), seg));

    EXPECT_FALSE(point_on_line_segment(point_type(1, 0), seg));
    EXPECT_FALSE(point_on_line_segment(point_type(1, 6), seg));
    EXPECT_FALSE(point_on_line_segment(point_type(2, 0), seg));
    EXPECT_FALSE(point_on_line_segment(point_type(2, 2), seg));
}


TEST_F(point_on_line_segment_tester, check_different_points_against_diagonal_line_segment)
{
    // given
    const line_segment_type seg(point_type(1, 1), point_type(7, 9));

    // when & then
    EXPECT_TRUE(point_on_line_segment(point_type(1, 1), seg));
    EXPECT_TRUE(point_on_line_segment(point_type(4, 5), seg));
    EXPECT_TRUE(point_on_line_segment(point_type(7, 9), seg));

    EXPECT_FALSE(point_on_line_segment(point_type(-2, -3), seg));
    EXPECT_FALSE(point_on_line_segment(point_type(10, 13), seg));
    EXPECT_FALSE(point_on_line_segment(point_type(4, 4), seg));
    EXPECT_FALSE(point_on_line_segment(point_type(5, 5), seg));
}


} // namespace testing
} // namespace geometry
} // namespace pk
