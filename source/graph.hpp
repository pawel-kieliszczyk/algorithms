#ifndef PK_GRAPH_HPP
#define PK_GRAPH_HPP


#include "vector.hpp"


namespace pk
{


template<int MAX_NUM_OF_VERTICES, int MAX_VERTEX_DEGREE>
class graph
{
public:
    typedef pk::vector<int, MAX_VERTEX_DEGREE> adjacency_list;

    void add_not_directed_edge(const int vertex_id_1, const int vertex_id_2)
    {
        adjacency_lists[vertex_id_1].push_back(vertex_id_2);
        adjacency_lists[vertex_id_2].push_back(vertex_id_1);
    }

    int size() const { return MAX_NUM_OF_VERTICES; }

    const adjacency_list& get_adjacency_list(const int vertex_id) const { return adjacency_lists[vertex_id]; }

private:
    adjacency_list adjacency_lists[MAX_NUM_OF_VERTICES];
};


} // namespace pk


#endif // PK_GRAPH_HPP
