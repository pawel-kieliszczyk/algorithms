#ifndef PK_DEPTHFIRSTSEARCH_HPP
#define PK_DEPTHFIRSTSEARCH_HPP


#include <algorithm>

#include "graph.hpp"


namespace pk
{


class depth_first_search
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
        bool visited[MAX_NUM_OF_VERTICES];
        std::fill(visited, visited + MAX_NUM_OF_VERTICES, false);

        run(g, starting_vertex_id, visitor, visited);
    }

private:
    template<
            int MAX_NUM_OF_VERTICES,
            int MAX_VERTEX_DEGREE,
            class Visitor>
    static void run(
            const graph<MAX_NUM_OF_VERTICES, MAX_VERTEX_DEGREE>& g,
            const int v,
            Visitor& visitor,
            bool* visited)
    {
        visited[v] = true;
        visitor.visit(v);

        const typename graph<MAX_NUM_OF_VERTICES, MAX_VERTEX_DEGREE>::adjacency_list& adj_v = g.get_adjacency_list(v);
        for(int i = 0; i < adj_v.size(); ++i)
        {
            const int u = adj_v[i];
            if(!visited[u])
                run(g, u, visitor, visited);
        }
    }
};


} // namespace pk


#endif // PK_DEPTHFIRSTSEARCH_HPP
