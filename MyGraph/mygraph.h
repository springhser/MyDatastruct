#ifndef MYGRAPH_H
#define MYGRAPH_H
#include "node.h"
#include "edge.h"
#include <vector>
using namespace std;

class MyGraph
{
public:
    MyGraph(int capacity);

    ~MyGraph();

    bool addNode(Node *pNode);  //

    void resetNode();


    bool setValueToMatrixDirectedGraph(int row, int col, int val = 1);

    bool setValueToMatrixUndirectedGraph(int row, int col, int val = 1);


    void printMatrix();


    void depthFirstTraverse(int nodeIndex);

    void breadthFirstTraverse(int nodeIndex);

    void primTree(int nodeIndex);

    void kruskalTree();

private:

    bool getValueFromMatrix(int row, int col, int &val);

    void breadthFirstTraverseImpl(vector<int> preVec);

    int getMinEdge(vector<Edge> edgeVec);

    bool isInSet(vector<int> nodeSet, int target);

    void mergeNodeSet(vector<int>&nodeSetA, vector<int>nodeSetB);

private:

    int N_Capacity; //the max volume of graph

    int N_NodeCount;    //count the num of Node

    Node *N_pNodeArray;     //the Array to store Node

    int *N_pMatrix;     //the Matrix to store adjacency matrix

    Edge *N_pEdge;
};

#endif // MYGRAPH_H
