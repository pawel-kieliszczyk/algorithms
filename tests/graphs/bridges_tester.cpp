#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "graphs/bridges.hpp"
#include "graphs/edge_types.hpp"
#include "graphs/graph.hpp"


namespace gt = testing;


namespace pk
{
namespace graphs
{
namespace testing
{
namespace
{


template<class edge_type>
class callback_mock
{
public:
    MOCK_METHOD1_T(notify, void(const edge_type& bridge));
};


} // namespace anonymous


struct bridges_tester : public gt::Test
{
    static const int V = 17;
    static const int E = 40;

    typedef edge edge_type;
    typedef graph_factory<V, E, edge_type> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    graph_factory_type gf;

    gt::StrictMock< callback_mock<edge_type> > callback;
};


/**
 * Tested graph:
 * (0)---(1)
 */
TEST_F(bridges_tester, tests_finding_bridges_in_graph_two_vertices_connected_with_one_edge)
{
    // given
    const int number_of_vertices = 2;
    gf.add_not_directed_edge(edge_type(0, 1));

    const graph_type& g = gf.create(number_of_vertices);

    // expect
    EXPECT_CALL(callback, notify(edge_type(0, 1)));

    // when
    bridges::run(g, callback);
}


/**
 * Tested graph:
 * (0)
 * / \
 * \ /
 * (1)
 *
 * FIXME: This is wrong behaviour and should be changed!
 */
TEST_F(bridges_tester, tests_finding_bridges_in_graph_two_vertices_connected_with_two_edges)
{
    // given
    const int number_of_vertices = 2;
    gf.add_not_directed_edge(edge_type(0, 1));
    gf.add_not_directed_edge(edge_type(0, 1));

    const graph_type& g = gf.create(number_of_vertices);

    // expect
    EXPECT_CALL(callback, notify(edge_type(0, 1)));

    // when
    bridges::run(g, callback);
}


/**
 * Tested graph:
 *    (0)---(1)   (7)   (12)
 *    / \         / \     \
 *   /   \       /   \     \
 * (2)---(3)   (8)   (9)  (13)
 *   \         / \        /  \
 *    \       /   \      /    \
 *    (4)   (10) (11)  (14)  (15)
 *    / \                \    /
 *   /   \                \  /
 * (5)---(6)              (16)
 */
TEST_F(bridges_tester, tests_finding_bridges_in_complex_graph)
{
    // given
    const int number_of_vertices = 17;
    gf.add_not_directed_edge(edge_type(0, 1));
    gf.add_not_directed_edge(edge_type(0, 2));
    gf.add_not_directed_edge(edge_type(0, 3));
    gf.add_not_directed_edge(edge_type(2, 3));
    gf.add_not_directed_edge(edge_type(2, 4));
    gf.add_not_directed_edge(edge_type(4, 5));
    gf.add_not_directed_edge(edge_type(4, 6));
    gf.add_not_directed_edge(edge_type(5, 6));
    gf.add_not_directed_edge(edge_type(7, 8));
    gf.add_not_directed_edge(edge_type(7, 9));
    gf.add_not_directed_edge(edge_type(8, 10));
    gf.add_not_directed_edge(edge_type(8, 11));
    gf.add_not_directed_edge(edge_type(12, 13));
    gf.add_not_directed_edge(edge_type(13, 14));
    gf.add_not_directed_edge(edge_type(13, 15));
    gf.add_not_directed_edge(edge_type(14, 16));
    gf.add_not_directed_edge(edge_type(15, 16));

    const graph_type& g = gf.create(number_of_vertices);

    // expect
    EXPECT_CALL(callback, notify(edge_type(0, 1)));
    EXPECT_CALL(callback, notify(edge_type(2, 4)));
    EXPECT_CALL(callback, notify(edge_type(7, 8)));
    EXPECT_CALL(callback, notify(edge_type(7, 9)));
    EXPECT_CALL(callback, notify(edge_type(8, 10)));
    EXPECT_CALL(callback, notify(edge_type(8, 11)));
    EXPECT_CALL(callback, notify(edge_type(12, 13)));

    // when
    bridges::run(g, callback);
}


} // namespace testing
} // namespace graphs
} // namespace pk
