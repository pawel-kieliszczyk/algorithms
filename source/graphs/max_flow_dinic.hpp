#ifndef PK_GRAPHS_MAX_FLOW_DINIC_HPP
#define PK_GRAPHS_MAX_FLOW_DINIC_HPP


#include <algorithm>
#include <limits>


namespace pk
{
namespace graphs
{

/**
 * Usage:
 * Use run() method. It returns the maximum flow.
 *
 * WARNING:
 * It will modify edges of the graph!
 *
 * edge->flow - It will set to the flow in this edge.
 */
template<class graph_type>
class max_flow_dinic
{
public:
    typename graph_type::edge_type::capacity_type run(graph_type& g, const int source_id, const int sink_id)
    {
        const typename graph_type::edge_type::capacity_type INF =
                std::numeric_limits<typename graph_type::edge_type::capacity_type>::max();

        initialize_c_to_zeros(g);

        typename graph_type::edge_type::capacity_type res(0);

        while(bfs(g, source_id, sink_id))
        {
            for(int i = 0; i < g.get_num_of_vertices(); ++i)
                begin_at[i] = 0;

            res += dfs(g, source_id, sink_id, INF);
        }

        set_flow_in_edges(g);

        return res;
    }

private:
    void initialize_c_to_zeros(const graph_type& g)
    {
        const typename graph_type::edge_type::capacity_type zero_capacity(0);

        for(int i = 0; i < g.get_num_of_vertices(); ++i)
            for(int j = 0; j < g.get_num_of_vertices(); ++j)
                c[i][j] = zero_capacity;

        for(int i = 0; i < g.get_num_of_vertices(); ++i)
        {
            const typename graph_type::adjacency_list& adj_v = g.get_adjacency_list(i);
            for(int j = 0; j < adj_v.size(); ++j)
                c[i][adj_v[j].to] = adj_v[j].capacity;
        }
    }

    bool bfs(const graph_type& g, const int source_id, const int sink_id)
    {
        for(int i = 0; i < g.get_num_of_vertices(); ++i)
            dist[i] = -1;
        dist[source_id] = 0;

        int q_beg = 0, q_end = 0;
        q[q_end++]=source_id;

        while(q_beg < q_end)
        {
            int v = q[q_beg++];
            const typename graph_type::adjacency_list& adj_v = g.get_adjacency_list(v);
            for(int i = 0; i < adj_v.size(); ++i)
            {
                const int u = adj_v[i].to;
                if((c[v][u] > 0) && (dist[u] == -1))
                {
                    dist[u] = dist[v] + 1;
                    q[q_end++] = u;
                }
            }
        }

        return (dist[sink_id] != -1); 
    }

    typename graph_type::edge_type::capacity_type dfs(
            const graph_type& g,
            const int starting_vertex_id,
            const int sink_id,
            typename graph_type::edge_type::capacity_type minimum)
    {
        const typename graph_type::edge_type::capacity_type zero_capacity(0);
        typename graph_type::edge_type::capacity_type res = zero_capacity;

        if((starting_vertex_id == sink_id) || ( minimum == typename graph_type::edge_type::capacity_type(0)))
            return minimum;

        const typename graph_type::adjacency_list& adj_v = g.get_adjacency_list(starting_vertex_id);
        for(int& i = begin_at[starting_vertex_id]; i < adj_v.size(); ++i)
        {
            const int u = adj_v[i].to;
            if((dist[starting_vertex_id] + 1 == dist[u]) && (c[starting_vertex_id][u] > zero_capacity))
            {
                const typename graph_type::edge_type::capacity_type y =
                        dfs(g, u, sink_id, std::min(minimum, c[starting_vertex_id][u]));

                c[starting_vertex_id][u] -= y; 
                c[u][starting_vertex_id] += y;

                minimum -= y;
                res += y;

                if(minimum == zero_capacity)
                    break;
            }
        }

        return res;
    }

    void set_flow_in_edges(graph_type& g)
    {
        for(int i = 0; i < g.get_num_of_vertices(); ++i)
        {
            typename graph_type::adjacency_list& adj_v = g.get_adjacency_list(i);
            for(int j = 0; j < adj_v.size(); ++j)
                adj_v[j].flow = adj_v[j].capacity - c[i][adj_v[j].to];
        }
    }

    typename graph_type::edge_type::capacity_type c[graph_type::max_num_of_vertices][graph_type::max_num_of_vertices];
    int dist[graph_type::max_num_of_vertices];
    int q[graph_type::max_num_of_vertices];
    int begin_at[graph_type::max_num_of_vertices];
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_MAX_FLOW_DINIC_HPP
