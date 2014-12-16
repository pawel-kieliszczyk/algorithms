#include <gtest/gtest.h>

#include "interval_tree_2d.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct interval_tree_2d_tester : public gt::Test
{
    static const int RANGE_1 = 8;
    static const int RANGE_2 = 6;

    typedef pk::interval_tree_2d<RANGE_1, RANGE_2> interval_tree_type;
    typedef interval_tree_type::entry_type entry_type;
    typedef interval_tree_type::range_type range_type;

    // tested class:
    interval_tree_type t; // accepts points from [0, RANGE_1 - 1] x [0, RANGE_2 - 1]
};


TEST_F(interval_tree_2d_tester, tests_empty_tree)
{
    // when and then
    EXPECT_EQ(0, t.count(range_type(0, 7), range_type(0, 5)));
}


TEST_F(interval_tree_2d_tester, tests_one_point_once_in_tree)
{
    // given
    const entry_type e(3, 2);

    // when
    t.insert(e);

    // then
    EXPECT_EQ(1, t.count(range_type(0, 7), range_type(0, 5)));

    EXPECT_EQ(0, t.count(range_type(0, 2), range_type(0, 5)));
    EXPECT_EQ(0, t.count(range_type(4, 7), range_type(0, 5)));

    EXPECT_EQ(0, t.count(range_type(0, 7), range_type(0, 1)));
    EXPECT_EQ(0, t.count(range_type(0, 7), range_type(3, 5)));

    EXPECT_EQ(1, t.count(range_type(3, 3), range_type(2, 2)));
}


TEST_F(interval_tree_2d_tester, tests_one_point_twice_in_tree)
{
    // given
    const entry_type e(3, 2);

    // when
    t.insert(e);
    t.insert(e);

    // then
    EXPECT_EQ(2, t.count(range_type(0, 7), range_type(0, 5)));

    EXPECT_EQ(0, t.count(range_type(0, 2), range_type(0, 5)));
    EXPECT_EQ(0, t.count(range_type(4, 7), range_type(0, 5)));

    EXPECT_EQ(0, t.count(range_type(0, 7), range_type(0, 1)));
    EXPECT_EQ(0, t.count(range_type(0, 7), range_type(3, 5)));

    EXPECT_EQ(2, t.count(range_type(3, 3), range_type(2, 2)));
}


TEST_F(interval_tree_2d_tester, tests_two_points_once_in_tree)
{
    // given
    const entry_type e1(3, 2);
    const entry_type e2(5, 4);

    // when
    t.insert(e1);
    t.insert(e2);

    // then
    EXPECT_EQ(2, t.count(range_type(0, 7), range_type(0, 5)));

    EXPECT_EQ(0, t.count(range_type(0, 2), range_type(0, 5)));
    EXPECT_EQ(0, t.count(range_type(4, 4), range_type(0, 5)));
    EXPECT_EQ(0, t.count(range_type(6, 7), range_type(0, 5)));

    EXPECT_EQ(0, t.count(range_type(0, 7), range_type(0, 1)));
    EXPECT_EQ(0, t.count(range_type(0, 7), range_type(3, 3)));
    EXPECT_EQ(0, t.count(range_type(0, 7), range_type(5, 5)));

    EXPECT_EQ(1, t.count(range_type(3, 3), range_type(2, 2)));
    EXPECT_EQ(1, t.count(range_type(5, 5), range_type(4, 4)));
}


TEST_F(interval_tree_2d_tester, tests_two_points_twice_in_tree)
{
    // given
    const entry_type e1(0, 0);
    const entry_type e2(7, 5);

    // when
    t.insert(e1);
    t.insert(e1);

    t.insert(e2);
    t.insert(e2);

    // then
    EXPECT_EQ(4, t.count(range_type(0, 7), range_type(0, 5)));

    EXPECT_EQ(0, t.count(range_type(1, 6), range_type(0, 5)));
    EXPECT_EQ(0, t.count(range_type(0, 7), range_type(1, 4)));

    EXPECT_EQ(2, t.count(range_type(0, 0), range_type(0, 0)));
    EXPECT_EQ(2, t.count(range_type(7, 7), range_type(5, 5)));
}


TEST_F(interval_tree_2d_tester, tests_all_points_once_in_tree)
{
    // when
    for(int x = 0; x <= 7; ++x)
        for(int y = 0; y <= 5; ++y)
            t.insert(entry_type(x, y));

    // then
    EXPECT_EQ(48, t.count(range_type(0, 7), range_type(0, 5)));

    for(int x = 0; x <= 7; ++x)
        for(int y = 0; y <= 5; ++y)
            EXPECT_EQ(1, t.count(range_type(x, x), range_type(y, y)));
}


} // namespace testing
} // namespace pk
