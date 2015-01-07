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
    // when and then
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
    EXPECT_EQ(55, nth_fibonacci_number(10));
    EXPECT_EQ(89, nth_fibonacci_number(11));
}


TEST_F(nth_fibonacci_number_tester, tests_fibonacci_numbers_modulo)
{
    // given
    const int mod = 4;

    // when and then
    EXPECT_EQ(0, nth_fibonacci_number(0, mod));
    EXPECT_EQ(1, nth_fibonacci_number(1, mod));
    EXPECT_EQ(1, nth_fibonacci_number(2, mod));
    EXPECT_EQ(2, nth_fibonacci_number(3, mod));
    EXPECT_EQ(3, nth_fibonacci_number(4, mod));
    EXPECT_EQ(1, nth_fibonacci_number(5, mod));
    EXPECT_EQ(0, nth_fibonacci_number(6, mod));
    EXPECT_EQ(1, nth_fibonacci_number(7, mod));
    EXPECT_EQ(1, nth_fibonacci_number(8, mod));
    EXPECT_EQ(2, nth_fibonacci_number(9, mod));
    EXPECT_EQ(3, nth_fibonacci_number(10, mod));
    EXPECT_EQ(1, nth_fibonacci_number(11, mod));
}


} // namespace testing
} // namespace pk
