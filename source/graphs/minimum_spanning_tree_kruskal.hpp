#ifndef PK_GRAPHS_MINIMUMSPANNINGTREEKRUSKAL_HPP
#define PK_GRAPHS_MINIMUMSPANNINGTREEKRUSKAL_HPP


#include "disjoint_sets.hpp"
#include "priority_queue.hpp"


namespace pk
{
namespace graphs
{


class minimum_spanning_tree_kruskal
{
public:
    template<class graph_type, class callback_type>
    static void run(const graph_type& g, callback_type& callback)
    {
        typedef const typename graph_type::edge_type edge_type;
        typedef edge_type* edge_type_pointer;

        pk::priority_queue<
                edge_type_pointer,
                graph_type::max_num_of_edges,
                edge_type_greater_comparator<edge_type> > q;

        const int num_of_vertices = g.get_num_of_vertices();

        pk::disjoint_sets sets(num_of_vertices);

        for(int vertex_id = 0; vertex_id < num_of_vertices; ++vertex_id)
        {
            const typename graph_type::adjacency_list& adj_list = g.get_adjacency_list(vertex_id);
            for(int i = 0; i < adj_list.size(); ++i)
                q.push(&adj_list[i]);
        }

        for(int i = 1; i < num_of_vertices; ++i)
        {
            edge_type_pointer e = q.top();
            q.pop();

            while(sets.get_set_id(e->from) == sets.get_set_id(e->to))
            {
                e = q.top();
                q.pop();
            }

            callback.notify(*e);
            sets.union_sets(e->from, e->to);
        }
    }

private:
    template<class edge_type>
    struct edge_type_greater_comparator
    {
        bool operator()(const edge_type* left, const edge_type* right)
        {
            if(left->weight > right->weight)
                return true;
            if(left->weight < right->weight)
                return false;

            if(left->from > right->from)
                return true;
            if(left->from < right->from)
                return false;

            return (left->to > right->to);
        }
    };
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_MINIMUMSPANNINGTREEKRUSKAL_HPP
