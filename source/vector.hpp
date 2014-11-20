#ifndef PK_VECTOR_HPP
#define PK_VECTOR_HPP


namespace pk
{


template<class T, int MAX_SIZE>
class vector
{
public:
    vector() : sz(0) {}

    void push_back(const T& elem) { data[sz++] = elem; }

    T& operator[](const int i) { return data[i]; }
    const T& operator[](const int i) const { return data[i]; }

    T& back() { return data[sz-1]; }
    const T& back() const { return data[sz-1]; }

    bool empty() { return (sz == 0); }
    int size() const { return sz; }

private:
    T data[MAX_SIZE];
    int sz;
};


} // namespace pk


#endif // PK_VECTOR_HPP
