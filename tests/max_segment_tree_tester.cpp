#include <vector>

#include <gtest/gtest.h>

#include "max_segment_tree.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct max_segment_tree_tester : public gt::Test
{
    static const int TREE_RANGE_LIMIT = 100;
    
    // tested class
    max_segment_tree<int, TREE_RANGE_LIMIT> tree;
};


TEST_F(max_segment_tree_tester, tests_empty_tree)
{
    // when & then
    EXPECT_EQ(0, tree.get_max(0, TREE_RANGE_LIMIT-1));
}


TEST_F(max_segment_tree_tester, tests_tree_with_single_segment_inserted)
{
    // when
    tree.update(3/*from*/, 5/*to*/, 1/*value*/);

    // then
    EXPECT_EQ(0, tree.get_max(0/*from*/, 2/*to*/));

    EXPECT_EQ(1, tree.get_max(3, 3));
    EXPECT_EQ(1, tree.get_max(4, 4));
    EXPECT_EQ(1, tree.get_max(5, 5));
    EXPECT_EQ(1, tree.get_max(3, 5));

    EXPECT_EQ(0, tree.get_max(6, TREE_RANGE_LIMIT-1));
}


TEST_F(max_segment_tree_tester, tests_tree_with_two_overlapping_segments_inserted)
{
    // when
    tree.update(3/*from*/, 5/*to*/, 1/*value*/);
    tree.update(4, 6, 2);

    // then
    EXPECT_EQ(0, tree.get_max(0/*from*/, 2/*to*/));

    EXPECT_EQ(1, tree.get_max(3, 3));
    EXPECT_EQ(3, tree.get_max(4, 4));
    EXPECT_EQ(3, tree.get_max(5, 5));
    EXPECT_EQ(2, tree.get_max(6, 6));
    EXPECT_EQ(3, tree.get_max(3, 6));

    EXPECT_EQ(0, tree.get_max(7, TREE_RANGE_LIMIT-1));
}


TEST_F(max_segment_tree_tester, tests_tree_with_two_not_overlapping_segments_inserted)
{
    // when
    tree.update(3/*from*/, 5/*to*/, 1/*value*/);
    tree.update(7, 9, 2);

    // then
    EXPECT_EQ(0, tree.get_max(0/*from*/, 2/*to*/));

    EXPECT_EQ(1, tree.get_max(3, 3));
    EXPECT_EQ(1, tree.get_max(4, 4));
    EXPECT_EQ(1, tree.get_max(5, 5));
    EXPECT_EQ(0, tree.get_max(6, 6));
    EXPECT_EQ(2, tree.get_max(7, 7));
    EXPECT_EQ(2, tree.get_max(8, 8));
    EXPECT_EQ(2, tree.get_max(9, 9));
    EXPECT_EQ(2, tree.get_max(3, 9));

    EXPECT_EQ(0, tree.get_max(10, TREE_RANGE_LIMIT-1));
}


} // namespace testing
} // namespace pk
