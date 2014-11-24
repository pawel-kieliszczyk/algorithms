#include <gtest/gtest.h>

#include "weighted_graph.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct weighted_graph_tester : gt::Test
{
    static const int VERTICES = 3;
    static const int MAX_VERTEX_DEGREE = 5;

    typedef weighted_graph<VERTICES, MAX_VERTEX_DEGREE> weighted_graph_type;

    // tested class:
    weighted_graph_type g;
};

TEST_F(weighted_graph_tester, tests_graph_properties)
{
    //given
    const int V = 42;
    const int E = 1337;

    // when and then
    const int v = weighted_graph<V, E>::max_num_of_vertices;
    const int e = weighted_graph<V, E>::max_vertex_degree;

    EXPECT_EQ(V, v);
    EXPECT_EQ(E, e);
}


} // namespace testing
} // namespace pk
