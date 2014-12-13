#include <gtest/gtest.h>

#include "disjoint_sets.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct disjoint_sets_tester : public gt::Test
{
    static const int MAX_ID = 7;
    typedef pk::disjoint_sets<MAX_ID> disjoint_sets_type;

    disjoint_sets_tester() : no_set_id(disjoint_sets_type::no_set) {}

    const int no_set_id;

    // tested class:
    disjoint_sets_type ds;
};


TEST_F(disjoint_sets_tester, tests_element_not_in_set)
{
    // given
    const int elem_id = 3;

    // when and then
    EXPECT_EQ(no_set_id, ds.get_set_id(elem_id));
}


TEST_F(disjoint_sets_tester, tests_one_element_in_set)
{
    // given
    const int elem_id = 3;

    // when
    ds.make_set(elem_id);

    // then
    EXPECT_NE(no_set_id, ds.get_set_id(elem_id));
}


TEST_F(disjoint_sets_tester, tests_different_ids_of_two_sets)
{
    // given
    const int elem_id1 = 3;
    const int elem_id2 = 5;

    // when
    ds.make_set(elem_id1);
    ds.make_set(elem_id2);

    // then
    EXPECT_NE(ds.get_set_id(elem_id1), ds.get_set_id(elem_id2));
}


} // namespace testing
} // namespace pk
