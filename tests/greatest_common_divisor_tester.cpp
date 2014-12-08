#include <gtest/gtest.h>

#include "greatest_common_divisor.hpp"


namespace pk
{
namespace testing
{


TEST(greatest_common_divisor_tester, tests_two_same_numbers)
{
    // when and then
    EXPECT_EQ(5, greatest_common_divisor(5, 5));
    EXPECT_EQ(42, greatest_common_divisor(42, 42));
}


TEST(greatest_common_divisor_tester, tests_two_numbers)
{
    // when and then
    EXPECT_EQ(7, greatest_common_divisor(7, 21));
    EXPECT_EQ(3, greatest_common_divisor(15, 9));
    EXPECT_EQ(1, greatest_common_divisor(5, 7));
    EXPECT_EQ(1, greatest_common_divisor(1, 1337));
}


TEST(greatest_common_divisor_tester, tests_two_numbers_one_of_which_is_zero)
{
    // when and then
    EXPECT_EQ(1, greatest_common_divisor(1, 0));
    EXPECT_EQ(7, greatest_common_divisor(0, 7));
}


TEST(greatest_common_divisor_tester, tests_different_types_of_numbers)
{
    // when and then
    EXPECT_EQ(1, greatest_common_divisor(3, 5));
    EXPECT_EQ(1u, greatest_common_divisor(3u, 5u));
    EXPECT_EQ(1L, greatest_common_divisor(3L, 5L));
    EXPECT_EQ(1LL, greatest_common_divisor(3LL, 5LL));
}


} // namespace testing
} // namespace pk
