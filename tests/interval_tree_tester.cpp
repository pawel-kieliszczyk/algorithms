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

    // tested class:
    pk::interval_tree<RANGE> t; // accepts values from [0, RANGE-1]
};


TEST_F(interval_tree_tester, tests_empty_tree)
{
    // when and then
    EXPECT_EQ(0, t.count(0, 7));
}


TEST_F(interval_tree_tester, tests_one_point_once_in_tree)
{
    // given
    const int x = 3;

    // when
    t.insert(x);

    // then
    EXPECT_EQ(1, t.count(0, 7));
    EXPECT_EQ(0, t.count(0, 2));
    EXPECT_EQ(1, t.count(3, 3));
    EXPECT_EQ(0, t.count(4, 7));
}


TEST_F(interval_tree_tester, tests_one_point_twice_in_tree)
{
    // given
    const int x = 3;

    // when
    t.insert(x);
    t.insert(x);

    // then
    EXPECT_EQ(2, t.count(0, 7));
    EXPECT_EQ(0, t.count(0, 2));
    EXPECT_EQ(2, t.count(3, 3));
    EXPECT_EQ(0, t.count(4, 7));
}


TEST_F(interval_tree_tester, tests_two_points_once_in_tree)
{
    // given
    const int x1 = 3;
    const int x2 = 5;

    // when
    t.insert(x1);
    t.insert(x2);

    // then
    EXPECT_EQ(2, t.count(0, 7));
    EXPECT_EQ(0, t.count(0, 2));
    EXPECT_EQ(1, t.count(3, 3));
    EXPECT_EQ(0, t.count(4, 4));
    EXPECT_EQ(1, t.count(5, 5));
    EXPECT_EQ(0, t.count(6, 7));

    EXPECT_EQ(2, t.count(3, 5));
}


TEST_F(interval_tree_tester, tests_two_points_twice_in_tree)
{
    // given
    const int x1 = 0;
    const int x2 = 7;

    // when
    t.insert(x1);
    t.insert(x1);

    t.insert(x2);
    t.insert(x2);

    // then
    EXPECT_EQ(4, t.count(0, 7));
    EXPECT_EQ(2, t.count(0, 0));
    EXPECT_EQ(0, t.count(1, 6));
    EXPECT_EQ(2, t.count(7, 7));
}


TEST_F(interval_tree_tester, tests_all_points_once_in_tree)
{
    // when
    for(int x = 0; x <= 7; ++x)
        t.insert(x);

    // then
    EXPECT_EQ(8, t.count(0, 7));
    EXPECT_EQ(1, t.count(0, 0));
    EXPECT_EQ(1, t.count(1, 1));
    EXPECT_EQ(1, t.count(2, 2));
    EXPECT_EQ(1, t.count(3, 3));
    EXPECT_EQ(1, t.count(4, 4));
    EXPECT_EQ(1, t.count(5, 5));
    EXPECT_EQ(1, t.count(6, 6));
    EXPECT_EQ(1, t.count(7, 7));
}


} // namespace testing
} // namespace pk
