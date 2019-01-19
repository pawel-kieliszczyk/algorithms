#include <gtest/gtest.h>

#include "graphs/edge_types.hpp"
#include "graphs/bipartite_graph.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{


struct bipartite_graph_tester : public gt::Test
{
    static const int U = 3;
    static const int V = 2;
    static const int E = 6;

    typedef bipartite_graph_factory<U, V, E, edge> bipartite_graph_factory_type;
    typedef bipartite_graph_factory_type::bipartite_graph_type bipartite_graph_type;

    // tested class:
    bipartite_graph_factory_type factory;
};


TEST_F(bipartite_graph_tester, tests_empty_graph)
{
    // when
    const bipartite_graph_type& g = factory.create(U, V);

    // then
    EXPECT_EQ(0, g.get_adjacency_list_u(0).size());
    EXPECT_EQ(0, g.get_adjacency_list_u(1).size());
    EXPECT_EQ(0, g.get_adjacency_list_u(2).size());

    EXPECT_EQ(3, g.get_num_of_vertices_u());
    EXPECT_EQ(2, g.get_num_of_vertices_v());
    EXPECT_EQ(0, g.get_num_of_edges());
}


TEST_F(bipartite_graph_tester, tests_adding_directed_edge)
{
    // when
    factory.add_directed_edge_uv(edge(1/*from*/, 2/*to*/));

    const bipartite_graph_type& g = factory.create(U, V);

    // then
    const bipartite_graph_type::adjacency_list& adj0 = g.get_adjacency_list_u(0);
    EXPECT_EQ(0, adj0.size());

    const bipartite_graph_type::adjacency_list& adj1 = g.get_adjacency_list_u(1);
    ASSERT_EQ(1, adj1.size());
    EXPECT_EQ(2, adj1[0].to);

    const bipartite_graph_type::adjacency_list& adj2 = g.get_adjacency_list_u(2);
    EXPECT_EQ(0, adj2.size());

    EXPECT_EQ(3, g.get_num_of_vertices_u());
    EXPECT_EQ(2, g.get_num_of_vertices_v());
    EXPECT_EQ(1, g.get_num_of_edges());
}


TEST_F(bipartite_graph_tester, tests_full_graph)
{

    // when
    factory.add_directed_edge_uv(edge(0/*from*/, 0/*to*/));
    factory.add_directed_edge_uv(edge(0, 1));
    factory.add_directed_edge_uv(edge(1, 0));
    factory.add_directed_edge_uv(edge(1, 1));
    factory.add_directed_edge_uv(edge(2, 0));
    factory.add_directed_edge_uv(edge(2, 1));

    const bipartite_graph_type& g = factory.create(U, V);

    // then
    const bipartite_graph_type::adjacency_list& adj0 = g.get_adjacency_list_u(0);
    ASSERT_EQ(2, adj0.size());
    EXPECT_EQ(0, adj0[0].to);
    EXPECT_EQ(1, adj0[1].to);

    const bipartite_graph_type::adjacency_list& adj1 = g.get_adjacency_list_u(1);
    ASSERT_EQ(2, adj1.size());
    EXPECT_EQ(0, adj1[0].to);
    EXPECT_EQ(1, adj1[1].to);

    const bipartite_graph_type::adjacency_list& adj2 = g.get_adjacency_list_u(2);
    ASSERT_EQ(2, adj2.size());
    EXPECT_EQ(0, adj2[0].to);
    EXPECT_EQ(1, adj2[1].to);

    EXPECT_EQ(3, g.get_num_of_vertices_u());
    EXPECT_EQ(2, g.get_num_of_vertices_v());
    EXPECT_EQ(6, g.get_num_of_edges());
}


TEST_F(bipartite_graph_tester, tests_reset_before_creation)
{
    // given
    factory.add_directed_edge_uv(edge(0/*from*/, 0/*to*/));
    factory.add_directed_edge_uv(edge(0, 1));
    factory.add_directed_edge_uv(edge(1, 1));

    // when
    factory.reset();
    const bipartite_graph_type& g = factory.create(U, V);

    // then
    EXPECT_EQ(0, g.get_adjacency_list_u(0).size());
    EXPECT_EQ(0, g.get_adjacency_list_u(1).size());
    EXPECT_EQ(0, g.get_adjacency_list_u(2).size());
}


TEST_F(bipartite_graph_tester, tests_reset_after_creation)
{
    // given
    factory.add_directed_edge_uv(edge(0/*from*/, 1/*to*/));
    factory.add_directed_edge_uv(edge(1, 1));

    factory.create(U, V);

    // when
    factory.reset();
    factory.add_directed_edge_uv(edge(0, 1));

    const bipartite_graph_type& g = factory.create(U, V);

    // then
    EXPECT_EQ(1, g.get_adjacency_list_u(0).size());
    EXPECT_EQ(0, g.get_adjacency_list_u(1).size());
    EXPECT_EQ(0, g.get_adjacency_list_u(2).size());
}


} // namespace testing
} // namespace graphs
} // namespace pk
