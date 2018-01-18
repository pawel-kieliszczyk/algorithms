#include <gtest/gtest.h>


#include "geometry/point.hpp"
#include "geometry/segment.hpp"
#include "geometry/segments_overlapping.hpp"


namespace gt = testing;


namespace pk
{
namespace geometry
{
namespace testing
{


struct segments_overlapping_tester : public gt::Test
{
    typedef point<int> point_type;
    typedef segment<point_type> segment_type;
};


TEST_F(segments_overlapping_tester, verify_two_same_segments)
{
    // given
    segment_type s1(point_type(1, 2), point_type(3, 4));
    segment_type s2(point_type(1, 2), point_type(3, 4));

    // when & then
    EXPECT_TRUE(segments_overlapping(s1, s2));
    EXPECT_TRUE(segments_overlapping(s2, s1));
}


TEST_F(segments_overlapping_tester, verify_two_same_segments_inverted)
{
    // given
    segment_type s1(point_type(1, 2), point_type(3, 4));
    segment_type s2(point_type(3, 4), point_type(1, 2));

    // when & then
    EXPECT_TRUE(segments_overlapping(s1, s2));
    EXPECT_TRUE(segments_overlapping(s2, s1));
}


TEST_F(segments_overlapping_tester, end_of_one_segment_is_on_the_other_segment)
{
    // given
    segment_type s1(point_type(1, 1), point_type(7, 9));

    segment_type s2(point_type(4, 5), point_type(3, 3));
    segment_type s3(point_type(4, 5), point_type(5, 9));

    segment_type s4(point_type(3, 3), point_type(4, 5));
    segment_type s5(point_type(5, 9), point_type(4, 5));

    // when & then
    EXPECT_TRUE(segments_overlapping(s1, s2));
    EXPECT_TRUE(segments_overlapping(s2, s1));

    EXPECT_TRUE(segments_overlapping(s1, s3));
    EXPECT_TRUE(segments_overlapping(s3, s1));

    EXPECT_TRUE(segments_overlapping(s1, s4));
    EXPECT_TRUE(segments_overlapping(s4, s1));

    EXPECT_TRUE(segments_overlapping(s1, s5));
    EXPECT_TRUE(segments_overlapping(s5, s1));
}


TEST_F(segments_overlapping_tester, verify_different_overlapping_cases)
{
    // given
    segment_type seg(point_type(3, 2), point_type(8, 4));

    segment_type overlapping1(point_type(2, -1), point_type(5, 3));
    segment_type overlapping2(point_type(5, 3), point_type(2, -1));

    segment_type overlapping3(point_type(2, 3), point_type(4, 2));
    segment_type overlapping4(point_type(4, 2), point_type(2, 3));

    segment_type overlapping5(point_type(5, 5), point_type(6, 2));
    segment_type overlapping6(point_type(6, 2), point_type(5, 5));

    segment_type overlapping7(point_type(6, 4), point_type(9, 0));
    segment_type overlapping8(point_type(9, 0), point_type(6, 4));

    segment_type overlapping9(point_type(7, 3), point_type(9, 6));
    segment_type overlapping10(point_type(9, 6), point_type(7, 3));

    // when & then
    EXPECT_TRUE(segments_overlapping(seg, overlapping1));
    EXPECT_TRUE(segments_overlapping(overlapping1, seg));

    EXPECT_TRUE(segments_overlapping(seg, overlapping2));
    EXPECT_TRUE(segments_overlapping(overlapping2, seg));

    EXPECT_TRUE(segments_overlapping(seg, overlapping3));
    EXPECT_TRUE(segments_overlapping(overlapping3, seg));

    EXPECT_TRUE(segments_overlapping(seg, overlapping4));
    EXPECT_TRUE(segments_overlapping(overlapping4, seg));

    EXPECT_TRUE(segments_overlapping(seg, overlapping5));
    EXPECT_TRUE(segments_overlapping(overlapping5, seg));

    EXPECT_TRUE(segments_overlapping(seg, overlapping6));
    EXPECT_TRUE(segments_overlapping(overlapping6, seg));

    EXPECT_TRUE(segments_overlapping(seg, overlapping7));
    EXPECT_TRUE(segments_overlapping(overlapping7, seg));

    EXPECT_TRUE(segments_overlapping(seg, overlapping8));
    EXPECT_TRUE(segments_overlapping(overlapping8, seg));

    EXPECT_TRUE(segments_overlapping(seg, overlapping9));
    EXPECT_TRUE(segments_overlapping(overlapping9, seg));

    EXPECT_TRUE(segments_overlapping(seg, overlapping10));
    EXPECT_TRUE(segments_overlapping(overlapping10, seg));
}


TEST_F(segments_overlapping_tester, verify_different_not_overlapping_cases)
{
    // given
    segment_type seg(point_type(3, 2), point_type(8, 4));

    segment_type not_overlapping1(point_type(1, 1), point_type(2, 3));
    segment_type not_overlapping2(point_type(2, 3), point_type(1, 1));

    segment_type not_overlapping3(point_type(2, 1), point_type(4, 2));
    segment_type not_overlapping4(point_type(4, 2), point_type(2, 1));

    segment_type not_overlapping5(point_type(1, 1), point_type(4, 3));
    segment_type not_overlapping6(point_type(4, 3), point_type(1, 1));

    segment_type not_overlapping7(point_type(5, 2), point_type(6, 1));
    segment_type not_overlapping8(point_type(6, 1), point_type(5, 2));

    segment_type not_overlapping9(point_type(4, 6), point_type(5, 4));
    segment_type not_overlapping10(point_type(5, 4), point_type(4, 6));

    segment_type not_overlapping11(point_type(6, 4), point_type(9, 5));
    segment_type not_overlapping12(point_type(9, 5), point_type(6, 4));

    segment_type not_overlapping13(point_type(7, 3), point_type(9, 4));
    segment_type not_overlapping14(point_type(9, 4), point_type(7, 3));

    segment_type not_overlapping15(point_type(9, 6), point_type(10, 4));
    segment_type not_overlapping16(point_type(10, 4), point_type(9, 6));

    // when & then
    EXPECT_FALSE(segments_overlapping(seg, not_overlapping1));
    EXPECT_FALSE(segments_overlapping(not_overlapping1, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping2));
    EXPECT_FALSE(segments_overlapping(not_overlapping2, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping3));
    EXPECT_FALSE(segments_overlapping(not_overlapping3, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping4));
    EXPECT_FALSE(segments_overlapping(not_overlapping4, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping5));
    EXPECT_FALSE(segments_overlapping(not_overlapping5, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping6));
    EXPECT_FALSE(segments_overlapping(not_overlapping6, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping7));
    EXPECT_FALSE(segments_overlapping(not_overlapping7, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping8));
    EXPECT_FALSE(segments_overlapping(not_overlapping8, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping9));
    EXPECT_FALSE(segments_overlapping(not_overlapping9, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping10));
    EXPECT_FALSE(segments_overlapping(not_overlapping10, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping11));
    EXPECT_FALSE(segments_overlapping(not_overlapping11, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping12));
    EXPECT_FALSE(segments_overlapping(not_overlapping12, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping13));
    EXPECT_FALSE(segments_overlapping(not_overlapping13, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping14));
    EXPECT_FALSE(segments_overlapping(not_overlapping14, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping15));
    EXPECT_FALSE(segments_overlapping(not_overlapping15, seg));

    EXPECT_FALSE(segments_overlapping(seg, not_overlapping16));
    EXPECT_FALSE(segments_overlapping(not_overlapping16, seg));
}


} // namespace testing
} // namespace geometry
} // namespace pk
