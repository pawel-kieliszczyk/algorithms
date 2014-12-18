#ifndef PK_BIGINT_HPP
#define PK_BIGINT_HPP


namespace pk
{


template<int MAX_DECIMAL_SIZE>
class bigint
{
public:
    bigint() { s[0] = '0'; s[1] = '\0'; }

    const char* c_str() { return s; }

private:
    char s[MAX_DECIMAL_SIZE];
};


} // namespace pk


#endif // PK_BIGINT_HPP
