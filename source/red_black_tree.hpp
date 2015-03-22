#ifndef PK_REDBLACKTREE_HPP
#define PK_REDBLACKTREE_HPP


#include "allocator.hpp"


namespace pk
{


/**
 * Red-black tree which keeps distinct elements (no duplications allowed).
 */
template<class T, int MaxElements, template<class, int> class Allocator = allocator>
class red_black_tree
{
public:
    typedef T value_type;

    red_black_tree() : root(&null_node), sz(0)
    {
        null_node.color = node::color_black;
        null_node.subtree_size = 0;
    }

    void insert(const value_type& elem)
    {
        node* new_node = alloc.allocate();
        new_node->value = elem;

        insert(new_node);

        ++sz;
    }

    void remove(const value_type& elem)
    {
        node* z = node_with_value(elem);
        remove(z);

        alloc.deallocate(z);

        --sz;
    }

    bool exists(const value_type& elem) const
    {
        node* result = root;

        while((result != &null_node) && (result->value != elem))
            result = (elem < result->value) ? result->left : result->right;

        return (result != &null_node);
    }

    const value_type& min() const
    {
        const node* m = node_in_subtree_with_minimum_value(root);
        return m->value;
    }

    const value_type& max() const
    {
        const node* m = node_in_subtree_with_maximum_value(root);
        return m->value;
    }

    int rank(const value_type& elem) const
    {
        const node* x = node_with_value(elem);
        return rank(x);
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
        enum ecolor { color_red, color_black };

        value_type value;
        ecolor color;
        int subtree_size;

        node* parent;
        node* left;
        node* right;
    };

    void insert(node* new_node)
    {
        node* y = &null_node;
        node* x = root;

        while(x != &null_node)
        {
            x->subtree_size += 1;

            y = x;
            x = (new_node->value < x->value) ? x->left : x->right;
        }

        new_node->parent = y;
        if(y == &null_node)
            root = new_node;
        else if(new_node->value < y->value)
            y->left = new_node;
        else
            y->right = new_node;

        new_node->left = &null_node;
        new_node->right = &null_node;
        new_node->color = node::color_red;
        new_node->subtree_size = 1;

        fix_up_after_insert(new_node);
    }

    void remove(node* z)
    {
        node* y = z;
        typename node::ecolor y_original_color = y->color;

        node* x;
        node* node_with_broken_subtree_size = z->parent;
        if(z->left == &null_node)
        {
            x = z->right;
            transplant(z, z->right);
        }
        else if(z->right == &null_node)
        {
            x = z->left;
            transplant(z, z->left);
        }
        else
        {
            y = node_in_subtree_with_minimum_value(z->right);
            y_original_color = y->color;
            x = y->right;

            if(y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                transplant(y, y->right);

                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);

            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;

            node_with_broken_subtree_size = x->parent;
        }

        fix_up_subtree_sizes_after_remove(node_with_broken_subtree_size);

        if(y_original_color == node::color_black)
            fix_up_after_remove(x);
    }

    int rank(const node* x) const
    {
        int result = x->left->subtree_size;

        for(const node* y = x; y != root; y = y->parent)
        {
            if(y == y->parent->right)
                result += y->parent->left->subtree_size + 1;
        }

        return result;
    }

    void fix_up_after_insert(node* z)
    {
        while(z->parent->color == node::color_red)
        {
            if(z->parent == z->parent->parent->left)
            {
                node* y = z->parent->parent->right;
                if(y->color == node::color_red)
                {
                    z->parent->color = node::color_black;
                    y->color = node::color_black;
                    z->parent->parent->color = node::color_red;
                    z = z->parent->parent;
                }
                else
                {
                    if(z == z->parent->right)
                    {
                        z = z->parent;
                        rotate_left(z);
                    }

                    z->parent->color = node::color_black;
                    z->parent->parent->color = node::color_red;
                    rotate_right(z->parent->parent);
                }
            }
            else
            {
                node* y = z->parent->parent->left;
                if(y && y->color == node::color_red)
                {
                    z->parent->color = node::color_black;
                    y->color = node::color_black;
                    z->parent->parent->color = node::color_red;
                    z = z->parent->parent;
                }
                else
                {
                    if(z == z->parent->left)
                    {
                        z = z->parent;
                        rotate_right(z);
                    }

                    z->parent->color = node::color_black;
                    z->parent->parent->color = node::color_red;
                    rotate_left(z->parent->parent);
                }
            }
        }

        root->color = node::color_black;
    }

    void fix_up_after_remove(node* x)
    {
        while((x != root) && (x->color == node::color_black))
        {
            if(x == x->parent->left)
            {
                node* w = x->parent->right;

                if(w->color == node::color_red)
                {
                    w->color = node::color_black;
                    x->parent->color = node::color_red;
                    rotate_left(x->parent);
                    w = x->parent->right;
                }

                if((w->left->color == node::color_black) && (w->right->color == node::color_black))
                {
                    w->color = node::color_red;
                    x = x->parent;
                }
                else
                {
                    if(w->right->color == node::color_black)
                    {
                        w->left->color = node::color_black;
                        w->color = node::color_red;
                        rotate_right(w);
                        w = x->parent->right;
                    }

                    w->color = x->parent->color;
                    x->parent->color = node::color_black;
                    w->right->color = node::color_black;
                    rotate_left(x->parent);
                    x = root;
                }
            }
            else
            {
                node* w = x->parent->left;

                if(w->color == node::color_red)
                {
                    w->color = node::color_black;
                    x->parent->color = node::color_red;
                    rotate_right(x->parent);
                    w = x->parent->left;
                }

                if((w->right->color == node::color_black) && (w->left->color == node::color_black))
                {
                    w->color = node::color_red;
                    x = x->parent;
                }
                else
                {
                    if(w->left->color == node::color_black)
                    {
                        w->right->color = node::color_black;
                        w->color = node::color_red;
                        rotate_left(w);
                        w = x->parent->left;
                    }

                    w->color = x->parent->color;
                    x->parent->color = node::color_black;
                    w->left->color = node::color_black;
                    rotate_right(x->parent);
                    x = root;
                }
            }
        }

        x->color = node::color_black;
    }

    void fix_up_subtree_sizes_after_remove(node* x)
    {
        while(x != &null_node)
        {
            x->subtree_size = x->left->subtree_size + x->right->subtree_size + 1;
            x = x->parent;
        }
    }

    void rotate_left(node* x)
    {
        node* y = x->right;
        x->right = y->left;

        if(y->left != &null_node)
            y->left->parent = x;

        y->parent = x->parent;

        if(x->parent == &null_node)
            root = y;
        else if(x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;

        x->subtree_size = x->left->subtree_size + x->right->subtree_size + 1;
        y->subtree_size = x->subtree_size + y->right->subtree_size + 1;
    }

    void rotate_right(node* x)
    {
        node* y = x->left;
        x->left = y->right;

        if(y->right != &null_node)
            y->right->parent = x;

        y->parent = x->parent;

        if(x->parent == &null_node)
            root = y;
        else if(x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;

        x->subtree_size = x->left->subtree_size + x->right->subtree_size + 1;
        y->subtree_size = x->subtree_size + y->left->subtree_size + 1;
    }

    node* node_with_value(const value_type& value) const
    {
        node* result = root;

        while(result->value != value)
            result = (value < result->value) ? result->left : result->right;

        return result;
    }

    void transplant(node* u, node* v)
    {
        if(u->parent == &null_node)
            root = v;
        else if(u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;

        v->parent = u->parent;
    }

    node* node_in_subtree_with_minimum_value(node* x) const
    {
        while(x->left != &null_node)
            x = x->left;

        return x;
    }

    node* node_in_subtree_with_maximum_value(node* x) const
    {
        while(x->right != &null_node)
            x = x->right;

        return x;
    }

    Allocator<node, MaxElements> alloc;

    node* root;
    node null_node;

    int sz;
};


} // namespace pk


#endif // PK_REDBLACKTREE_HPP
