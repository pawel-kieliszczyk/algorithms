#ifndef PK_DEPTHFIRSTSEARCH_HPP
#define PK_DEPTHFIRSTSEARCH_HPP


#include <algorithm>

#include "stack.hpp"


namespace pk
{


class depth_first_search
{
public:
    template<
            class graph_type,
            class visitor_type>
    static void run(
            const graph_type& g,
            const int starting_vertex_id,
            visitor_type& visitor)
    {
        pk::stack<int, graph_type::max_num_of_edges> s;

        bool visited[graph_type::num_of_vertices];
        std::fill(visited, visited + graph_type::num_of_vertices, false);

        s.push(starting_vertex_id);

        while(!s.empty())
        {
            const int v = s.top();
            s.pop();

            if(visited[v])
                continue;

            visitor.visit(v);
            visited[v] = true;

            const typename graph_type::adjacency_list& adj_v = g.get_adjacency_list(v);
            for(int i = adj_v.size(); i >= 0; --i)
            {
                const int u = adj_v[i].to;

                if(visited[u])
                    continue;

                s.push(u);
            }
        }
    }
};


} // namespace pk


#endif // PK_DEPTHFIRSTSEARCH_HPP
