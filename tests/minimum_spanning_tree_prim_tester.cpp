#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "minimum_spanning_tree_prim.hpp"
#include "weighted_graph.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{
namespace
{

struct callback_mock
{
    MOCK_METHOD3(notify, void(const int, const int, const int));
};

} // namespace anonymous


struct minimum_spanning_tree_prim_tester : public gt::Test
{
    static const int VERTICES = 9;
    static const int MAX_VERTEX_DEGREE = 13;

    typedef weighted_graph<VERTICES, MAX_VERTEX_DEGREE> weighted_graph_type;

    weighted_graph_type g;
};


/**
 * Tested graph:
 *  0 --[6]-- 1 --[5]-- 2
 *  |         |         |
 * [4]       [4]       [3]
 *  |         |         |
 *  3 --[5]-- 4 --[1]-- 5
 */
TEST_F(minimum_spanning_tree_prim_tester, test)
{
    // given
    g.add_not_directed_edge(0/*from*/, 1/*to*/, 6/*weight*/);
    g.add_not_directed_edge(0, 3, 4);
    g.add_not_directed_edge(1, 2, 5);
    g.add_not_directed_edge(1, 4, 4);
    g.add_not_directed_edge(2, 5, 3);
    g.add_not_directed_edge(3, 4, 5);
    g.add_not_directed_edge(4, 5, 1);

    gt::StrictMock<callback_mock> cm;

    // expect
    gt::InSequence seq;
    EXPECT_CALL(cm, notify(0/*from*/, 3/*to*/, 4/*weight*/));
    EXPECT_CALL(cm, notify(3/*from*/, 4/*to*/, 5/*weight*/));
    EXPECT_CALL(cm, notify(4/*from*/, 5/*to*/, 1/*weight*/));
    EXPECT_CALL(cm, notify(5/*from*/, 2/*to*/, 3/*weight*/));
    EXPECT_CALL(cm, notify(4/*from*/, 1/*to*/, 4/*weight*/));

    // when and then
    minimum_spanning_tree_prim::run(g, 0/*starting vertex*/, cm);
}


} // namespace testing
} // namespace pk
