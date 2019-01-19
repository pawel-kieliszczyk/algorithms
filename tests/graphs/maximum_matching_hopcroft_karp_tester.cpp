#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "graphs/edge_types.hpp"
#include "graphs/bipartite_graph.hpp"
#include "graphs/maximum_matching_hopcroft_karp.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{


struct maximum_matching_hopcroft_karp_tester : public gt::Test
{
    static const int U = 5;
    static const int V = 5;
    static const int E = 10;

    typedef bipartite_graph_factory<U, V, E, edge> bipartite_graph_factory_type;
    typedef bipartite_graph_factory_type::bipartite_graph_type bipartite_graph_type;

    bipartite_graph_factory_type factory;
};


/**
 * (0)--->(0)
 *         ^
 *    ____/
 *   /
 * (1)    (1)
 */
TEST_F(maximum_matching_hopcroft_karp_tester, test_small_graph_matching_eq_1)
{
    // given
    factory.add_directed_edge_uv(edge(0, 0));
    factory.add_directed_edge_uv(edge(1, 0));

    const bipartite_graph_type& g = factory.create(2, 2);

    // when and then
    maximum_matching_hopcroft_karp<bipartite_graph_type> hk;
    EXPECT_EQ(1, hk.run(g));
}


/**
 * (0)--->(0)
 *
 * (1)--->(1)
 */
TEST_F(maximum_matching_hopcroft_karp_tester, test_small_graph_matching_eq_2)
{
    // given
    factory.add_directed_edge_uv(edge(0, 0));
    factory.add_directed_edge_uv(edge(1, 1));

    const bipartite_graph_type& g = factory.create(2, 2);

    // when and then
    maximum_matching_hopcroft_karp<bipartite_graph_type> hk;
    EXPECT_EQ(2, hk.run(g));
}


TEST_F(maximum_matching_hopcroft_karp_tester, test_small_graph_matching_eq_5)
{
    // given
    factory.add_directed_edge_uv(edge(0, 0));
    factory.add_directed_edge_uv(edge(0, 1));

    factory.add_directed_edge_uv(edge(1, 0));
    factory.add_directed_edge_uv(edge(1, 4));

    factory.add_directed_edge_uv(edge(2, 2));
    factory.add_directed_edge_uv(edge(2, 3));

    factory.add_directed_edge_uv(edge(3, 0));
    factory.add_directed_edge_uv(edge(3, 4));

    factory.add_directed_edge_uv(edge(4, 1));
    factory.add_directed_edge_uv(edge(4, 3));

    const bipartite_graph_type& g = factory.create(5, 5);

    // when and then
    maximum_matching_hopcroft_karp<bipartite_graph_type> hk;
    EXPECT_EQ(5, hk.run(g));
}


} // namespace testing
} // namespace graphs
} // namespace pk
