#ifndef PK_PRIORITYQUEUE_HPP
#define PK_PRIORITYQUEUE_HPP


#include <algorithm>
#include <functional>

#include "vector.hpp"


namespace pk
{


template<class T, int Size, class Compare>
class priority_queue
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


template<class T, int Size> class min_priority_queue : public priority_queue<T, Size, std::greater<T> > {};
template<class T, int Size> class max_priority_queue : public priority_queue<T, Size, std::less<T> > {};


} // namespace pk


#endif // PK_PRIORITYQUEUE_HPP
