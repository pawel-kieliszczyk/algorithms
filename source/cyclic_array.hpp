#ifndef PK_CYCLICARRAY_HPP
#define PK_CYCLICARRAY_HPP


namespace pk
{


template<class T, int SIZE>
class cyclic_array
{
public:
    cyclic_array() : first_index(0) { data = new T[SIZE]; }

    T& operator[](const int i) { return data[(first_index + i) % SIZE]; }
    const T& operator[](const int i) const { return data[(first_index + i) % SIZE]; }

    void shift_left(int d) { if(d < 0) d = (d % SIZE) + SIZE; first_index = (first_index + d) % SIZE; }

private:
    cyclic_array(const cyclic_array&);
    cyclic_array& operator=(const cyclic_array&);

    T* data;
    int first_index;
};


} // namespace pk


#endif // PK_CYCLICARRAY_HPP
