#ifndef PK_STACK_HPP
#define PK_STACK_HPP


namespace pk
{


template<class T, int MAX_SIZE>
class stack
{
public:
    stack() : sz(0) {}

    void push(const T& elem) { data[sz++] = elem; }
    void pop() { --sz; }

    T& top() { return data[sz-1]; }
    const T& top() const { return data[sz-1]; }

    bool empty() const { return (sz == 0); }
    int size() const { return sz; }

private:
    T data[MAX_SIZE];
    int sz;
};


} // namespace pk


#endif // PK_STACK_HPP
