#ifndef PK_BINARYSEARCHTREE_HPP
#define PK_BINARYSEARCHTREE_HPP


#include "allocator.hpp"


namespace pk
{


template<class T, int MaxElements>
class binary_search_tree
{
public:
    typedef T value_type;

    binary_search_tree() : root(0), sz(0) {}

    void insert(const value_type& elem)
    {
        node* parent = 0;
        node* new_node = root;
        while(new_node != 0)
        {
            parent = new_node;
            new_node = (elem < new_node->value) ? new_node->left : new_node->right;
        }

        new_node = alloc.allocate();

        new_node->value = elem;
        new_node->left = 0;
        new_node->right = 0;

        if(parent == 0)
        {
            root = new_node;
        }
        else if(elem < parent->value)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }

        ++sz;
    }

    const value_type* search(const value_type& elem)
    {
        node* result = root;

        while((result != 0) && (result->value != elem))
            result = (elem < result->value) ? result->left : result->right;

        return (result != 0) ? &result->value : 0;
    }

    int size() const
    {
        return sz;
    }

private:
    struct node
    {
        value_type value;

        node* left;
        node* right;
    };

    allocator<node, MaxElements> alloc;

    node* root;
    int sz;
};


} // namespace pk


#endif // PK_BINARYSEARCHTREE_HPP
