#ifndef PK_GRAPHS_GRAPH_HPP
#define PK_GRAPHS_GRAPH_HPP


#include <algorithm>

#include "vector.hpp"


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
    void set_edges(const edge_type* edges_, const int sz_) { edges = edges_; sz = sz_; }

    const edge_type& operator[](const int edge_index) const { return edges[edge_index]; }

    int size() const { return sz; }

private:
    const edge_type* edges;
    int sz;
};


template<int V, int E, class edge_t>
class graph
{
public:
    static const int num_of_vertices = V;
    static const int max_num_of_edges = E;

    typedef edge_t edge_type;
    typedef detail::graph_adjacency_list<edge_type> adjacency_list;

    graph() { adjacency_lists = new adjacency_list[num_of_vertices]; }
    ~graph() { delete[] adjacency_lists; }

    void set_edges(const edge_type* edges, const int num_of_edges)
    {
        for(int first = 0; first < num_of_edges; )
        {
            int last = first;
            while(++last < num_of_edges)
            {
                if(edges[last].from != edges[first].from)
                    break;
            }

            adjacency_lists[edges[first].from].set_edges(edges + first, last - first);
            first = last;
        }
    }

    const adjacency_list& get_adjacency_list(const int vertex_id) const { return adjacency_lists[vertex_id]; }

private:
    graph(const graph&);
    graph& operator=(const graph&);

    adjacency_list* adjacency_lists;
};


} // namespace detail


template<int num_of_vertices, int max_num_of_edges, class edge_type>
class graph_factory
{
public:
    typedef detail::graph<num_of_vertices, max_num_of_edges, edge_type> graph_type;

    void add_directed_edge(const edge_type& e)
    {
        edges.push_back(e);
    }

    void add_not_directed_edge(const edge_type& e)
    {
        edges.push_back(e);

        edges.push_back(e);
        std::swap(edges.back().from, edges.back().to);
    }

    const graph_type& create()
    {
        std::sort(edges.begin(), edges.end(), edges_sorter());
        g.set_edges(edges.begin(), edges.size());

        return g;
    }

    void reset() { edges.reset(); }

private:
    struct edges_sorter
    {
        bool operator()(const edge_type& left, const edge_type& right) { return (left.from < right.from); }
    };

    pk::vector<edge_type, max_num_of_edges> edges;
    graph_type g;
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_GRAPH_HPP
