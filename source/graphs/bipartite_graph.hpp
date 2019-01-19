#ifndef PK_GRAPHS_BIPARTITEGRAPH_HPP
#define PK_GRAPHS_BIPARTITEGRAPH_HPP


#include <algorithm>

#include "vector.hpp"


/**
 * Bipartite graph class can represent a bipartite graph.
 * Vertices are represented by sets U (indexed [0,..,U-1]) and V (indexed [0,..,V-1]).
 * Currenlty only edges from U to V are supported.
 * For example:
 *     + edge 1->1 is an edge from vertex 1 in U to vertex 1 in V.
 *     + edge 2->3 is an edge from vertex 2 in U to vertex 3 in V.
 */
namespace pk
{
namespace graphs
{
namespace detail
{


template<class edge_type>
class graph_adjacency_list
{
public:
    graph_adjacency_list() : sz(0) {}
    void set_edges(edge_type* edges_, const int sz_) { edges = edges_; sz = sz_; }

    edge_type& operator[](const int edge_index) { return edges[edge_index]; }
    const edge_type& operator[](const int edge_index) const { return edges[edge_index]; }

    int size() const { return sz; }

    void reset() { sz = 0; }

private:
    edge_type* edges;
    int sz;
};


template<int U, int V, int E, class edge_t>
class bipartite_graph
{
public:
    static const int max_num_of_vertices_u = U;
    static const int max_num_of_vertices_v = V;
    static const int max_num_of_edges = E;

    typedef edge_t edge_type;
    typedef detail::graph_adjacency_list<edge_type> adjacency_list;

    bipartite_graph()
    {
        adjacency_lists = new adjacency_list[max_num_of_vertices_u];
    }

    ~bipartite_graph()
    {
        delete[] adjacency_lists;
    }

    void initialize(const int new_real_num_of_vertices_u, const int new_real_num_of_vertices_v, edge_type* edges, const int new_real_num_of_edges)
    {
        real_num_of_vertices_u = new_real_num_of_vertices_u;
        real_num_of_vertices_v = new_real_num_of_vertices_v;
        real_num_of_edges = new_real_num_of_edges;

        reset_adjacency_lists();

        for(int first = 0; first < real_num_of_edges; )
        {
            int last = first;
            while(++last < real_num_of_edges)
            {
                if(edges[last].from != edges[first].from)
                    break;
            }

            adjacency_lists[edges[first].from].set_edges(edges + first, last - first);
            first = last;
        }
    }

    int get_num_of_vertices_u() const
    {
        return real_num_of_vertices_u;
    }

    int get_num_of_vertices_v() const
    {
        return real_num_of_vertices_v;
    }

    int get_num_of_edges() const
    {
        return real_num_of_edges;
    }

    const adjacency_list& get_adjacency_list_u(const int vertex_id) const
    {
        return adjacency_lists[vertex_id];
    }

private:
    void reset_adjacency_lists()
    {
        for(int i = 0; i < real_num_of_vertices_u; ++i)
            adjacency_lists[i].reset();
    }

    bipartite_graph(const bipartite_graph&);
    bipartite_graph& operator=(const bipartite_graph&);

    int real_num_of_vertices_u;
    int real_num_of_vertices_v;
    int real_num_of_edges;

    adjacency_list* adjacency_lists;
};


} // namespace detail


template<int num_of_vertices_u, int num_of_vertices_v, int max_num_of_edges, class edge_type>
class bipartite_graph_factory
{
public:
    typedef detail::bipartite_graph<num_of_vertices_u, num_of_vertices_v, max_num_of_edges, edge_type> bipartite_graph_type;

    void add_directed_edge_uv(const edge_type& e)
    {
        edges_uv.push_back(e);
    }

    bipartite_graph_type& create(const int real_num_of_vertices_u, const int real_num_of_vertices_v)
    {
        std::sort(edges_uv.begin(), edges_uv.end(), edges_sorter());
        g.initialize(real_num_of_vertices_u, real_num_of_vertices_v, edges_uv.begin(), edges_uv.size());

        return g;
    }

    void reset()
    {
        edges_uv.clear();
    }

private:
    struct edges_sorter
    {
        bool operator()(const edge_type& left, const edge_type& right) { return (left.from < right.from); }
    };

    pk::vector<edge_type, max_num_of_edges> edges_uv;
    bipartite_graph_type g;
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_BIPARTITEGRAPH_HPP
