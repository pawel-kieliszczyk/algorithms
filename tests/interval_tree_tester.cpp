#include <gtest/gtest.h>

#include "interval_tree.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct interval_tree_testing : public gt::Test
{
    static const int RANGE = 8;

    // tested class:
    pk::interval_tree<RANGE> t; // accepts points from [0, RANGE-1]
};


TEST_F(interval_tree_testing, tests_empty_tree)
{
    // when and then
    EXPECT_EQ(0, t.count(0, 7));
}


TEST_F(interval_tree_testing, tests_one_point_once_in_tree)
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


TEST_F(interval_tree_testing, tests_one_point_twice_in_tree)
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


TEST_F(interval_tree_testing, tests_two_points_once_in_tree)
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


TEST_F(interval_tree_testing, tests_two_points_twice_in_tree)
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


} // namespace testing
} // namespace pk
