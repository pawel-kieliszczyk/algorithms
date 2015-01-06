#ifndef PK_GRAPHS_SHORTESTPATHSDIJKSTRA_HPP
#define PK_GRAPHS_SHORTESTPATHSDIJKSTRA_HPP


#include <algorithm>
#include <limits>

#include "vector.hpp"


namespace pk
{
namespace graphs
{


class shortest_paths_dijkstra
{
public:
    template<class graph_type, class callback_type>
    static void run(const graph_type& g, const int starting_vertex, callback_type& callback)
    {
        typedef typename graph_type::edge_type::weight_type weight_type;
        const weight_type infinity = std::numeric_limits<weight_type>::max();

        pk::vector<bool, graph_type::num_of_vertices> processed_vertices(false);
        pk::vector<weight_type, graph_type::num_of_vertices> path_lengths(infinity);

        dijkstra_heap<graph_type::num_of_vertices, weight_type> h(starting_vertex, path_lengths.cbegin());

        path_lengths[starting_vertex] = weight_type();

        for(int i = 0; i < graph_type::num_of_vertices; ++i)
        {
            const int u = h.get_root();

            if(path_lengths[u] == infinity)
                break;

            h.remove_root();

            processed_vertices[u] = true;
            callback.notify(u, path_lengths[u]);

            const typename graph_type::adjacency_list& adj_u = g.get_adjacency_list(u);
            for(int j = 0; j < adj_u.size(); ++j)
            {
                const int v = adj_u[j].to;
                if(processed_vertices[v])
                    continue;

                if(path_lengths[v] > path_lengths[u] + adj_u[j].weight)
                {
                    path_lengths[v] = path_lengths[u] + adj_u[j].weight;
                    h.fix_heap_after_path_length_change(v);
                }
            }
        }
    }

private:
    template<int heap_size, class weight_type>
    class dijkstra_heap
    {
    public:
        dijkstra_heap(const int starting_vertex, const weight_type* path_lengths_) : size(heap_size), path_lengths(path_lengths_)
        {
            prepare_heap();
            fix_heap_with_starting_vertex(starting_vertex);
        }

        int get_root() const
        {
            return heap_array[0];
        }

        void remove_root()
        {
            heap_array[0] = heap_array[--size];
            heap_array_index[heap_array[0]] = 0;

            int parent = 0;

            while(true)
            {
                const int left = 2 * parent + 1;
                const int right = left + 1;

                if(left >= size)
                    return;

                int min_path_length = path_lengths[heap_array[left]];
                int child_with_min_path_length_index = left;

                if(right < size)
                {
                    if(min_path_length > path_lengths[heap_array[right]])
                    {
                        min_path_length = path_lengths[heap_array[right]];
                        child_with_min_path_length_index = right;
                    }
                }

                if(path_lengths[heap_array[parent]] <= min_path_length)
                    return;

                std::swap(heap_array[parent], heap_array[child_with_min_path_length_index]);
                heap_array_index[heap_array[parent]] = parent;
                heap_array_index[heap_array[child_with_min_path_length_index]] = child_with_min_path_length_index;

                parent = child_with_min_path_length_index;
            }
        }

        void fix_heap_after_path_length_change(const int vertex_with_changed_path_length)
        {
            int child = heap_array_index[vertex_with_changed_path_length];
            while(child != 0)
            {
                int parent = (child - 1) / 2;

                if(path_lengths[heap_array[parent]] <= path_lengths[heap_array[child]])
                    break;

                std::swap(heap_array[parent], heap_array[child]);
                heap_array_index[heap_array[parent]] = parent;
                heap_array_index[heap_array[child]] = child;

                child = parent;
            }
        }

    private:
        void prepare_heap()
        {
            for(int i = 0; i < heap_size; ++i)
            {
                heap_array[i] = i;
                heap_array_index[i] = i;
            }
        }

        void fix_heap_with_starting_vertex(const int starting_vertex)
        {
            std::swap(heap_array[0], heap_array[starting_vertex]);
            heap_array_index[starting_vertex] = 0;
            heap_array_index[0] = starting_vertex;
        }

        int size; ///< current number of elements in the heap
        int heap_array[heap_size]; ///< contains vertex ids organized by path lengths
        int heap_array_index[heap_size]; ///< heap_array_index[u] contains the index of u in heap_array

        const weight_type* path_lengths; ///< pointer to lengths of all already calculated paths
    };
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_SHORTESTPATHSDIJKSTRA_HPP
