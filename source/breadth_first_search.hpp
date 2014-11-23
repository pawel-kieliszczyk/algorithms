#ifndef PK_BREADTHFIRSTSEARCH_HPP
#define PK_BREADTHFIRSTSEARCH_HPP


#include <algorithm>

#include "graph.hpp"


namespace pk
{


class breadth_first_search
{
public:
    template<
            int MAX_NUM_OF_VERTICES,
            int MAX_VERTEX_DEGREE,
            class Visitor>
    static void run(
            const graph<MAX_NUM_OF_VERTICES, MAX_VERTEX_DEGREE>& g,
            const int starting_vertex_id,
            Visitor& visitor)
    {
        visitor.visit(starting_vertex_id);
    }
};


} // namespace pk


#endif // PK_BREADTHFIRSTSEARCH_HPP
