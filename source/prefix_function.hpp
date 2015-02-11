#ifndef PK_PREFIXFUNCTION_HPP
#define PK_PREFIXFUNCTION_HPP


namespace pk
{


/**
 * Computes Knuth's prefix function in linear time complexity.
 *
 * Can be used as a string searching algorithm.
 * For a given pattern and string call run() function
 * with text = pattern#string and find all occurances of
 * pattern's size in the computed prefix-suffix table.
 */
template<int MaxTextSize>
class prefix_function
{
public:
    /**
     * Computes Knuth's prefix function for a given text.
     * The result can be obtained by get_prefix_suffix_table() function.
     */
    void run(const char* text, const int text_size)
    {
        prefix_suffix_table[0] = 0;
        int t = prefix_suffix_table[0];

        for(int i = 1; i < text_size; ++i)
        {
            while(t > 0 && text[t] != text[i])
                t = prefix_suffix_table[t-1];

            if(text[t] == text[i])
                ++t;
            prefix_suffix_table[i] = t;
        }
    }

    /**
     * Returns a prefix-suffix table for a text computed by run() function,
     * where i'th element of the table is the longest (but shorter that i+1)
     * prefix-suffix of a substring text[0,..,i].
     */
    const int* get_prefix_suffix_table() const
    {
        return prefix_suffix_table;
    }

private:
    int prefix_suffix_table[MaxTextSize];
};


} // namespace pk


#endif // PK_PREFIXFUNCTION_HPP
