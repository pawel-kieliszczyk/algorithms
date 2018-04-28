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


struct weighted_graph_tester : public gt::Test
{
    static const int V = 3;
    static const int E = 6;

    typedef int weight_type;
    typedef weighted_edge<weight_type> weighted_edge_type;
    typedef graph_factory<V, E, weighted_edge_type> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    // tested class:
    graph_factory_type factory;
};


TEST_F(weighted_graph_tester, tests_empty_graph)
{
    // when
    const graph_type& g = factory.create(V);

    // then
    EXPECT_EQ(0, g.get_adjacency_list(0).size());
    EXPECT_EQ(0, g.get_adjacency_list(1).size());
    EXPECT_EQ(0, g.get_adjacency_list(2).size());
}


TEST_F(weighted_graph_tester, tests_adding_directed_edge)
{
    // when
    factory.add_directed_edge(weighted_edge_type(1/*from*/, 2/*to*/, 11/*weight*/));

    const graph_type& g = factory.create(V);

    // then
    const graph_type::adjacency_list& adj0 = g.get_adjacency_list(0);
    EXPECT_EQ(0, adj0.size());

    const graph_type::adjacency_list& adj1 = g.get_adjacency_list(1);
    ASSERT_EQ(1, adj1.size());
    EXPECT_EQ(2, adj1[0].to);
    EXPECT_EQ(11, adj1[0].weight);

    const graph_type::adjacency_list& adj2 = g.get_adjacency_list(2);
    EXPECT_EQ(0, adj2.size());
}


TEST_F(weighted_graph_tester, test_adding_not_directed_edge)
{
    // when
    factory.add_not_directed_edge(weighted_edge_type(1/*from*/, 2/*to*/, 11/*weight*/));

    const graph_type& g = factory.create(V);

    // then
    const graph_type::adjacency_list& adj0 = g.get_adjacency_list(0);
    EXPECT_EQ(0, adj0.size());

    const graph_type::adjacency_list& adj1 = g.get_adjacency_list(1);
    ASSERT_EQ(1, adj1.size());
    EXPECT_EQ(2, adj1[0].to);
    EXPECT_EQ(11, adj1[0].weight);

    const graph_type::adjacency_list& adj2 = g.get_adjacency_list(2);
    EXPECT_EQ(1, adj2.size());
    EXPECT_EQ(1, adj2[0].to);
    EXPECT_EQ(11, adj2[0].weight);
}


TEST_F(weighted_graph_tester, tests_full_graph)
{

    // when
    factory.add_not_directed_edge(weighted_edge_type(0/*from*/, 1/*to*/, 11/*weight*/));
    factory.add_not_directed_edge(weighted_edge_type(0, 2, 22));
    factory.add_not_directed_edge(weighted_edge_type(1, 2, 33));

    const graph_type& g = factory.create(V);

    // then
    const graph_type::adjacency_list& adj0 = g.get_adjacency_list(0);
    ASSERT_EQ(2, adj0.size());

    EXPECT_EQ(1, adj0[0].to);
    EXPECT_EQ(11, adj0[0].weight);

    EXPECT_EQ(2, adj0[1].to);
    EXPECT_EQ(22, adj0[1].weight);

    const graph_type::adjacency_list& adj1 = g.get_adjacency_list(1);
    ASSERT_EQ(2, adj1.size());

    EXPECT_EQ(0, adj1[0].to);
    EXPECT_EQ(11, adj1[0].weight);

    EXPECT_EQ(2, adj1[1].to);
    EXPECT_EQ(33, adj1[1].weight);

    const graph_type::adjacency_list& adj2 = g.get_adjacency_list(2);
    ASSERT_EQ(2, adj2.size());

    EXPECT_EQ(0, adj2[0].to);
    EXPECT_EQ(22, adj2[0].weight);

    EXPECT_EQ(1, adj2[1].to);
    EXPECT_EQ(33, adj2[1].weight);
}


TEST_F(weighted_graph_tester, tests_reset)
{
    // given
    factory.add_not_directed_edge(weighted_edge_type(0/*from*/, 1/*to*/, 11/*weight*/));
    factory.add_not_directed_edge(weighted_edge_type(0, 2, 22));
    factory.add_not_directed_edge(weighted_edge_type(1, 2, 33));

    // when
    factory.reset();
    const graph_type& g = factory.create(V);

    // then
    EXPECT_EQ(0, g.get_adjacency_list(0).size());
    EXPECT_EQ(0, g.get_adjacency_list(1).size());
    EXPECT_EQ(0, g.get_adjacency_list(2).size());
}


} // namespace testing
} // namespace graphs
} // namespace pk
