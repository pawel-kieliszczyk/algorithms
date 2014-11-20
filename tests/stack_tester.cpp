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

    stack_tester() : element1(42) {}

    const int element1;

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


} // namespace testing
} // namespace pk
