#include <gtest/gtest.h>


#include "geometry/point.hpp"


namespace gt = testing;


namespace pk
{
namespace geometry
{
namespace testing
{


struct point_tester : public gt::Test
{
};


TEST_F(point_tester, create_point_default_constructor)
{
    // when & then
    point<int> p;
}


TEST_F(point_tester, create_point_nondefault_constructor)
{
    // given
    const int x = 13;
    const int y = 42;

    // when
    point<int> p(x, y);

    // then
    EXPECT_EQ(x, p.get_x());
    EXPECT_EQ(y, p.get_y());
}


TEST_F(point_tester, modify_x_and_verify)
{
    // given
    const int x = 13;
    const int y = 42;

    point<int> p(x, y);

    // when
    const int new_x = 99;
    p.set_x(new_x);

    // then
    EXPECT_EQ(new_x, p.get_x());
    EXPECT_EQ(y, p.get_y());
}


TEST_F(point_tester, modify_y_and_verify)
{
    // given
    const int x = 13;
    const int y = 42;

    point<int> p(x, y);

    // when
    const int new_y = 99;
    p.set_y(new_y);

    // then
    EXPECT_EQ(x, p.get_x());
    EXPECT_EQ(new_y, p.get_y());
}


TEST_F(point_tester, modify_x_and_y_and_verify)
{
    // given
    const int x = 13;
    const int y = 42;

    point<int> p(x, y);

    // when
    const int new_x = 99;
    const int new_y = 123;
    p.set_x(new_x);
    p.set_y(new_y);

    // then
    EXPECT_EQ(new_x, p.get_x());
    EXPECT_EQ(new_y, p.get_y());
}


} // namespace testing
} // namespace geometry
} // namespace pk
