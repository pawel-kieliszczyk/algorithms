#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "depth_first_search.hpp"
#include "graph.hpp"
#include "weighted_graph.hpp"

#include "mocks/visitor_mock.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct depth_first_search_tester : public gt::Test
{
    static const int VERTICES = 29;
    static const int MAX_VERTEX_DEGREE = 28;

    typedef graph<VERTICES, MAX_VERTEX_DEGREE> graph_type;
    typedef weighted_graph<VERTICES, MAX_VERTEX_DEGREE> weighted_graph_type;

    graph_type g;
    weighted_graph_type wg;
};


TEST_F(depth_first_search_tester, tests_empty_graph)
{
    // given
    const int starting_vertex = 0;
    gt::StrictMock<visitor_mock> vm;

    // expect
    EXPECT_CALL(vm, visit(starting_vertex));

    // when and then
    depth_first_search::run(g, starting_vertex, vm);
}


TEST_F(depth_first_search_tester, tests_empty_weighted_graph)
{
    // given
    const int starting_vertex = 0;
    gt::StrictMock<visitor_mock> vm;

    // expect
    EXPECT_CALL(vm, visit(starting_vertex));

    // when and then
    depth_first_search::run(wg, starting_vertex, vm);
}


/**
 * Tested graph:
 * 0 - 1 - 2
 * |   |   |
 * 3 - 4 - 5
 */
TEST_F(depth_first_search_tester, tests_custom_graph)
{
    // given
    g.add_not_directed_edge(0, 1);
    g.add_not_directed_edge(0, 3);
    g.add_not_directed_edge(1, 2);
    g.add_not_directed_edge(1, 4);
    g.add_not_directed_edge(2, 5);
    g.add_not_directed_edge(3, 4);
    g.add_not_directed_edge(4, 5);

    const int starting_vertex = 0;
    gt::StrictMock<visitor_mock> vm;

    // expect
    gt::InSequence seq;
    EXPECT_CALL(vm, visit(0)); // starting_vertex
    EXPECT_CALL(vm, visit(1));
    EXPECT_CALL(vm, visit(2));
    EXPECT_CALL(vm, visit(5));
    EXPECT_CALL(vm, visit(4));
    EXPECT_CALL(vm, visit(3));

    // when and then
    depth_first_search::run(g, starting_vertex, vm);
}


} // namespace testing
} // namespace pk
