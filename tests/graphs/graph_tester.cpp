#include <gtest/gtest.h>

#include "graphs/edge_types.hpp"
#include "graphs/graph.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{


struct graph_tester : public gt::Test
{
    static const int V = 3;
    static const int E = 6;

    typedef graph_factory<V, E, edge> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    // tested class:
    graph_factory_type factory;
};


TEST_F(graph_tester, tests_empty_graph)
{
    // when
    const graph_type& g = factory.create();

    // then
    EXPECT_EQ(0, g.get_adjacency_list(0).size());
    EXPECT_EQ(0, g.get_adjacency_list(1).size());
    EXPECT_EQ(0, g.get_adjacency_list(2).size());
}


TEST_F(graph_tester, tests_adding_directed_edge)
{
    // when
    factory.add_directed_edge(edge(1/*from*/, 2/*to*/));

    const graph_type& g = factory.create();

    // then
    const graph_type::adjacency_list& adj0 = g.get_adjacency_list(0);
    EXPECT_EQ(0, adj0.size());

    const graph_type::adjacency_list& adj1 = g.get_adjacency_list(1);
    ASSERT_EQ(1, adj1.size());
    EXPECT_EQ(2, adj1[0].to);

    const graph_type::adjacency_list& adj2 = g.get_adjacency_list(2);
    EXPECT_EQ(0, adj2.size());
}


TEST_F(graph_tester, test_adding_not_directed_edge)
{
    // when
    factory.add_not_directed_edge(edge(1/*from*/, 2/*to*/));

    const graph_type& g = factory.create();

    // then
    const graph_type::adjacency_list& adj0 = g.get_adjacency_list(0);
    EXPECT_EQ(0, adj0.size());

    const graph_type::adjacency_list& adj1 = g.get_adjacency_list(1);
    ASSERT_EQ(1, adj1.size());
    EXPECT_EQ(2, adj1[0].to);

    const graph_type::adjacency_list& adj2 = g.get_adjacency_list(2);
    EXPECT_EQ(1, adj2.size());
    EXPECT_EQ(1, adj2[0].to);
}


TEST_F(graph_tester, tests_full_graph)
{

    // when
    factory.add_not_directed_edge(edge(0/*from*/, 1/*to*/));
    factory.add_not_directed_edge(edge(0, 2));
    factory.add_not_directed_edge(edge(1, 2));

    const graph_type& g = factory.create();

    // then
    const graph_type::adjacency_list& adj0 = g.get_adjacency_list(0);
    ASSERT_EQ(2, adj0.size());
    EXPECT_EQ(1, adj0[0].to);
    EXPECT_EQ(2, adj0[1].to);

    const graph_type::adjacency_list& adj1 = g.get_adjacency_list(1);
    ASSERT_EQ(2, adj1.size());
    EXPECT_EQ(0, adj1[0].to);
    EXPECT_EQ(2, adj1[1].to);

    const graph_type::adjacency_list& adj2 = g.get_adjacency_list(2);
    ASSERT_EQ(2, adj2.size());
    EXPECT_EQ(0, adj2[0].to);
    EXPECT_EQ(1, adj2[1].to);
}


TEST_F(graph_tester, tests_reset)
{
    // given
    factory.add_not_directed_edge(edge(0/*from*/, 1/*to*/));
    factory.add_not_directed_edge(edge(0, 2));
    factory.add_not_directed_edge(edge(1, 2));

    // when
    factory.reset();
    const graph_type& g = factory.create();

    // then
    EXPECT_EQ(0, g.get_adjacency_list(0).size());
    EXPECT_EQ(0, g.get_adjacency_list(1).size());
    EXPECT_EQ(0, g.get_adjacency_list(2).size());
}


} // namespace testing
} // namespace graphs
} // namespace pk
