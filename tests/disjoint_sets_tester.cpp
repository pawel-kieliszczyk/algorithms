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
      : elem_id_1(0),
        elem_id_2(3),
        elem_id_3(5),
        elem_id_4(6)
    {
    }

    const int elem_id_1;
    const int elem_id_2;
    const int elem_id_3;
    const int elem_id_4;

    // tested class:
    disjoint_sets_type ds;
};


TEST_F(disjoint_sets_tester, tests_different_ids_of_two_one_element_sets)
{
    // then
    EXPECT_NE(ds.get_set_id(elem_id_1), ds.get_set_id(elem_id_2));
}


TEST_F(disjoint_sets_tester, tests_union_of_two_one_element_sets)
{
    // when
    ds.union_sets(elem_id_1, elem_id_2);

    // then
    EXPECT_EQ(ds.get_set_id(elem_id_1), ds.get_set_id(elem_id_2));
}


TEST_F(disjoint_sets_tester, tests_different_ids_one_element_set_and_two_element_set)
{
    // when
    ds.union_sets(elem_id_1, elem_id_2);

    // then
    EXPECT_NE(ds.get_set_id(elem_id_1), ds.get_set_id(elem_id_3));
    EXPECT_NE(ds.get_set_id(elem_id_2), ds.get_set_id(elem_id_3));
}


TEST_F(disjoint_sets_tester, tests_union_of_two_element_set_and_one_element_set)
{
    // given
    ds.union_sets(elem_id_1, elem_id_2);

    // when
    ds.union_sets(elem_id_1, elem_id_3);

    // then
    EXPECT_EQ(ds.get_set_id(elem_id_1), ds.get_set_id(elem_id_2));
    EXPECT_EQ(ds.get_set_id(elem_id_2), ds.get_set_id(elem_id_3));
}


TEST_F(disjoint_sets_tester, tests_union_of_two_two_element_sets)
{
    // given
    ds.union_sets(elem_id_1, elem_id_2);
    ds.union_sets(elem_id_3, elem_id_4);

    // when
    ds.union_sets(elem_id_2, elem_id_4);

    // then
    EXPECT_EQ(ds.get_set_id(elem_id_1), ds.get_set_id(elem_id_2));
    EXPECT_EQ(ds.get_set_id(elem_id_2), ds.get_set_id(elem_id_3));
    EXPECT_EQ(ds.get_set_id(elem_id_3), ds.get_set_id(elem_id_4));
}


} // namespace testing
} // namespace pk
