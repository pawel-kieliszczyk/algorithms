#ifndef PK_GRAPHS_TOPOLOGICALSORT_HPP
#define PK_GRAPHS_TOPOLOGICALSORT_HPP


#include <algorithm>

#include "stack.hpp"
#include "vector.hpp"


namespace pk
{
namespace graphs
{


class topological_sort
{
public:
    template<class graph_type, class output_iterator>
    static bool run(const graph_type& graph, output_iterator output)
    {
        pk::vector<int, graph_type::max_num_of_vertices> colors(0, graph.get_num_of_vertices());
        pk::stack<int, graph_type::max_num_of_vertices> s;

        for(int v = 0; v < graph.get_num_of_vertices(); ++v)
        {
            if(colors[v] != 0)
                continue;

            if(!dfs(graph, v, colors, s))
                return false;
        }

        while(!s.empty())
        {
            *output++ = s.top();
            s.pop();
        }

        return true;
    }

private:
    template<class graph_type>
    static bool dfs(
            const graph_type& graph,
            const int vertex_id,
            pk::vector<int, graph_type::max_num_of_vertices>& colors,
            pk::stack<int, graph_type::max_num_of_vertices>& s)
    {
        if(colors[vertex_id] == 1)
            return false;

        if(colors[vertex_id] == 2)
            return true;

        colors[vertex_id] = 1;

        const typename graph_type::adjacency_list& adjacent_edges = graph.get_adjacency_list(vertex_id);
        for(int i = 0; i < adjacent_edges.size(); ++i)
        {
            if(!dfs(graph, adjacent_edges[i].to, colors, s))
                return false;
        }

        colors[vertex_id] = 2;
        s.push(vertex_id);

        return true;
    }
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_TOPOLOGICALSORT_HPP
