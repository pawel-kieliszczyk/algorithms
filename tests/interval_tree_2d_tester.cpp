#include <gtest/gtest.h>

#include "interval_tree_dim.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct interval_tree_2d_tester : public gt::Test
{
    static const int RANGE_1 = 8;
    static const int RANGE_2 = 6;

    typedef pk::interval_tree_dim<int, RANGE_1, RANGE_2> interval_tree_type;
    typedef interval_tree_type::entry_type entry_type;
    typedef interval_tree_type::range_type range_type;
    typedef interval_tree_type::subrange_type subrange_type;

    // tested class:
    interval_tree_type t; // accepts points from [0, RANGE_1 - 1] x [0, RANGE_2 - 1]
};


TEST_F(interval_tree_2d_tester, tests_empty_tree)
{
    // when and then
    range_type range = build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5));
    EXPECT_EQ(0, t.count(range));
}


TEST_F(interval_tree_2d_tester, tests_one_point_once_in_tree)
{
    // given
    const entry_type entry = build_interval_tree_entry(3, 2);
    const int value = 1;

    // when
    t.insert(entry, value);

    // then
    EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 2), subrange_type(0, 5))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(4, 7), subrange_type(0, 5))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 1))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(3, 5))));

    EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(3, 3), subrange_type(2, 2))));
}


TEST_F(interval_tree_2d_tester, tests_one_point_twice_in_tree)
{
    // given
    const entry_type entry = build_interval_tree_entry(3, 2);
    const int value = 1;

    // when
    t.insert(entry, value);
    t.insert(entry, value);

    // then
    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 2), subrange_type(0, 5))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(4, 7), subrange_type(0, 5))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 1))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(3, 5))));
    
    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(3, 3), subrange_type(2, 2))));
}


TEST_F(interval_tree_2d_tester, tests_two_points_once_in_tree)
{
    // given
    const entry_type entry1 = build_interval_tree_entry(3, 2);
    const entry_type entry2 = build_interval_tree_entry(5, 4);
    const int value = 1;

    // when
    t.insert(entry1, value);
    t.insert(entry2, value);

    // then
    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 2), subrange_type(0, 5))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(4, 4), subrange_type(0, 5))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(6, 7), subrange_type(0, 5))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 1))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(3, 3))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(5, 5))));

    EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(3, 3), subrange_type(2, 2))));
    EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(5, 5), subrange_type(4, 4))));
}


TEST_F(interval_tree_2d_tester, tests_two_points_twice_in_tree)
{
    // given
    const entry_type entry1 = build_interval_tree_entry(3, 2);
    const entry_type entry2 = build_interval_tree_entry(5, 4);
    const int value = 2;

    // when
    t.insert(entry1, value);
    t.insert(entry2, value);

    // then
    EXPECT_EQ(4, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 2), subrange_type(0, 5))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(4, 4), subrange_type(0, 5))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(6, 7), subrange_type(0, 5))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 1))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(3, 3))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(5, 5))));

    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(3, 3), subrange_type(2, 2))));
    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(5, 5), subrange_type(4, 4))));
}


TEST_F(interval_tree_2d_tester, tests_all_points_once_in_tree)
{
    // given
    const int value = 1;

    // when
    for(int x = 0; x <= 7; ++x)
        for(int y = 0; y <= 5; ++y)
            t.insert(build_interval_tree_entry(x, y), value);

    // then
    EXPECT_EQ(48, t.count(build_interval_tree_range(subrange_type(0, 7), subrange_type(0, 5))));

    for(int x = 0; x <= 7; ++x)
        for(int y = 0; y <= 5; ++y)
            EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(x, x), subrange_type(y, y))));
}


} // namespace testing
} // namespace pk
