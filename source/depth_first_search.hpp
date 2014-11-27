#ifndef PK_DEPTHFIRSTSEARCH_HPP
#define PK_DEPTHFIRSTSEARCH_HPP


#include <algorithm>


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
        bool visited[graph_type::num_of_vertices];
        std::fill(visited, visited + graph_type::num_of_vertices, false);

        run(g, starting_vertex_id, visitor, visited);
    }

private:
    template<
            class graph_type,
            class visitor_type>
    static void run(
            const graph_type& g,
            const int v,
            visitor_type& visitor,
            bool* visited)
    {
        visited[v] = true;
        visitor.visit(v);

        const typename graph_type::adjacency_list& adj_v = g.get_adjacency_list(v);
        for(int i = 0; i < adj_v.size(); ++i)
        {
            const int u = adj_v[i].to;
            if(!visited[u])
                run(g, u, visitor, visited);
        }
    }
};


} // namespace pk


#endif // PK_DEPTHFIRSTSEARCH_HPP
