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
    void pop_back() { --sz; }

    T& operator[](const int i) { return data[i]; }
    const T& operator[](const int i) const { return data[i]; }

    T& front() { return data[0]; }
    const T& front() const { return data[0]; }

    T& back() { return data[sz-1]; }
    const T& back() const { return data[sz-1]; }

    T* begin() { return data; }
    const T* cbegin() const { return data; }

    T* end() { return (data + sz); }
    const T* cend() const { return (data + sz); }

    bool empty() { return (sz == 0); }
    int size() const { return sz; }

private:
    T data[MAX_SIZE];
    int sz;
};


} // namespace pk


#endif // PK_VECTOR_HPP
