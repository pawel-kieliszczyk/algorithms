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
    static const int MAX_SIZE_IN_BINARY_REPRESENTATION = 20;

//    pk::bigint<MAX_SIZE_IN_BINARY_REPRESENTATION> bi(const char* init_value)
//    {
//        return pk::bigint<MAX_SIZE_IN_BINARY_REPRESENTATION>(init_value);
//    }
};


TEST_F(bigint_tester, tests_default_value)
{
    // given
    pk::bigint<MAX_SIZE_IN_BINARY_REPRESENTATION> a;

    // when and then
    EXPECT_EQ(0, strcmp(a.decimal_c_str(), "0"));
}


TEST_F(bigint_tester, tests_initialization_from_cstring)
{
    // given
    pk::bigint<MAX_SIZE_IN_BINARY_REPRESENTATION> a("0");
    pk::bigint<MAX_SIZE_IN_BINARY_REPRESENTATION> b("1");
//    pk::bigint<MAX_SIZE_IN_BINARY_REPRESENTATION> c("12345");
//    pk::bigint<MAX_SIZE_IN_BINARY_REPRESENTATION> d("-999");
//    pk::bigint<MAX_SIZE_IN_BINARY_REPRESENTATION> e("-0");

    // when and then
    EXPECT_EQ(0, strcmp(a.decimal_c_str(), "0"));
    EXPECT_EQ(0, strcmp(b.decimal_c_str(), "1"));
//    EXPECT_EQ(0, strcmp(c.c_str(), "12345"));
//    EXPECT_EQ(0, strcmp(d.c_str(), "-999"));
//    EXPECT_EQ(0, strcmp(e.c_str(), "0"));
}


//TEST_F(bigint_tester, tests_is_positive)
//{
//    EXPECT_TRUE(bi("42").is_positive());
//    EXPECT_TRUE(bi("1337").is_positive());
//
//    EXPECT_FALSE(bi("0").is_positive());
//    EXPECT_FALSE(bi("-42").is_positive());
//    EXPECT_FALSE(bi("-1337").is_positive());
//}
//
//
//TEST_F(bigint_tester, tests_is_negative)
//{
//    EXPECT_FALSE(bi("0").is_negative());
//    EXPECT_FALSE(bi("42").is_negative());
//    EXPECT_FALSE(bi("1337").is_negative());
//
//    EXPECT_TRUE(bi("-42").is_negative());
//    EXPECT_TRUE(bi("-1337").is_negative());
//}
//
//
//TEST_F(bigint_tester, tests_equality)
//{
//    // when and then
//    EXPECT_TRUE(bi("0") == bi("0"));
//    EXPECT_TRUE(bi("-0") == bi("0"));
//    EXPECT_TRUE(bi("123") == bi("123"));
//    EXPECT_TRUE(bi("-456") == bi("-456"));
//
//    EXPECT_FALSE(bi("0") == bi("1"));
//    EXPECT_FALSE(bi("123") == bi("456"));
//    EXPECT_FALSE(bi("-1") == bi("1"));
//    EXPECT_FALSE(bi("-999") == bi("-888"));
//}
//
//
//TEST_F(bigint_tester, tests_inequality)
//{
//    // when and then
//    EXPECT_TRUE(bi("0") != bi("1"));
//    EXPECT_TRUE(bi("123") != bi("456"));
//    EXPECT_TRUE(bi("-1") != bi("1"));
//    EXPECT_TRUE(bi("-999") != bi("-888"));
//
//    EXPECT_FALSE(bi("0") != bi("0"));
//    EXPECT_FALSE(bi("-0") != bi("0"));
//    EXPECT_FALSE(bi("123") != bi("123"));
//    EXPECT_FALSE(bi("-456") != bi("-456"));
//}
//
//
//TEST_F(bigint_tester, tests_lower)
//{
//    // when and then
//    EXPECT_TRUE(bi("0") < bi("1"));
//    EXPECT_TRUE(bi("123") < bi("456"));
//    EXPECT_TRUE(bi("-1") < bi("0"));
//    EXPECT_TRUE(bi("-42") < bi("1337"));
//
//    EXPECT_FALSE(bi("0") < bi("0"));
//    EXPECT_FALSE(bi("123") < bi("123"));
//    EXPECT_FALSE(bi("1337") < bi("42"));
//    EXPECT_FALSE(bi("-42") < bi("-42"));
//    EXPECT_FALSE(bi("-42") < bi("-1337"));
//    EXPECT_FALSE(bi("42") < bi("-1337"));
//}


} // namespace testing
} // namespace pk
