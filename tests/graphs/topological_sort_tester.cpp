#include <gtest/gtest.h>

#include "graphs/edge_types.hpp"
#include "graphs/graph.hpp"
#include "graphs/topological_sort.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{


struct topological_sort_tester : public gt::Test
{
    static const int V = 9;
    static const int E = 9;

    typedef edge edge_type;
    typedef graph_factory<V, E, edge_type> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    graph_factory_type gf;
};


TEST_F(topological_sort_tester, tests_sorting_two_not_connected_vertices)
{
    // given
    const int num_of_vertices = 2;
    const graph_type& g = gf.create(num_of_vertices);

    // when
    int order[num_of_vertices];
    EXPECT_TRUE(topological_sort::run(g, order));

    // then
    EXPECT_EQ(1, order[0]);
    EXPECT_EQ(0, order[1]);
}


TEST_F(topological_sort_tester, tests_sorting_two_connected_vertices)
{
    // given
    const int num_of_vertices = 2;

    gf.add_directed_edge(edge_type(1/*from*/, 0/*to*/));

    const graph_type& g = gf.create(num_of_vertices);

    // when
    int order[num_of_vertices];
    EXPECT_TRUE(topological_sort::run(g, order));

    // then
    EXPECT_EQ(1, order[0]);
    EXPECT_EQ(0, order[1]);
}


/**
 * Tested graph:
 * (0)    (3)
 *
 * (1)<---(2)
 */
TEST_F(topological_sort_tester, tests_sorting_small_graph)
{
    // given
    const int num_of_vertices = 4;

    gf.add_directed_edge(edge_type(2/*from*/, 1/*to*/));

    const graph_type& g = gf.create(num_of_vertices);

    // when
    int order[num_of_vertices];
    EXPECT_TRUE(topological_sort::run(g, order));

    // then
    EXPECT_EQ(3, order[0]);
    EXPECT_EQ(2, order[1]);
    EXPECT_EQ(1, order[2]);
    EXPECT_EQ(0, order[3]);
}


/**
 * Tested graph:
 * (2)--->(0)
 *  |      ^
 *  |      |
 *  v     /
 * (1)---'
 */
TEST_F(topological_sort_tester, tests_sorting_bigger_graph)
{
    // given
    const int num_of_vertices = 3;

    gf.add_directed_edge(edge_type(1/*from*/, 0/*to*/));
    gf.add_directed_edge(edge_type(2, 0));
    gf.add_directed_edge(edge_type(2, 1));

    const graph_type& g = gf.create(num_of_vertices);

    // when
    int order[num_of_vertices];
    EXPECT_TRUE(topological_sort::run(g, order));

    // then
    EXPECT_EQ(2, order[0]);
    EXPECT_EQ(1, order[1]);
    EXPECT_EQ(0, order[2]);
}


/**
 * Tested graph:
 *        (0)           (8)--->(7)
 *         ^             |      |
 *  (2)    |             |      |
 *         |\____        |      |
 *         |     \       V      V
 * (1)<---(4)--->(3)<---(5)--->(6)
 */
TEST_F(topological_sort_tester, tests_sorting_biggest_graph)
{
    // given
    const int num_of_vertices = 9;

    gf.add_directed_edge(edge_type(3/*from*/, 0/*to*/));
    gf.add_directed_edge(edge_type(4, 0));
    gf.add_directed_edge(edge_type(4, 1));
    gf.add_directed_edge(edge_type(4, 3));
    gf.add_directed_edge(edge_type(5, 3));
    gf.add_directed_edge(edge_type(5, 6));
    gf.add_directed_edge(edge_type(7, 6));
    gf.add_directed_edge(edge_type(8, 5));
    gf.add_directed_edge(edge_type(8, 7));

    const graph_type& g = gf.create(num_of_vertices);

    // when
    int order[num_of_vertices];
    EXPECT_TRUE(topological_sort::run(g, order));

    // then
    EXPECT_EQ(8, order[0]);
    EXPECT_EQ(7, order[1]);
    EXPECT_EQ(5, order[2]);
    EXPECT_EQ(6, order[3]);
    EXPECT_EQ(4, order[4]);
    EXPECT_EQ(3, order[5]);
    EXPECT_EQ(2, order[6]);
    EXPECT_EQ(1, order[7]);
    EXPECT_EQ(0, order[8]);
}


} // namespace testing
} // namespace graphs
} // namespace pk
