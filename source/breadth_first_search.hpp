#ifndef PK_BREADTHFIRSTSEARCH_HPP
#define PK_BREADTHFIRSTSEARCH_HPP


#include <algorithm>

#include "graph.hpp"
#include "queue.hpp"


namespace pk
{


class breadth_first_search
{
public:
    template<
            int MAX_NUM_OF_VERTICES,
            int MAX_VERTEX_DEGREE,
            class Visitor>
    static void run(
            const graph<MAX_NUM_OF_VERTICES, MAX_VERTEX_DEGREE>& g,
            const int starting_vertex_id,
            Visitor& visitor)
    {
        pk::queue<int, MAX_NUM_OF_VERTICES> q;

        bool visited[MAX_NUM_OF_VERTICES];
        std::fill(visited, visited + MAX_NUM_OF_VERTICES, false);

        q.push(starting_vertex_id);
        visited[starting_vertex_id] = true;

        while(!q.empty())
        {
            const int v = q.front();
            q.pop();

            visitor.visit(v);

            const typename graph<MAX_NUM_OF_VERTICES, MAX_VERTEX_DEGREE>::adjacency_list& adj_v = g.get_adjacency_list(v);
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
