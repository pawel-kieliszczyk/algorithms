#include <gtest/gtest.h>

#include "meta/greatest_common_divisor.hpp"
#include "meta/static_assertion.hpp"


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
    // when and then
    STATIC_ASSERTION((greatest_common_divisor<1, 1>::value == 1));
    STATIC_ASSERTION((greatest_common_divisor<5, 5>::value == 5));
    STATIC_ASSERTION((greatest_common_divisor<42, 42>::value == 42));
}


TEST_F(meta_greatest_common_divisor_tester, tests_two_numbers)
{
    // when and then
    STATIC_ASSERTION((greatest_common_divisor<7, 21>::value == 7));
    STATIC_ASSERTION((greatest_common_divisor<15, 9>::value == 3));
    STATIC_ASSERTION((greatest_common_divisor<5, 7>::value == 1));
    STATIC_ASSERTION((greatest_common_divisor<1, 1337>::value == 1));
}


TEST_F(meta_greatest_common_divisor_tester, tests_two_numbers_one_of_which_is_zero)
{
    // when and then
    STATIC_ASSERTION((greatest_common_divisor<1, 0>::value == 1));
    STATIC_ASSERTION((greatest_common_divisor<0, 7>::value == 7));
}


} // namespace testing
} // namespace meta
} // namespace pk
