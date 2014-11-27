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
        const int infinity = std::numeric_limits<int>::max();

        bool processed_vertices[graph_type::max_num_of_vertices];
        std::fill(processed_vertices, processed_vertices + graph_type::max_num_of_vertices, false);

        int path_lengths[graph_type::max_num_of_vertices];
        std::fill(path_lengths, path_lengths + graph_type::max_num_of_vertices, infinity);

        dijkstra_heap<graph_type::max_num_of_vertices> h(starting_vertex);

        path_lengths[starting_vertex] = 0;

        for(int i = 0; i < graph_type::max_num_of_vertices; ++i)
        {
            const int u = h.get_root();

            if(path_lengths[u] == infinity)
                break;

            h.remove_root(path_lengths);

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
                    h.fix_heap_after_path_length_change(path_lengths, v);
                }
            }
        }
    }

private:
    template<int heap_size>
    class dijkstra_heap
    {
    public:
        dijkstra_heap(const int starting_vertex) : size(heap_size)
        {
            prepare_heap();
            fix_heap_with_starting_vertex(starting_vertex);
        }

        int get_root() const
        {
            return heap_array[0];
        }

        void remove_root(const int* path_lengths)
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

        void fix_heap_after_path_length_change(const int* path_lengths, const int vertex_with_changed_path_length)
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
    };
};


} // namespace pk


#endif // PK_SHORTESTPATHSDIJKSTRA_HPP
