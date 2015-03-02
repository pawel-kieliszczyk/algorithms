#ifndef PK_GRAPHS_BRIDGES_HPP
#define PK_GRAPHS_BRIDGES_HPP


#include <algorithm>

#include "vector.hpp"


namespace pk
{
namespace graphs
{


/**
 * NOTE: Recursive algorithm. For bigger graphs it might exceed available stack size limit.
 * TODO: Reimplement without recursion.
 *
 * NOTE: Doesn't work with graphs with doubled edges.
 * FIXME: Fix counting doubled edges as bridges.
 */
class bridges
{
public:
    template<class graph_type, class callback_type>
    static void run(const graph_type& graph, callback_type& callback)
    {
        int time = 0;
        pk::vector<int, graph_type::max_num_of_vertices> dist(0, graph.get_num_of_vertices());

        for(int u = 0; u < dist.size(); ++u)
        {
            if(dist[u] == 0)
            {
                find_bridges_in_component(graph, u, callback, dist, time);
            }
        }
    }

private:
    template<
            class graph_type,
            class callback_type,
            class dist_sequence_type>
    static void find_bridges_in_component(
            const graph_type& graph,
            const int v,
            callback_type& callback,
            dist_sequence_type& dist,
            int& time)
    {
        int low = dist[v] = time++;

        const typename graph_type::adjacency_list& adj_v = graph.get_adjacency_list(v);
        for(int i = 0; i < adj_v.size(); ++i)
        {
            const int u = adj_v[i].to;

            if(dist[u] == 0)
            {
                const int temp = find_bridges_in_component(graph, adj_v[i], callback, dist, time);
                low = std::min(low, temp);
            }
            else
            {
                low = std::min(low, dist[u]);
            }
        }
    }

    template<
            class graph_type,
            class callback_type,
            class dist_sequence_type>
    static int find_bridges_in_component(
            const graph_type& graph,
            const typename graph_type::edge_type& edge,
            callback_type& callback,
            dist_sequence_type& dist,
            int& time)
    {
        int low = dist[edge.to] = time++;

        const typename graph_type::adjacency_list& adj_to = graph.get_adjacency_list(edge.to);
        for(int i = 0; i < adj_to.size(); ++i)
        {
            const int u = adj_to[i].to;

            if(u != edge.from)
            {
                if(dist[u] == 0)
                {
                    const int temp = find_bridges_in_component(graph, adj_to[i], callback, dist, time);
                    low = std::min(low, temp);
                }
                else
                {
                    low = std::min(low, dist[u]);
                }
            }
        }

        if(low == dist[edge.to])
        {
            callback.notify(edge);
        }

        return low;
    }
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_BRIDGES_HPP
