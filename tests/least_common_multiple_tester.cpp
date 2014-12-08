#include <gtest/gtest.h>

#include "least_common_multiple.hpp"


namespace pk
{
namespace testing
{


TEST(least_common_multiple_tester, tests_two_same_numbers)
{
    // when and then
    EXPECT_EQ(1, least_common_multiple(1, 1));
    EXPECT_EQ(5, least_common_multiple(5, 5));
    EXPECT_EQ(42, least_common_multiple(42, 42));
}


TEST(least_common_multiple_tester, tests_two_numbers)
{
    // when and then
    EXPECT_EQ(10, least_common_multiple(5, 10));
    EXPECT_EQ(30, least_common_multiple(6, 10));
    EXPECT_EQ(35, least_common_multiple(7, 5));
}


TEST(least_common_multiple_tester, tests_different_types_of_numbers)
{
    // when and then
    EXPECT_EQ(15, least_common_multiple(3, 5));
    EXPECT_EQ(15u, least_common_multiple(3u, 5u));
    EXPECT_EQ(15L, least_common_multiple(3L, 5L));
    EXPECT_EQ(15LL, least_common_multiple(3LL, 5LL));
}


} // namespace testing
} // namespace pk
