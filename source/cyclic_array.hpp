#ifndef PK_CYCLICARRAY_HPP
#define PK_CYCLICARRAY_HPP


namespace pk
{


template<class T, int SIZE>
class cyclic_array
{
public:
    cyclic_array() { data = new T[SIZE]; }

    T& operator[](const int i) { return data[i]; }
    const T& operator[](const int i) const { return data[i]; }

    void shift(const int d) {}

private:
    cyclic_array(const cyclic_array&);
    cyclic_array& operator=(const cyclic_array&);

    T* data;
};


} // namespace pk


#endif // PK_CYCLICARRAY_HPP
