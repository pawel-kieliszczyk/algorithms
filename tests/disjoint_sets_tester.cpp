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

    disjoint_sets_tester()
      : elem_id_1(3),
        elem_id_2(5),
        no_set_id(disjoint_sets_type::no_set)
    {
    }

    const int elem_id_1;
    const int elem_id_2;

    const int no_set_id;

    // tested class:
    disjoint_sets_type ds;
};


TEST_F(disjoint_sets_tester, tests_element_not_in_set)
{
    // when and then
    EXPECT_EQ(no_set_id, ds.get_set_id(elem_id_1));
}


TEST_F(disjoint_sets_tester, tests_one_element_in_set)
{
    // when
    ds.make_set(elem_id_1);

    // then
    EXPECT_NE(no_set_id, ds.get_set_id(elem_id_1));
}


TEST_F(disjoint_sets_tester, tests_different_ids_of_two_sets)
{
    // when
    ds.make_set(elem_id_1);
    ds.make_set(elem_id_2);

    // then
    EXPECT_NE(ds.get_set_id(elem_id_1), ds.get_set_id(elem_id_2));
}


TEST_F(disjoint_sets_tester, tests_unions_two_sets)
{
    // given
    ds.make_set(elem_id_1);
    ds.make_set(elem_id_2);

    // when
    ds.union_sets(elem_id_1, elem_id_2);

    // then
    EXPECT_EQ(ds.get_set_id(elem_id_1), ds.get_set_id(elem_id_2));
}


} // namespace testing
} // namespace pk
