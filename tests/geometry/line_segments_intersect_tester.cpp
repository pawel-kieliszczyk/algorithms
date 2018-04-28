#include <gtest/gtest.h>


#include "geometry/point.hpp"
#include "geometry/line_segment.hpp"
#include "geometry/line_segments_intersect.hpp"


namespace gt = testing;


namespace pk
{
namespace geometry
{
namespace testing
{


struct line_segments_intersect_tester : public gt::Test
{
    typedef point<int> point_type;
    typedef line_segment<point_type> line_segment_type;
};


TEST_F(line_segments_intersect_tester, verify_two_same_line_segments)
{
    // given
    line_segment_type ls1(point_type(1, 2), point_type(3, 4));
    line_segment_type ls2(point_type(1, 2), point_type(3, 4));

    // when & then
    EXPECT_TRUE(line_segments_intersect(ls1, ls2));
    EXPECT_TRUE(line_segments_intersect(ls2, ls1));
}


TEST_F(line_segments_intersect_tester, verify_two_same_line_segments_inverted)
{
    // given
    line_segment_type ls1(point_type(1, 2), point_type(3, 4));
    line_segment_type ls2(point_type(3, 4), point_type(1, 2));

    // when & then
    EXPECT_TRUE(line_segments_intersect(ls1, ls2));
    EXPECT_TRUE(line_segments_intersect(ls2, ls1));
}


TEST_F(line_segments_intersect_tester, end_of_one_line_segment_is_on_the_other_line_segment)
{
    // given
    line_segment_type ls1(point_type(1, 1), point_type(7, 9));

    line_segment_type ls2(point_type(4, 5), point_type(3, 3));
    line_segment_type ls3(point_type(4, 5), point_type(5, 9));

    line_segment_type ls4(point_type(3, 3), point_type(4, 5));
    line_segment_type ls5(point_type(5, 9), point_type(4, 5));

    // when & then
    EXPECT_TRUE(line_segments_intersect(ls1, ls2));
    EXPECT_TRUE(line_segments_intersect(ls2, ls1));

    EXPECT_TRUE(line_segments_intersect(ls1, ls3));
    EXPECT_TRUE(line_segments_intersect(ls3, ls1));

    EXPECT_TRUE(line_segments_intersect(ls1, ls4));
    EXPECT_TRUE(line_segments_intersect(ls4, ls1));

    EXPECT_TRUE(line_segments_intersect(ls1, ls5));
    EXPECT_TRUE(line_segments_intersect(ls5, ls1));
}


TEST_F(line_segments_intersect_tester, verify_different_overlapping_cases)
{
    // given
    line_segment_type seg(point_type(3, 2), point_type(8, 4));

    line_segment_type overlapping1(point_type(2, -1), point_type(5, 3));
    line_segment_type overlapping2(point_type(5, 3), point_type(2, -1));

    line_segment_type overlapping3(point_type(2, 3), point_type(4, 2));
    line_segment_type overlapping4(point_type(4, 2), point_type(2, 3));

    line_segment_type overlapping5(point_type(5, 5), point_type(6, 2));
    line_segment_type overlapping6(point_type(6, 2), point_type(5, 5));

    line_segment_type overlapping7(point_type(6, 4), point_type(9, 0));
    line_segment_type overlapping8(point_type(9, 0), point_type(6, 4));

    line_segment_type overlapping9(point_type(7, 3), point_type(9, 6));
    line_segment_type overlapping10(point_type(9, 6), point_type(7, 3));

    // when & then
    EXPECT_TRUE(line_segments_intersect(seg, overlapping1));
    EXPECT_TRUE(line_segments_intersect(overlapping1, seg));

    EXPECT_TRUE(line_segments_intersect(seg, overlapping2));
    EXPECT_TRUE(line_segments_intersect(overlapping2, seg));

    EXPECT_TRUE(line_segments_intersect(seg, overlapping3));
    EXPECT_TRUE(line_segments_intersect(overlapping3, seg));

    EXPECT_TRUE(line_segments_intersect(seg, overlapping4));
    EXPECT_TRUE(line_segments_intersect(overlapping4, seg));

    EXPECT_TRUE(line_segments_intersect(seg, overlapping5));
    EXPECT_TRUE(line_segments_intersect(overlapping5, seg));

    EXPECT_TRUE(line_segments_intersect(seg, overlapping6));
    EXPECT_TRUE(line_segments_intersect(overlapping6, seg));

    EXPECT_TRUE(line_segments_intersect(seg, overlapping7));
    EXPECT_TRUE(line_segments_intersect(overlapping7, seg));

    EXPECT_TRUE(line_segments_intersect(seg, overlapping8));
    EXPECT_TRUE(line_segments_intersect(overlapping8, seg));

    EXPECT_TRUE(line_segments_intersect(seg, overlapping9));
    EXPECT_TRUE(line_segments_intersect(overlapping9, seg));

    EXPECT_TRUE(line_segments_intersect(seg, overlapping10));
    EXPECT_TRUE(line_segments_intersect(overlapping10, seg));
}


TEST_F(line_segments_intersect_tester, verify_different_not_overlapping_cases)
{
    // given
    line_segment_type seg(point_type(3, 2), point_type(8, 4));

    line_segment_type not_overlapping1(point_type(1, 1), point_type(2, 3));
    line_segment_type not_overlapping2(point_type(2, 3), point_type(1, 1));

    line_segment_type not_overlapping3(point_type(2, 1), point_type(4, 2));
    line_segment_type not_overlapping4(point_type(4, 2), point_type(2, 1));

    line_segment_type not_overlapping5(point_type(1, 1), point_type(4, 3));
    line_segment_type not_overlapping6(point_type(4, 3), point_type(1, 1));

    line_segment_type not_overlapping7(point_type(5, 2), point_type(6, 1));
    line_segment_type not_overlapping8(point_type(6, 1), point_type(5, 2));

    line_segment_type not_overlapping9(point_type(4, 6), point_type(5, 4));
    line_segment_type not_overlapping10(point_type(5, 4), point_type(4, 6));

    line_segment_type not_overlapping11(point_type(6, 4), point_type(9, 5));
    line_segment_type not_overlapping12(point_type(9, 5), point_type(6, 4));

    line_segment_type not_overlapping13(point_type(7, 3), point_type(9, 4));
    line_segment_type not_overlapping14(point_type(9, 4), point_type(7, 3));

    line_segment_type not_overlapping15(point_type(9, 6), point_type(10, 4));
    line_segment_type not_overlapping16(point_type(10, 4), point_type(9, 6));

    // when & then
    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping1));
    EXPECT_FALSE(line_segments_intersect(not_overlapping1, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping2));
    EXPECT_FALSE(line_segments_intersect(not_overlapping2, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping3));
    EXPECT_FALSE(line_segments_intersect(not_overlapping3, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping4));
    EXPECT_FALSE(line_segments_intersect(not_overlapping4, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping5));
    EXPECT_FALSE(line_segments_intersect(not_overlapping5, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping6));
    EXPECT_FALSE(line_segments_intersect(not_overlapping6, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping7));
    EXPECT_FALSE(line_segments_intersect(not_overlapping7, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping8));
    EXPECT_FALSE(line_segments_intersect(not_overlapping8, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping9));
    EXPECT_FALSE(line_segments_intersect(not_overlapping9, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping10));
    EXPECT_FALSE(line_segments_intersect(not_overlapping10, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping11));
    EXPECT_FALSE(line_segments_intersect(not_overlapping11, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping12));
    EXPECT_FALSE(line_segments_intersect(not_overlapping12, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping13));
    EXPECT_FALSE(line_segments_intersect(not_overlapping13, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping14));
    EXPECT_FALSE(line_segments_intersect(not_overlapping14, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping15));
    EXPECT_FALSE(line_segments_intersect(not_overlapping15, seg));

    EXPECT_FALSE(line_segments_intersect(seg, not_overlapping16));
    EXPECT_FALSE(line_segments_intersect(not_overlapping16, seg));
}


} // namespace testing
} // namespace geometry
} // namespace pk
