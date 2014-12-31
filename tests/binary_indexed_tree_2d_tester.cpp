#include <gtest/gtest.h>

#include "binary_indexed_tree_2d.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct binary_indexed_tree_2d_tester : public gt::Test
{
    static const int RANGE_1 = 20;
    static const int RANGE_2 = 30;

    binary_indexed_tree_2d_tester() : t(RANGE_1, RANGE_2) {}

    // tested class:
    typedef binary_indexed_tree_2d<int, RANGE_1, RANGE_2> bit; // accepts entries from [0, RANGE_1-1] x [0, RANGE_2-1]
    bit t;
};


TEST_F(binary_indexed_tree_2d_tester, tests_empty_tree)
{
    // when and then
    EXPECT_EQ(0, t.count_less_equal(19, 29));

    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 19), bit::subrange(0, 29)));
}


TEST_F(binary_indexed_tree_2d_tester, tests_one_element_once_in_tree)
{
    // given
    const int x = 7;
    const int y = 13;

    const int value = 1;

    // when
    t.increase(bit::entry(x, y), value);

    // then
    EXPECT_EQ(0, t.count_less_equal(6, 29));
    EXPECT_EQ(0, t.count_less_equal(19, 12));

    EXPECT_EQ(1, t.count_less_equal(7, 13));
    EXPECT_EQ(1, t.count_less_equal(19, 29));

    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 6), bit::subrange(0, 29)));
    EXPECT_EQ(0, t.count_in_range(bit::subrange(8, 19), bit::subrange(0, 29)));

    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 19), bit::subrange(0, 12)));
    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 19), bit::subrange(14, 29)));

    EXPECT_EQ(1, t.count_in_range(bit::subrange(7, 7), bit::subrange(13, 13)));

    EXPECT_EQ(1, t.count_in_range(bit::subrange(0, 19), bit::subrange(0, 29)));
}


TEST_F(binary_indexed_tree_2d_tester, tests_one_element_twice_in_tree)
{
    // given
    const int x = 7;
    const int y = 13;

    const int value = 2;

    // when
    t.increase(bit::entry(x, y), value);
    t.increase(bit::entry(x, y), value);

    // then
    EXPECT_EQ(0, t.count_less_equal(6, 29));
    EXPECT_EQ(0, t.count_less_equal(19, 12));

    EXPECT_EQ(4, t.count_less_equal(7, 13));
    EXPECT_EQ(4, t.count_less_equal(19, 29));

    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 6), bit::subrange(0, 29)));
    EXPECT_EQ(0, t.count_in_range(bit::subrange(8, 19), bit::subrange(0, 29)));

    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 19), bit::subrange(0, 12)));
    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 19), bit::subrange(14, 29)));

    EXPECT_EQ(4, t.count_in_range(bit::subrange(7, 7), bit::subrange(13, 13)));

    EXPECT_EQ(4, t.count_in_range(bit::subrange(0, 19), bit::subrange(0, 29)));
}


TEST_F(binary_indexed_tree_2d_tester, tests_two_elements_once_in_tree)
{
    // given
    const int x1 = 0;
    const int y1 = 0;

    const int x2 = 7;
    const int y2 = 13;

    const int value1 = 2;
    const int value2 = 3;

    // when
    t.increase(bit::entry(x1, y1), value1);
    t.increase(bit::entry(x2, y2), value2);

    // then
    EXPECT_EQ(2, t.count_less_equal(0, 0));
    EXPECT_EQ(5, t.count_less_equal(7, 13));
    EXPECT_EQ(5, t.count_less_equal(19, 29));

    EXPECT_EQ(2, t.count_in_range(bit::subrange(0, 0), bit::subrange(0, 29)));
    EXPECT_EQ(0, t.count_in_range(bit::subrange(1, 6), bit::subrange(0, 29)));
    EXPECT_EQ(3, t.count_in_range(bit::subrange(7, 7), bit::subrange(0, 29)));
    EXPECT_EQ(0, t.count_in_range(bit::subrange(8, 19), bit::subrange(0, 29)));

    EXPECT_EQ(2, t.count_in_range(bit::subrange(0, 19), bit::subrange(0, 0)));
    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 19), bit::subrange(1, 12)));
    EXPECT_EQ(3, t.count_in_range(bit::subrange(0, 19), bit::subrange(13, 13)));
    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 19), bit::subrange(15, 29)));

    EXPECT_EQ(2, t.count_in_range(bit::subrange(0, 0), bit::subrange(0, 0)));
    EXPECT_EQ(3, t.count_in_range(bit::subrange(7, 7), bit::subrange(13, 13)));

    EXPECT_EQ(5, t.count_in_range(bit::subrange(0, 7), bit::subrange(0, 13)));

    EXPECT_EQ(5, t.count_in_range(bit::subrange(0, 19), bit::subrange(0, 29)));
}


TEST_F(binary_indexed_tree_2d_tester, tests_setting_elements)
{
    // given
    const int x = 7;
    const int y = 13;

    const int old_value = 42;
    const int new_value = 1;

    t.increase(bit::entry(x, y), old_value);

    // when
    t.set(bit::entry(x, y), new_value);

    // then
    EXPECT_EQ(0, t.count_less_equal(6, 29));
    EXPECT_EQ(0, t.count_less_equal(19, 12));

    EXPECT_EQ(1, t.count_less_equal(7, 13));
    EXPECT_EQ(1, t.count_less_equal(19, 29));

    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 6), bit::subrange(0, 29)));
    EXPECT_EQ(0, t.count_in_range(bit::subrange(8, 19), bit::subrange(0, 29)));

    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 19), bit::subrange(0, 12)));
    EXPECT_EQ(0, t.count_in_range(bit::subrange(0, 19), bit::subrange(14, 29)));

    EXPECT_EQ(1, t.count_in_range(bit::subrange(7, 7), bit::subrange(13, 13)));

    EXPECT_EQ(1, t.count_in_range(bit::subrange(0, 19), bit::subrange(0, 29)));
}


} // namespace testing
} // namespace pk
