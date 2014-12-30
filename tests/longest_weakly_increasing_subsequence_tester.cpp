#include <vector>

#include <gtest/gtest.h>

#include "longest_monotonic_subsequence.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct longest_weakly_increasing_subsequence_tester : public gt::Test
{
    static const int MAX_SEQUENCE_SIZE = 9;

    // tested class:
    typedef longest_monotonic_subsequence<MAX_SEQUENCE_SIZE> lms;
};


TEST_F(longest_weakly_increasing_subsequence_tester, tests_empty_sequence)
{
    // given
    std::vector<int> numbers;

    // when and then
    EXPECT_EQ(0, lms::weakly_increasing(numbers.begin(), numbers.end()));
}


TEST_F(longest_weakly_increasing_subsequence_tester, tests_one_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(42);

    // when and then
    EXPECT_EQ(1, lms::weakly_increasing(numbers.begin(), numbers.end()));
}


TEST_F(longest_weakly_increasing_subsequence_tester, tests_sequence_of_all_equal_elements)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(42);
    numbers.push_back(42);
    numbers.push_back(42);

    // when and then
    EXPECT_EQ(3, lms::weakly_increasing(numbers.begin(), numbers.end()));
}


TEST_F(longest_weakly_increasing_subsequence_tester, tests_sequence_of_all_strictly_decreasing_elements)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(33);
    numbers.push_back(11);
    numbers.push_back(0);
    numbers.push_back(-22);
    numbers.push_back(-55);

    // when and then
    EXPECT_EQ(1, lms::weakly_increasing(numbers.begin(), numbers.end()));
}


TEST_F(longest_weakly_increasing_subsequence_tester, tests_sequence_of_all_strictly_increasing_elements)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(-55);
    numbers.push_back(-22);
    numbers.push_back(0);
    numbers.push_back(11);
    numbers.push_back(33);

    // when and then
    EXPECT_EQ(5, lms::weakly_increasing(numbers.begin(), numbers.end()));
}


TEST_F(longest_weakly_increasing_subsequence_tester, tests_sequence_of_all_weakly_increasing_elements)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(11);
    numbers.push_back(11);
    numbers.push_back(22);
    numbers.push_back(22);
    numbers.push_back(33);

    // when and then
    EXPECT_EQ(5, lms::weakly_increasing(numbers.begin(), numbers.end()));
}


TEST_F(longest_weakly_increasing_subsequence_tester, tests_sequence_of_randomized_elements)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(55);
    numbers.push_back(-22);
    numbers.push_back(33);
    numbers.push_back(77);
    numbers.push_back(22);
    numbers.push_back(22);
    numbers.push_back(44);
    numbers.push_back(11);
    numbers.push_back(66);

    // when and then
    EXPECT_EQ(5, lms::weakly_increasing(numbers.begin(), numbers.end()));
}


} // namespace testing
} // namespace pk
