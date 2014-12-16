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
    typedef interval_tree_type::range_type range_type;

    // tested class:
    interval_tree_type t; // accepts points from [0, RANGE_1 - 1] x [0, RANGE_2 - 1]
};


TEST_F(interval_tree_2d_tester, tests_empty_tree)
{
    // when and then
    EXPECT_EQ(0, t.count(range_type(0, 7), range_type(0, 5)));
}


} // namespace testing
} // namespace pk
