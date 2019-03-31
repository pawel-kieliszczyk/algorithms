#ifndef PK_GRAPHS_STRONGLYCONNECTEDCOMPONENTSTARJAN_HPP
#define PK_GRAPHS_STRONGLYCONNECTEDCOMPONENTSTARJAN_HPP


#include <algorithm>

#include "stack.hpp"


namespace pk
{
namespace graphs
{


template<class GraphType>
class strongly_connected_components_tarjan
{
public:
    typedef GraphType graph_type;

    /**
     * Finds strongly connected components in a directed graph.
     * Each vertes will have an assigned component ID in compontent_ids array.
     * The same ID for u and v means that they belong to the same stringly connected component.
     * 
     * Returns number of found components.
     */
    int run(const graph_type& g, int* component_ids)
    {
        std::fill(index, index + g.get_num_of_vertices(), -1);
        std::fill(on_stack, on_stack + g.get_num_of_vertices(), false);

        idx = 0;
        next_component_id = 0;
        s.clear();
        for(int u = 0; u < g.get_num_of_vertices(); ++u)
        {
            if(index[u] == -1)
                connect(g, u, component_ids);
        }

        return next_component_id;
    }

private:
    void connect(const graph_type& g, const int u, int* component_ids)
    {
        index[u] = idx;
        low_link[u] = idx;
        ++idx;

        s.push(u);
        on_stack[u] = true;

        const typename graph_type::adjacency_list& adj_u = g.get_adjacency_list(u);
        for(int i = 0; i < adj_u.size(); ++i)
        {
            const int v = adj_u[i].to;
            if(index[v] == -1)
            {
                connect(g, v, component_ids);
                low_link[u] = std::min(low_link[u], low_link[v]);
            }
            else if(on_stack[v])
            {
                low_link[u] = std::min(low_link[u], low_link[v]);
            }
        }

        if(low_link[u] == index[u])
        {
            const int this_component_id = next_component_id++;
            while(true)
            {
                const int v = s.top();
                s.pop();

                on_stack[v] = false;
                component_ids[v] = this_component_id;

                if(v == u)
                    break;
            }
        }
    }

    int idx;
    pk::stack<int, graph_type::max_num_of_vertices> s;
    int index[graph_type::max_num_of_vertices];
    int low_link[graph_type::max_num_of_vertices];
    bool on_stack[graph_type::max_num_of_vertices];
    int next_component_id;
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_STRONGLYCONNECTEDCOMPONENTSTARJAN_HPP
