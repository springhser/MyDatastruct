#include "edge.h"

Edge::Edge(int nodeIndexA, int nodeIndexB, int weightValue)
{
    N_NodeIndexA = nodeIndexA;
    N_NodeIndexB = nodeIndexB;
    N_WeightValue = weightValue;
    N_BSelected = false;
}
