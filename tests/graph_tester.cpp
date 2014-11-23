#include <gtest/gtest.h>

#include "graph.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct graph_tester : public gt::Test
{
    static const int VERTICES = 3;
    static const int MAX_VERTEX_DEGREE = 5;

    typedef graph<VERTICES, MAX_VERTEX_DEGREE> graph_type;

    // tested class:
    graph_type g;
};


TEST_F(graph_tester, tests_graph_properties)
{
    //given
    const int V = 42;
    const int E = 1337;

    // when and then
    const int v = graph<V, E>::max_num_of_vertices;
    const int e = graph<V, E>::max_vertex_degree;

    EXPECT_EQ(V, v);
    EXPECT_EQ(E, e);
}


TEST_F(graph_tester, tests_empty_graph)
{
    // given
    ASSERT_EQ(3, g.size());

    // when and then
    EXPECT_EQ(0, g.get_adjacency_list(0).size());
    EXPECT_EQ(0, g.get_adjacency_list(1).size());
    EXPECT_EQ(0, g.get_adjacency_list(2).size());
}


TEST_F(graph_tester, tests_full_graph)
{
    // given
    ASSERT_EQ(3, g.size());

    // when
    g.add_not_directed_edge(0, 1);
    g.add_not_directed_edge(0, 2);
    g.add_not_directed_edge(1, 2);

    // then
    const graph_type::adjacency_list& adj0 = g.get_adjacency_list(0);
    ASSERT_EQ(2, adj0.size());
    EXPECT_EQ(1, adj0[0]);
    EXPECT_EQ(2, adj0[1]);

    const graph_type::adjacency_list& adj1 = g.get_adjacency_list(1);
    ASSERT_EQ(2, adj1.size());
    EXPECT_EQ(0, adj1[0]);
    EXPECT_EQ(2, adj1[1]);

    const graph_type::adjacency_list& adj2 = g.get_adjacency_list(2);
    ASSERT_EQ(2, adj2.size());
    EXPECT_EQ(0, adj2[0]);
    EXPECT_EQ(1, adj2[1]);
}


TEST_F(graph_tester, test_adding_directed_edge)
{
    // given
    ASSERT_EQ(3, g.size());

    // when
    g.add_directed_edge(1, 2);

    // then
    const graph_type::adjacency_list& adj0 = g.get_adjacency_list(0);
    EXPECT_EQ(0, adj0.size());

    const graph_type::adjacency_list& adj1 = g.get_adjacency_list(1);
    ASSERT_EQ(1, adj1.size());
    EXPECT_EQ(2, adj1[0]);

    const graph_type::adjacency_list& adj2 = g.get_adjacency_list(2);
    EXPECT_EQ(0, adj2.size());
}


TEST_F(graph_tester, test_adding_not_directed_edge)
{
    // given
    ASSERT_EQ(3, g.size());

    // when
    g.add_not_directed_edge(1, 2);

    // then
    const graph_type::adjacency_list& adj0 = g.get_adjacency_list(0);
    EXPECT_EQ(0, adj0.size());

    const graph_type::adjacency_list& adj1 = g.get_adjacency_list(1);
    ASSERT_EQ(1, adj1.size());
    EXPECT_EQ(2, adj1[0]);

    const graph_type::adjacency_list& adj2 = g.get_adjacency_list(2);
    EXPECT_EQ(1, adj2.size());
    EXPECT_EQ(1, adj2[0]);
}


TEST_F(graph_tester, tests_reset)
{
    // given
    ASSERT_EQ(3, g.size());
    g.add_directed_edge(0, 1);
    g.add_directed_edge(1, 2);
    g.add_directed_edge(2, 0);

    // when
    g.reset();

    // then
    EXPECT_EQ(0, g.get_adjacency_list(0).size());
    EXPECT_EQ(0, g.get_adjacency_list(1).size());
    EXPECT_EQ(0, g.get_adjacency_list(2).size());
}


} // namespace testing
} // namespace pk
