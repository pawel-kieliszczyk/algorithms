#include <gtest/gtest.h>

#include "graph.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct graph_tester : public gt::Test
{
    static const int VERTICES = 3;
    static const int MAX_VERTEX_DEGREE = 5;

    typedef graph<VERTICES, MAX_VERTEX_DEGREE> graph_type;

    // tested class:
    graph_type g;
};


TEST_F(graph_tester, test_empty_graph)
{
    ASSERT_EQ(3, g.size());

    EXPECT_EQ(0, g.get_adjacency_list(0).size());
    EXPECT_EQ(0, g.get_adjacency_list(1).size());
    EXPECT_EQ(0, g.get_adjacency_list(2).size());
}


} // namespace testing
} // namespace pk
