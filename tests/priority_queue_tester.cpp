#include <gtest/gtest.h>

#include "priority_queue.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct priority_queue_tester : public gt::Test
{
    static const int MAX_SIZE = 29;

    // tested class:
    pk::min_priority_queue<int, MAX_SIZE> prio_queue;
};


TEST_F(priority_queue_tester, tests_emptyness_of_empty_priority_queue)
{
    EXPECT_TRUE(prio_queue.empty());
}


TEST_F(priority_queue_tester, tests_emptyness_after_push_and_pop)
{
    // given
    const int element = 42;

    // when
    prio_queue.push(element);
    prio_queue.pop();

    // then
    EXPECT_TRUE(prio_queue.empty());
}


TEST_F(priority_queue_tester, tests_emptyness_of_nonempty_priority_queue)
{
    // given
    const int element = 42;

    // when
    prio_queue.push(element);

    // then
    EXPECT_FALSE(prio_queue.empty());
}


TEST_F(priority_queue_tester, tests_size_of_empty_priority_queue)
{
    EXPECT_EQ(0, prio_queue.size());
}


TEST_F(priority_queue_tester, tests_size_of_nonempty_priority_queue)
{
    // given
    const int element = 42;

    // when and then
    prio_queue.push(element);
    EXPECT_EQ(1, prio_queue.size());

    // when and then
    prio_queue.push(element);
    EXPECT_EQ(2, prio_queue.size());

    // when and then
    prio_queue.pop();
    EXPECT_EQ(1, prio_queue.size());
}


TEST_F(priority_queue_tester, tests_push)
{
    // when
    prio_queue.push(42);

    // then
    EXPECT_EQ(42, prio_queue.top());

    // when
    prio_queue.push(7);

    // then
    EXPECT_EQ(7, prio_queue.top());

    // when
    prio_queue.push(1337);

    // then
    EXPECT_EQ(7, prio_queue.top());
}


TEST_F(priority_queue_tester, tests_pop)
{
    // given
    prio_queue.push(42);
    prio_queue.push(7);
    prio_queue.push(1337);

    // when
    prio_queue.pop();

    // then
    EXPECT_EQ(42, prio_queue.top());

    // when
    prio_queue.pop();

    // then
    EXPECT_EQ(1337, prio_queue.top());
}


} // namespace testing
} // namespace pk
