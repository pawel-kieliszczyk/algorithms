#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "shortest_paths_dijkstra.hpp"
#include "weighted_graph.hpp"


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
    // given
    static const int SMALL_GRAPH_VERTICES = 3;
    static const int SMALL_GRAPH_MAX_VERTEX_DEGREE = 2;
    static const int BIGGER_GRAPH_VERTICES = 9;
    static const int BIGGER_GRAPH_MAX_VERTEX_DEGREE = 4;

    typedef weighted_graph<SMALL_GRAPH_VERTICES, SMALL_GRAPH_MAX_VERTEX_DEGREE> small_graph_type;
    typedef weighted_graph<BIGGER_GRAPH_VERTICES, BIGGER_GRAPH_MAX_VERTEX_DEGREE> bigger_graph_type;

    small_graph_type small_graph;
    bigger_graph_type bigger_graph;
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
    small_graph.add_not_directed_edge(0/*from*/, 1/*to*/, 4/*weight*/);
    small_graph.add_not_directed_edge(0, 2, 2);
    small_graph.add_not_directed_edge(1, 2, 1);

    const int starting_vertex = 0;
    gt::StrictMock<callback_mock> cm;

    // expect
    EXPECT_CALL(cm, notify(starting_vertex/*to*/, 0/*path length*/));
    EXPECT_CALL(cm, notify(2/*to*/, 2/*path length*/));
    EXPECT_CALL(cm, notify(1/*to*/, 3/*path length*/));

    // when and then
    shortest_paths_dijkstra::run(small_graph, starting_vertex, cm);
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
    bigger_graph.add_not_directed_edge(0/*from*/, 1/*to*/, 4/*weight*/);
    bigger_graph.add_not_directed_edge(0, 7, 8);
    bigger_graph.add_not_directed_edge(1, 2, 8);
    bigger_graph.add_not_directed_edge(1, 7, 11);
    bigger_graph.add_not_directed_edge(2, 3, 7);
    bigger_graph.add_not_directed_edge(2, 5, 4);
    bigger_graph.add_not_directed_edge(2, 8, 2);
    bigger_graph.add_not_directed_edge(3, 4, 9);
    bigger_graph.add_not_directed_edge(3, 5, 14);
    bigger_graph.add_not_directed_edge(4, 5, 10);
    bigger_graph.add_not_directed_edge(5, 6, 2);
    bigger_graph.add_not_directed_edge(6, 7, 1);
    bigger_graph.add_not_directed_edge(6, 8, 6);
    bigger_graph.add_not_directed_edge(7, 8, 7);

    const int starting_vertex = 0;
    gt::StrictMock<callback_mock> cm;

    // expect
    EXPECT_CALL(cm, notify(starting_vertex/*to*/, 0/*path length*/));
    EXPECT_CALL(cm, notify(1/*to*/, 4/*path length*/));
    EXPECT_CALL(cm, notify(7/*to*/, 8/*path length*/));
    EXPECT_CALL(cm, notify(6/*to*/, 9/*path length*/));
    EXPECT_CALL(cm, notify(5/*to*/, 11/*path length*/));
    EXPECT_CALL(cm, notify(2/*to*/, 12/*path length*/));
    EXPECT_CALL(cm, notify(8/*to*/, 14/*path length*/));
    EXPECT_CALL(cm, notify(3/*to*/, 19/*path length*/));
    EXPECT_CALL(cm, notify(4/*to*/, 21/*path length*/));

    // when and then
    shortest_paths_dijkstra::run(bigger_graph, starting_vertex, cm);
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
    small_graph.add_not_directed_edge(0/*from*/, 1/*to*/, 2/*weight*/);

    const int starting_vertex = 0;
    gt::StrictMock<callback_mock> cm;

    // expect
    EXPECT_CALL(cm, notify(starting_vertex/*to*/, 0/*path length*/));
    EXPECT_CALL(cm, notify(1/*to*/, 2/*path length*/));

    // when and then
    shortest_paths_dijkstra::run(small_graph, starting_vertex, cm);
}


} // namespace testing
} // namespace pk
