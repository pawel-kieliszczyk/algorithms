#include <gtest/gtest.h>

#include "interval_tree.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct interval_tree_testing : public gt::Test
{
    static const int RANGE = 100;

    // tested class:
    pk::interval_tree<RANGE> t; // accepts points from [0, 99]
};


TEST_F(interval_tree_testing, tests_empty_tree)
{
    // when and then
    EXPECT_EQ(0, t.count(0, 99));
}


} // namespace testing
} // namespace pk
