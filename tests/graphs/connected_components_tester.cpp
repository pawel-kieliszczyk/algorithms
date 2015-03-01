#include <gtest/gtest.h>

#include "graphs/connected_components.hpp"
#include "graphs/edge_types.hpp"
#include "graphs/graph.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{


struct connected_components_tester : public gt::Test
{
    static const int V = 10;
    static const int E = 20;

    typedef edge edge_type;
    typedef graph_factory<V, E, edge_type> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    graph_factory_type gf;

    // tested class:
    connected_components<graph_type> cc;
};


/**
 * Tests one-component graph:
 * (0)---(1)
 *   \   /
 *    (2)
 */
TEST_F(connected_components_tester, tests_number_of_components_in_one_component_graph)
{
    // given
    const int num_of_vertices = 3;

    gf.add_not_directed_edge(edge_type(0, 1));
    gf.add_not_directed_edge(edge_type(0, 2));
    gf.add_not_directed_edge(edge_type(1, 2));

    const graph_type& g = gf.create(num_of_vertices);

    // when
    cc.find_components(g);

    // then
    EXPECT_EQ(1, cc.get_number_of_components());
}


/**
 * Tests one-component graph:
 * (0)---(1)
 *   \   /
 *    (2)
 */
TEST_F(connected_components_tester, tests_component_ids_in_one_component_graph)
{
    // given
    const int num_of_vertices = 3;

    gf.add_not_directed_edge(edge_type(0, 1));
    gf.add_not_directed_edge(edge_type(0, 2));
    gf.add_not_directed_edge(edge_type(1, 2));

    const graph_type& g = gf.create(num_of_vertices);

    // when
    cc.find_components(g);

    // then
    EXPECT_EQ(cc.get_component_id(0), cc.get_component_id(1));
    EXPECT_EQ(cc.get_component_id(1), cc.get_component_id(2));
}


/**
 * Tests one-component graph:
 * (0)---(1)
 *   \   /
 *    (2)
 */
TEST_F(connected_components_tester, tests_raw_data_component_ids_in_one_component_graph)
{
    // given
    const int num_of_vertices = 3;

    gf.add_not_directed_edge(edge_type(0, 1));
    gf.add_not_directed_edge(edge_type(0, 2));
    gf.add_not_directed_edge(edge_type(1, 2));

    const graph_type& g = gf.create(num_of_vertices);

    // when
    cc.find_components(g);
    const int* component_ids = cc.get_raw_component_ids();

    // then
    EXPECT_EQ(component_ids[0], component_ids[1]);
    EXPECT_EQ(component_ids[1], component_ids[2]);
}


/**
 * Tests two-component graph:
 * (0)---(1)  (3)
 *   \   /     |
 *    (2)     (4)
 */
TEST_F(connected_components_tester, tests_number_of_components_in_two_component_graphs)
{
    // given
    const int num_of_vertices = 5;

    gf.add_not_directed_edge(edge_type(0, 1));
    gf.add_not_directed_edge(edge_type(0, 2));
    gf.add_not_directed_edge(edge_type(1, 2));
    gf.add_not_directed_edge(edge_type(3, 4));

    const graph_type& g = gf.create(num_of_vertices);

    // when
    cc.find_components(g);

    // then
    EXPECT_EQ(2, cc.get_number_of_components());
}


/**
 * Tests two-component graph:
 * (0)---(1)  (3)
 *   \   /     |
 *    (2)     (4)
 */
TEST_F(connected_components_tester, tests_component_ids_in_two_component_graphs)
{
    // given
    const int num_of_vertices = 5;

    gf.add_not_directed_edge(edge_type(0, 1));
    gf.add_not_directed_edge(edge_type(0, 2));
    gf.add_not_directed_edge(edge_type(1, 2));
    gf.add_not_directed_edge(edge_type(3, 4));

    const graph_type& g = gf.create(num_of_vertices);

    // when
    cc.find_components(g);

    // then
    EXPECT_EQ(cc.get_component_id(0), cc.get_component_id(1));
    EXPECT_EQ(cc.get_component_id(1), cc.get_component_id(2));

    EXPECT_NE(cc.get_component_id(0), cc.get_component_id(3));

    EXPECT_EQ(cc.get_component_id(3), cc.get_component_id(4));
}


/**
 * Tests two-component graph:
 * (0)---(1)  (3)
 *   \   /     |
 *    (2)     (4)
 */
TEST_F(connected_components_tester, tests_raw_data_component_ids_in_two_component_graphs)
{
    // given
    const int num_of_vertices = 5;

    gf.add_not_directed_edge(edge_type(0, 1));
    gf.add_not_directed_edge(edge_type(0, 2));
    gf.add_not_directed_edge(edge_type(1, 2));
    gf.add_not_directed_edge(edge_type(3, 4));

    const graph_type& g = gf.create(num_of_vertices);

    // when
    cc.find_components(g);
    const int* component_ids = cc.get_raw_component_ids();

    // then
    EXPECT_EQ(component_ids[0], component_ids[1]);
    EXPECT_EQ(component_ids[1], component_ids[2]);

    EXPECT_NE(component_ids[0], component_ids[3]);

    EXPECT_EQ(component_ids[3], component_ids[4]);
}


} // namespace testing
} // namespace graphs
} // namespace pk
