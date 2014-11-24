#ifndef PK_EDGETYPES_HPP
#define PK_EDGETYPES_HPP


namespace pk
{


struct edge
{
    edge() {}
    edge(const int to_) : to(to_) {}

    int to;
};


struct weighted_edge : public edge
{
    weighted_edge() {}
    weighted_edge(const int to_, const int weight_) : edge(to_), weight(weight_) {}

    int weight;
};


} // namespace pk


#endif // PK_EDGETYPES_HPP
