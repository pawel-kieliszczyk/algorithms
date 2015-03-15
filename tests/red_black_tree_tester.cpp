#include <gtest/gtest.h>

#include "red_black_tree.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct red_black_tree_tester : public gt::Test
{
    static const int MAX_SIZE = 100;

    // tested class:
    red_black_tree<int, MAX_SIZE> rbt;
};


TEST_F(red_black_tree_tester, tests_emptyness_of_empty_tree)
{
    // when and then
    EXPECT_TRUE(rbt.empty());
}


TEST_F(red_black_tree_tester, tests_emptyness_after_insertion)
{
    // given
    const int elem = 11;

    // when
    rbt.insert(elem);

    // then
    EXPECT_FALSE(rbt.empty());
}


TEST_F(red_black_tree_tester, tests_emptyness_after_insertion_and_removal)
{
    // given
    const int elem = 11;
    rbt.insert(elem);

    // when
    rbt.remove(elem);

    // then
    EXPECT_TRUE(rbt.empty());
}


TEST_F(red_black_tree_tester, tests_emptyness_after_mixed_insertions_and_removals)
{
    // given
    const int elem1 = 11;
    const int elem2 = 22;
    const int elem3 = 33;

    // when
    rbt.insert(elem1);
    rbt.insert(elem2);
    rbt.remove(elem2);

    // then
    EXPECT_FALSE(rbt.empty());

    // when
    rbt.insert(elem3);

    // then
    EXPECT_FALSE(rbt.empty());

    // when
    rbt.remove(elem1);
    rbt.remove(elem3);

    // then
    EXPECT_TRUE(rbt.empty());
}


TEST_F(red_black_tree_tester, tests_size_of_empty_tree)
{
    // when and then
    EXPECT_EQ(0, rbt.size());
}


TEST_F(red_black_tree_tester, tests_size_after_insertion)
{
    // given
    const int elem = 11;

    // when
    rbt.insert(elem);

    // then
    EXPECT_EQ(1, rbt.size());
}


TEST_F(red_black_tree_tester, tests_size_after_insertion_and_removal)
{
    // given
    const int elem = 11;
    rbt.insert(elem);

    // when
    rbt.remove(elem);

    // then
    EXPECT_EQ(0, rbt.size());
}


TEST_F(red_black_tree_tester, tests_size_after_mixed_insertions_and_removals)
{
    // given
    const int elem1 = 11;
    const int elem2 = 22;
    const int elem3 = 33;

    // when
    rbt.insert(elem1);
    rbt.insert(elem2);
    rbt.remove(elem2);

    // then
    EXPECT_EQ(1, rbt.size());

    // when
    rbt.insert(elem3);

    // then
    EXPECT_EQ(2, rbt.size());

    // when
    rbt.remove(elem1);
    rbt.remove(elem3);

    // then
    EXPECT_EQ(0, rbt.size());
}


TEST_F(red_black_tree_tester, tests_existance_of_missing_element)
{
    // given
    const int elem = 11;

    // when and then
    EXPECT_FALSE(rbt.exists(elem));
}


TEST_F(red_black_tree_tester, tests_existance_of_inserted_element)
{
    // given
    const int elem = 11;

    // when
    rbt.insert(elem);

    // then
    EXPECT_TRUE(rbt.exists(elem));
}


TEST_F(red_black_tree_tester, tests_existance_of_many_inserted_elements)
{
    // given
    const int num_of_elements = 10;
    const int elements[num_of_elements] = {55, 22, 66, -44, 0, -22, 33, 11, 44, -33};

    // when
    for(int i = 0; i < num_of_elements; ++i)
        rbt.insert(elements[i]);

    // then
    for(int i = 0; i < num_of_elements; ++i)
        EXPECT_TRUE(rbt.exists(elements[i]));
}


TEST_F(red_black_tree_tester, tests_existance_of_removed_element)
{
    // given
    const int elem = 11;
    rbt.insert(elem);

    // when
    rbt.remove(elem);

    // then
    EXPECT_FALSE(rbt.exists(elem));
}


TEST_F(red_black_tree_tester, tests_existance_of_many_removed_elements)
{
    // given
    const int num_of_elements = 10;
    const int elements[num_of_elements] = {55, 22, 66, -44, 0, -22, 33, 11, 44, -33};

    for(int i = 0; i < num_of_elements; ++i)
        rbt.insert(elements[i]);

    // when
    for(int i = num_of_elements - 1; i >= 0; --i)
        rbt.remove(elements[i]);

    // then
    for(int i = 0; i < num_of_elements; ++i)
        EXPECT_FALSE(rbt.exists(elements[i]));
}


TEST_F(red_black_tree_tester, tests_existance_of_mixed_inserted_and_removed_elements)
{
    // given
    const int elem1 = 33;
    const int elem2 = 22;
    const int elem3 = 11;

    // when
    rbt.insert(elem1);
    rbt.insert(elem2);
    rbt.remove(elem2);

    // then
    EXPECT_TRUE(rbt.exists(elem1));
    EXPECT_FALSE(rbt.exists(elem2));
    EXPECT_FALSE(rbt.exists(elem3));

    // when
    rbt.insert(elem3);

    // then
    EXPECT_TRUE(rbt.exists(elem1));
    EXPECT_FALSE(rbt.exists(elem2));
    EXPECT_TRUE(rbt.exists(elem3));

    // when
    rbt.remove(elem1);
    rbt.remove(elem3);

    // then
    EXPECT_FALSE(rbt.exists(elem1));
    EXPECT_FALSE(rbt.exists(elem2));
    EXPECT_FALSE(rbt.exists(elem3));
}


TEST_F(red_black_tree_tester, tests_minimum_element)
{
    // given
    const int num_of_elements = 7;
    const int elements[num_of_elements] = {55, 22, 66, -44, 0, -20, 33};

    // when
    for(int i = 0; i < num_of_elements; ++i)
        rbt.insert(elements[i]);

    // then
    EXPECT_EQ(-44, rbt.min());
}


TEST_F(red_black_tree_tester, tests_maximum_element)
{
    // given
    const int num_of_elements = 7;
    const int elements[num_of_elements] = {55, 22, 66, -44, 0, -20, 33};

    // when
    for(int i = 0; i < num_of_elements; ++i)
        rbt.insert(elements[i]);

    // then
    EXPECT_EQ(66, rbt.max());
}


TEST_F(red_black_tree_tester, tests_ranks_after_insertions)
{
    // given
    const int num_of_elements = 10;
    const int elements[num_of_elements] = {55, 22, 66, -44, 0, -22, 33, 11, 44, -33};

    // when
    for(int i = 0; i < num_of_elements; ++i)
        rbt.insert(elements[i]);

    // then
    EXPECT_EQ(0, rbt.rank(-44));
    EXPECT_EQ(1, rbt.rank(-33));
    EXPECT_EQ(2, rbt.rank(-22));
    EXPECT_EQ(3, rbt.rank(0));
    EXPECT_EQ(4, rbt.rank(11));
    EXPECT_EQ(5, rbt.rank(22));
    EXPECT_EQ(6, rbt.rank(33));
    EXPECT_EQ(7, rbt.rank(44));
    EXPECT_EQ(8, rbt.rank(55));
    EXPECT_EQ(9, rbt.rank(66));
}


TEST_F(red_black_tree_tester, tests_ranks_after_removals)
{
    // given
    const int num_of_elements_to_insert = 10;
    const int num_of_elements_to_remove = 5;
    const int elements_to_insert[num_of_elements_to_insert] = {55, 22, 66, -44, 0, -22, 33, 11, 44, -33};
    const int elements_to_remove[num_of_elements_to_remove] = {55,     66,      0,      33,     44     };

    for(int i = 0; i < num_of_elements_to_insert; ++i)
        rbt.insert(elements_to_insert[i]);

    // when
    for(int i = 0; i < num_of_elements_to_remove; ++i)
        rbt.remove(elements_to_remove[i]);

    // then
    EXPECT_EQ(0, rbt.rank(-44));
    EXPECT_EQ(1, rbt.rank(-33));
    EXPECT_EQ(2, rbt.rank(-22));
    EXPECT_EQ(3, rbt.rank(11));
    EXPECT_EQ(4, rbt.rank(22));
}


} // namespace testing
} // namespace pk
