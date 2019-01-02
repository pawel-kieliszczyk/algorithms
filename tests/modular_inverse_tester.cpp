#include <gtest/gtest.h>

#include "modular_inverse.hpp"


namespace pk
{
namespace testing
{


TEST(modular_inverse_tester, tests_mod7)
{
    // when and then
    EXPECT_EQ(1, modular_inverse(1, 7));
    EXPECT_EQ(4, modular_inverse(2, 7));
    EXPECT_EQ(5, modular_inverse(3, 7));
    EXPECT_EQ(2, modular_inverse(4, 7));
    EXPECT_EQ(3, modular_inverse(5, 7));
    EXPECT_EQ(6, modular_inverse(6, 7));
}


TEST(modular_inverse_tester, tests_mod11)
{
    // when and then
    EXPECT_EQ(1, modular_inverse(1, 11));
    EXPECT_EQ(6, modular_inverse(2, 11));
    EXPECT_EQ(4, modular_inverse(3, 11));
    EXPECT_EQ(3, modular_inverse(4, 11));
    EXPECT_EQ(9, modular_inverse(5, 11));
    EXPECT_EQ(2, modular_inverse(6, 11));
    EXPECT_EQ(8, modular_inverse(7, 11));
    EXPECT_EQ(7, modular_inverse(8, 11));
    EXPECT_EQ(5, modular_inverse(9, 11));
    EXPECT_EQ(10, modular_inverse(10, 11));
}


} // namespace testing
} // namespace pk
