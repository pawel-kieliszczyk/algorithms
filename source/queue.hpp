#ifndef PK_QUEUE_HPP
#define PK_QUEUE_HPP


namespace pk
{


template<class T, int MAX_NUM_OF_PUSHES>
class queue
{
public:
    queue() : begin(0), end(0) { data = new T[MAX_NUM_OF_PUSHES]; }
    ~queue() { delete[] data; }

    void push(const T& elem) { data[end++] = elem; }
    void pop() { ++begin; }

    T& front() { return data[begin]; }
    const T& front() const { return data[begin]; }

    bool empty() const { return (begin == end); }
    int size() const { return (end - begin); }

private:
    queue(const queue&);
    queue& operator=(const queue&);

    T* data;
    int begin;
    int end;
};


} // namespace pk


#endif // PK_QUEUE_HPP
