#include <gtest/gtest.h>


#include "geometry/point.hpp"
#include "geometry/line_segment.hpp"


namespace gt = testing;


namespace pk
{
namespace geometry
{
namespace testing
{


struct line_segment_tester : public gt::Test
{
    typedef point<int> point_type;
};


TEST_F(line_segment_tester, create_line_segment_default_constructor)
{
    // when & then
    line_segment<point_type> ls;
}


TEST_F(line_segment_tester, create_line_segment_nondefault_constructor)
{
    // given
    point_type p1(1, 2);
    point_type p2(3, 4);

    // when
    line_segment<point_type> ls(p1, p2);

    // then
    EXPECT_EQ(1, ls.p1.x);
    EXPECT_EQ(2, ls.p1.y);
    EXPECT_EQ(3, ls.p2.x);
    EXPECT_EQ(4, ls.p2.y);
}


TEST_F(line_segment_tester, modify_p1_and_verify)
{
    // given
    point_type p1(1, 2);
    point_type p2(3, 4);

    line_segment<point_type> ls(p1, p2);

    // when
    point_type new_p1(5, 6);
    ls.p1 = new_p1;

    // then
    EXPECT_EQ(5, ls.p1.x);
    EXPECT_EQ(6, ls.p1.y);
    EXPECT_EQ(3, ls.p2.x);
    EXPECT_EQ(4, ls.p2.y);
}


TEST_F(line_segment_tester, modify_p2_and_verify)
{
    // given
    point_type p1(1, 2);
    point_type p2(3, 4);

    line_segment<point_type> ls(p1, p2);

    // when
    point_type new_p2(5, 6);
    ls.p2 = new_p2;

    // then
    EXPECT_EQ(1, ls.p1.x);
    EXPECT_EQ(2, ls.p1.y);
    EXPECT_EQ(5, ls.p2.x);
    EXPECT_EQ(6, ls.p2.y);
}


TEST_F(line_segment_tester, modify_p1_and_p2_and_verify)
{
    // given
    point_type p1(1, 2);
    point_type p2(3, 4);

    line_segment<point_type> ls(p1, p2);

    // when
    point_type new_p1(5, 6);
    point_type new_p2(7, 8);
    ls.p1 = new_p1;
    ls.p2 = new_p2;

    // then
    EXPECT_EQ(5, ls.p1.x);
    EXPECT_EQ(6, ls.p1.y);
    EXPECT_EQ(7, ls.p2.x);
    EXPECT_EQ(8, ls.p2.y);
}


} // namespace testing
} // namespace geometry
} // namespace pk
