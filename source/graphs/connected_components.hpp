#ifndef PK_GRAPHS_CONNECTEDCOMPONENTS_HPP
#define PK_GRAPHS_CONNECTEDCOMPONENTS_HPP


#include "queue.hpp"
#include "vector.hpp"


namespace pk
{
namespace graphs
{


template<class Graph>
class connected_components
{
public:
    typedef Graph graph_type;

    connected_components() : component_ids(new int[graph_type::max_num_of_vertices]) {}
    ~connected_components() { delete[] component_ids; }

    void find_components(const graph_type& g)
    {
        number_of_components = 0;
        pk::vector<bool, graph_type::max_num_of_vertices> visited(false, g.get_num_of_vertices());

        for(int u = 0; u < visited.size(); ++u)
        {
            if(!visited[u])
            {
                visit_next_component(g, u, visited);
                ++number_of_components;
            }
        }
    }

    int get_number_of_components() const
    {
        return number_of_components;
    }

    int get_component_id(const int vertex_id) const
    {
        return component_ids[vertex_id];
    }

    const int* get_raw_component_ids() const
    {
        return component_ids;
    }

private:
    connected_components(const connected_components&);
    connected_components& operator=(const connected_components&);

    template<class Sequence>
    void visit_next_component(const graph_type& g, const int starting_vertex_id, Sequence& visited)
    {
        pk::queue<int, graph_type::max_num_of_vertices> q;

        q.push(starting_vertex_id);
        visited[starting_vertex_id] = true;

        while(!q.empty())
        {
            const int v = q.front();
            q.pop();

            component_ids[v] = number_of_components;

            const typename graph_type::adjacency_list& adj_v = g.get_adjacency_list(v);
            for(int i = 0; i < adj_v.size(); ++i)
            {
                const int u = adj_v[i].to;

                if(visited[u])
                    continue;

                q.push(u);
                visited[u] = true;
            }
        }
    }

    int* component_ids;
    int number_of_components;
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_CONNECTEDCOMPONENTS_HPP
