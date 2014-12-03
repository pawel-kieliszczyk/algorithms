#ifndef PK_GRAPH_HPP
#define PK_GRAPH_HPP


#include <algorithm>


namespace pk
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

    graph(const edge_type* edges, const int num_of_edges)
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
    adjacency_list adjacency_lists[num_of_vertices];
};


} // namespace detail


template<int num_of_vertices, int max_num_of_edges, class edge_type>
class graph_factory
{
public:
    typedef detail::graph<num_of_vertices, max_num_of_edges, edge_type> graph_type;

    graph_factory() : edges_count(0) {}

    void add_directed_edge(const edge_type& e)
    {
        edges[edges_count++] = e;
    }

    void add_not_directed_edge(const edge_type& e)
    {
        edges[edges_count] = e;

        edges[++edges_count] = e;
        std::swap(edges[edges_count].from, edges[edges_count].to);

        ++edges_count;
    }

    graph_type create()
    {
        std::sort(edges, edges + edges_count, edges_sorter());
        return graph_type(edges, edges_count);
    }

    void reset() { edges_count = 0; }

private:
    struct edges_sorter
    {
        bool operator()(const edge_type& left, const edge_type& right) { return (left.from < right.from); }
    };

    edge_type edges[max_num_of_edges];
    int edges_count;
};


} // namespace pk


#endif // PK_GRAPH_HPP
