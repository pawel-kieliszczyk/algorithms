#include <gtest/gtest.h>

#include "prime_numbers_generator.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct prime_numbers_generator_tester : public gt::Test
{
    static const int RANGE = 20;

    typedef prime_numbers_generator<RANGE> generator_type;
};


TEST_F(prime_numbers_generator_tester, tests)
{
    // given
    generator_type gen;

    // when
    const generator_type::prime_numbers_collection& primes = gen.get_prime_numbers();

    // then
    ASSERT_EQ(8, primes.size());

    EXPECT_EQ(2, primes[0]);
    EXPECT_EQ(3, primes[1]);
    EXPECT_EQ(5, primes[2]);
    EXPECT_EQ(7, primes[3]);
    EXPECT_EQ(11, primes[4]);
    EXPECT_EQ(13, primes[5]);
    EXPECT_EQ(17, primes[6]);
    EXPECT_EQ(19, primes[7]);
}


} // namespace testing
} // namespace pk
