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


} // namespace testing
} // namespace graphs
} // namespace pk
