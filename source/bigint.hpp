#ifndef PK_BIGINT_HPP
#define PK_BIGINT_HPP


#include <algorithm>
#include <cstring>


namespace pk
{
//namespace detail
//{
//
//
//typedef unsigned char digit_type;
//
//
//inline digit_type char_to_digit(const char c)
//{
//    return (c - '0');
//}
//
//
//inline digit_type digit_to_char(const digit_type d)
//{
//    return ('0' + d);
//}
//
//
//} // namespace detail


template<int MAX_SIZE_IN_BINARY_REPRESENTATION>
class bigint
{
private:
    static const int MAX_SIZE_IN_DECIMAL_REPRESENTATION = MAX_SIZE_IN_BINARY_REPRESENTATION;

public:
    bigint()
    {
        std::fill(binary_representation, binary_representation + MAX_SIZE_IN_BINARY_REPRESENTATION, false);
    }

//    bigint() : sz(1), sgn(sign_plus) { digits[0] = 0; }
//
//    bigint(const bigint& other) : sz(other.sz), sgn(other.sgn)
//    {
//        std::copy(other.digits, other.digits + sz, digits);
//    }
//
//    bigint& operator=(const bigint& other)
//    {
//        sz = other.sz;
//        sgn = other.sgn;
//
//        std::copy(other.digits, other.digits + sz, digits);
//
//        return *this;
//    }

    bigint(const char* init_value_decimal)
    {
        std::fill(binary_representation, binary_representation + MAX_SIZE_IN_BINARY_REPRESENTATION, false);
        if(init_value_decimal[0] == '-')
        {
            binary_representation[0] = true;
            initialize_from_decimal(init_value_decimal + 1);
//            sgn = sign_minus;
//            initialize_digits(init_value + 1);
//
//            check_minus_zero();
        }
        else
        {
            initialize_from_decimal(init_value_decimal);
//            sgn = sign_plus;
//            initialize_digits(init_value);
        }
    }

//    bigint& operator+()
//    {
//        return *this;
//    }
//
//    const bigint& operator+() const
//    {
//        return *this;
//    }
//
//    bigint operator-()
//    {
//        sgn = opposite_sign(sgn);
//        bigint result = *this;
//        sgn = opposite_sign(sgn);
//
//        return result;
//    }
//
//    bool is_positive() const
//    {
//        return ((sgn == sign_plus) && !(is_zero()));
//    }
//
//    bool is_negative() const
//    {
//        return (sgn == sign_minus);
//    }
//
//    const char* c_str() const
//    {
//        if(sgn == sign_minus)
//        {
//            cstr[0] = '-';
//            std::transform(digits, digits + sz, cstr + 1, detail::digit_to_char);
//            std::reverse(cstr + 1, cstr + sz + 1);
//            cstr[sz+1] = '\0';
//        }
//        else
//        {
//            std::transform(digits, digits + sz, cstr, detail::digit_to_char);
//            std::reverse(cstr, cstr + sz);
//            cstr[sz] = '\0';
//        }
//
//        return cstr;
//    }
    const char* decimal_c_str() const
    {
        // TODO: fix negative numbers
        decimal_representation[MAX_SIZE_IN_DECIMAL_REPRESENTATION-1] = '\0';
        int decimal_idx = MAX_SIZE_IN_DECIMAL_REPRESENTATION - 2;
        decimal_representation[decimal_idx] = '0';
        for(int i = MAX_SIZE_IN_BINARY_REPRESENTATION - 1; i >= 0; --i)
        {
            //
        }

        return decimal_representation + decimal_idx;
    }

private:
//    enum sign
//    {
//        sign_plus = 0,
//        sign_minus = 1
//    };
//
//    sign opposite_sign(const sign s)
//    {
//        return (1 - s);
//    }

    void initialize_from_decimal(const char* init_value_decimal)
    {
        char decimal[MAX_SIZE_IN_DECIMAL_REPRESENTATION];
        int len = strlen(init_value_decimal);
        std::copy(init_value_decimal, init_value_decimal + len, decimal);
        std::reverse(decimal, decimal + len);
        for(int i = 0; i < len; ++i)
            decimal[i] -= '0';

        int binary_idx = MAX_SIZE_IN_BINARY_REPRESENTATION - 1;
        do
        {
            binary_representation[binary_idx--] = (decimal[0] % 2 == 1);
        }
        while(div_by_2(decimal, len));
//        sz = strlen(init_value);
        for(int i = 0; i < MAX_SIZE_IN_BINARY_REPRESENTATION; ++i)
            printf("%d", binary_representation[i]);
        printf("\n");
//
//        std::transform(init_value, init_value + sz, digits, detail::char_to_digit);
//        std::reverse(digits, digits + sz);
    }

    bool div_by_2(char* decimal, const int len)
    {
        bool all_zeros = true;
        for(int i = 0; i < len; ++i)
        {
            if(decimal[i] != 0)
            {
                all_zeros = false;
                break;
            }
        }

        if(all_zeros)
            return false;

        int c = 0;
        for(int i = len - 1; i >= 0; --i)
        {
            const int new_c = decimal[i] % 2;
            decimal[i] = (10*c + decimal[i]) / 2;
            c = new_c;
        }

        return true;
    }

//    void remove_leading_zeros()
//    {
//        while((sz > 1) && (digits[sz-1] == 0))
//            --sz;
//    }
//
//    void check_minus_zero()
//    {
//        if(sgn == sign_plus)
//            return;
//
//        if(sz > 1)
//            return;
//
//        if(digits[0] == 0)
//            sgn = sign_plus;
//    }
//
//    bool is_zero() const
//    {
//        if((sz == 1) && (digits[0] == 0))
//            return true;
//
//        return false;
//    }
//
//    detail::digit_type digit_or_zero(const int i) const
//    {
//        if(i < sz)
//            return digits[i];
//
//        return 0;
//    }
//
//    detail::digit_type digits[MAX_DECIMAL_SIZE];
//    int sz;
//
//    sign sgn;
//
//    mutable char cstr[MAX_DECIMAL_SIZE];
    bool binary_representation[MAX_SIZE_IN_BINARY_REPRESENTATION];
    mutable char decimal_representation[MAX_SIZE_IN_DECIMAL_REPRESENTATION]; // TODO: reduce the size
};


//template<int MAX_DECIMAL_SIZE>
//inline bool operator==(const bigint<MAX_DECIMAL_SIZE>& left, const bigint<MAX_DECIMAL_SIZE>& right)
//{
//    return (strcmp(left.c_str(), right.c_str()) == 0);
//}
//
//
//template<int MAX_DECIMAL_SIZE>
//inline bool operator!=(const bigint<MAX_DECIMAL_SIZE>& left, const bigint<MAX_DECIMAL_SIZE>& right)
//{
//    return !(left == right);
//}
//
//
//template<int MAX_DECIMAL_SIZE>
//inline bool operator<(const bigint<MAX_DECIMAL_SIZE>& left, const bigint<MAX_DECIMAL_SIZE>& right)
//{
//    const char* left_rep = left.c_str();
//    const char* right_rep = right.c_str();
//
//    if(left_rep[0] == '-')
//    {
//        if(right_rep[0] == '-')
//        {
//            ++left_rep;
//            ++right_rep;
//
//            const int left_size = strlen(left_rep);
//            const int right_size = strlen(right_rep);
//
//            if(left_size < right_size)
//                return false;
//
//            if(left_size > right_size)
//                return true;
//
//            for(int i = 0; i < left_size; ++i)
//            {
//                if(left_rep[i] < right_rep[i])
//                    return false;
//
//                if(left_rep[i] > right_rep[i])
//                    return true;
//            }
//
//            return false;
//        }
//        else
//        {
//            return true;
//        }
//    }
//    else
//    {
//        if(right_rep[0] == '-')
//        {
//            return false;
//        }
//        else
//        {
//            const int left_size = strlen(left_rep);
//            const int right_size = strlen(right_rep);
//
//            if(left_size < right_size)
//                return true;
//
//            if(left_size > right_size)
//                return false;
//
//            for(int i = 0; i < left_size; ++i)
//            {
//                if(left_rep[i] < right_rep[i])
//                    return true;
//
//                if(left_rep[i] > right_rep[i])
//                    return false;
//            }
//
//            return false;
//        }
//    }
//}


} // namespace pk


#endif // PK_BIGINT_HPP
