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
    static output_iterator run(const graph_type& graph, const output_iterator output_first)
    {
        const int num_of_vertices = graph.get_num_of_vertices();
        output_iterator output_last = output_first;

        pk::vector<bool, graph_type::max_num_of_vertices> visited(false, num_of_vertices);
        pk::stack<stack_entry, graph_type::max_num_of_edges> s;

        for(int i = num_of_vertices - 1; i >= 0; --i)
        {
            if(!visited[i])
                s.push(stack_entry(false, i));

            while(!s.empty())
            {
                const stack_entry e = s.top();
                s.pop();

                if(e.is_parent)
                {
                    *output_last++ = e.vertex_id;
                    continue;
                }

                visited[e.vertex_id] = true;
                s.push(stack_entry(true, e.vertex_id));

                const typename graph_type::adjacency_list& adjacent_edges = graph.get_adjacency_list(e.vertex_id);
                for(int i = 0; i < adjacent_edges.size(); ++i)
                {
                    const int v = adjacent_edges[i].to;
                    if(!visited[v])
                        s.push(stack_entry(false, v));
                }
            }
        }

        std::reverse(output_first, output_last);
        return output_last;
    }

private:
    struct stack_entry
    {
        stack_entry() {}
        stack_entry(bool is_parent_, int vertex_id_) : is_parent(is_parent_), vertex_id(vertex_id_) {}

        bool is_parent;
        int vertex_id;
    };
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_TOPOLOGICALSORT_HPP
