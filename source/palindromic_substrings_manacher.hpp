#ifndef PK_PALINDROMICSUBSTRINGSMANACHER_HPP
#define PK_PALINDROMICSUBSTRINGSMANACHER_HPP


#include <algorithm>


namespace pk
{


/**
 * Can be used to find longest palindromic substring.
 * WARNING: Add "guards" ath both ends of the input string before calling run()
 *          For example if your string is "abcd", modify it to "#abcd$" first.
 */
template<int MaxTextSize>
class palindromic_substrings_manacher
{
public:
    /**
     * WARNING: text_size parameter should count "guards" as well
     */
    void find_even(const char* text, const int text_size)
    {
        palindromic_substrings_table[0] = 0;
        int i = 1;
        int t = 0;
        while(i < text_size)
        {
           while(text[i-t] == text[i+t+1])
               ++t;

           palindromic_substrings_table[i] = t;

           int k = 1;
           while((k <= t) && (palindromic_substrings_table[i-k] != palindromic_substrings_table[i]-k))
           {
               palindromic_substrings_table[i+k] = std::min(palindromic_substrings_table[i-k], palindromic_substrings_table[i]-k);
              ++k;
           }

           t = std::max(0, t-k);
           i += k;
        }
    }
    /**
     * WARNING: text_size parameter should count "guards" as well
     */
    void find_odd(const char* text, const int text_size)
    {
        palindromic_substrings_table[0] = 0;
        int i = 1;
        int t = 1;
        while(i < text_size)
        {
           while(text[i-t] == text[i+t])
               ++t;

           palindromic_substrings_table[i] = t;

           int k = 1;
           while((k <= t) && (palindromic_substrings_table[i-k] != palindromic_substrings_table[i]-k))
           {
               palindromic_substrings_table[i+k] = std::min(palindromic_substrings_table[i-k], palindromic_substrings_table[i]-k);
              ++k;
           }

           t = std::max(1, t-k);
           i += k;
        }
    }

    /**
     * table[i] = k means that substring text[i-k+1,..,i+k] is a palindrome (of length 2*k)
     */
    const int* get_palindromic_substrings_table() const
    {
        return palindromic_substrings_table;
    }

private:
    int palindromic_substrings_table[MaxTextSize];
};


} // namespace pk


#endif // PK_PALINDROMICSUBSTRINGSMANACHER_HPP
