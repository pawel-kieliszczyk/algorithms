#include <algorithm>
#include <string>

#include <gtest/gtest.h>

#include "palindromic_substrings_manacher.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct palindromic_substrings_manacher_tester : public gt::Test
{
    static const int MAX_TEXT_SIZE = 100;

    // tested class:
    palindromic_substrings_manacher<MAX_TEXT_SIZE> ps;
};


TEST_F(palindromic_substrings_manacher_tester, tests_even_palindromes_in_ab)
{
    // given
    const std::string text = "#ab$";

    // when
    ps.find_even(text.c_str(), text.size());

    // then
    const int* palindromic_substrings_table = ps.get_palindromic_substrings_table();

    EXPECT_EQ(0, palindromic_substrings_table[0]);
    EXPECT_EQ(0, palindromic_substrings_table[1]);
    EXPECT_EQ(0, palindromic_substrings_table[2]);
    EXPECT_EQ(0, palindromic_substrings_table[3]);
}


TEST_F(palindromic_substrings_manacher_tester, tests_even_palindromes_in_aa)
{
    // given
    const std::string text = "#aa$";

    // when
    ps.find_even(text.c_str(), text.size());

    // then
    const int* palindromic_substrings_table = ps.get_palindromic_substrings_table();

    EXPECT_EQ(0, palindromic_substrings_table[0]);
    EXPECT_EQ(1, palindromic_substrings_table[1]);
    EXPECT_EQ(0, palindromic_substrings_table[2]);
    EXPECT_EQ(0, palindromic_substrings_table[3]);
}


TEST_F(palindromic_substrings_manacher_tester, tests_even_palindromes_in_aaaa)
{
    // given
    const std::string text = "#aaaa$";

    // when
    ps.find_even(text.c_str(), text.size());

    // then
    const int* palindromic_substrings_table = ps.get_palindromic_substrings_table();

    EXPECT_EQ(0, palindromic_substrings_table[0]);
    EXPECT_EQ(1, palindromic_substrings_table[1]);
    EXPECT_EQ(2, palindromic_substrings_table[2]);
    EXPECT_EQ(1, palindromic_substrings_table[3]);
    EXPECT_EQ(0, palindromic_substrings_table[4]);
    EXPECT_EQ(0, palindromic_substrings_table[5]);
}


TEST_F(palindromic_substrings_manacher_tester, tests_even_palindromes_in_abbabb)
{
    // given
    const std::string text = "#abbabb$";

    // when
    ps.find_even(text.c_str(), text.size());

    // then
    const int* palindromic_substrings_table = ps.get_palindromic_substrings_table();

    EXPECT_EQ(0, palindromic_substrings_table[0]);
    EXPECT_EQ(0, palindromic_substrings_table[1]);
    EXPECT_EQ(2, palindromic_substrings_table[2]);
    EXPECT_EQ(0, palindromic_substrings_table[3]);
    EXPECT_EQ(0, palindromic_substrings_table[4]);
    EXPECT_EQ(1, palindromic_substrings_table[5]);
    EXPECT_EQ(0, palindromic_substrings_table[6]);
    EXPECT_EQ(0, palindromic_substrings_table[7]);
}


TEST_F(palindromic_substrings_manacher_tester, tests_even_palindromes_in_beeppeeb)
{
    // given
    const std::string text = "#beeppeeb$";

    // when
    ps.find_even(text.c_str(), text.size());

    // then
    const int* palindromic_substrings_table = ps.get_palindromic_substrings_table();

    EXPECT_EQ(0, palindromic_substrings_table[0]);
    EXPECT_EQ(0, palindromic_substrings_table[1]);
    EXPECT_EQ(1, palindromic_substrings_table[2]);
    EXPECT_EQ(0, palindromic_substrings_table[3]);
    EXPECT_EQ(4, palindromic_substrings_table[4]);
    EXPECT_EQ(0, palindromic_substrings_table[5]);
    EXPECT_EQ(1, palindromic_substrings_table[6]);
    EXPECT_EQ(0, palindromic_substrings_table[7]);
    EXPECT_EQ(0, palindromic_substrings_table[8]);
    EXPECT_EQ(0, palindromic_substrings_table[9]);
}


TEST_F(palindromic_substrings_manacher_tester, tests_even_palindromes_in_abcbabbabcba)
{
    // given
    const std::string text = "#abcbabbabcba$";

    // when
    ps.find_even(text.c_str(), text.size());

    // then
    const int* palindromic_substrings_table = ps.get_palindromic_substrings_table();

    EXPECT_EQ(0, palindromic_substrings_table[0]);
    EXPECT_EQ(0, palindromic_substrings_table[1]);
    EXPECT_EQ(0, palindromic_substrings_table[2]);
    EXPECT_EQ(0, palindromic_substrings_table[3]);
    EXPECT_EQ(0, palindromic_substrings_table[4]);
    EXPECT_EQ(0, palindromic_substrings_table[5]);
    EXPECT_EQ(6, palindromic_substrings_table[6]);
    EXPECT_EQ(0, palindromic_substrings_table[7]);
    EXPECT_EQ(0, palindromic_substrings_table[8]);
    EXPECT_EQ(0, palindromic_substrings_table[9]);
    EXPECT_EQ(0, palindromic_substrings_table[10]);
    EXPECT_EQ(0, palindromic_substrings_table[11]);
    EXPECT_EQ(0, palindromic_substrings_table[12]);
    EXPECT_EQ(0, palindromic_substrings_table[13]);
}


TEST_F(palindromic_substrings_manacher_tester, tests_odd_palindromes_in_a)
{
    // given
    const std::string text = "#a$";

    // when
    ps.find_odd(text.c_str(), text.size());

    // then
    const int* palindromic_substrings_table = ps.get_palindromic_substrings_table();

    EXPECT_EQ(0, palindromic_substrings_table[0]);
    EXPECT_EQ(1, palindromic_substrings_table[1]);
    EXPECT_EQ(0, palindromic_substrings_table[2]);
}


TEST_F(palindromic_substrings_manacher_tester, tests_odd_palindromes_in_ab)
{
    // given
    const std::string text = "#ab$";

    // when
    ps.find_odd(text.c_str(), text.size());

    // then
    const int* palindromic_substrings_table = ps.get_palindromic_substrings_table();

    EXPECT_EQ(0, palindromic_substrings_table[0]);
    EXPECT_EQ(1, palindromic_substrings_table[1]);
    EXPECT_EQ(1, palindromic_substrings_table[2]);
    EXPECT_EQ(0, palindromic_substrings_table[3]);
}


TEST_F(palindromic_substrings_manacher_tester, tests_odd_palindromes_in_aba)
{
    // given
    const std::string text = "#aba$";

    // when
    ps.find_odd(text.c_str(), text.size());

    // then
    const int* palindromic_substrings_table = ps.get_palindromic_substrings_table();

    EXPECT_EQ(0, palindromic_substrings_table[0]);
    EXPECT_EQ(1, palindromic_substrings_table[1]);
    EXPECT_EQ(2, palindromic_substrings_table[2]);
    EXPECT_EQ(1, palindromic_substrings_table[3]);
    EXPECT_EQ(0, palindromic_substrings_table[4]);
}


TEST_F(palindromic_substrings_manacher_tester, tests_odd_palindromes_in_abaacaaba)
{
    // given
    const std::string text = "#abaacaaba$";

    // when
    ps.find_odd(text.c_str(), text.size());

    // then
    const int* palindromic_substrings_table = ps.get_palindromic_substrings_table();

    EXPECT_EQ(0, palindromic_substrings_table[0]);
    EXPECT_EQ(1, palindromic_substrings_table[1]);
    EXPECT_EQ(2, palindromic_substrings_table[2]);
    EXPECT_EQ(1, palindromic_substrings_table[3]);
    EXPECT_EQ(1, palindromic_substrings_table[4]);
    EXPECT_EQ(5, palindromic_substrings_table[5]);
    EXPECT_EQ(1, palindromic_substrings_table[6]);
    EXPECT_EQ(1, palindromic_substrings_table[7]);
    EXPECT_EQ(2, palindromic_substrings_table[8]);
    EXPECT_EQ(1, palindromic_substrings_table[9]);
    EXPECT_EQ(0, palindromic_substrings_table[10]);
}


} // namespace testing
} // namespace pk
