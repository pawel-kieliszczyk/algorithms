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
    void set_edges(edge_type* edges_, const int sz_) { edges = edges_; sz = sz_; }

    edge_type& operator[](const int edge_index) { return edges[edge_index]; }
    const edge_type& operator[](const int edge_index) const { return edges[edge_index]; }

    int size() const { return sz; }

    void reset() { sz = 0; }

private:
    edge_type* edges;
    int sz;
};


template<int V, int E, class edge_t>
class graph
{
public:
    static const int max_num_of_vertices = V;
    static const int max_num_of_edges = E;

    typedef edge_t edge_type;
    typedef detail::graph_adjacency_list<edge_type> adjacency_list;

    graph()
    {
        adjacency_lists = new adjacency_list[max_num_of_vertices];
    }

    ~graph()
    {
        delete[] adjacency_lists;
    }

    void initialize(const int new_real_num_of_vertices, edge_type* edges, const int new_real_num_of_edges)
    {
        real_num_of_vertices = new_real_num_of_vertices;
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

    int get_num_of_vertices() const
    {
        return real_num_of_vertices;
    }

    int get_num_of_edges() const
    {
        return real_num_of_vertices;
    }

    adjacency_list& get_adjacency_list(const int vertex_id)
    {
        return adjacency_lists[vertex_id];
    }

    const adjacency_list& get_adjacency_list(const int vertex_id) const
    {
        return adjacency_lists[vertex_id];
    }

private:
    void reset_adjacency_lists()
    {
        for(int i = 0; i < real_num_of_vertices; ++i)
            adjacency_lists[i].reset();
    }

    graph(const graph&);
    graph& operator=(const graph&);

    int real_num_of_vertices;
    int real_num_of_edges;

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

    void add_residual_edge(const edge_type& e)
    {
        edges.push_back(e);

        edge_type reverse_edge = e;
        std::swap(reverse_edge.from, reverse_edge.to);
        reverse_edge.capacity = typename edge_type::capacity_type();

        edges.push_back(reverse_edge);
    }

    graph_type& create(const int real_num_of_vertices)
    {
        std::sort(edges.begin(), edges.end(), edges_sorter());
        g.initialize(real_num_of_vertices, edges.begin(), edges.size());

        return g;
    }

    void reset()
    {
        edges.clear();
    }

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
