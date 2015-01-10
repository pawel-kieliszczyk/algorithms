#ifndef PK_GRAPHS_SHORTESTPATHSFLOYDWARSHALL_HPP
#define PK_GRAPHS_SHORTESTPATHSFLOYDWARSHALL_HPP


#include <limits>


namespace pk
{
namespace graphs
{


template<const int V, class WeightType>
class shortest_paths_floyd_warshall
{
public:
    typedef WeightType weight_type;
    typedef const weight_type (*shortest_paths_matrix)[V];

    shortest_paths_floyd_warshall() : infinity(std::numeric_limits<weight_type>::max()) {}

    template<class graph_type>
    void run(const graph_type& g)
    {
        num_of_vertices = g.get_num_of_vertices();

        initialize_all_paths_to_infinity_and_each_vertex_to_zero();
        set_initial_paths_to_neighbours(g);
        compute_shortest_paths();
    }

    shortest_paths_matrix get_shortest_paths_matrix() const
    {
        return shortest_paths;
    }

    const weight_type infinity;

private:
    void initialize_all_paths_to_infinity_and_each_vertex_to_zero()
    {
        for(int i = 0; i < num_of_vertices; ++i)
        {
            for(int j = 0; j < num_of_vertices; ++j)
                shortest_paths[i][j] = infinity;

            shortest_paths[i][i] = weight_type(0);
        }
    }

    template<class graph_type>
    void set_initial_paths_to_neighbours(const graph_type& g)
    {
        for(int v = 0; v < num_of_vertices; ++v)
        {
            const typename graph_type::adjacency_list& adj_v = g.get_adjacency_list(v);
            for(int i = 0; i < adj_v.size(); ++i)
            {
                const int u = adj_v[i].to;
                shortest_paths[v][u] = adj_v[i].weight;
            }
        }
    }

    void compute_shortest_paths()
    {
        for(int k = 0; k < num_of_vertices; ++k)
        {
            for(int i = 0; i < num_of_vertices; ++i)
            {
                for(int j = 0; j < num_of_vertices; ++j)
                {
                    if((shortest_paths[i][k] == infinity) || (shortest_paths[k][j] == infinity))
                        continue;

                    const weight_type w = shortest_paths[i][k] + shortest_paths[k][j];
                    if(w < shortest_paths[i][j])
                        shortest_paths[i][j] = w;
                }
            }
        }
    }

    weight_type shortest_paths[V][V];
    int num_of_vertices;
};


} // namespace graphs
} // namespace pk


#endif // PK_GRAPHS_SHORTESTPATHSFLOYDWARSHALL_HPP
