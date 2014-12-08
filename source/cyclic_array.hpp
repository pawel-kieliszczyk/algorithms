#ifndef PK_CYCLICARRAY_HPP
#define PK_CYCLICARRAY_HPP


namespace pk
{


template<class T, int SIZE>
class cyclic_array
{
public:
    typedef T value_type;
    static const int size = SIZE;

    cyclic_array() : first_index(0) { data = new T[SIZE]; }

    value_type& operator[](const int i) { return data[(first_index + i) % SIZE]; }
    const value_type& operator[](const int i) const { return data[(first_index + i) % SIZE]; }

    void shift_left(int d) { if(d < 0) d = (d % SIZE) + SIZE; first_index = (first_index + d) % SIZE; }
    void shift_right(const int d) { shift_left(SIZE - d); }

private:
    cyclic_array(const cyclic_array&);
    cyclic_array& operator=(const cyclic_array&);

    value_type* data;
    int first_index;
};


} // namespace pk


#endif // PK_CYCLICARRAY_HPP
