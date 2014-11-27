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


TEST_F(weighted_graph_tester, tests_empty_graph)
{
    // given
    ASSERT_EQ(3, g.size());

    // when and then
    EXPECT_EQ(0, g.get_adjacency_list(0).size());
    EXPECT_EQ(0, g.get_adjacency_list(1).size());
    EXPECT_EQ(0, g.get_adjacency_list(2).size());
}


TEST_F(weighted_graph_tester, tests_full_graph)
{
    // given
    ASSERT_EQ(3, g.size());

    // when
    g.add_not_directed_edge(0/*from*/, 1/*to*/, 11/*weight*/);
    g.add_not_directed_edge(0/*from*/, 2/*to*/, 22/*weight*/);
    g.add_not_directed_edge(1/*from*/, 2/*to*/, 33/*weight*/);

    // then
    const weighted_graph_type::adjacency_list& adj0 = g.get_adjacency_list(0);
    ASSERT_EQ(2, adj0.size());
    EXPECT_EQ(1, adj0[0].to);
    EXPECT_EQ(11, adj0[0].weight);
    EXPECT_EQ(2, adj0[1].to);
    EXPECT_EQ(22, adj0[1].weight);

    const weighted_graph_type::adjacency_list& adj1 = g.get_adjacency_list(1);
    ASSERT_EQ(2, adj1.size());
    EXPECT_EQ(0, adj1[0].to);
    EXPECT_EQ(11, adj1[0].weight);
    EXPECT_EQ(2, adj1[1].to);
    EXPECT_EQ(33, adj1[1].weight);

    const weighted_graph_type::adjacency_list& adj2 = g.get_adjacency_list(2);
    ASSERT_EQ(2, adj2.size());
    EXPECT_EQ(0, adj2[0].to);
    EXPECT_EQ(22, adj2[0].weight);
    EXPECT_EQ(1, adj2[1].to);
    EXPECT_EQ(33, adj2[1].weight);
}


TEST_F(weighted_graph_tester, test_adding_directed_edge)
{
    // given
    ASSERT_EQ(3, g.size());
    const int from = 1;
    const int to = 2;
    const int weight = 42;

    // when
    g.add_directed_edge(from, to, weight);

    // then
    const weighted_graph_type::adjacency_list& adj_from = g.get_adjacency_list(from);
    ASSERT_EQ(1, adj_from.size());
    EXPECT_EQ(to, adj_from[0].to);
    EXPECT_EQ(weight, adj_from[0].weight);

    const weighted_graph_type::adjacency_list& adj_to = g.get_adjacency_list(to);
    EXPECT_EQ(0, adj_to.size());
}


TEST_F(weighted_graph_tester, test_adding_not_directed_edge)
{
    // given
    ASSERT_EQ(3, g.size());
    const int v1 = 1;
    const int v2 = 2;
    const int weight = 42;

    // when
    g.add_not_directed_edge(v1, v2, weight);

    // then
    const weighted_graph_type::adjacency_list& adj1 = g.get_adjacency_list(v1);
    ASSERT_EQ(1, adj1.size());
    EXPECT_EQ(v2, adj1[0].to);
    EXPECT_EQ(weight, adj1[0].weight);

    const weighted_graph_type::adjacency_list& adj2 = g.get_adjacency_list(v2);
    EXPECT_EQ(1, adj2.size());
    EXPECT_EQ(v1, adj2[0].to);
    EXPECT_EQ(weight, adj2[0].weight);
}


TEST_F(weighted_graph_tester, tests_reset)
{
    // given
    ASSERT_EQ(3, g.size());
    g.add_directed_edge(0, 1, 42);
    g.add_directed_edge(1, 2, 42);
    g.add_directed_edge(2, 0, 42);

    // when
    g.reset();

    // then
    EXPECT_EQ(0, g.get_adjacency_list(0).size());
    EXPECT_EQ(0, g.get_adjacency_list(1).size());
    EXPECT_EQ(0, g.get_adjacency_list(2).size());
}


} // namespace testing
} // namespace pk
