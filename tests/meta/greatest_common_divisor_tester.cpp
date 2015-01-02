#include <gtest/gtest.h>

#include "meta/greatest_common_divisor.hpp"


namespace gt = testing;


namespace pk
{
namespace meta
{
namespace testing
{


struct meta_greatest_common_divisor_tester : public gt::Test
{
};


TEST_F(meta_greatest_common_divisor_tester, tests_two_same_numbers)
{
    // when
    const int gcd_1_1 = greatest_common_divisor<1, 1>::value;
    const int gcd_5_5 = greatest_common_divisor<5, 5>::value;
    const int gcd_42_42 = greatest_common_divisor<42, 42>::value;

    // then
    EXPECT_EQ(1, gcd_1_1);
    EXPECT_EQ(5, gcd_5_5);
    EXPECT_EQ(42, gcd_42_42);
}


TEST_F(meta_greatest_common_divisor_tester, tests_two_numbers)
{
    // when
    const int gcd_7_21 = greatest_common_divisor<7, 21>::value;
    const int gcd_15_9 = greatest_common_divisor<15, 9>::value;
    const int gcd_5_7 = greatest_common_divisor<5, 7>::value;
    const int gcd_1_1337 = greatest_common_divisor<1, 1337>::value;

    // then
    EXPECT_EQ(7, gcd_7_21);
    EXPECT_EQ(3, gcd_15_9);
    EXPECT_EQ(1, gcd_5_7);
    EXPECT_EQ(1, gcd_1_1337);
}


TEST_F(meta_greatest_common_divisor_tester, tests_two_numbers_one_of_which_is_zero)
{
    // when
    const int gcd_1_0 = greatest_common_divisor<1, 0>::value;
    const int gcd_0_7 = greatest_common_divisor<0, 7>::value;

    // then
    EXPECT_EQ(1, gcd_1_0);
    EXPECT_EQ(7, gcd_0_7);
}


} // namespace testing
} // namespace meta
} // namespace pk
