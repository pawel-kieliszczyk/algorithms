#ifndef PK_BIGINT_HPP
#define PK_BIGINT_HPP


#include <algorithm>
#include <cstring>


namespace pk
{
namespace detail
{


typedef unsigned char digit_type;


inline digit_type char_to_digit(const char c)
{
    return (c - '0');
}


inline digit_type digit_to_char(const digit_type d)
{
    return ('0' + d);
}


} // namespace detail


template<int MAX_DECIMAL_SIZE>
class bigint
{
public:
    bigint() : sz(1), sgn(sign_plus) { digits[0] = 0; }

    bigint(const bigint& other) : sz(other.sz), sgn(other.sgn)
    {
        std::copy(other.digits, other.digits + sz, digits);
    }

    bigint& operator=(const bigint& other)
    {
        sz = other.sz;
        sgn = other.sgn;

        std::copy(other.digits, other.digits + sz, digits);

        return *this;
    }

    bigint(const char* init_value)
    {
        if(init_value[0] == '-')
        {
            sgn = sign_minus;
            initialize_digits(init_value + 1);

            check_minus_zero();
        }
        else
        {
            sgn = sign_plus;
            initialize_digits(init_value);
        }
    }

    bigint& operator+()
    {
        return *this;
    }

    const bigint& operator+() const
    {
        return *this;
    }

    bigint operator-()
    {
        sgn = opposite_sign(sgn);
        bigint result = *this;
        sgn = opposite_sign(sgn);

        return result;
    }

    bool is_positive() const
    {
        return ((sgn == sign_plus) && !(is_zero()));
    }

    bool is_negative() const
    {
        return (sgn == sign_minus);
    }

    const char* c_str() const
    {
        if(sgn == sign_minus)
        {
            cstr[0] = '-';
            std::transform(digits, digits + sz, cstr + 1, detail::digit_to_char);
            std::reverse(cstr + 1, cstr + sz + 1);
            cstr[sz+1] = '\0';
        }
        else
        {
            std::transform(digits, digits + sz, cstr, detail::digit_to_char);
            std::reverse(cstr, cstr + sz);
            cstr[sz] = '\0';
        }

        return cstr;
    }

private:
    enum sign
    {
        sign_plus = 0,
        sign_minus = 1
    };

    sign opposite_sign(const sign s)
    {
        return (1 - s);
    }

    void initialize_digits(const char* init_value)
    {
        sz = strlen(init_value);

        std::transform(init_value, init_value + sz, digits, detail::char_to_digit);
        std::reverse(digits, digits + sz);
    }

    void remove_leading_zeros()
    {
        while((sz > 1) && (digits[sz-1] == 0))
            --sz;
    }

    void check_minus_zero()
    {
        if(sgn == sign_plus)
            return;

        if(sz > 1)
            return;

        if(digits[0] == 0)
            sgn = sign_plus;
    }

    bool is_zero() const
    {
        if((sz == 1) && (digits[0] == 0))
            return true;

        return false;
    }

    detail::digit_type digit_or_zero(const int i) const
    {
        if(i < sz)
            return digits[i];

        return 0;
    }

    detail::digit_type digits[MAX_DECIMAL_SIZE];
    int sz;

    sign sgn;

    mutable char cstr[MAX_DECIMAL_SIZE];
};


template<int MAX_DECIMAL_SIZE>
inline bool operator==(const bigint<MAX_DECIMAL_SIZE>& left, const bigint<MAX_DECIMAL_SIZE>& right)
{
    return (strcmp(left.c_str(), right.c_str()) == 0);
}


template<int MAX_DECIMAL_SIZE>
inline bool operator!=(const bigint<MAX_DECIMAL_SIZE>& left, const bigint<MAX_DECIMAL_SIZE>& right)
{
    return !(left == right);
}


template<int MAX_DECIMAL_SIZE>
inline bool operator<(const bigint<MAX_DECIMAL_SIZE>& left, const bigint<MAX_DECIMAL_SIZE>& right)
{
    const char* left_rep = left.c_str();
    const char* right_rep = right.c_str();

    if(left_rep[0] == '-')
    {
        if(right_rep[0] == '-')
        {
            ++left_rep;
            ++right_rep;

            const int left_size = strlen(left_rep);
            const int right_size = strlen(right_rep);

            if(left_size < right_size)
                return false;

            if(left_size > right_size)
                return true;

            for(int i = 0; i < left_size; ++i)
            {
                if(left_rep[i] < right_rep[i])
                    return false;

                if(left_rep[i] > right_rep[i])
                    return true;
            }

            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if(right_rep[0] == '-')
        {
            return false;
        }
        else
        {
            const int left_size = strlen(left_rep);
            const int right_size = strlen(right_rep);

            if(left_size < right_size)
                return true;

            if(left_size > right_size)
                return false;

            for(int i = 0; i < left_size; ++i)
            {
                if(left_rep[i] < right_rep[i])
                    return true;

                if(left_rep[i] > right_rep[i])
                    return false;
            }

            return false;
        }
    }
}


} // namespace pk


#endif // PK_BIGINT_HPP
