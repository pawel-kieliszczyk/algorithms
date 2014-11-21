#ifndef PK_QUEUE_HPP
#define PK_QUEUE_HPP


namespace pk
{


template<class T, int MAX_NUM_OF_PUSHES>
class queue
{
public:
    queue() : begin(0), end(0) {}

    void push(const T& elem) { end++; }
    void pop() { ++begin; }

    bool empty() const { return (begin == end); }

private:
    T data[MAX_NUM_OF_PUSHES];
    int begin;
    int end;
};


} // namespace pk


#endif // PK_QUEUE_HPP
