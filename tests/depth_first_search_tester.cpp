#include <gtest/gtest.h>

#include "depth_first_search.hpp"
#include "graph.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


namespace
{


struct visit_mock
{
    visit_mock() : visited(false) {}

    void operator()(const int vertex_id) { visited = true; }

    bool visited;
};


} // namespace anonymous


struct depth_first_search_tester : public gt::Test
{
    static const int VERTICES = 29;
    static const int MAX_VERTEX_DEGREE = 28;

    typedef graph<VERTICES, MAX_VERTEX_DEGREE> graph_type;

    graph_type g;
};


TEST_F(depth_first_search_tester, test)
{
    // given
    const int starting_vertex = 0;
    visit_mock vm;

    depth_first_search::run(g, starting_vertex, vm);

    EXPECT_TRUE(vm.visited);
}


} // namespace testing
} // namespace pk
