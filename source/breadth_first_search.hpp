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
            class Graph,
            class Visitor>
    static void run(
            const Graph& g,
            const int starting_vertex_id,
            Visitor& visitor)
    {
        pk::queue<int, Graph::max_num_of_vertices> q;

        bool visited[Graph::max_num_of_vertices];
        std::fill(visited, visited + Graph::max_num_of_vertices, false);

        q.push(starting_vertex_id);
        visited[starting_vertex_id] = true;

        while(!q.empty())
        {
            const int v = q.front();
            q.pop();

            visitor.visit(v);

            const typename Graph::adjacency_list& adj_v = g.get_adjacency_list(v);
            for(int i = 0; i < adj_v.size(); ++i)
            {
                const int u = adj_v[i];

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
