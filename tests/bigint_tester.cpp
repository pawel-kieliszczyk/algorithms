#include <cstring>

#include <gtest/gtest.h>

#include "bigint.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct bigint_tester : public gt::Test
{
    static const int MAX_DECIMAL_SIZE = 5;
};


TEST_F(bigint_tester, tests_default_value)
{
    // given
    pk::bigint<MAX_DECIMAL_SIZE> a;

    // when and then
    ASSERT_EQ(0, strcmp(a.c_str(), "0"));
}


} // namespace testing
} // namespace pk
