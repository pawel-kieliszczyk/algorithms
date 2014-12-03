#ifndef PK_EDGETYPES_HPP
#define PK_EDGETYPES_HPP


namespace pk
{


struct edge
{
    edge() {}
    edge(const int from_, const int to_) : from(from_), to(to_) {}

    int from;
    int to;
};


template<class weight_t = int>
struct weighted_edge : public edge
{
    typedef weight_t weight_type;

    weighted_edge() {}
    weighted_edge(const int from_, const int to_, const weight_type weight_) : edge(from_, to_), weight(weight_) {}

    weight_type weight;
};


template<class weight_type>
inline bool operator==(const weighted_edge<weight_type>& left, const weighted_edge<weight_type>& right)
{
    return ((left.from == right.from) && (left.to == right.to) && (left.weight == right.weight));
}


} // namespace pk


#endif // PK_EDGETYPES_HPP