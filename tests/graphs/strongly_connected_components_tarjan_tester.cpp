#include <gtest/gtest.h>

#include "graphs/strongly_connected_components_tarjan.hpp"
#include "graphs/edge_types.hpp"
#include "graphs/graph.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{


struct strongly_connected_components_tarjan_tester : public gt::Test
{
    static const int V = 10;
    static const int E = 20;

    typedef edge edge_type;
    typedef graph_factory<V, E, edge_type> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    graph_factory_type gf;

    // tested class:
    strongly_connected_components_tarjan<graph_type> scc;
};


/**
 * (0)--->(1)--------->(2)<--->(3)
 *  ^      | \___.      |       ^
 *  |      |     |      |       |
 *  |      v     v      v       v
 *  `-----(4)-->(5)<-->(6)<----(7)
 */
TEST_F(strongly_connected_components_tarjan_tester, tests_xyz)
{
    // given
    gf.add_directed_edge(edge_type(0/*from*/, 1/*to*/));
    gf.add_directed_edge(edge_type(1, 2));
    gf.add_directed_edge(edge_type(1, 4));
    gf.add_directed_edge(edge_type(1, 5));
    gf.add_directed_edge(edge_type(2, 3));
    gf.add_directed_edge(edge_type(2, 6));
    gf.add_directed_edge(edge_type(3, 2));
    gf.add_directed_edge(edge_type(3, 7));
    gf.add_directed_edge(edge_type(4, 0));
    gf.add_directed_edge(edge_type(4, 5));
    gf.add_directed_edge(edge_type(5, 6));
    gf.add_directed_edge(edge_type(6, 5));
    gf.add_directed_edge(edge_type(7, 3));
    gf.add_directed_edge(edge_type(7, 6));

    const graph_type& g = gf.create(8);

    // when
    int component_ids[V];
    const int num_of_components = scc.run(g, component_ids);

    // then
    ASSERT_EQ(3, num_of_components);

    const int first_component_id = component_ids[0];
    EXPECT_EQ(first_component_id, component_ids[0]);
    EXPECT_EQ(first_component_id, component_ids[1]);
    EXPECT_EQ(first_component_id, component_ids[4]);

    const int second_component_id = component_ids[2];
    EXPECT_EQ(second_component_id, component_ids[2]);
    EXPECT_EQ(second_component_id, component_ids[3]);
    EXPECT_EQ(second_component_id, component_ids[7]);

    const int third_component_id = component_ids[5];
    EXPECT_EQ(third_component_id, component_ids[5]);
    EXPECT_EQ(third_component_id, component_ids[6]);
}


} // namespace testing
} // namespace graphs
} // namespace pk
