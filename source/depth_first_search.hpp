#ifndef PK_DEPTHFIRSTSEARCH_HPP
#define PK_DEPTHFIRSTSEARCH_HPP


#include "graph.hpp"


namespace pk
{


class depth_first_search
{
public:
    template<
            int MAX_NUM_OF_VERTICES,
            int MAX_VERTEX_DEGREE,
            class visit_function>
    static void run(
            const graph<MAX_NUM_OF_VERTICES, MAX_VERTEX_DEGREE>& graph,
            const int starting_vertex_id,
            visit_function visit)
    {
        visit(starting_vertex_id);
    }
};


} // namespace pk


#endif // PK_DEPTHFIRSTSEARCH_HPP
