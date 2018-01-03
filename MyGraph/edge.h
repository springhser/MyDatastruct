#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:
    Edge(int nodeIndexA=0, int nodeIndexB=0, int weightValue=0);
    int N_NodeIndexA;
    int N_NodeIndexB;
    int N_WeightValue;
    bool N_BSelected;
};

#endif // EDGE_H
