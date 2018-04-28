#ifndef PK_GRAPHS_TESTING_VISITORMOCK_HPP
#define PK_GRAPHS_TESTING_VISITORMOCK_HPP


#include <gmock/gmock.h>


namespace pk
{
namespace graphs
{
namespace testing
{


class visitor_mock
{
public:
    MOCK_METHOD1(visit, void(const int));
};


} // namespace testing
} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_TESTING_VISITORMOCK_HPP
