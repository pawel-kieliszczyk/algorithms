#ifndef PK_DISJOINTSETS_HPP
#define PK_DISJOINTSETS_HPP


#include "vector.hpp"


namespace pk
{


template<int MAX_ELEM_ID>
class disjoint_sets
{
public:
    static const int no_set = -1;

    disjoint_sets() : nodes(-1) {}

    void make_set(const int elem_id) { nodes[elem_id] = elem_id; }

    void union_sets(const int elem_id_1, const int elem_id_2) {}

    int get_set_id(const int elem_id) const { return nodes[elem_id]; }

private:
    pk::vector<int, MAX_ELEM_ID + 1> nodes;
};


} // namespace pk


#endif // PK_DISJOINTSETS_HPP
