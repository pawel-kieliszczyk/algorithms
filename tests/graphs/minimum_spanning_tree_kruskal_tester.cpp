#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "graphs/edge_types.hpp"
#include "graphs/graph.hpp"
#include "graphs/minimum_spanning_tree_kruskal.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{


struct minimum_spanning_tree_kruskal_tester : public gt::Test
{
    static const int V = 6;
    static const int E = 14;

    typedef int weight_type;
    typedef weighted_edge<weight_type> weighted_edge_type;
    typedef graph_factory<V, E, weighted_edge_type> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    graph_factory_type factory;
};


namespace
{

struct callback_mock
{
    MOCK_METHOD1(notify, void(const minimum_spanning_tree_kruskal_tester::weighted_edge_type&));
};

} // namespace anonymous


/**
 * Tested graph:
 *     6     5
 * (0)---(1)---(2)
 *  |     |     |
 *  |4    |4    |3
 *  |     |     |
 * (3)---(4)---(5)
 *     5     1
 */
TEST_F(minimum_spanning_tree_kruskal_tester, tests_sample_graph)
{
    // given
    factory.add_not_directed_edge(weighted_edge_type(0/*from*/, 1/*to*/, 6/*weight*/));
    factory.add_not_directed_edge(weighted_edge_type(0, 3, 4));
    factory.add_not_directed_edge(weighted_edge_type(1, 2, 5));
    factory.add_not_directed_edge(weighted_edge_type(1, 4, 4));
    factory.add_not_directed_edge(weighted_edge_type(2, 5, 3));
    factory.add_not_directed_edge(weighted_edge_type(3, 4, 5));
    factory.add_not_directed_edge(weighted_edge_type(4, 5, 1));

    const graph_type& g = factory.create(V);
    gt::StrictMock<callback_mock> cm;

    // expect
    gt::InSequence seq;
    EXPECT_CALL(cm, notify(weighted_edge_type(4/*from*/, 5/*to*/, 1/*weight*/)));
    EXPECT_CALL(cm, notify(weighted_edge_type(2, 5, 3)));
    EXPECT_CALL(cm, notify(weighted_edge_type(0, 3, 4)));
    EXPECT_CALL(cm, notify(weighted_edge_type(1, 4, 4)));
    EXPECT_CALL(cm, notify(weighted_edge_type(3, 4, 5)));

    // when and then
    minimum_spanning_tree_kruskal::run(g, cm);
}


} // namespace testing
} // namespace graphs
} // namespace pk
