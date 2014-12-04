#include <gtest/gtest.h>

#include "cyclic_array.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct cyclic_array_tester : public gt::Test
{
    cyclic_array_tester() : elem1(11), elem2(22), elem3(33)
    {
        ca[0] = elem1;
        ca[1] = elem2;
        ca[2] = elem3;
    }

    static const int SIZE = 3;

    const int elem1;
    const int elem2;
    const int elem3;

    // tested class:
    cyclic_array<int, SIZE> ca;
};


TEST_F(cyclic_array_tester, tests_shift_Left_by_zero)
{
    // when
    ca.shift_left(0);

    // then
    EXPECT_EQ(elem1, ca[0]);
    EXPECT_EQ(elem2, ca[1]);
    EXPECT_EQ(elem3, ca[2]);
}


TEST_F(cyclic_array_tester, tests_shift_left_by_small_value)
{
    // when
    ca.shift_left(1);

    // then
    EXPECT_EQ(elem2, ca[0]);
    EXPECT_EQ(elem3, ca[1]);
    EXPECT_EQ(elem1, ca[2]);
}


TEST_F(cyclic_array_tester, tests_shift_left_by_bigger_value)
{
    // when
    ca.shift_left(5);

    // then
    EXPECT_EQ(elem3, ca[0]);
    EXPECT_EQ(elem1, ca[1]);
    EXPECT_EQ(elem2, ca[2]);
}


} // namespace testing
} // namespace pk
