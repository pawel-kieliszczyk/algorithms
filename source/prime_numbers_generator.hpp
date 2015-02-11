#ifndef PK_PRIMENUMBERSGENERATOR_HPP
#define PK_PRIMENUMBERSGENERATOR_HPP


#include "sieve_of_eratosthenes.hpp"
#include "vector.hpp"


namespace pk
{


/**
 * Computes prime numbers in [0, Range-1].
 * Range should be greater than 1.
 */
template<int Range>
class prime_numbers_generator
{
public:
    typedef pk::vector<int, Range> prime_numbers_collection;

    prime_numbers_generator()
    {
        sieve_of_eratosthenes<Range> sieve;
        const bool* array = sieve.get_sieve_array();

        for(int i = 2; i < Range; ++i)
        {
            if(array[i])
                primes.push_back(i);
        }
    }

    const prime_numbers_collection& get_prime_numbers() const
    {
        return primes;
    }

private:
    prime_numbers_collection primes;
};


} // namespace pk


#endif // PK_PRIMENUMBERSGENERATOR_HPP
