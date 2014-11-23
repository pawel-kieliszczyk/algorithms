#ifndef PK_TESTING_VISITORMOCK_HPP
#define PK_TESTING_VISITORMOCK_HPP


#include <gmock/gmock.h>


namespace pk
{
namespace testing
{


class visitor_mock
{
public:
    MOCK_METHOD1(visit, void(const int));
};


} // namespace testing
} // namespace pk


#endif // PK_TESTING_VISITORMOCK_HPP
