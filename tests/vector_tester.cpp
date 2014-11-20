#include <gtest/gtest.h>

#include "vector.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct vector_tester : public gt::Test
{
    static const int MAX_ELEMENTS = 13;

    vector_tester() : element(42) {}

    const int element;

    // tested class:
    pk::vector<int, MAX_ELEMENTS> vec;
};


TEST_F(vector_tester, tests_emptyness_of_empty_vector)
{
    EXPECT_TRUE(vec.empty());
}


TEST_F(vector_tester, tests_emptyness_of_nonempty_vector)
{
    // when
    vec.push_back(element);

    // then
    EXPECT_FALSE(vec.empty());
}


TEST_F(vector_tester, tests_size_of_empty_vector)
{
    EXPECT_EQ(0, vec.size());
}


TEST_F(vector_tester, tests_size_of_nonempty_vector)
{
    // when
    vec.push_back(element);

    // then
    EXPECT_EQ(1, vec.size());
}


TEST_F(vector_tester, tests_push_back)
{
    // when
    vec.push_back(element);

    // then
    EXPECT_EQ(element, vec[0]);
}


} // namespace testing
} // namespace pk
