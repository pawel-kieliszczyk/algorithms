#ifndef PK_HEAP_HPP
#define PK_HEAP_HPP


#include <algorithm>
#include <functional>

#include "vector.hpp"


namespace pk
{


template<class T, int Size, class Compare>
class heap
{
public:
    void push(const T& elem)
    {
        data.push_back(elem);
        std::push_heap(data.begin(), data.end(), comp);
    }
    void pop() { data.pop_back(); }

    const T& top() const { return data.front(); }

    bool empty() const { return data.empty(); }
    int size() const { return data.size(); }

private:
    pk::vector<T, Size> data;
    Compare comp;
};


template<class T, int Size> class min_heap : public heap<T, Size, std::greater<T> > {};
template<class T, int Size> class max_heap : public heap<T, Size, std::less<T> > {};


} // namespace pk


#endif // PK_HEAP_HPP
