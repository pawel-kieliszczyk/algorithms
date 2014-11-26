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
    static const int VERTICES = 9;
    static const int MAX_VERTEX_DEGREE = 13;

    typedef weighted_graph<VERTICES, MAX_VERTEX_DEGREE> weighted_graph_type;

    weighted_graph_type g;
};

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
TEST_F(shortest_paths_dijkstra_tester, test)
{
    // given
    g.add_not_directed_edge(0/*from*/, 1/*to*/, 4/*weight*/);
    g.add_not_directed_edge(0, 7, 8);
    g.add_not_directed_edge(1, 2, 8);
    g.add_not_directed_edge(1, 7, 11);
    g.add_not_directed_edge(2, 3, 7);
    g.add_not_directed_edge(2, 5, 4);
    g.add_not_directed_edge(2, 8, 2);
    g.add_not_directed_edge(3, 4, 9);
    g.add_not_directed_edge(3, 5, 14);
    g.add_not_directed_edge(4, 5, 10);
    g.add_not_directed_edge(5, 6, 2);
    g.add_not_directed_edge(6, 7, 1);
    g.add_not_directed_edge(6, 8, 6);
    g.add_not_directed_edge(7, 8, 7);

    const int starting_vertex = 0;
    gt::StrictMock<callback_mock> cm;

    // expect
    EXPECT_CALL(cm, notify(starting_vertex/*to*/, 0/*path length*/));
    EXPECT_CALL(cm, notify(1/*to*/, 4/*path length*/));
    EXPECT_CALL(cm, notify(7/*to*/, 8/*path length*/));
    // ...

    // when and then
    pk::shortest_paths_dijkstra::run(g, starting_vertex, cm);
}


} // namespace testing
} // namespace pk
