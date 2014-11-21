#include <gtest/gtest.h>

#include "vector.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct vector_tester : public gt::Test
{
    static const int MAX_ELEMENTS = 13;

    vector_tester() : element1(42), element2(1337) {}

    const int element1;
    const int element2;

    // tested class:
    pk::vector<int, MAX_ELEMENTS> vec;
};


TEST_F(vector_tester, tests_emptyness_of_empty_vector)
{
    EXPECT_TRUE(vec.empty());
}


TEST_F(vector_tester, tests_emptyness_after_push_and_pop_back)
{
    // when
    vec.push_back(element1);
    vec.pop_back();

    // then
    EXPECT_TRUE(vec.empty());
}


TEST_F(vector_tester, tests_emptyness_of_nonempty_vector)
{
    // when
    vec.push_back(element1);

    // then
    EXPECT_FALSE(vec.empty());
}


TEST_F(vector_tester, tests_size_of_empty_vector)
{
    EXPECT_EQ(0, vec.size());
}


TEST_F(vector_tester, tests_size_of_nonempty_vector)
{
    // when and then
    vec.push_back(element1);
    EXPECT_EQ(1, vec.size());

    // when and then
    vec.push_back(element2);
    EXPECT_EQ(2, vec.size());

    // when and then
    vec.pop_back();
    EXPECT_EQ(1, vec.size());
}


TEST_F(vector_tester, tests_push_back)
{
    // when
    vec.push_back(element1);
    vec.push_back(element2);

    // then
    EXPECT_EQ(element1, vec[0]);
    EXPECT_EQ(element2, vec[1]);
}


TEST_F(vector_tester, tests_pop_back)
{
    // given
    vec.push_back(element1);
    vec.push_back(element2);

    // when
    vec.pop_back();

    // then
    ASSERT_EQ(1, vec.size());
    EXPECT_EQ(element1, vec[0]);
}


TEST_F(vector_tester, tests_back)
{
    // when and then
    vec.push_back(element1);
    EXPECT_EQ(element1, vec.back());

    // when and then
    vec.push_back(element2);
    EXPECT_EQ(element2, vec.back());
}


TEST_F(vector_tester, tests_front)
{
    // when and then
    vec.push_back(element1);
    EXPECT_EQ(element1, vec.front());

    // when and then
    vec.push_back(element2);
    EXPECT_EQ(element1, vec.front());
}


TEST_F(vector_tester, tests_begin)
{
    // when
    vec.push_back(element1);

    // then
    EXPECT_EQ(element1, *vec.begin());
}


TEST_F(vector_tester, tests_end)
{
    // when
    vec.push_back(element1);

    // then
    EXPECT_EQ(element1, *(vec.end() - 1));
}


TEST_F(vector_tester, tests_begin_and_end)
{
    // when
    vec.push_back(element1);
    vec.push_back(element2);

    // then
    int* it = vec.begin();
    EXPECT_EQ(element1, *it);

    ++it;
    EXPECT_EQ(element2, *it);

    ++it;
    EXPECT_EQ(vec.end(), it);
}


TEST_F(vector_tester, tests_cbegin_and_cend)
{
    // given
    vec.push_back(element1);

    // when
    const pk::vector<int, MAX_ELEMENTS>& constVec = vec;

    // then
    const int* it = constVec.cbegin();
    EXPECT_EQ(element1, *it);

    ++it;
    EXPECT_EQ(constVec.cend(), it);
}


} // namespace testing
} // namespace pk
