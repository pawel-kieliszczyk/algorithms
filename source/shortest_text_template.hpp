#ifndef PK_SHORTESTTEXTTEMPLATE_HPP
#define PK_SHORTESTTEXTTEMPLATE_HPP


#include "prefix_function.hpp"


namespace pk
{


template<int MaxTextSize>
class shortest_text_template
{
public:
    int run(const char* text, const int text_size)
    {
        prefix_function<MaxTextSize> pf;
        pf.run(text, text_size);

        const int* prefix_suffix_table = pf.get_prefix_suffix_table();

        for(int i = 0; i < text_size; ++i)
        {
            ranges[i] = i;
            templates[i] = i + 1;
        }

        for(int i = 1; i < text_size; ++i)
        {
            const int prefix_suffix = prefix_suffix_table[i];
            if(prefix_suffix > 0)
            {
                const int q = templates[prefix_suffix-1];
                if(ranges[q-1] >= i - q)
                {
                    templates[i] = q;
                    ranges[q-1] = i;
                }
            }
        }

        return templates[text_size-1];
    }

private:
    int ranges[MaxTextSize];
    int templates[MaxTextSize];
};


} // namespace pk


#endif // PK_SHORTESTTEXTTEMPLATE_HPP
