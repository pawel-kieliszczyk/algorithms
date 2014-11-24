#ifndef PK_WEIGHTEDGRAPH_HPP
#define PK_WEIGHTEDGRAPH_HPP


#include "edge_types.hpp"
#include "vector.hpp"


namespace pk
{


template<int MAX_NUM_OF_VERTICES, int MAX_VERTEX_DEGREE>
class weighted_graph
{
public:
    static const int max_num_of_vertices = MAX_NUM_OF_VERTICES;
    static const int max_vertex_degree = MAX_VERTEX_DEGREE;

    typedef pk::vector<weighted_edge, max_vertex_degree> adjacency_list;
};


} // namespace pk


#endif // PK_WEIGHTEDGRAPH_HPP
