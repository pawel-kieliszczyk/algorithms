#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "graphs/edge_types.hpp"
#include "graphs/graph.hpp"
#include "graphs/max_flow_dinic.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{


struct max_flow_dinic_tester : public gt::Test
{
    static const int V = 7;
    static const int E = 22;

    typedef int capacity_type;
    typedef max_flow_edge<capacity_type> max_flow_edge_type;
    typedef graph_factory<V, E, max_flow_edge_type> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    graph_factory_type factory;

    void verify_flow(
            const graph_type& g,
            const int from,
            const int to,
            const capacity_type& expected_flow)
    {
        const graph_type::adjacency_list& adj_list = g.get_adjacency_list(from);
        for(int i = 0; i < adj_list.size(); ++i)
        {
            if(adj_list[i].to == to)
            {
                EXPECT_EQ(expected_flow, adj_list[i].flow);
                return;
            }
        }

        EXPECT_TRUE(false) << "Edge from " << from << " to " << to << " not found in the graph!";
    }
};


/**
 * (0)--1-->(1)
 */
TEST_F(max_flow_dinic_tester, tests_graph_with_one_edge_capacity_one)
{
    // given
    factory.add_residual_edge(max_flow_edge_type(0/*from*/, 1/*to*/, 1/*capacity*/));

    graph_type& g = factory.create(V);

    // when
    pk::graphs::max_flow_dinic<graph_type> dinic;
    EXPECT_EQ(1, dinic.run(g, 0, 1));

    // then
    verify_flow(g, 0/*from*/, 1/*to*/, 1/*expected flow*/);
}


/**
 * (0)--29-->(1)
 */
TEST_F(max_flow_dinic_tester, tests_graph_with_one_edge_capacity_twenty_nine)
{
    // given
    factory.add_residual_edge(max_flow_edge_type(0/*from*/, 1/*to*/, 29/*capacity*/));

    graph_type& g = factory.create(V);

    // when
    pk::graphs::max_flow_dinic<graph_type> dinic;
    EXPECT_EQ(29, dinic.run(g, 0, 1));

    // then
    verify_flow(g, 0/*from*/, 1/*to*/, 29/*expected flow*/);
}


/**
 * (0)<--3-->(1)
 */
TEST_F(max_flow_dinic_tester, tests_graph_with_cycle)
{
    // given
    factory.add_directed_edge(max_flow_edge_type(0/*from*/, 1/*to*/, 3/*capacity*/));
    factory.add_directed_edge(max_flow_edge_type(1, 0, 3));

    graph_type& g = factory.create(V);

    // when
    pk::graphs::max_flow_dinic<graph_type> dinic;
    EXPECT_EQ(3, dinic.run(g, 0, 1));

    // then
    verify_flow(g, 0/*from*/, 1/*to*/, 3/*expected flow*/);
    verify_flow(g, 1, 0,-3);
}


/**
 *         (3)
 *         ^ \__1___
 *    _1__/         \
 *   /               v
 * (0)--1-->(1)--1-->(2)
 *           |        |
 *          1|       1|
 *           v        v
 *          (4)--1-->(5)
 */
TEST_F(max_flow_dinic_tester, tests_custom_small_graph)
{
    // given
    factory.add_residual_edge(max_flow_edge_type(0/*from*/, 1/*to*/, 1/*capacity*/));
    factory.add_residual_edge(max_flow_edge_type(0, 3, 1));
    factory.add_residual_edge(max_flow_edge_type(1, 2, 1));
    factory.add_residual_edge(max_flow_edge_type(1, 4, 1));
    factory.add_residual_edge(max_flow_edge_type(2, 5, 1));
    factory.add_residual_edge(max_flow_edge_type(3, 2, 1));
    factory.add_residual_edge(max_flow_edge_type(4, 5, 1));

    graph_type& g = factory.create(V);

    // when
    pk::graphs::max_flow_dinic<graph_type> dinic;
    EXPECT_EQ(2, dinic.run(g, 0, 5));

    // then
    verify_flow(g, 0/*from*/, 1/*to*/, 1/*expected flow*/);
    verify_flow(g, 0, 3, 1);
    verify_flow(g, 1, 2, 0);
    verify_flow(g, 1, 4, 1);
    verify_flow(g, 2, 5, 1);
    verify_flow(g, 3, 2, 1);
    verify_flow(g, 4, 5, 1);
}


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
TEST_F(max_flow_dinic_tester, tests_custom_bigger_graph)
{
    // given
    factory.add_residual_edge(max_flow_edge_type(0/*from*/, 1/*to*/, 9/*capacity*/));
    factory.add_residual_edge(max_flow_edge_type(0, 4, 9));
    factory.add_residual_edge(max_flow_edge_type(1, 2, 7));
    factory.add_residual_edge(max_flow_edge_type(1, 3, 3));
    factory.add_residual_edge(max_flow_edge_type(2, 3, 4));
    factory.add_residual_edge(max_flow_edge_type(2, 6, 6));
    factory.add_residual_edge(max_flow_edge_type(3, 5, 2));
    factory.add_residual_edge(max_flow_edge_type(3, 6, 9));
    factory.add_residual_edge(max_flow_edge_type(4, 3, 3));
    factory.add_residual_edge(max_flow_edge_type(4, 5, 6));
    factory.add_residual_edge(max_flow_edge_type(5, 6, 8));

    graph_type& g = factory.create(V);

    // when
    pk::graphs::max_flow_dinic<graph_type> dinic;
    EXPECT_EQ(18, dinic.run(g, 0, 6));

    // then
    verify_flow(g, 0/*from*/, 1/*to*/, 9/*expected flow*/);
    verify_flow(g, 0, 4, 9);
    verify_flow(g, 1, 2, 6);
    verify_flow(g, 1, 3, 3);
    verify_flow(g, 2, 3, 0);
    verify_flow(g, 2, 6, 6);
    verify_flow(g, 3, 5, 0);
    verify_flow(g, 3, 6, 6);
    verify_flow(g, 4, 3, 3);
    verify_flow(g, 4, 5, 6);
    verify_flow(g, 5, 6, 6);
}


} // namespace testing
} // namespace graphs
} // namespace pk
