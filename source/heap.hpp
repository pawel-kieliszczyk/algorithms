#ifndef PK_HEAP_HPP
#define PK_HEAP_HPP


#include "vector.hpp"


namespace pk
{


template<class T, int SIZE>
class heap
{
public:
    void push(const T& elem) { data.push_back(elem); }
    void pop() { data.pop_back(); }

    bool empty() const { return data.empty(); }
    int size() const { return data.size(); }

private:
    pk::vector<T, SIZE> data;
};


} // namespace pk


#endif // PK_HEAP_HPP
