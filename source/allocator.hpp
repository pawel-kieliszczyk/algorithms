#ifndef PK_ALLOCATOR_HPP
#define PK_ALLOCATOR_HPP


namespace pk
{


template<class T, const int MaxAllocations>
class allocator
{
public:
    typedef T value_type;

    allocator() : next_free(data), not_used_so_far(data) {}

    value_type* allocate()
    {
        value_type* result = &next_free->value;

        if(next_free == not_used_so_far)
        {
            ++next_free;
            ++not_used_so_far;
        }
        else
        {
            next_free = next_free->next_free_if_no_data;
        }

        return result;
    }

    void deallocate(value_type* data)
    {
        entry* e = reinterpret_cast<entry*>(data);
        e->next_free_if_no_data = next_free;
        next_free = e;
    }

private:
    struct entry
    {
        value_type value;
        entry* next_free_if_no_data;
    };

    entry data[MaxAllocations];
    entry* next_free;
    entry* not_used_so_far;
};


} // namespace pk


#endif // PK_ALLOCATOR_HPP
