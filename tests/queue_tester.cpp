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


} // namespace testing
} // namespace pk
