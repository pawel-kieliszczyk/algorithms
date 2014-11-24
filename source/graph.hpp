#ifndef PK_GRAPH_HPP
#define PK_GRAPH_HPP


#include "edge_types.hpp"
#include "vector.hpp"


namespace pk
{


template<int MAX_NUM_OF_VERTICES, int MAX_VERTEX_DEGREE>
class graph
{
public:
    static const int max_num_of_vertices = MAX_NUM_OF_VERTICES;
    static const int max_vertex_degree = MAX_VERTEX_DEGREE;

    typedef pk::vector<edge, max_vertex_degree> adjacency_list;

    void add_directed_edge(const int vertex_id_from, const int vertex_id_to)
    {
        adjacency_lists[vertex_id_from].push_back(edge(vertex_id_to));
    }

    void add_not_directed_edge(const int vertex_id_1, const int vertex_id_2)
    {
        add_directed_edge(vertex_id_1, vertex_id_2);
        add_directed_edge(vertex_id_2, vertex_id_1);
    }

    void reset() { for(int i = 0; i < max_num_of_vertices; ++i) adjacency_lists[i].reset(); }

    int size() const { return max_num_of_vertices; }

    const adjacency_list& get_adjacency_list(const int vertex_id) const { return adjacency_lists[vertex_id]; }

private:
    adjacency_list adjacency_lists[max_num_of_vertices];
};


} // namespace pk


#endif // PK_GRAPH_HPP
