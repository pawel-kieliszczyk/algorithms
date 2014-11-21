#include <gtest/gtest.h>

#include "queue.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct queue_tester : public gt::Test
{
    static const int MAX_PUSHES = 13;

    queue_tester() : element1(42), element2(1337) {}

    const int element1;
    const int element2;

    // tested class:
    pk::queue<int, MAX_PUSHES> q;
};


TEST_F(queue_tester, tests_emptyness_of_empty_queue)
{
    EXPECT_TRUE(q.empty());
}


TEST_F(queue_tester, tests_emptyness_of_nonempty_queue)
{
    // when
    q.push(element1);

    // then
    EXPECT_FALSE(q.empty());
}


TEST_F(queue_tester, tests_emptyness_after_push_and_pop)
{
    // when
    q.push(element1);
    q.pop();

    // then
    EXPECT_TRUE(q.empty());
}


TEST_F(queue_tester, tests_size_of_empty_queue)
{
    EXPECT_EQ(0, q.size());
}


TEST_F(queue_tester, tests_size_of_nonempty_queue)
{
    // when and then
    q.push(element1);
    EXPECT_EQ(1, q.size());

    // when and then
    q.push(element2);
    EXPECT_EQ(2, q.size());

    // when and then
    q.pop();
    EXPECT_EQ(1, q.size());
}


} // namespace testing
} // namespace pk
