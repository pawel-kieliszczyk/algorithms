#include <gtest/gtest.h>

#include "binary_search_tree.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct binary_search_tree_tester : public gt::Test
{
    static const int MAX_SIZE = 20;

    // tested class:
    binary_search_tree<int, MAX_SIZE> bst;
};


TEST_F(binary_search_tree_tester, tests_size_of_empty_tree)
{
    // when and then
    EXPECT_EQ(0, bst.size());
}


TEST_F(binary_search_tree_tester, tests_size_of_non_empty_tree)
{
    // given
    const int elem1 = 11;
    const int elem2 = 22;
    const int elem3 = 33;

    // when
    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);

    // then
    EXPECT_EQ(3, bst.size());
}


TEST_F(binary_search_tree_tester, tests_existing_elements)
{
    // given
    const int elem1 = 11;
    const int elem2 = 33;
    const int elem3 = 22;

    // when
    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);

    // then
    EXPECT_TRUE(bst.exists(elem1));
    EXPECT_TRUE(bst.exists(elem2));
    EXPECT_TRUE(bst.exists(elem3));
}


TEST_F(binary_search_tree_tester, tests_non_existing_elements)
{
    // given
    const int elem1 = 11;
    const int elem2 = 33;
    const int elem3 = 22;

    const int elem4 = 44;
    const int elem5 = 55;

    // when
    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);

    // then
    EXPECT_FALSE(bst.exists(elem4));
    EXPECT_FALSE(bst.exists(elem5));
}


TEST_F(binary_search_tree_tester, tests_elements_discinction)
{
    // given
    const int elem1 = 11;
    const int elem2 = elem1;

    // when
    bst.insert(elem1);
    bst.insert(elem2);

    // then
    EXPECT_EQ(1, bst.size());
}


TEST_F(binary_search_tree_tester, tests_min_element)
{
    // given
    const int elem1 = -10;
    const int elem2 = 13;
    const int elem3 = -29;
    const int elem4 = 0;

    // when
    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);
    bst.insert(elem4);

    //then
    EXPECT_EQ(-29, bst.min());
}


TEST_F(binary_search_tree_tester, tests_max_element_in_non_empty_tree)
{
    // given
    const int elem1 = -10;
    const int elem2 = 13;
    const int elem3 = -29;
    const int elem4 = 0;

    // when
    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);
    bst.insert(elem4);

    //then
    EXPECT_EQ(13, bst.max());
}


/**
 * Removes 11 from:
 *    (22)
 *    /
 * (11)
 */
TEST_F(binary_search_tree_tester, tests_removing_left_child_leaf)
{
    // given
    const int elem1 = 22;
    const int elem2 = 11;

    bst.insert(elem1);
    bst.insert(elem2);

    // when
    bst.remove(elem2);

    // then
    EXPECT_EQ(1, bst.size());

    EXPECT_TRUE(bst.exists(elem1));
    EXPECT_FALSE(bst.exists(elem2));
}


/**
 * Removes 22 from:
 * (11)
 *    \
 *    (22)
 */
TEST_F(binary_search_tree_tester, tests_removing_right_child_leaf)
{
    // given
    const int elem1 = 11;
    const int elem2 = 22;

    bst.insert(elem1);
    bst.insert(elem2);

    // when
    bst.remove(elem2);

    // then
    EXPECT_EQ(1, bst.size());

    EXPECT_TRUE(bst.exists(elem1));
    EXPECT_FALSE(bst.exists(elem2));
}


/**
 * Removes 42 from:
 * (42)
 */
TEST_F(binary_search_tree_tester, tests_removing_root_leaf)
{
    // given
    const int elem = 42;

    bst.insert(elem);

    // when
    bst.remove(elem);

    // then
    EXPECT_EQ(0, bst.size());
    EXPECT_FALSE(bst.exists(elem));
}


/**
 * Removes 22 from:
 *       (33)
 *       /
 *    (22)
 *    /
 * (11)
 */
TEST_F(binary_search_tree_tester, tests_removing_left_child_with_left_child)
{
    // given
    const int elem1 = 33;
    const int elem2 = 22;
    const int elem3 = 11;

    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);

    // when
    bst.remove(elem2);

    // then
    EXPECT_EQ(2, bst.size());

    EXPECT_TRUE(bst.exists(elem1));
    EXPECT_FALSE(bst.exists(elem2));
    EXPECT_TRUE(bst.exists(elem3));
}


/**
 * Removes 11 from:
 *    (33)
 *    /
 * (11)
 *    \
 *    (22)
 */
TEST_F(binary_search_tree_tester, tests_removing_left_child_with_right_child)
{
    // given
    const int elem1 = 33;
    const int elem2 = 11;
    const int elem3 = 22;

    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);

    // when
    bst.remove(elem2);

    // then
    EXPECT_EQ(2, bst.size());

    EXPECT_TRUE(bst.exists(elem1));
    EXPECT_FALSE(bst.exists(elem2));
    EXPECT_TRUE(bst.exists(elem3));
}


/**
 * Removes 33 from:
 * (11)
 *    \
 *    (33)
 *    /
 * (22)
 */
TEST_F(binary_search_tree_tester, tests_removing_right_child_with_left_child)
{
    // given
    const int elem1 = 11;
    const int elem2 = 33;
    const int elem3 = 22;

    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);

    // when
    bst.remove(elem2);

    // then
    EXPECT_EQ(2, bst.size());

    EXPECT_TRUE(bst.exists(elem1));
    EXPECT_FALSE(bst.exists(elem2));
    EXPECT_TRUE(bst.exists(elem3));
}


/**
 * Removes 11 from:
 * (11)
 *    \
 *    (22)
 *       \
 *       (33)
 */
TEST_F(binary_search_tree_tester, tests_removing_right_child_with_right_child)
{
    // given
    const int elem1 = 11;
    const int elem2 = 22;
    const int elem3 = 33;

    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);

    // when
    bst.remove(elem2);

    // then
    EXPECT_EQ(2, bst.size());

    EXPECT_TRUE(bst.exists(elem1));
    EXPECT_FALSE(bst.exists(elem2));
    EXPECT_TRUE(bst.exists(elem3));
}


/**
 * Removes 22 from:
 *    (22)
 *    /
 * (11)
 */
TEST_F(binary_search_tree_tester, tests_removing_root_with_left_child)
{
    // given
    const int elem1 = 22;
    const int elem2 = 11;

    bst.insert(elem1);
    bst.insert(elem2);

    // when
    bst.remove(elem1);

    // then
    EXPECT_EQ(1, bst.size());

    EXPECT_FALSE(bst.exists(elem1));
    EXPECT_TRUE(bst.exists(elem2));
}


/**
 * Removes 11 from:
 * (11)
 *    \
 *    (22)
 */
TEST_F(binary_search_tree_tester, tests_removing_root_with_right_child)
{
    // given
    const int elem1 = 11;
    const int elem2 = 22;

    bst.insert(elem1);
    bst.insert(elem2);

    // when
    bst.remove(elem1);

    // then
    EXPECT_EQ(1, bst.size());

    EXPECT_FALSE(bst.exists(elem1));
    EXPECT_TRUE(bst.exists(elem2));
}


/**
 * Removes 33 from:
 * (11)
 *    \
 *    (33)
 *    /  \
 * (22)  (55)
 *       /
 *    (44)
 */
TEST_F(binary_search_tree_tester, tests_removing_node_with_two_childs)
{
    // given
    const int elem1 = 11;
    const int elem2 = 33;
    const int elem3 = 22;
    const int elem4 = 55;
    const int elem5 = 44;

    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);
    bst.insert(elem4);
    bst.insert(elem5);

    // when
    bst.remove(elem3);

    // then
    EXPECT_EQ(4, bst.size());

    EXPECT_TRUE(bst.exists(elem1));
    EXPECT_TRUE(bst.exists(elem2));
    EXPECT_FALSE(bst.exists(elem3));
    EXPECT_TRUE(bst.exists(elem4));
    EXPECT_TRUE(bst.exists(elem5));
}


/**
 * Removes 22 from:
 *    (22)
 *    /  \
 * (11)  (33)
 */
TEST_F(binary_search_tree_tester, tests_removing_root_with_two_childs)
{
    // given
    const int elem1 = 22;
    const int elem2 = 11;
    const int elem3 = 33;

    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);

    // when
    bst.remove(elem1);

    // then
    EXPECT_EQ(2, bst.size());

    EXPECT_FALSE(bst.exists(elem1));
    EXPECT_TRUE(bst.exists(elem2));
    EXPECT_TRUE(bst.exists(elem3));
}


/**
 * Removes all nodes in sequence (5, 3, 6, 7, 1, 4, 2, 8, 9):
 *       (5)
 *      /   \
 *   (3)     (7)
 *   / \     / \
 * (1) (4) (6) (9)
 *   \         /
 *   (2)     (8)
 */
TEST_F(binary_search_tree_tester, tests_removing_many_nodes)
{
    // given
    const int elem1 = 5;
    const int elem2 = 3;
    const int elem3 = 1;
    const int elem4 = 2;
    const int elem5 = 4;
    const int elem6 = 7;
    const int elem7 = 6;
    const int elem8 = 9;
    const int elem9 = 8;

    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);
    bst.insert(elem4);
    bst.insert(elem5);
    bst.insert(elem6);
    bst.insert(elem7);
    bst.insert(elem8);
    bst.insert(elem9);

    // when
    bst.remove(elem1);

    // then
    EXPECT_EQ(8, bst.size());

    EXPECT_FALSE(bst.exists(elem1));
    EXPECT_TRUE(bst.exists(elem2));
    EXPECT_TRUE(bst.exists(elem3));
    EXPECT_TRUE(bst.exists(elem4));
    EXPECT_TRUE(bst.exists(elem5));
    EXPECT_TRUE(bst.exists(elem6));
    EXPECT_TRUE(bst.exists(elem7));
    EXPECT_TRUE(bst.exists(elem8));
    EXPECT_TRUE(bst.exists(elem9));

    // when
    bst.remove(elem2);

    // then
    EXPECT_EQ(7, bst.size());

    EXPECT_FALSE(bst.exists(elem2));
    EXPECT_TRUE(bst.exists(elem3));
    EXPECT_TRUE(bst.exists(elem4));
    EXPECT_TRUE(bst.exists(elem5));
    EXPECT_TRUE(bst.exists(elem6));
    EXPECT_TRUE(bst.exists(elem7));
    EXPECT_TRUE(bst.exists(elem8));
    EXPECT_TRUE(bst.exists(elem9));

    // when
    bst.remove(elem7);

    // then
    EXPECT_EQ(6, bst.size());

    EXPECT_TRUE(bst.exists(elem3));
    EXPECT_TRUE(bst.exists(elem4));
    EXPECT_TRUE(bst.exists(elem5));
    EXPECT_TRUE(bst.exists(elem6));
    EXPECT_FALSE(bst.exists(elem7));
    EXPECT_TRUE(bst.exists(elem8));
    EXPECT_TRUE(bst.exists(elem9));

    // when
    bst.remove(elem6);

    // then
    EXPECT_EQ(5, bst.size());

    EXPECT_TRUE(bst.exists(elem3));
    EXPECT_TRUE(bst.exists(elem4));
    EXPECT_TRUE(bst.exists(elem5));
    EXPECT_FALSE(bst.exists(elem6));
    EXPECT_TRUE(bst.exists(elem8));
    EXPECT_TRUE(bst.exists(elem9));

    // when
    bst.remove(elem3);

    // then
    EXPECT_EQ(4, bst.size());

    EXPECT_FALSE(bst.exists(elem3));
    EXPECT_TRUE(bst.exists(elem4));
    EXPECT_TRUE(bst.exists(elem5));
    EXPECT_TRUE(bst.exists(elem8));
    EXPECT_TRUE(bst.exists(elem9));

    // when
    bst.remove(elem5);

    // then
    EXPECT_EQ(3, bst.size());

    EXPECT_TRUE(bst.exists(elem4));
    EXPECT_FALSE(bst.exists(elem5));
    EXPECT_TRUE(bst.exists(elem8));
    EXPECT_TRUE(bst.exists(elem9));

    // when
    bst.remove(elem4);

    // then
    EXPECT_EQ(2, bst.size());

    EXPECT_FALSE(bst.exists(elem4));
    EXPECT_TRUE(bst.exists(elem8));
    EXPECT_TRUE(bst.exists(elem9));

    // when
    bst.remove(elem9);

    // then
    EXPECT_EQ(1, bst.size());

    EXPECT_TRUE(bst.exists(elem8));
    EXPECT_FALSE(bst.exists(elem9));

    // when
    bst.remove(elem8);

    // then
    EXPECT_EQ(0, bst.size());

    EXPECT_FALSE(bst.exists(elem8));
}


} // namespace testing
} // namespace pk
