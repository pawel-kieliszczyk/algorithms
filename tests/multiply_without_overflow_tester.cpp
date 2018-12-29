#include <gtest/gtest.h>

#include "multiply_without_overflow.hpp"


namespace pk
{
namespace testing
{


TEST(multiply_without_overflow_tester, tests_few_multiplications)
{
    // when and then
    EXPECT_EQ(0, multiply_without_overflow(1, 0, 107));
    EXPECT_EQ(0, multiply_without_overflow(0, 1, 107));
    EXPECT_EQ(1, multiply_without_overflow(1, 1, 107));
    EXPECT_EQ(21, multiply_without_overflow(3, 7, 107));

    EXPECT_EQ(3, multiply_without_overflow(2, 5, 7));
    EXPECT_EQ(1, multiply_without_overflow(3, 5, 7));
    EXPECT_EQ(6, multiply_without_overflow(4, 5, 7));

    EXPECT_EQ(613016319, multiply_without_overflow(123456789, 123456789, 1000000009));
}


} // namespace testing
} // namespace pk
