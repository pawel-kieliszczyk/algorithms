#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "graphs/edge_types.hpp"
#include "graphs/graph.hpp"
#include "graphs/max_flow_edmonds_karp.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{


struct max_flow_edmonds_karp_tester : public gt::Test
{
    static const int V = 7;
    static const int E = 11;

    typedef int capacity_type;
    typedef max_flow_edge<capacity_type> max_flow_edge_type;
    typedef graph_factory<V, E, max_flow_edge_type> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    graph_factory_type factory;
};


/**
 *          7
 *     (1)---->(2)
 *     ^ \     / \
 *   9/  3\   /4  \6
 *   /     v v  9  v
 * (0)     (3)---->(6)
 *   \     ^ \     ^
 *   9\  3/   \2  /8
 *     v /     v /
 *     (4)---->(5)
 *          6
 */
TEST_F(max_flow_edmonds_karp_tester, tests_custom_graph)
{
    // given
    factory.add_directed_edge(max_flow_edge_type(0/*from*/, 1/*to*/, 9/*capacity*/));
    factory.add_directed_edge(max_flow_edge_type(0, 4, 9));
    factory.add_directed_edge(max_flow_edge_type(1, 2, 7));
    factory.add_directed_edge(max_flow_edge_type(1, 3, 3));
    factory.add_directed_edge(max_flow_edge_type(2, 3, 4));
    factory.add_directed_edge(max_flow_edge_type(2, 6, 6));
    factory.add_directed_edge(max_flow_edge_type(3, 5, 2));
    factory.add_directed_edge(max_flow_edge_type(3, 6, 9));
    factory.add_directed_edge(max_flow_edge_type(4, 3, 3));
    factory.add_directed_edge(max_flow_edge_type(4, 5, 6));
    factory.add_directed_edge(max_flow_edge_type(5, 6, 8));

    graph_type& g = factory.create(V);

    // when
    pk::graphs::max_flow_edmonds_karp::run(g, 0, 6);

    // then
    EXPECT_EQ(9, g.get_adjacency_list(0)[0].flow);
    EXPECT_EQ(9, g.get_adjacency_list(0)[1].flow);
    EXPECT_EQ(6, g.get_adjacency_list(1)[0].flow);
    EXPECT_EQ(3, g.get_adjacency_list(1)[1].flow);
    EXPECT_EQ(0, g.get_adjacency_list(2)[0].flow);
    EXPECT_EQ(6, g.get_adjacency_list(2)[1].flow);
    EXPECT_EQ(0, g.get_adjacency_list(3)[0].flow);
    EXPECT_EQ(6, g.get_adjacency_list(3)[1].flow);
    EXPECT_EQ(3, g.get_adjacency_list(4)[0].flow);
    EXPECT_EQ(6, g.get_adjacency_list(4)[1].flow);
    EXPECT_EQ(6, g.get_adjacency_list(5)[0].flow);
}


} // namespace testing
} // namespace graphs
} // namespace pk
