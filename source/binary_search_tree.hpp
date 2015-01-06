#ifndef PK_GRAPHS_BINARYSEARCHTREE_HPP
#define PK_GRAPHS_BINARYSEARCHTREE_HPP


#include "allocator.hpp"


namespace pk
{


/**
 * Binary search tree which keeps distinct elements (no duplications allowed).
 */
template<class T, int MaxElements, template<class, int> class Allocator = allocator>
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
            if(elem == new_node->value)
                return;

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

    void remove(const value_type& elem)
    {
        node* parent = 0;
        node* to_remove = root;

        while(to_remove != 0)
        {
            if(elem == to_remove->value)
                break;

            parent = to_remove;
            to_remove = (elem < to_remove->value) ? to_remove->left : to_remove->right;
        }

        remove(to_remove, parent);
    }

    bool exists(const value_type& elem) const
    {
        node* result = root;

        while((result != 0) && (result->value != elem))
            result = (elem < result->value) ? result->left : result->right;

        return (result != 0);
    }

    const value_type& min() const
    {
        node* result = root;
        while(result->left != 0)
            result = result->left;

        return result->value;
    }

    const value_type& max() const
    {
        node* result = root;
        while(result->right != 0)
            result = result->right;

        return result->value;
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
    struct node
    {
        value_type value;

        node* left;
        node* right;
    };

    void remove(node* to_remove, node* parent)
    {
        node* const original_to_remove = to_remove;

        if(to_remove != 0)
        {
            if((to_remove->left != 0) && (to_remove->right != 0))
            {
                parent = to_remove;
                to_remove = to_remove->right;

                while(to_remove->left != 0)
                {
                    parent = to_remove;
                    to_remove = to_remove->left;
                }
            }

            node* x = (to_remove->left != 0) ? to_remove->left : to_remove->right;

            if(parent == 0)
                root = x;
            else if(to_remove == parent->left)
                parent->left = x;
            else
                parent->right = x;

            if(to_remove != original_to_remove)
                original_to_remove->value = to_remove->value;

            alloc.deallocate(to_remove);
            --sz;
        }
    }

    Allocator<node, MaxElements> alloc;

    node* root;
    int sz;
};


} // namespace pk


#endif // PK_GRAPHS_BINARYSEARCHTREE_HPP
