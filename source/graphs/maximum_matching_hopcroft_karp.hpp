#ifndef PK_GRAPHS_MAXIMUM_MATCHING_HOPCROFT_KARP_HPP
#define PK_GRAPHS_MAXIMUM_MATCHING_HOPCROFT_KARP_HPP


#include <limits>

#include "queue.hpp"


namespace pk
{
namespace graphs
{


template<class bipartite_graph_type>
class maximum_matching_hopcroft_karp
{
public:
    int run(const bipartite_graph_type& g)
    {
        INF = std::numeric_limits<int>::max();
        null_id = bipartite_graph_type::max_num_of_vertices_u;

        for(int u = 0; u < g.get_num_of_vertices_u(); ++u)
            pair_u[u] = null_id;
        for(int v = 0; v < g.get_num_of_vertices_v(); ++v)
            pair_v[v] = null_id;

        int matching = 0;

        while(bfs(g))
        {
            for(int u = 0; u < g.get_num_of_vertices_u(); ++u)
            {
                if(pair_u[u] == null_id)
                {
                    if(dfs(g, u))
                        ++matching;
                }
            }
        }

        return matching;
    }

private:
    bool bfs(const bipartite_graph_type& g)
    {
        pk::queue<int, bipartite_graph_type::max_num_of_vertices_u + 1> q;

        for(int u = 0; u < g.get_num_of_vertices_u(); ++u)
        {
            if(pair_u[u] == null_id)
            {
                dist[u] = 0;
                q.push(u);
            }
            else
            {
                dist[u] = INF;
            }
        }
        dist[null_id] = INF;

        while(!q.empty())
        {
            const int u = q.front();
            q.pop();

            if(dist[u] < dist[null_id])
            {
                const typename bipartite_graph_type::adjacency_list& adj_u = g.get_adjacency_list_u(u);
                for(int i = 0; i < adj_u.size(); ++i)
                {
                    const int v = adj_u[i].to;
                    if(dist[pair_v[v]] == INF)
                    {
                        dist[pair_v[v]] = dist[u] + 1;
                        q.push(pair_v[v]);
                    }
                }
            }
        }

        return (dist[null_id] != INF);
    }

    bool dfs(const bipartite_graph_type& g, const int u)
    {
        if(u != null_id)
        {
            const typename bipartite_graph_type::adjacency_list& adj_u = g.get_adjacency_list_u(u);
            for(int i = 0; i < adj_u.size(); ++i)
            {
                const int v = adj_u[i].to;
                if(dist[pair_v[v]] == dist[u] + 1)
                {
                    if(dfs(g, pair_v[v]))
                    {
                        pair_v[v] = u;
                        pair_u[u] = v;

                        return true;
                    }
                }
            }

            dist[u] = INF;
            return false;
        }

        return true;
    }

    int INF;
    int null_id;

    int pair_u[bipartite_graph_type::max_num_of_vertices_u];
    int pair_v[bipartite_graph_type::max_num_of_vertices_v];
    int dist[bipartite_graph_type::max_num_of_vertices_u + 1];
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_MAXIMUM_MATCHING_HOPCROFT_KARP_HPP
