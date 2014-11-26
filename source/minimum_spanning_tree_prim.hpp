#ifndef PK_MINIMUMSPANNINGTREEPRIM_HPP
#define PK_MINIMUMSPANNINGTREEPRIM_HPP


#include <algorithm>
#include <functional>
#include <queue>


namespace pk
{
namespace detail
{


struct mst_edge
{
    mst_edge(const int from_, const int to_, const int weight_) : from(from_), to(to_), weight(weight_) {}

    int from;
    int to;
    int weight;
};


inline bool operator>(const mst_edge& left, const mst_edge& right)
{
    return (left.weight > right.weight);
}


} // namespace detail


class minimum_spanning_tree_prim
{
private:
    typedef std::priority_queue<detail::mst_edge, std::vector<detail::mst_edge>, std::greater<detail::mst_edge> > queue_type;

public:
    template<class graph_type, class callback_type>
    static void run(const graph_type& g, const int starting_vertex, callback_type& callback)
    {
        // TODO: replace the queue so that it contains vertices instead of edges.
        //       This will increase time complexity to O(E * log(V))
        //       and space complexity to O(V)
        queue_type q;

        bool visited[graph_type::max_num_of_vertices];
        std::fill(visited, visited + graph_type::max_num_of_vertices, false);

        visited[starting_vertex] = true;
        add_not_visited_neighbours_to_queue(g, q, starting_vertex, visited);

        while(!q.empty())
        {
            const detail::mst_edge e = q.top();
            q.pop();

            if(visited[e.to])
                continue;

            callback.notify(e.from, e.to, e.weight);

            visited[e.to] = true;
            add_not_visited_neighbours_to_queue(g, q, e.to, visited);
        }
    }

private:
    template<class graph_type>
    static void add_not_visited_neighbours_to_queue(const graph_type& g, queue_type& q, const int vertex_id, const bool* visited)
    {
        const typename graph_type::adjacency_list& adj_list = g.get_adjacency_list(vertex_id);
        for(int i = 0; i < adj_list.size(); ++i)
        {
            const typename graph_type::edge_type& e = adj_list[i];
            if(!visited[e.to])
            {
                q.push(detail::mst_edge(vertex_id, e.to, e.weight));
            }
        }
    }
};


} // namespace pk


#endif // PK_MINIMUMSPANNINGTREEPRIM_HPP
