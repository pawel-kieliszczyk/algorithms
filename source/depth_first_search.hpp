#ifndef PK_DEPTHFIRSTSEARCH_HPP
#define PK_DEPTHFIRSTSEARCH_HPP


#include <algorithm>


namespace pk
{


class depth_first_search
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
        bool visited[Graph::max_num_of_vertices];
        std::fill(visited, visited + Graph::max_num_of_vertices, false);

        run(g, starting_vertex_id, visitor, visited);
    }

private:
    template<
            class Graph,
            class Visitor>
    static void run(
            const Graph& g,
            const int v,
            Visitor& visitor,
            bool* visited)
    {
        visited[v] = true;
        visitor.visit(v);

        const typename Graph::adjacency_list& adj_v = g.get_adjacency_list(v);
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
