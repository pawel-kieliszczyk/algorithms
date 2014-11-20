#ifndef PK_VECTOR_HPP
#define PK_VECTOR_HPP


namespace pk
{


template<class T, int MAX_SIZE>
class vector
{
public:
    bool empty() { return true; }
    int size() const { return 0; }
};


} // namespace pk


#endif // PK_VECTOR_HPP
