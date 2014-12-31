#include <gtest/gtest.h>

#include "binary_indexed_tree.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct binary_indexed_tree_tester : public gt::Test
{
    static const int RANGE = 20;

    // tested class:
    binary_indexed_tree<int, RANGE> t; // accepts entries from [0, RANGE-1]
};


TEST_F(binary_indexed_tree_tester, tests_empty_tree)
{
    // when and then
    EXPECT_EQ(0, t.count_less_equal(19));

    EXPECT_EQ(0, t.count_in_range(0, 19));
}


TEST_F(binary_indexed_tree_tester, tests_one_element_once_in_tree)
{
    // given
    const int elem = 7;
    const int value = 1;

    // when
    t.increase(elem, value);

    // then
    EXPECT_EQ(0, t.count_less_equal(6));
    EXPECT_EQ(1, t.count_less_equal(7));
    EXPECT_EQ(1, t.count_less_equal(19));

    EXPECT_EQ(0, t.count_in_range(0, 6));
    EXPECT_EQ(1, t.count_in_range(7, 7));
    EXPECT_EQ(0, t.count_in_range(8, 19));

    EXPECT_EQ(1, t.count_in_range(0, 19));
}


TEST_F(binary_indexed_tree_tester, tests_one_element_twice_in_tree)
{
    // given
    const int elem = 7;
    const int value1 = 2;
    const int value2 = 3;

    // when
    t.increase(elem, value1);
    t.increase(elem, value2);

    // then
    EXPECT_EQ(0, t.count_less_equal(6));
    EXPECT_EQ(5, t.count_less_equal(7));
    EXPECT_EQ(5, t.count_less_equal(19));

    EXPECT_EQ(0, t.count_in_range(0, 6));
    EXPECT_EQ(5, t.count_in_range(7, 7));
    EXPECT_EQ(0, t.count_in_range(8, 19));

    EXPECT_EQ(5, t.count_in_range(0, 19));
}


TEST_F(binary_indexed_tree_tester, tests_two_elements_once_in_tree)
{
    // given
    const int elem1 = 0;
    const int elem2 = 7;

    const int value1 = 2;
    const int value2 = 3;

    // when
    t.increase(elem1, value1);
    t.increase(elem2, value2);

    // then
    EXPECT_EQ(2, t.count_less_equal(0));
    EXPECT_EQ(2, t.count_less_equal(6));
    EXPECT_EQ(5, t.count_less_equal(7));
    EXPECT_EQ(5, t.count_less_equal(19));

    EXPECT_EQ(2, t.count_in_range(0, 0));
    EXPECT_EQ(0, t.count_in_range(1, 6));
    EXPECT_EQ(3, t.count_in_range(7, 7));
    EXPECT_EQ(0, t.count_in_range(8, 19));

    EXPECT_EQ(5, t.count_in_range(0, 19));
}


TEST_F(binary_indexed_tree_tester, tests_two_elements_twice_in_tree)
{
    // given
    const int elem1 = 7;
    const int elem2 = 19;

    const int value1 = 2;
    const int value2 = 3;

    // when
    t.increase(elem1, value1);
    t.increase(elem1, value1);
    t.increase(elem2, value2);
    t.increase(elem2, value2);

    // then
    EXPECT_EQ(0, t.count_less_equal(6));
    EXPECT_EQ(4, t.count_less_equal(7));
    EXPECT_EQ(4, t.count_less_equal(18));
    EXPECT_EQ(10, t.count_less_equal(19));

    EXPECT_EQ(0, t.count_in_range(0, 6));
    EXPECT_EQ(4, t.count_in_range(7, 7));
    EXPECT_EQ(0, t.count_in_range(8, 18));
    EXPECT_EQ(6, t.count_in_range(19, 19));

    EXPECT_EQ(10, t.count_in_range(0, 19));
}


TEST_F(binary_indexed_tree_tester, tests_setting_elements)
{
    // given
    const int elem = 7;
    const int old_value = 1337;
    const int new_value = 42;

    t.increase(elem, old_value);

    // when
    t.set(elem, new_value);

    // then
    EXPECT_EQ(0, t.count_less_equal(6));
    EXPECT_EQ(42, t.count_less_equal(7));
    EXPECT_EQ(42, t.count_less_equal(19));

    EXPECT_EQ(0, t.count_in_range(0, 6));
    EXPECT_EQ(42, t.count_in_range(7, 7));
    EXPECT_EQ(0, t.count_in_range(8, 19));

    EXPECT_EQ(42, t.count_in_range(0, 19));
}


} // namespace testing
} // namespace pk
