#include <gtest/gtest.h>

#include "interval_tree.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct interval_tree_tester : public gt::Test
{
    static const int RANGE = 8;

    typedef pk::interval_tree<int, RANGE> interval_tree_type;
    typedef interval_tree_type::entry_type entry_type;
    typedef interval_tree_type::range_type range_type;
    typedef interval_tree_type::subrange_type subrange_type;

    // tested class:
    interval_tree_type t; // accepts values from [0, RANGE-1]
};


TEST_F(interval_tree_tester, tests_empty_tree)
{
    // when and then
    range_type range = build_interval_tree_range(subrange_type(0, 7));
    EXPECT_EQ(0, t.count(range));
}


TEST_F(interval_tree_tester, tests_one_point_once_in_tree)
{
    // given
    const entry_type entry = build_interval_tree_entry(3);
    const int value = 1;

    // when
    t.insert(entry, value);

    // then
    EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(0, 7))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 2))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(4, 7))));

    EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(3, 3))));
}


TEST_F(interval_tree_tester, tests_one_point_twice_in_tree)
{
    // given
    const entry_type entry = build_interval_tree_entry(3);
    const int value = 1;

    // when
    t.insert(entry, value);
    t.insert(entry, value);

    // then
    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(0, 7))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 2))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(4, 7))));

    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(3, 3))));
}


TEST_F(interval_tree_tester, tests_two_points_once_in_tree)
{
    // given
    const entry_type entry1 = build_interval_tree_entry(3);
    const entry_type entry2 = build_interval_tree_entry(5);
    const int value = 1;

    // when
    t.insert(entry1, value);
    t.insert(entry2, value);

    // then
    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(0, 7))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 2))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(4, 4))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(6, 7))));

    EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(3, 3))));
    EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(5, 5))));
}


TEST_F(interval_tree_tester, tests_two_points_twice_in_tree)
{
    // given
    const entry_type entry1 = build_interval_tree_entry(3);
    const entry_type entry2 = build_interval_tree_entry(5);
    const int value = 2;

    // when
    t.insert(entry1, value);
    t.insert(entry2, value);

    // then
    EXPECT_EQ(4, t.count(build_interval_tree_range(subrange_type(0, 7))));

    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(0, 2))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(4, 4))));
    EXPECT_EQ(0, t.count(build_interval_tree_range(subrange_type(6, 7))));

    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(3, 3))));
    EXPECT_EQ(2, t.count(build_interval_tree_range(subrange_type(5, 5))));
}


TEST_F(interval_tree_tester, tests_all_points_once_in_tree)
{
    // given
    const int value = 1;

    // when
    for(int x = 0; x <= 7; ++x)
        t.insert(build_interval_tree_entry(x), value);

    // then
    EXPECT_EQ(8, t.count(build_interval_tree_range(subrange_type(0, 7))));

    for(int x = 0; x <= 7; ++x)
        EXPECT_EQ(1, t.count(build_interval_tree_range(subrange_type(x, x))));
}


} // namespace testing
} // namespace pk
