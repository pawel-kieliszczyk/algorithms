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

    int size() const { return MAX_NUM_OF_VERTICES; }

    const adjacency_list& get_adjacency_list(const int vertexId) const { return adjacency_lists[vertexId]; }

private:
    adjacency_list adjacency_lists[MAX_NUM_OF_VERTICES];
};


} // namespace pk


#endif // PK_GRAPH_HPP
