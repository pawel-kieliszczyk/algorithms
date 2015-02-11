#include <gtest/gtest.h>

#include "shortest_text_template.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct shortest_text_template_tester : public gt::Test
{
    static const int MAX_TEST_SIZE = 40;

    // tested class:
    shortest_text_template<MAX_TEST_SIZE> stt;
};


TEST_F(shortest_text_template_tester, tests_aaaa)
{
    // given
    const std::string s = "aaaa";

    // when and then
    EXPECT_EQ(1, stt.run(s.c_str(), s.size()));
}


TEST_F(shortest_text_template_tester, tests_abc)
{
    // given
    const std::string s = "abc";

    // when and then
    EXPECT_EQ(3, stt.run(s.c_str(), s.size()));
}


TEST_F(shortest_text_template_tester, tests_ababab)
{
    // given
    const std::string s = "ababab";

    // when and then
    EXPECT_EQ(2, stt.run(s.c_str(), s.size()));
}


TEST_F(shortest_text_template_tester, tests_ababa)
{
    // given
    const std::string s = "ababa";

    // when and then
    EXPECT_EQ(3, stt.run(s.c_str(), s.size()));
}


TEST_F(shortest_text_template_tester, tests_ababbababbabababbabababbababbaba)
{
    // given
    const std::string s = "ababbababbabababbabababbababbaba";

    // when and then
    EXPECT_EQ(8, stt.run(s.c_str(), s.size()));
}


} // namespace testing
} // namespace pk
