#ifndef PK_SIEVEOFERATOSTHENES_HPP
#define PK_SIEVEOFERATOSTHENES_HPP


#include <algorithm>


namespace pk
{


/**
 * Computes prime numbers in [0, Range-1].
 * Range should be greater than 1.
 */
template<int Range>
class sieve_of_eratosthenes
{
public:
    sieve_of_eratosthenes()
    {
        sieve[0] = false;
        sieve[1] = false;
        std::fill(sieve + 2, sieve + Range, true);

        for(int i = 2; i < Range; ++i)
        {
            if(sieve[i])
            {
                for(int w = i + i; w < Range; w += i)
                    sieve[w] = false;
            }
        }
    }

    bool is_prime(const int n) const
    {
        return sieve[n];
    }

    const bool* get_sieve_array() const
    {
        return sieve;
    }

private:
    bool sieve[Range];
};


} // namespace pk


#endif // PK_SIEVEOFERATOSTHENES_HPP
