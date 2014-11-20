#include <gtest/gtest.h>

#include "stack.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct stack_tester : public gt::Test
{
    static const int MAX_ELEMENTS = 13;

    stack_tester() : element1(42), element2(1337) {}

    const int element1;
    const int element2;

    // tested class:
    pk::stack<int, MAX_ELEMENTS> s;
};


TEST_F(stack_tester, tests_emptyness_of_empty_stack)
{
    EXPECT_TRUE(s.empty());
}


TEST_F(stack_tester, tests_emptyness_of_nonempty_stack)
{
    // when
    s.push(element1);

    // then
    EXPECT_FALSE(s.empty());
}


TEST_F(stack_tester, tests_emptyness_after_push_and_pop)
{
    // when
    s.push(element1);
    s.pop();

    // then
    EXPECT_TRUE(s.empty());
}


TEST_F(stack_tester, tests_size_of_empty_stack)
{
    EXPECT_EQ(0, s.size());
}


TEST_F(stack_tester, tests_size_of_nonempty_stack)
{
    // when and then
    s.push(element1);
    EXPECT_EQ(1, s.size());

    // when and then
    s.push(element2);
    EXPECT_EQ(2, s.size());

    // when and then
    s.pop();
    EXPECT_EQ(1, s.size());
}



} // namespace testing
} // namespace pk
