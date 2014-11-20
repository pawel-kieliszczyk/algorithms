#ifndef PK_VECTOR_HPP
#define PK_VECTOR_HPP


namespace pk
{


template<class T, int MAX_SIZE>
class vector
{
public:
    void push_back(const T& elem) { data[0] = elem; }

    T& operator[](const int i) { return data[i]; }
    const T& operator[](const int i) const { return data[i]; }

    bool empty() { return true; }
    int size() const { return 0; }

private:
    T data[MAX_SIZE];
};


} // namespace pk


#endif // PK_VECTOR_HPP
