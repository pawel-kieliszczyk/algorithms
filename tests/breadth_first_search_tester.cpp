#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "breadth_first_search.hpp"
#include "edge_types.hpp"
#include "graph.hpp"

#include "mocks/visitor_mock.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct breadth_first_search_tester : public gt::Test
{
    static const int V = 29;
    static const int E = 28;

    typedef graph_factory<V, E, edge> graph_factory_type;
    typedef graph_factory_type::graph_type graph_type;

    graph_factory_type factory;
};


TEST_F(breadth_first_search_tester, tests_empty_graph)
{
    // given
    graph_type g = factory.create();

    const int starting_vertex = 0;
    gt::StrictMock<visitor_mock> vm;

    // expect
    EXPECT_CALL(vm, visit(starting_vertex));

    // when and then
    breadth_first_search::run(g, starting_vertex, vm);
}


/**
 * Tested graph:
 * 0 -- 1 -- 2
 * |    |    |
 * 3 -- 4 -- 5
 */
TEST_F(breadth_first_search_tester, tests_custom_graph)
{
    // given
    factory.add_not_directed_edge(edge(0/*from*/, 1/*to*/));
    factory.add_not_directed_edge(edge(0, 3));
    factory.add_not_directed_edge(edge(1, 2));
    factory.add_not_directed_edge(edge(1, 4));
    factory.add_not_directed_edge(edge(2, 5));
    factory.add_not_directed_edge(edge(3, 4));
    factory.add_not_directed_edge(edge(4, 5));

    graph_type g = factory.create();

    const int starting_vertex = 0;
    gt::StrictMock<visitor_mock> vm;

    // expect
    gt::InSequence seq;
    EXPECT_CALL(vm, visit(0)); // starting_vertex
    EXPECT_CALL(vm, visit(1));
    EXPECT_CALL(vm, visit(3));
    EXPECT_CALL(vm, visit(2));
    EXPECT_CALL(vm, visit(4));
    EXPECT_CALL(vm, visit(5));

    // when and then
    breadth_first_search::run(g, starting_vertex, vm);
}


} // namespace testing
} // namespace pk
