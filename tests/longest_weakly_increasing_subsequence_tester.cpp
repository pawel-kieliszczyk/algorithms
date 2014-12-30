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
};


TEST_F(longest_weakly_increasing_subsequence_tester, tests_one_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(42);

    // when and then
    EXPECT_EQ(1, longest_monotonic_subsequence::weakly_increasing(numbers.begin(), numbers.end()));
}


} // namespace testing
} // namespace pk
