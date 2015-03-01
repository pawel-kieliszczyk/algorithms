#ifndef PK_REDBLACKTREE_HPP
#define PK_REDBLACKTREE_HPP


namespace pk
{


template<class T, int MaxSize>
class red_black_tree
{
public:
    typedef T value_type;

    red_black_tree() : sz(0) {}

    void insert(const value_type& elem)
    {
        ++sz;
    }

    int size() const
    {
        return sz;
    }

    bool empty() const
    {
        return (sz == 0);
    }

private:
    int sz;
};


} // namespace pk


#endif // PK_REDBLACKTREE_HPP
