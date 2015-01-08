#include <algorithm>
#include <string>

#include <gtest/gtest.h>

#include "prefix_function.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct prefix_function_tester : public gt::Test
{
    static const int MAX_TEXT_SIZE = 100;

    // tested class:
    prefix_function<MAX_TEXT_SIZE> pf;
};


TEST_F(prefix_function_tester, tests_abcd)
{
    // given
    const std::string text = "abcd";

    // when
    pf.run(text.c_str(), text.size());

    // then
    const int* prefix_suffix_table = pf.get_prefix_suffix_table();

    EXPECT_EQ(0, prefix_suffix_table[0]);
    EXPECT_EQ(0, prefix_suffix_table[1]);
    EXPECT_EQ(0, prefix_suffix_table[2]);
    EXPECT_EQ(0, prefix_suffix_table[3]);
}


TEST_F(prefix_function_tester, tests_aaaa)
{
    // given
    const std::string text = "aaaa";

    // when
    pf.run(text.c_str(), text.size());

    // then
    const int* prefix_suffix_table = pf.get_prefix_suffix_table();

    EXPECT_EQ(0, prefix_suffix_table[0]);
    EXPECT_EQ(1, prefix_suffix_table[1]);
    EXPECT_EQ(2, prefix_suffix_table[2]);
    EXPECT_EQ(3, prefix_suffix_table[3]);
}


TEST_F(prefix_function_tester, tests_abcabcabc)
{
    // given
    const std::string text = "abcabcabc";

    // when
    pf.run(text.c_str(), text.size());

    // then
    const int* prefix_suffix_table = pf.get_prefix_suffix_table();

    EXPECT_EQ(0, prefix_suffix_table[0]);
    EXPECT_EQ(0, prefix_suffix_table[1]);
    EXPECT_EQ(0, prefix_suffix_table[2]);
    EXPECT_EQ(1, prefix_suffix_table[3]);
    EXPECT_EQ(2, prefix_suffix_table[4]);
    EXPECT_EQ(3, prefix_suffix_table[5]);
    EXPECT_EQ(4, prefix_suffix_table[6]);
    EXPECT_EQ(5, prefix_suffix_table[7]);
    EXPECT_EQ(6, prefix_suffix_table[8]);
}


TEST_F(prefix_function_tester, tests_abcdabcaba)
{
    // given
    const std::string text = "abcdabcaba";

    // when
    pf.run(text.c_str(), text.size());

    // then
    const int* prefix_suffix_table = pf.get_prefix_suffix_table();

    EXPECT_EQ(0, prefix_suffix_table[0]);
    EXPECT_EQ(0, prefix_suffix_table[1]);
    EXPECT_EQ(0, prefix_suffix_table[2]);
    EXPECT_EQ(0, prefix_suffix_table[3]);
    EXPECT_EQ(1, prefix_suffix_table[4]);
    EXPECT_EQ(2, prefix_suffix_table[5]);
    EXPECT_EQ(3, prefix_suffix_table[6]);
    EXPECT_EQ(1, prefix_suffix_table[7]);
    EXPECT_EQ(2, prefix_suffix_table[8]);
    EXPECT_EQ(1, prefix_suffix_table[9]);
}


TEST_F(prefix_function_tester, tests_pattern_searching_in_text)
{
    // given
    const std::string pattern = "abca";
    const std::string text = "abaabcdabcabdabcabcad";
    // pattern ends at:                 ^     ^  ^

    // when
    std::string s = pattern + "#" + text;
    pf.run(s.c_str(), s.size());

    // then
    const int* prefix_suffix_table = pf.get_prefix_suffix_table();

    EXPECT_EQ(3u, std::count(prefix_suffix_table, prefix_suffix_table + s.size(), pattern.size()));

    const int first_occurance = pattern.size() + 1 + 10;
    EXPECT_EQ(4, prefix_suffix_table[first_occurance]);

    const int second_occurance = pattern.size() + 1 + 16;
    EXPECT_EQ(4, prefix_suffix_table[second_occurance]);

    const int third_occurance = pattern.size() + 1 + 19;
    EXPECT_EQ(4, prefix_suffix_table[third_occurance]);
}


} // namespace testing
} // namespace pk
