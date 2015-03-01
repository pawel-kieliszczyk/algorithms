#include <gtest/gtest.h>

#include "red_black_tree.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct red_black_tree_tester : public gt::Test
{
    static const int MAX_SIZE = 20;

    // tested class:
    red_black_tree<int, MAX_SIZE> rbt;
};


TEST_F(red_black_tree_tester, tests_emptyness_of_empty_tree)
{
    // when and then
    EXPECT_TRUE(rbt.empty());
}


TEST_F(red_black_tree_tester, tests_emptyness_of_non_empty_tree)
{
    // given
    const int elem = 11;

    // when
    rbt.insert(elem);

    // then
    EXPECT_FALSE(rbt.empty());
}


TEST_F(red_black_tree_tester, tests_size_of_empty_tree)
{
    // when and then
    EXPECT_EQ(0, rbt.size());
}


TEST_F(red_black_tree_tester, tests_size_of_non_empty_tree)
{
    // given
    const int elem1 = 11;
    const int elem2 = 22;
    const int elem3 = 33;

    // when
    rbt.insert(elem1);
    rbt.insert(elem2);
    rbt.insert(elem3);

    // then
    EXPECT_EQ(3, rbt.size());
}


} // namespace testing
} // namespace pk
