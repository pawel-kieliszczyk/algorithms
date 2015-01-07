#include <gtest/gtest.h>

#include "nth_fibonacci_number.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct nth_fibonacci_number_tester : public gt::Test
{
};


TEST_F(nth_fibonacci_number_tester, tests_fibonacci_numbers)
{
    EXPECT_EQ(0, nth_fibonacci_number(0));
    EXPECT_EQ(1, nth_fibonacci_number(1));
    EXPECT_EQ(1, nth_fibonacci_number(2));
    EXPECT_EQ(2, nth_fibonacci_number(3));
    EXPECT_EQ(3, nth_fibonacci_number(4));
    EXPECT_EQ(5, nth_fibonacci_number(5));
    EXPECT_EQ(8, nth_fibonacci_number(6));
    EXPECT_EQ(13, nth_fibonacci_number(7));
    EXPECT_EQ(21, nth_fibonacci_number(8));
    EXPECT_EQ(34, nth_fibonacci_number(9));
}


} // namespace testing
} // namespace pk
