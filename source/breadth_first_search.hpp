#ifndef PK_BREADTHFIRSTSEARCH_HPP
#define PK_BREADTHFIRSTSEARCH_HPP


#include <algorithm>

#include "queue.hpp"


namespace pk
{


class breadth_first_search
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
        pk::queue<int, graph_type::num_of_vertices> q;

        bool visited[graph_type::num_of_vertices];
        std::fill(visited, visited + graph_type::num_of_vertices, false);

        q.push(starting_vertex_id);
        visited[starting_vertex_id] = true;

        while(!q.empty())
        {
            const int v = q.front();
            q.pop();

            visitor.visit(v);

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
};


} // namespace pk


#endif // PK_BREADTHFIRSTSEARCH_HPP
