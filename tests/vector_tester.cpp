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


TEST_F(vector_tester, tests_empty_vector)
{
    EXPECT_TRUE(vec.empty());
}


} // namespace testing
} // namespace pk
