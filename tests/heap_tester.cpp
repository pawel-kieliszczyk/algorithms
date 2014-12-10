#include <gtest/gtest.h>

#include "heap.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct heap_tester : public gt::Test
{
    static const int MAX_SIZE = 29;

    // tested class:
    pk::heap<int, MAX_SIZE> h;
};


TEST_F(heap_tester, tests_emptyness_of_empty_heap)
{
    EXPECT_TRUE(h.empty());
}


TEST_F(heap_tester, tests_emptyness_after_push_and_pop)
{
    // given
    const int element = 42;

    // when
    h.push(element);
    h.pop();

    // then
    EXPECT_TRUE(h.empty());
}


TEST_F(heap_tester, tests_emptyness_of_nonempty_heap)
{
    // given
    const int element = 42;

    // when
    h.push(element);

    // then
    EXPECT_FALSE(h.empty());
}


} // namespace testing
} // namespace pk
