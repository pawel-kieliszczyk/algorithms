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

    // tested class:
    pk::vector<int, MAX_ELEMENTS> vec;
};


TEST_F(vector_tester, tests_empty)
{
    EXPECT_TRUE(vec.empty());
}


TEST_F(vector_tester, tests_size)
{
    EXPECT_EQ(0, vec.size());
}


TEST_F(vector_tester, tests_push_back)
{
    // given
    const int element = 42;

    // when
    vec.push_back(element);

    // then
    EXPECT_EQ(element, vec[0]);
}


} // namespace testing
} // namespace pk
