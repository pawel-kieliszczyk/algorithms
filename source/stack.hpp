#ifndef PK_STACK_HPP
#define PK_STACK_HPP


namespace pk
{


template<class T, int MAX_SIZE>
class stack
{
public:
    stack() : sz(0) {}

    void push(const T& elem) { ++sz; }
    void pop() { --sz; }

    bool empty() const { return (sz == 0); }
    int size() const { return sz; }

private:
    T data[MAX_SIZE];
    int sz;
};


} // namespace pk


#endif // PK_STACK_HPP
