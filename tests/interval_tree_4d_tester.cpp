#include <gtest/gtest.h>

#include "interval_tree_dim.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct interval_tree_4d_tester : public gt::Test
{
    static const int RANGE_1 = 8;
    static const int RANGE_2 = 6;
    static const int RANGE_3 = 10;
    static const int RANGE_4 = 3;

    typedef pk::interval_tree_dim<int, RANGE_1, RANGE_2, RANGE_3, RANGE_4> interval_tree_type;
    typedef interval_tree_type::entry_type entry_type;
    typedef interval_tree_type::range_type range_type;
    typedef interval_tree_type::subrange_type subrange_type;

    // tested class:
    interval_tree_type t; // accepts points from [0, RANGE_1 - 1] x [0, RANGE_2 - 1] x [0, RANGE_3 - 1] x [0, RANGE_4 - 1]
};


/**
 * Custom test, just to make sure, that 4D version works OK.
 * For more detailed tests look at 1D, 2D and 3D versions.
 */
TEST_F(interval_tree_4d_tester, tests_two_points_once_in_tree)
{
    // given
    const entry_type entry1 = build_interval_tree_entry(3, 2, 5, 0);
    const entry_type entry2 = build_interval_tree_entry(5, 4, 3, 1);
    const int value = 1;

    // when
    t.insert(entry1, value);
    t.insert(entry2, value);

    // then
    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5), subrange_type(0, 9), subrange_type(0, 3))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 2), subrange_type(0, 5), subrange_type(0, 9), subrange_type(0, 3))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(4, 4), subrange_type(0, 5), subrange_type(0, 9), subrange_type(0, 3))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(6, 7), subrange_type(0, 5), subrange_type(0, 9), subrange_type(0, 3))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 1), subrange_type(0, 9), subrange_type(0, 3))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(3, 3), subrange_type(0, 9), subrange_type(0, 3))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(5, 5), subrange_type(0, 9), subrange_type(0, 3))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5), subrange_type(0, 2), subrange_type(0, 3))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5), subrange_type(4, 4), subrange_type(0, 3))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5), subrange_type(6, 9), subrange_type(0, 3))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5), subrange_type(0, 9), subrange_type(2, 2))));

    EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(3, 3), subrange_type(2, 2), subrange_type(5, 5), subrange_type(0, 0))));
    EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(5, 5), subrange_type(4, 4), subrange_type(3, 3), subrange_type(1, 1))));
}


} // namespace testing
} // namespace pk
