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
    priority_queue() {}

    priority_queue(const T* first, const T* last)
    {
        while(first != last)
            data.push_back(*first++);

        std::make_heap(data.begin(), data.end(), comp);
    }

    void push(const T& elem)
    {
        data.push_back(elem);
        std::push_heap(data.begin(), data.end(), comp);
    }

    void pop()
    {
        std::pop_heap(data.begin(), data.end(), comp);
        data.pop_back();
    }

    const T& top() const { return data.front(); }

    bool empty() const { return data.empty(); }
    int size() const { return data.size(); }

private:
    pk::vector<T, Size> data;
    Compare comp;
};


template<class T, int Size> class min_priority_queue : public priority_queue<T, Size, std::greater<T> >
{
public:
    min_priority_queue() {}
    min_priority_queue(const T* first, const T* last) : priority_queue<T, Size, std::greater<T> >(first, last) {}
};


template<class T, int Size> class max_priority_queue : public priority_queue<T, Size, std::less<T> >
{
public:
    max_priority_queue() {}
    max_priority_queue(const T* first, const T* last) : priority_queue<T, Size, std::less<T> >(first, last) {}
};


} // namespace pk


#endif // PK_PRIORITYQUEUE_HPP
