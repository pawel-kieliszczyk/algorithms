#ifndef PK_SHORTESTPATHSDIJKSTRA_HPP
#define PK_SHORTESTPATHSDIJKSTRA_HPP


#include <algorithm>
#include <limits>


namespace pk
{


class shortest_paths_dijkstra
{
public:
    template<class graph_type, class callback_type>
    static void run(const graph_type& g, const int starting_vertex, callback_type& callback)
    {
        bool qs[graph_type::max_num_of_vertices];
        std::fill(qs, qs + graph_type::max_num_of_vertices, false);

        int path_lengths[graph_type::max_num_of_vertices];
        std::fill(path_lengths, path_lengths + graph_type::max_num_of_vertices, std::numeric_limits<int>::max());
    }
};


} // namespace pk


#endif // PK_SHORTESTPATHSDIJKSTRA_HPP
