#ifndef PK_DISJOINTSETS_HPP
#define PK_DISJOINTSETS_HPP


namespace pk
{


class disjoint_sets
{
public:
    disjoint_sets(const int max_elem_id) : nodes(new node[max_elem_id+1])
    {
        for(int elem_id = 0; elem_id <= max_elem_id; ++elem_id)
        {
            nodes[elem_id].up = elem_id;
            nodes[elem_id].rank = 0;
        }
    }

    ~disjoint_sets() { delete[] nodes; }

    void union_sets(const int elem_id_1, const int elem_id_2)
    {
        const int elem_1_set_id = get_set_id(elem_id_1);
        const int elem_2_set_id = get_set_id(elem_id_2);

        if(elem_1_set_id != elem_2_set_id)
        {
            if(nodes[elem_1_set_id].rank > nodes[elem_2_set_id].rank)
            {
                nodes[elem_2_set_id].up = elem_1_set_id;
            }
            else
            {
                nodes[elem_1_set_id].up = elem_2_set_id;

                if(nodes[elem_1_set_id].rank == nodes[elem_2_set_id].rank)
                    nodes[elem_2_set_id].rank++;
            }
        }
    }

    int get_set_id(const int elem_id)
    {
        if(nodes[elem_id].up != elem_id)
            nodes[elem_id].up = get_set_id(nodes[elem_id].up);

        return nodes[elem_id].up;
    }

private:
    struct node
    {
        int up;
        int rank;
    };

    disjoint_sets(const disjoint_sets&);
    disjoint_sets& operator=(const disjoint_sets&);

    node* nodes;
};


} // namespace pk


#endif // PK_DISJOINTSETS_HPP
