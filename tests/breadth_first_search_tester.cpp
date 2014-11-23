#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "breadth_first_search.hpp"
#include "graph.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


namespace
{


class visit_mock
{
public:
    MOCK_METHOD1(visit, void(const int));
};


} // namespace anonymous


struct breadth_first_search_tester : public gt::Test
{
    static const int VERTICES = 29;
    static const int MAX_VERTEX_DEGREE = 28;

    typedef graph<VERTICES, MAX_VERTEX_DEGREE> graph_type;

    graph_type g;
};


TEST_F(breadth_first_search_tester, tests_empty_graph)
{
    // given
    const int starting_vertex = 0;
    visit_mock vm;

    // expect
    EXPECT_CALL(vm, visit(starting_vertex));

    // when and then
    breadth_first_search::run(g, starting_vertex, vm);
}


} // namespace testing
} // namespace pk
