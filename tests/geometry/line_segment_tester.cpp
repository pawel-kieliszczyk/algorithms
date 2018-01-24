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
    EXPECT_EQ(1, ls.get_p1().get_x());
    EXPECT_EQ(2, ls.get_p1().get_y());
    EXPECT_EQ(3, ls.get_p2().get_x());
    EXPECT_EQ(4, ls.get_p2().get_y());
}


TEST_F(line_segment_tester, modify_p1_and_verify)
{
    // given
    point_type p1(1, 2);
    point_type p2(3, 4);

    line_segment<point_type> ls(p1, p2);

    // when
    point_type new_p1(5, 6);
    ls.set_p1(new_p1);

    // then
    EXPECT_EQ(5, ls.get_p1().get_x());
    EXPECT_EQ(6, ls.get_p1().get_y());
    EXPECT_EQ(3, ls.get_p2().get_x());
    EXPECT_EQ(4, ls.get_p2().get_y());
}


TEST_F(line_segment_tester, modify_p2_and_verify)
{
    // given
    point_type p1(1, 2);
    point_type p2(3, 4);

    line_segment<point_type> ls(p1, p2);

    // when
    point_type new_p2(5, 6);
    ls.set_p2(new_p2);

    // then
    EXPECT_EQ(1, ls.get_p1().get_x());
    EXPECT_EQ(2, ls.get_p1().get_y());
    EXPECT_EQ(5, ls.get_p2().get_x());
    EXPECT_EQ(6, ls.get_p2().get_y());
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
    ls.set_p1(new_p1);
    ls.set_p2(new_p2);

    // then
    EXPECT_EQ(5, ls.get_p1().get_x());
    EXPECT_EQ(6, ls.get_p1().get_y());
    EXPECT_EQ(7, ls.get_p2().get_x());
    EXPECT_EQ(8, ls.get_p2().get_y());
}


} // namespace testing
} // namespace geometry
} // namespace pk
