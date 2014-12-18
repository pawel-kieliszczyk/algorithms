#ifndef PK_BIGINT_HPP
#define PK_BIGINT_HPP


#include <algorithm>
#include <cstring>


namespace pk
{


template<int MAX_DECIMAL_SIZE>
class bigint
{
public:
    bigint() { s[0] = '0'; s[1] = '\0'; }

    bigint(const char* init_value)
    {
        const int size = strlen(init_value);
        std::copy(init_value, init_value + size + 1, s);

        if(s[0] == '-' && s[1] == '0')
        {
            s[0] = '0';
            s[1] = '\0';
        }
    }

    const char* c_str() const { return s; }

private:
    char s[MAX_DECIMAL_SIZE];
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


} // namespace pk


#endif // PK_BIGINT_HPP
