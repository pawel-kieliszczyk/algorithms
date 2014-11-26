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

        dijkstra_heap<graph_type::max_num_of_vertices> h(starting_vertex);

        path_lengths[starting_vertex] = 0;

        for(int i = 0; i < graph_type::max_num_of_vertices; ++i)
        {
            const int u = h.get_root();
            h.remove_root(path_lengths);

            qs[u] = true;
            callback.notify(u, path_lengths[u]);

            const typename graph_type::adjacency_list& adj_u = g.get_adjacency_list(u);
            for(int j = 0; j < adj_u.size(); ++j)
            {
                const int v = adj_u[j].to;
                if(qs[v])
                    continue;

                if(path_lengths[v] > path_lengths[u] + adj_u[j].weight)
                {
                    path_lengths[v] = path_lengths[u] + adj_u[j].weight;
                    h.fix_after_change(path_lengths, v);
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
            return h[0];
        }

        void remove_root(const int* d)
        {
            h[0] = h[--size];
            hp[h[0]] = 0;

            int parent = 0;

            while(true)
            {
                const int left = 2 * parent + 1;
                const int right = left + 1;
    
                if(left >= size)
                    return;
    
                int d_min = d[h[left]];
                int p_min = left;

                if(right < size)
                {
                    if(d_min > d[h[right]])
                    {
                        d_min = d[h[right]];
                        p_min = right;
                    }
                }

                if(d[h[parent]] <= d_min)
                    return;

                std::swap(h[parent], h[p_min]);
                hp[h[parent]] = parent;
                hp[h[p_min]] = p_min;

                parent = p_min;
            }
        }

        void fix_after_change(const int* d, const int v)
        {
            int child = hp[v];
            while(child != 0)
            {
                int parent = (child - 1) / 2;

                if(d[h[parent]] <= d[h[child]])
                    break;

                std::swap(h[parent], h[child]);
                hp[h[parent]] = parent;
                hp[h[child]] = child;

                child = parent;
            }
        }

    private:
        void prepare_heap()
        {
            for(int i = 0; i < heap_size; ++i)
            {
                h[i] = i; // probably should be std::numeric_limits<int>::max()
                hp[i] = i;
            }
        }

        void fix_heap_with_starting_vertex(const int starting_vertex)
        {
            std::swap(h[0], h[starting_vertex]);
            hp[starting_vertex] = 0;
            hp[0] = starting_vertex;
        }

        int size;
        int h[heap_size];
        int hp[heap_size];
    };
};


} // namespace pk


#endif // PK_SHORTESTPATHSDIJKSTRA_HPP
