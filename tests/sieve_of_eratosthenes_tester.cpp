#include <gtest/gtest.h>

#include "sieve_of_eratosthenes.hpp"


namespace gt = testing;


namespace pk
{
namespace testing
{


struct sieve_of_eratosthenes_tester : public gt::Test
{
    static const int RANGE = 20;

    // tested class:
    sieve_of_eratosthenes<RANGE> sieve; // computes prime numbers in [0, RANGE-1]
};


TEST_F(sieve_of_eratosthenes_tester, tests_sieve_array)
{
    // when
    const bool* array = sieve.get_sieve_array();

    // then
    EXPECT_FALSE(array[0]);
    EXPECT_FALSE(array[1]);
    EXPECT_TRUE(array[2]);
    EXPECT_TRUE(array[3]);
    EXPECT_FALSE(array[4]);
    EXPECT_TRUE(array[5]);
    EXPECT_FALSE(array[6]);
    EXPECT_TRUE(array[7]);
    EXPECT_FALSE(array[8]);
    EXPECT_FALSE(array[9]);
    EXPECT_FALSE(array[10]);
    EXPECT_TRUE(array[11]);
    EXPECT_FALSE(array[12]);
    EXPECT_TRUE(array[13]);
    EXPECT_FALSE(array[14]);
    EXPECT_FALSE(array[15]);
    EXPECT_FALSE(array[16]);
    EXPECT_TRUE(array[17]);
    EXPECT_FALSE(array[18]);
    EXPECT_TRUE(array[19]);
}


TEST_F(sieve_of_eratosthenes_tester, tests_checking_prime_numbers)
{
    // when and then
    EXPECT_FALSE(sieve.is_prime(0));
    EXPECT_FALSE(sieve.is_prime(1));
    EXPECT_TRUE(sieve.is_prime(2));
    EXPECT_TRUE(sieve.is_prime(3));
    EXPECT_FALSE(sieve.is_prime(4));
    EXPECT_TRUE(sieve.is_prime(5));
    EXPECT_FALSE(sieve.is_prime(6));
    EXPECT_TRUE(sieve.is_prime(7));
    EXPECT_FALSE(sieve.is_prime(8));
    EXPECT_FALSE(sieve.is_prime(9));
    EXPECT_FALSE(sieve.is_prime(10));
    EXPECT_TRUE(sieve.is_prime(11));
    EXPECT_FALSE(sieve.is_prime(12));
    EXPECT_TRUE(sieve.is_prime(13));
    EXPECT_FALSE(sieve.is_prime(14));
    EXPECT_FALSE(sieve.is_prime(15));
    EXPECT_FALSE(sieve.is_prime(16));
    EXPECT_TRUE(sieve.is_prime(17));
    EXPECT_FALSE(sieve.is_prime(18));
    EXPECT_TRUE(sieve.is_prime(19));
}


} // namespace testing
} // namespace pk
