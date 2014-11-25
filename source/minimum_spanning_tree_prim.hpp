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
public:
    template<class graph_type, class callback_type>
    static void run(const graph_type& g, const int starting_vertex, callback_type& callback)
    {
        std::priority_queue<detail::mst_edge, std::vector<detail::mst_edge>, std::greater<detail::mst_edge> > q;

        bool visited[graph_type::max_num_of_vertices];
        std::fill(visited, visited + graph_type::max_num_of_vertices, false);

        int u = starting_vertex;
        visited[u] = true;

        const typename graph_type::adjacency_list& adj_u = g.get_adjacency_list(u);
        for(int i = 0; i < adj_u.size(); ++i)
        {
            const typename graph_type::edge_type& e = adj_u[i];
            if(!visited[e.to])
            {
                q.push(detail::mst_edge(u, e.to, e.weight));
            }
        }

        while(!q.empty())
        {
            const detail::mst_edge e = q.top();
            q.pop();

            if(visited[e.to])
                continue;

            callback.notify(e.from, e.to, e.weight);
            visited[e.to] = true;

            const typename graph_type::adjacency_list& adj_to = g.get_adjacency_list(e.to);
            for(int i = 0; i < adj_to.size(); ++i)
            {
                const typename graph_type::edge_type& to_e = adj_to[i];
                if(!visited[to_e.to])
                {
                    q.push(detail::mst_edge(e.to, to_e.to, to_e.weight));
                }
            }
        }
    }
};


} // namespace pk


#endif // PK_MINIMUMSPANNINGTREEPRIM_HPP
