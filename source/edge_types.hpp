#ifndef PK_EDGETYPES_HPP
#define PK_EDGETYPES_HPP


namespace pk
{


struct edge
{
    int to;
};


struct weighted_edge : public edge
{
    int weight;
};


} // namespace pk


#endif // PK_EDGETYPES_HPP
