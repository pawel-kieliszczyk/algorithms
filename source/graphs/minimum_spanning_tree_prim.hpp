#ifndef PK_GRAPHS_MINIMUMSPANNINGTREEPRIM_HPP
#define PK_GRAPHS_MINIMUMSPANNINGTREEPRIM_HPP


#include <algorithm>
#include <functional>

#include "priority_queue.hpp"
#include "vector.hpp"


namespace pk
{
namespace graphs
{


class minimum_spanning_tree_prim
{
public:
    template<class graph_type, class callback_type>
    static void run(const graph_type& g, const int starting_vertex, callback_type& callback)
    {
        // TODO: replace the queue so that it contains vertices instead of edges.
        //       This will improve space complexity to O(V)
        typedef const typename graph_type::edge_type edge_type;
        typedef edge_type* edge_type_pointer;

        pk::priority_queue<
                edge_type_pointer,
                graph_type::max_num_of_edges,
                edge_type_greater_comparator<edge_type> > q;

        pk::vector<bool, graph_type::num_of_vertices> visited(false);

        visited[starting_vertex] = true;
        add_not_visited_neighbours_to_queue(g, q, starting_vertex, visited.cbegin());

        while(!q.empty())
        {
            const edge_type_pointer e = q.top();
            q.pop();

            if(visited[e->to])
                continue;

            callback.notify(*e);

            visited[e->to] = true;
            add_not_visited_neighbours_to_queue(g, q, e->to, visited.cbegin());
        }
    }

private:
    template<class edge_type>
    struct edge_type_greater_comparator
    {
        bool operator()(const edge_type* left, const edge_type* right)
        {
            return (left->weight > right->weight);
        }
    };

    template<class graph_type, class queue_type>
    static void add_not_visited_neighbours_to_queue(const graph_type& g, queue_type& q, const int vertex_id, const bool* visited)
    {
        const typename graph_type::adjacency_list& adj_list = g.get_adjacency_list(vertex_id);
        for(int i = 0; i < adj_list.size(); ++i)
        {
            const typename graph_type::edge_type& e = adj_list[i];

            if(!visited[e.to])
                q.push(&e);
        }
    }
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_MINIMUMSPANNINGTREEPRIM_HPP
