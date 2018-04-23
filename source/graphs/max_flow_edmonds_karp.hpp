#ifndef PK_GRAPHS_MAX_FLOW_EDMONDS_KARP_HPP
#define PK_GRAPHS_MAX_FLOW_EDMONDS_KARP_HPP


#include <algorithm>

#include "queue.hpp"


namespace pk
{
namespace graphs
{

/**
 * Usage:
 * Use run() method.
 *
 * WARNING:
 * It will modify edges of the graph!
 *
 * edge->flow - It will set to the flow in this edge.
 *
 * To get maximum flow, sum up flows in all edges starting from the source
 * or flows in all edged ending in the sink.
 */
class max_flow_edmonds_karp
{
public:
    template<class graph_type>
    static void run(graph_type& g, const int source_id, const int sink_id)
    {
        initialize_flows_to_zeros(g);

        typename graph_type::edge_type* edge_from_pred[graph_type::max_num_of_vertices];

        while(find_path_to_sink(g, source_id, sink_id, edge_from_pred))
        {
            typename graph_type::edge_type::capacity_type min_capacity =
                    find_available_flow<graph_type>(source_id, sink_id, edge_from_pred);

            update_flow<graph_type>(g, source_id, sink_id, edge_from_pred, min_capacity);
        }
    }

private:
    template<class graph_type>
    static void initialize_flows_to_zeros(graph_type& g)
    {
        for(int v = 0; v < g.get_num_of_vertices(); ++v)
        {
            typename graph_type::adjacency_list& adj_v = g.get_adjacency_list(v);
            for(int i = 0; i < adj_v.size(); ++i)
                adj_v[i].flow = 0;
        }
    }

    template<class graph_type>
    static bool find_path_to_sink(
            graph_type& g,
            const int source_id,
            const int sink_id,
            typename graph_type::edge_type** edge_from_pred)
    {
        pk::queue<int, graph_type::max_num_of_vertices> q;
        std::fill(edge_from_pred, edge_from_pred + g.get_num_of_vertices(), (typename graph_type::edge_type*)0);

        q.push(source_id);

        while(!q.empty())
        {
            const int v = q.front();
            q.pop();

            typename graph_type::adjacency_list& adj_v = g.get_adjacency_list(v);
            for(int i = 0; i < adj_v.size(); ++i)
            {
                const typename graph_type::edge_type::capacity_type& residual_capacity =
                        adj_v[i].capacity - adj_v[i].flow;

                if(!residual_capacity)
                    continue;

                const int u = adj_v[i].to;

                if(edge_from_pred[u] != 0)
                    continue;

                if(u == source_id)
                    continue;

                edge_from_pred[u] = &adj_v[i];

                if(u == sink_id)
                    return true;

                q.push(u);
            }
        }

        return false;
    }

    template<class graph_type>
    static typename graph_type::edge_type::capacity_type find_available_flow(
            const int source_id,
            const int sink_id,
            typename graph_type::edge_type** edge_from_pred)
    {
        typename graph_type::edge_type::capacity_type min_capacity =
                std::numeric_limits<typename graph_type::edge_type::capacity_type>::max();

        typename graph_type::edge_type* edge = edge_from_pred[sink_id];
        while(edge->from != source_id)
        {
            min_capacity = std::min(min_capacity, edge->capacity - edge->flow);
            edge = edge_from_pred[edge->from];
        }
        min_capacity = std::min(min_capacity, edge->capacity - edge->flow);

        return min_capacity;
    }

    template<class graph_type>
    static void update_flow(
            graph_type& g,
            const int source_id,
            const int sink_id,
            typename graph_type::edge_type** edge_from_pred,
            const typename graph_type::edge_type::capacity_type& min_capacity)
    {
        typename graph_type::edge_type* edge = edge_from_pred[sink_id];
        while(edge->from != source_id)
        {
            edge->flow += min_capacity;

            typename graph_type::adjacency_list& adj_to = g.get_adjacency_list(edge->to);
            for(int i = 0; i < adj_to.size(); ++i)
            {
                if(adj_to[i].to == edge->from)
                {
                    adj_to[i].flow -= min_capacity;
                    break;
                }
            }

            edge = edge_from_pred[edge->from];
        }

        edge->flow += min_capacity;

        typename graph_type::adjacency_list& adj_to = g.get_adjacency_list(edge->to);
        for(int i = 0; i < adj_to.size(); ++i)
        {
            if(adj_to[i].to == edge->from)
            {
                adj_to[i].flow -= min_capacity;
                break;
            }
        }
    }
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_MAX_FLOW_EDMONDS_KARP_HPP
