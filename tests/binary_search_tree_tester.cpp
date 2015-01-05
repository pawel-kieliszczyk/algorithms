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


TEST_F(binary_search_tree_tester, tests_searching_existing_elements)
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
    const int* found_elem1 = bst.search(elem1);
    const int* found_elem2 = bst.search(elem2);
    const int* found_elem3 = bst.search(elem3);

    ASSERT_NE(reinterpret_cast<const int*>(0), found_elem1);
    ASSERT_NE(reinterpret_cast<const int*>(0), found_elem2);
    ASSERT_NE(reinterpret_cast<const int*>(0), found_elem3);

    EXPECT_EQ(11, *found_elem1);
    EXPECT_EQ(33, *found_elem2);
    EXPECT_EQ(22, *found_elem3);
}


TEST_F(binary_search_tree_tester, tests_searching_non_existing_elements)
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
    const int* found_elem4 = bst.search(elem4);
    const int* found_elem5 = bst.search(elem5);

    ASSERT_EQ(reinterpret_cast<const int*>(0), found_elem4);
    ASSERT_EQ(reinterpret_cast<const int*>(0), found_elem5);
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


TEST_F(binary_search_tree_tester, tests_min_element_in_empty_tree)
{
    // when and then
    const int* min_elem = bst.min();
    ASSERT_EQ(reinterpret_cast<const int*>(0), min_elem);
}


TEST_F(binary_search_tree_tester, tests_min_element_in_non_empty_tree)
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
    const int* min_elem = bst.min();

    ASSERT_NE(reinterpret_cast<const int*>(0), min_elem);
    EXPECT_EQ(-29, *min_elem);
}


TEST_F(binary_search_tree_tester, tests_max_element_in_empty_tree)
{
    // when and then
    const int* min_elem = bst.max();
    ASSERT_EQ(reinterpret_cast<const int*>(0), min_elem);
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
    const int* min_elem = bst.max();

    ASSERT_NE(reinterpret_cast<const int*>(0), min_elem);
    EXPECT_EQ(13, *min_elem);
}


TEST_F(binary_search_tree_tester, tests_removing_left_child_leaf)
{
    // given
    const int elem1 = 11;
    const int elem2 = 7;

    bst.insert(elem1);
    bst.insert(elem2);

    // when
    bst.remove(elem2);

    // then
    EXPECT_EQ(1, bst.size());

    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem1));
    ASSERT_EQ(reinterpret_cast<const int*>(0), bst.search(elem2));
}


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

    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem1));
    ASSERT_EQ(reinterpret_cast<const int*>(0), bst.search(elem2));
}


TEST_F(binary_search_tree_tester, tests_removing_root_leaf)
{
    // given
    const int elem = 42;

    bst.insert(elem);

    // when
    bst.remove(elem);

    // then
    EXPECT_EQ(0, bst.size());
    ASSERT_EQ(reinterpret_cast<const int*>(0), bst.search(elem));
}


/**
 * Removes 22 from:
 *     (33)
 *     /
 *   (22)
 *   /
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

    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem1));
    ASSERT_EQ(reinterpret_cast<const int*>(0), bst.search(elem2));
    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem3));
}


/**
 * Removes 11 from:
 *   (33)
 *   /
 * (11)
 *   \
 *   (22)
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

    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem1));
    ASSERT_EQ(reinterpret_cast<const int*>(0), bst.search(elem2));
    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem3));
}


/**
 * Removes 33 from:
 * (11)
 *   \
 *   (33)
 *   /
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

    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem1));
    ASSERT_EQ(reinterpret_cast<const int*>(0), bst.search(elem2));
    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem3));
}


/**
 * Removes 11 from:
 * (11)
 *   \
 *   (22)
 *     \
 *     (33)
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

    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem1));
    ASSERT_EQ(reinterpret_cast<const int*>(0), bst.search(elem2));
    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem3));
}


/**
 * Removes 22 from:
 *   (22)
 *   /
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

    ASSERT_EQ(reinterpret_cast<const int*>(0), bst.search(elem1));
    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem2));
}


/**
 * Removes 11 from:
 * (11)
 *   \
 *   (22)
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

    ASSERT_EQ(reinterpret_cast<const int*>(0), bst.search(elem1));
    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem2));
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

    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem1));
    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem2));
    ASSERT_EQ(reinterpret_cast<const int*>(0), bst.search(elem3));
    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem4));
    ASSERT_NE(reinterpret_cast<const int*>(0), bst.search(elem5));
}


} // namespace testing
} // namespace pk
