#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "edge_types.hpp"
#include "graph.hpp"
#include "shortest_paths_dijkstra.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{
namespace
{


class callback_mock
{
public:
    MOCK_METHOD2(notify, void(const int to, const int path_length));
};


} // namespace anonymous


struct shortest_paths_dijkstra_tester : public gt::Test
{
    static const int SMALL_V = 3;
    static const int SMALL_E = 6;
    static const int BIGGER_V = 9;
    static const int BIGGER_E = 28;

    typedef int weight_type;
    typedef weighted_edge<weight_type> weighted_edge_type;

    typedef graph_factory<SMALL_V, SMALL_E, weighted_edge_type> small_graph_factory_type;
    typedef small_graph_factory_type::graph_type small_graph_type;

    typedef graph_factory<BIGGER_V, BIGGER_E, weighted_edge_type> bigger_graph_factory_type;
    typedef bigger_graph_factory_type::graph_type bigger_graph_type;

    small_graph_factory_type small_graph_factory;
    bigger_graph_factory_type bigger_graph_factory;
};


/**
 * Tested graph:
 *
 *     4
 * (0)---(1)
 *  |   /
 * 2|  /1
 *  | /
 * (2)
 */
TEST_F(shortest_paths_dijkstra_tester, tests_small_graph)
{
    // given
    small_graph_factory.add_not_directed_edge(weighted_edge_type(0/*from*/, 1/*to*/, 4/*weight*/));
    small_graph_factory.add_not_directed_edge(weighted_edge_type(0, 2, 2));
    small_graph_factory.add_not_directed_edge(weighted_edge_type(1, 2, 1));

    small_graph_type g = small_graph_factory.create();

    const int starting_vertex = 0;
    gt::StrictMock<callback_mock> cm;

    // expect
    EXPECT_CALL(cm, notify(starting_vertex/*to*/, 0/*path length*/));
    EXPECT_CALL(cm, notify(2, 2));
    EXPECT_CALL(cm, notify(1, 3));

    // when and then
    shortest_paths_dijkstra::run(g, starting_vertex, cm);
}


/**
 * Tested graph:
 *
 *          8      7
 *      (1)---(2)-----(3)
 *     / |     | \     | \
 *   4/  |    2|  \    |  \9
 *   /   |11   |   |   |   \
 * (0)   |    (8)  |4  |14 (4)
 *   \   |   / |   |   |   /
 *   8\  | 7/  |6   \  |  /10
 *     \ | /   |     \ | /
 *      (7)---(6)-----(5)
 *          1      2
 */
TEST_F(shortest_paths_dijkstra_tester, tests_bigger_graph)
{
    // given
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(0/*from*/, 1/*to*/, 4/*weight*/));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(0, 7, 8));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(1, 2, 8));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(1, 7, 11));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(2, 3, 7));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(2, 5, 4));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(2, 8, 2));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(3, 4, 9));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(3, 5, 14));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(4, 5, 10));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(5, 6, 2));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(6, 7, 1));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(6, 8, 6));
    bigger_graph_factory.add_not_directed_edge(weighted_edge_type(7, 8, 7));
    
    bigger_graph_type g = bigger_graph_factory.create();

    const int starting_vertex = 0;
    gt::StrictMock<callback_mock> cm;

    // expect
    EXPECT_CALL(cm, notify(starting_vertex/*to*/, 0/*path length*/));
    EXPECT_CALL(cm, notify(1, 4));
    EXPECT_CALL(cm, notify(7, 8));
    EXPECT_CALL(cm, notify(6, 9));
    EXPECT_CALL(cm, notify(5, 11));
    EXPECT_CALL(cm, notify(2, 12));
    EXPECT_CALL(cm, notify(8, 14));
    EXPECT_CALL(cm, notify(3, 19));
    EXPECT_CALL(cm, notify(4, 21));

    // when and then
    shortest_paths_dijkstra::run(g, starting_vertex, cm);
}


/**
 * Tested graph:
 *
 *     2
 * (0)---(1)
 *
 * (2)
 */
TEST_F(shortest_paths_dijkstra_tester, tests_disconnected_graph)
{
    // given
    small_graph_factory.add_not_directed_edge(weighted_edge_type(0/*from*/, 1/*to*/, 2/*weight*/));

    small_graph_type g = small_graph_factory.create();

    const int starting_vertex = 0;
    gt::StrictMock<callback_mock> cm;

    // expect
    EXPECT_CALL(cm, notify(starting_vertex/*to*/, 0/*path length*/));
    EXPECT_CALL(cm, notify(1, 2));

    // when and then
    shortest_paths_dijkstra::run(g, starting_vertex, cm);
}


} // namespace testing
} // namespace pk
