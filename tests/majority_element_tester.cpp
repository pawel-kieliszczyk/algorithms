#include <vector>

#include <gtest/gtest.h>

#include "majority_element.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct majority_element_tester : public gt::Test
{
    //
};


TEST_F(majority_element_tester, tests_existing_majority_element_in_one_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(42);

    // when
    std::vector<int>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_NE(numbers.end(), elem);
    EXPECT_EQ(42, *elem);
}


TEST_F(majority_element_tester, tests_nonexisting_majority_element_in_two_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(11);
    numbers.push_back(22);

    // when
    std::vector<int>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_EQ(numbers.end(), elem);
}


TEST_F(majority_element_tester, tests_existing_majority_element_in_two_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(11);
    numbers.push_back(11);

    // when
    std::vector<int>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_NE(numbers.end(), elem);
    ASSERT_EQ(11, *elem);
}


TEST_F(majority_element_tester, tests_nonexisting_majority_element_in_three_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(11);
    numbers.push_back(22);
    numbers.push_back(33);

    // when
    std::vector<int>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_EQ(numbers.end(), elem);
}


TEST_F(majority_element_tester, tests_existing_majority_element_in_three_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(11);
    numbers.push_back(22);
    numbers.push_back(22);

    // when
    std::vector<int>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_NE(numbers.end(), elem);
    ASSERT_EQ(22, *elem);
}


TEST_F(majority_element_tester, tests_nonexisting_majority_element_in_four_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(11);
    numbers.push_back(11);
    numbers.push_back(22);
    numbers.push_back(22);

    // when
    std::vector<int>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_EQ(numbers.end(), elem);
}


TEST_F(majority_element_tester, tests_existing_majority_element_in_four_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(42);
    numbers.push_back(42);
    numbers.push_back(42);
    numbers.push_back(42);

    // when
    std::vector<int>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_NE(numbers.end(), elem);
    ASSERT_EQ(42, *elem);
}


TEST_F(majority_element_tester, tests_nonexisting_majority_element_in_five_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(11);
    numbers.push_back(11);
    numbers.push_back(22);
    numbers.push_back(22);
    numbers.push_back(33);

    // when
    std::vector<int>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_EQ(numbers.end(), elem);
}


TEST_F(majority_element_tester, tests_existing_majority_element_in_five_element_sequence)
{
    // given
    std::vector<int> numbers;
    numbers.push_back(11);
    numbers.push_back(11);
    numbers.push_back(22);
    numbers.push_back(22);
    numbers.push_back(11);

    // when
    std::vector<int>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_NE(numbers.end(), elem);
    ASSERT_EQ(11, *elem);
}


TEST_F(majority_element_tester, tests_nonexisting_majority_element_in_two_noninteger_element_sequence)
{
    // given
    std::vector<double> numbers;
    numbers.push_back(12.3);
    numbers.push_back(-45.6);

    // when
    std::vector<double>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_EQ(numbers.end(), elem);
}


TEST_F(majority_element_tester, tests_existing_majority_element_in_two_noninteger_element_sequence)
{
    // given
    std::vector<double> numbers;
    numbers.push_back(12.3);
    numbers.push_back(12.3);

    // when
    std::vector<double>::iterator elem = majority_element(numbers.begin(), numbers.end());

    // then
    ASSERT_NE(numbers.end(), elem);
    ASSERT_EQ(12.3, *elem);
}


} // namespace testing
} // namespace pk
