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
TEST_F(max_flow_edmonds_karp_tester, tests_custom_small_graph)
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
    pk::graphs::max_flow_edmonds_karp::run(g, 0, 5);

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
TEST_F(max_flow_edmonds_karp_tester, tests_custom_bigger_graph)
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
    pk::graphs::max_flow_edmonds_karp::run(g, 0, 6);

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
