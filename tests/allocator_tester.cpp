#include <gtest/gtest.h>


#include "allocator.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct allocator_tester : public gt::Test
{
    static const int MAX_SIZE = 6;

    // tested class:
    allocator<int, MAX_SIZE> a;
};


TEST_F(allocator_tester, tests_allocations)
{
    // when
    int* elem1 = a.allocate();
    int* elem2 = a.allocate();
    int* elem3 = a.allocate();
    int* elem4 = a.allocate();
    int* elem5 = a.allocate();
    int* elem6 = a.allocate();

    *elem1 = 11;
    *elem2 = 22;
    *elem3 = 33;
    *elem4 = 44;
    *elem5 = 55;
    *elem6 = 66;

    // then
    EXPECT_EQ(11, *elem1);
    EXPECT_EQ(22, *elem2);
    EXPECT_EQ(33, *elem3);
    EXPECT_EQ(44, *elem4);
    EXPECT_EQ(55, *elem5);
    EXPECT_EQ(66, *elem6);
}


TEST_F(allocator_tester, tests_deallocations)
{
    // given
    int* elem1 = a.allocate();
    int* elem2 = a.allocate();
    int* elem3 = a.allocate();
    int* elem4 = a.allocate();
    int* elem5 = a.allocate();
    int* elem6 = a.allocate();

    *elem1 = 11;
    *elem2 = 22;
    *elem3 = 33;
    *elem4 = 44;
    *elem5 = 55;
    *elem6 = 66;

    // when
    a.deallocate(elem3);
    a.deallocate(elem5);

    int* elem7 = a.allocate();
    int* elem8 = a.allocate();

    *elem7 = 77;
    *elem8 = 88;

    // then
    EXPECT_EQ(11, *elem1);
    EXPECT_EQ(22, *elem2);
    EXPECT_EQ(44, *elem4);
    EXPECT_EQ(66, *elem6);
    EXPECT_EQ(77, *elem7);
    EXPECT_EQ(88, *elem8);
}


} // namespace testing
} // namespace pk
