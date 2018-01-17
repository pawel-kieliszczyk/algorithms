#include <gtest/gtest.h>


#include "geometry/point.hpp"
#include "geometry/segment.hpp"


namespace gt = testing;


namespace pk
{
namespace geometry
{
namespace testing
{


struct segment_tester : public gt::Test
{
    typedef point<int> point_type;
};


TEST_F(segment_tester, create_segment_default_constructor)
{
    // when & then
    segment<point_type> s;
}


TEST_F(segment_tester, create_segment_nondefault_constructor)
{
    // given
    point_type p1(1, 2);
    point_type p2(3, 4);

    // when
    segment<point_type> s(p1, p2);

    // then
    EXPECT_EQ(1, s.get_p1().get_x());
    EXPECT_EQ(2, s.get_p1().get_y());
    EXPECT_EQ(3, s.get_p2().get_x());
    EXPECT_EQ(4, s.get_p2().get_y());
}


TEST_F(segment_tester, modify_p1_and_verify)
{
    // given
    point_type p1(1, 2);
    point_type p2(3, 4);

    segment<point_type> s(p1, p2);

    // when
    point_type new_p1(5, 6);
    s.set_p1(new_p1);

    // then
    EXPECT_EQ(5, s.get_p1().get_x());
    EXPECT_EQ(6, s.get_p1().get_y());
    EXPECT_EQ(3, s.get_p2().get_x());
    EXPECT_EQ(4, s.get_p2().get_y());
}


TEST_F(segment_tester, modify_p2_and_verify)
{
    // given
    point_type p1(1, 2);
    point_type p2(3, 4);

    segment<point_type> s(p1, p2);

    // when
    point_type new_p2(5, 6);
    s.set_p2(new_p2);

    // then
    EXPECT_EQ(1, s.get_p1().get_x());
    EXPECT_EQ(2, s.get_p1().get_y());
    EXPECT_EQ(5, s.get_p2().get_x());
    EXPECT_EQ(6, s.get_p2().get_y());
}


TEST_F(segment_tester, modify_p1_and_p2_and_verify)
{
    // given
    point_type p1(1, 2);
    point_type p2(3, 4);

    segment<point_type> s(p1, p2);

    // when
    point_type new_p1(5, 6);
    point_type new_p2(7, 8);
    s.set_p1(new_p1);
    s.set_p2(new_p2);

    // then
    EXPECT_EQ(5, s.get_p1().get_x());
    EXPECT_EQ(6, s.get_p1().get_y());
    EXPECT_EQ(7, s.get_p2().get_x());
    EXPECT_EQ(8, s.get_p2().get_y());
}


} // namespace testing
} // namespace geometry
} // namespace pk