#include <gtest/gtest.h>

#include "graphs/edge_types.hpp"
#include "graphs/graph.hpp"
#include "graphs/shortest_paths_floyd_warshall.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{


struct shortest_paths_floyd_warshall_tester : public gt::Test
{
    static const int V = 10;
    static const int E = 45;

    typedef int weight_type;
    typedef weighted_edge<weight_type> edge_type;
    typedef graph_factory<V, E, edge_type> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    graph_factory_type gf;

    // tested class:
    typedef shortest_paths_floyd_warshall<V, weight_type> floyd_warshall;
    floyd_warshall fw;
};


TEST_F(shortest_paths_floyd_warshall_tester, tests_graph_with_one_directed_edge)
{
    // given
    const int real_number_of_vertices = 3;

    gf.add_directed_edge(edge_type(1/*from*/, 2/*to*/, 42/*weight*/));
    const graph_type& g = gf.create(real_number_of_vertices);

    // when
    fw.run(g);

    // then
    floyd_warshall::shortest_paths_matrix m = fw.get_shortest_paths_matrix();

    EXPECT_EQ(0,           m[0][0]);
    EXPECT_EQ(fw.infinity, m[0][1]);
    EXPECT_EQ(fw.infinity, m[0][2]);

    EXPECT_EQ(fw.infinity, m[1][0]);
    EXPECT_EQ(0,           m[1][1]);
    EXPECT_EQ(42,          m[1][2]);

    EXPECT_EQ(fw.infinity, m[2][0]);
    EXPECT_EQ(fw.infinity, m[2][1]);
    EXPECT_EQ(0,           m[2][2]);
}


TEST_F(shortest_paths_floyd_warshall_tester, tests_graph_with_one_not_directed_edge)
{
    // given
    const int real_number_of_vertices = 3;

    gf.add_not_directed_edge(edge_type(1/*from*/, 2/*to*/, 42/*weight*/));
    const graph_type& g = gf.create(real_number_of_vertices);

    // when
    fw.run(g);

    // then
    floyd_warshall::shortest_paths_matrix m = fw.get_shortest_paths_matrix();

    EXPECT_EQ(0,           m[0][0]);
    EXPECT_EQ(fw.infinity, m[0][1]);
    EXPECT_EQ(fw.infinity, m[0][2]);

    EXPECT_EQ(fw.infinity, m[1][0]);
    EXPECT_EQ(0,           m[1][1]);
    EXPECT_EQ(42,          m[1][2]);

    EXPECT_EQ(fw.infinity, m[2][0]);
    EXPECT_EQ(42,          m[2][1]);
    EXPECT_EQ(0,           m[2][2]);
}


/**
 * Tested graph:
 *
 *      5       7
 * (0)-----(1)-----(2)
 */
TEST_F(shortest_paths_floyd_warshall_tester, tests_graph_with_two_not_directed_edges)
{
    // given
    const int real_number_of_vertices = 3;

    gf.add_not_directed_edge(edge_type(0/*from*/, 1/*to*/, 5/*weight*/));
    gf.add_not_directed_edge(edge_type(1, 2, 7));

    const graph_type& g = gf.create(real_number_of_vertices);

    // when
    fw.run(g);

    // then
    floyd_warshall::shortest_paths_matrix m = fw.get_shortest_paths_matrix();

    EXPECT_EQ(0,  m[0][0]);
    EXPECT_EQ(5,  m[0][1]);
    EXPECT_EQ(12, m[0][2]);

    EXPECT_EQ(5, m[1][0]);
    EXPECT_EQ(0, m[1][1]);
    EXPECT_EQ(7, m[1][2]);

    EXPECT_EQ(12, m[2][0]);
    EXPECT_EQ(7,  m[2][1]);
    EXPECT_EQ(0,  m[2][2]);
}


/**
 * Tested graph:
 *
 *     11      -2
 * (0)---->(1)---->(2)
 */
TEST_F(shortest_paths_floyd_warshall_tester, tests_graph_with_negative_edge_weight)
{
    // given
    const int real_number_of_vertices = 3;

    gf.add_directed_edge(edge_type(0/*from*/, 1/*to*/, 11/*weight*/));
    gf.add_directed_edge(edge_type(1, 2, -2));

    const graph_type& g = gf.create(real_number_of_vertices);

    // when
    fw.run(g);

    // then
    floyd_warshall::shortest_paths_matrix m = fw.get_shortest_paths_matrix();

    EXPECT_EQ(0,  m[0][0]);
    EXPECT_EQ(11, m[0][1]);
    EXPECT_EQ(9,  m[0][2]);

    EXPECT_EQ(fw.infinity, m[1][0]);
    EXPECT_EQ(0,           m[1][1]);
    EXPECT_EQ(-2,          m[1][2]);

    EXPECT_EQ(fw.infinity, m[2][0]);
    EXPECT_EQ(fw.infinity, m[2][1]);
    EXPECT_EQ(0,           m[2][2]);
}


/**
 * Tested graph:
 *
 *     8     3
 * (0)---(1)---(2)
 *  | \   |
 * 3|  \7 |1
 *  |   \ |
 * (3)---(4)
 *     2
 */
TEST_F(shortest_paths_floyd_warshall_tester, tests_complex_graph)
{
    // given
    const int real_number_of_vertices = 5;

    gf.add_not_directed_edge(edge_type(0/*from*/, 1/*to*/, 8/*weight*/));
    gf.add_not_directed_edge(edge_type(0, 3, 3));
    gf.add_not_directed_edge(edge_type(0, 4, 7));
    gf.add_not_directed_edge(edge_type(1, 2, 3));
    gf.add_not_directed_edge(edge_type(1, 4, 1));
    gf.add_not_directed_edge(edge_type(3, 4, 2));

    const graph_type& g = gf.create(real_number_of_vertices);

    // when
    fw.run(g);

    // then
    floyd_warshall::shortest_paths_matrix m = fw.get_shortest_paths_matrix();

    EXPECT_EQ(0, m[0][0]);
    EXPECT_EQ(6, m[0][1]);
    EXPECT_EQ(9, m[0][2]);
    EXPECT_EQ(3, m[0][3]);
    EXPECT_EQ(5, m[0][4]);

    EXPECT_EQ(6, m[1][0]);
    EXPECT_EQ(0, m[1][1]);
    EXPECT_EQ(3, m[1][2]);
    EXPECT_EQ(3, m[1][3]);
    EXPECT_EQ(1, m[1][4]);

    EXPECT_EQ(9, m[2][0]);
    EXPECT_EQ(3, m[2][1]);
    EXPECT_EQ(0, m[2][2]);
    EXPECT_EQ(6, m[2][3]);
    EXPECT_EQ(4, m[2][4]);

    EXPECT_EQ(3, m[3][0]);
    EXPECT_EQ(3, m[3][1]);
    EXPECT_EQ(6, m[3][2]);
    EXPECT_EQ(0, m[3][3]);
    EXPECT_EQ(2, m[3][4]);

    EXPECT_EQ(5, m[4][0]);
    EXPECT_EQ(1, m[4][1]);
    EXPECT_EQ(4, m[4][2]);
    EXPECT_EQ(2, m[4][3]);
    EXPECT_EQ(0, m[4][4]);
}


/**
 * Tested graph:
 *
 *     5.2     7.1
 * (0)-----(1)-----(2)
 */
TEST_F(shortest_paths_floyd_warshall_tester, tests_graph_with_noninteger_edge_weights)
{
    typedef weighted_edge<double> noninteger_edge_type;
    typedef graph_factory<V, E, noninteger_edge_type> noninteger_graph_factory_type;
    noninteger_graph_factory_type graph_factory;

    // given
    const int real_number_of_vertices = 3;

    graph_factory.add_not_directed_edge(noninteger_edge_type(0/*from*/, 1/*to*/, 5.2/*weight*/));
    graph_factory.add_not_directed_edge(noninteger_edge_type(1, 2, 7.1));

    const noninteger_graph_factory_type::graph_type& g = graph_factory.create(real_number_of_vertices);

    // when
    typedef shortest_paths_floyd_warshall<V, double> noninteger_floyd_warshall;
    noninteger_floyd_warshall fw;
    fw.run(g);

    // then
    noninteger_floyd_warshall::shortest_paths_matrix m = fw.get_shortest_paths_matrix();

    EXPECT_EQ(0.0,  m[0][0]);
    EXPECT_EQ(5.2,  m[0][1]);
    EXPECT_EQ(12.3, m[0][2]);

    EXPECT_EQ(5.2, m[1][0]);
    EXPECT_EQ(0.0, m[1][1]);
    EXPECT_EQ(7.1, m[1][2]);

    EXPECT_EQ(12.3, m[2][0]);
    EXPECT_EQ(7.1,  m[2][1]);
    EXPECT_EQ(0.0,  m[2][2]);
}


} // namespace testing
} // namespace graphs
} // namespace pk
