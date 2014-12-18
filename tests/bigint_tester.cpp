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
    static const int MAX_DECIMAL_SIZE = 100;

    pk::bigint<MAX_DECIMAL_SIZE> bi(const char* init_value)
    {
        return pk::bigint<MAX_DECIMAL_SIZE>(init_value);
    }
};


TEST_F(bigint_tester, tests_default_value)
{
    // given
    pk::bigint<MAX_DECIMAL_SIZE> a;

    // when and then
    ASSERT_EQ(0, strcmp(a.c_str(), "0"));
}


TEST_F(bigint_tester, tests_initialization_from_cstring)
{
    // given
    pk::bigint<MAX_DECIMAL_SIZE> a("0");
    pk::bigint<MAX_DECIMAL_SIZE> b("1");
    pk::bigint<MAX_DECIMAL_SIZE> c("12345");
    pk::bigint<MAX_DECIMAL_SIZE> d("-999");
    pk::bigint<MAX_DECIMAL_SIZE> e("-0");

    // when and then
    ASSERT_EQ(0, strcmp(a.c_str(), "0"));
    ASSERT_EQ(0, strcmp(b.c_str(), "1"));
    ASSERT_EQ(0, strcmp(c.c_str(), "12345"));
    ASSERT_EQ(0, strcmp(d.c_str(), "-999"));
    ASSERT_EQ(0, strcmp(e.c_str(), "0"));
}


TEST_F(bigint_tester, tests_equality)
{
    // when and then
    ASSERT_EQ(bi("0"), bi("0"));
    ASSERT_EQ(bi("-0"), bi("0"));
    ASSERT_EQ(bi("123"), bi("123"));
    ASSERT_EQ(bi("-456"), bi("-456"));
}


TEST_F(bigint_tester, tests_inequality)
{
    // when and then
    ASSERT_NE(bi("0"), bi("1"));
    ASSERT_NE(bi("123"), bi("456"));
    ASSERT_NE(bi("-1"), bi("1"));
}


} // namespace testing
} // namespace pk
