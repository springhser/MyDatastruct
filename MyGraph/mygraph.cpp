#include <iostream>
#include <vector>
#include <cstring>
#include "mygraph.h"
#include "node.h"
#include "edge.h"
using namespace std;

MyGraph::MyGraph(int capactiy)
{
    N_Capacity = capactiy;

    N_NodeCount = 0;

    N_pNodeArray = new Node[N_Capacity];

    N_pMatrix = new int[N_Capacity*N_Capacity];
    memset(N_pMatrix, 0, N_Capacity*N_Capacity*sizeof(int));

    N_pEdge = new Edge[N_Capacity-1];
}


MyGraph::~MyGraph()
{
    delete []N_pNodeArray;
    delete []N_pMatrix;
    delete []N_pEdge;
}

bool MyGraph::addNode(Node *pNode)
{
    if(pNode == nullptr)
    {
        return false;
    }

    N_pNodeArray[N_NodeCount].N_Data = pNode->N_Data;
    N_pNodeArray[N_NodeCount].N_isVisited = pNode->N_isVisited;
    N_NodeCount++;

    return true;
}

void MyGraph::resetNode()
{
    for(int i=0; i<N_Capacity; i++)
    {
        N_pNodeArray[i].N_isVisited = false;
    }
}

bool MyGraph::setValueToMatrixDirectedGraph(int row, int col, int val)
{
    if(row <0 || row >= N_Capacity)
    {
        cout << "out of index" << endl;
        return false;
    }
    if(col < 0 || col >= N_Capacity)
    {
        cout << "out of index" << endl;
        return false;
    }

    N_pMatrix[row*N_Capacity + col] = val;

    return true;
}

bool MyGraph::setValueToMatrixUndirectedGraph(int row, int col, int val)
{
    if(row <0 || row >= N_Capacity)
    {
        cout << "out of index" << endl;
        return false;
    }
    if(col < 0 || col >= N_Capacity)
    {
        cout << "out of index" << endl;
        return false;
    }

    N_pMatrix[row*N_Capacity + col] = val;
    N_pMatrix[col*N_Capacity + row] = val;

    return true;
}


void MyGraph::printMatrix()
{
    for(int i=0; i<N_Capacity; i++)
    {
        for(int j=0; j<N_Capacity; j++)
        {
            cout << N_pMatrix[i*N_Capacity + j] << " ";
        }
        cout << endl;
    }
}


bool MyGraph::getValueFromMatrix(int row, int col, int &val)
{
    if(row <0 || row >= N_Capacity)
    {
        cout << "out of index" << endl;
        return false;
    }
    if(col < 0 || col >= N_Capacity)
    {
        cout << "out of index" << endl;
        return false;
    }

    val = N_pMatrix[row*N_Capacity + col];

    return true;
}

void MyGraph::depthFirstTraverse(int nodeIndex)
{
//    cout << "print depthFirstTraverse:" << endl;
    cout << N_pNodeArray[nodeIndex].N_Data << " ";

    N_pNodeArray[nodeIndex].N_isVisited = true;

    int value = 0;
    for(int i=0; i<N_Capacity; i++)
    {
//        this->getValueFromMatrix(nodeIndex, i, value);
        getValueFromMatrix(nodeIndex, i, value);
        if(value != 0)
        {
            if(N_pNodeArray[i].N_isVisited)
            {
                continue;
            }
            else
            {
                depthFirstTraverse(i);
            }
        }
        else
        {
            continue;
        }
    }
}

void MyGraph::breadthFirstTraverse(int nodeIndex)
{
//    cout << "breadthFirstTraverse " << endl;
    cout << N_pNodeArray[nodeIndex].N_Data << " ";
    vector<int> curVec;
     curVec.push_back(nodeIndex);
     N_pNodeArray[nodeIndex].N_isVisited = true;

     breadthFirstTraverseImpl(curVec);
}

void MyGraph::breadthFirstTraverseImpl(vector<int> preVec)
{
    vector<int> curVec;
    int value = 0;

    for(int j=0; j<(int)preVec.size(); j++)
    {
        for(int i=0; i<N_Capacity; i++)
        {
            getValueFromMatrix(preVec[j], i, value);
            if(value != 0)
            {
                if(N_pNodeArray[i].N_isVisited)
                {
                    continue;
                }
                else
                {
                    cout << N_pNodeArray[i].N_Data << " ";
                    curVec.push_back(i);
                    N_pNodeArray[i].N_isVisited = true;
                }
            }
        }
    }

    if((int)curVec.size() != 0)
    {
        breadthFirstTraverseImpl(curVec);
    }
    else
    {
        return;
    }
}

void MyGraph::primTree(int nodeIndex)
{
    int value = 0;
    int edgeCount = 0;
    vector<int> nodeVec;
    vector<Edge> edgeVec;

    nodeVec.push_back(nodeIndex);
    N_pNodeArray[nodeIndex].N_isVisited = true;

    while(edgeCount < N_Capacity)
    {
        int temp = nodeVec.back();

        for(int i=0; i<N_Capacity; i++)
        {
            getValueFromMatrix(temp, i, value);
            if(value != 0)
            {
                if(N_pNodeArray[i].N_isVisited)
                {
                    continue;
                }
                else
                {
                    Edge edge(temp, i, value);
                    edgeVec.push_back(edge);
                }
            }
        }

        int edgeIndex = getMinEdge(edgeVec);
        edgeVec[edgeIndex].N_BSelected = true;

        cout << edgeVec[edgeIndex].N_NodeIndexA << "----" <<edgeVec[edgeIndex].N_NodeIndexB<<" ";
        cout << edgeVec[edgeIndex].N_WeightValue << endl;

        N_pEdge[edgeCount] = edgeVec[edgeIndex];
        edgeCount++;

        int nextNodeIndex = edgeVec[edgeIndex].N_NodeIndexB;

        nodeVec.push_back(nextNodeIndex);
        N_pNodeArray[nextNodeIndex].N_isVisited = true;

        cout << N_pNodeArray[nextNodeIndex].N_Data << endl;

    }
}

int MyGraph::getMinEdge(vector<Edge> edgeVec)
{
    int minWeight = 0;
    int i = 0;
    int edgeIndex = 0;

    for(;i<(int)edgeVec.size();i++)
    {
        if(!edgeVec[i].N_BSelected)
        {
            minWeight = edgeVec[i].N_WeightValue;
            edgeIndex = i;
            break;
        }
    }

    if(minWeight == 0)
    {
        return -1;
    }

    for(;i<(int)edgeVec.size();i++)
    {
        if(edgeVec[i].N_BSelected)
        {
            continue;
        }
        else
        {
            if(minWeight > edgeVec[i].N_WeightValue)
            {
                minWeight = edgeVec[i].N_WeightValue;
                edgeIndex = i;
            }
        }
    }

    return edgeIndex;
}


void MyGraph::kruskalTree()
{
    int value = 0;
//    int edgeIndex = 0;
    int edgeCount = 0;

    vector<vector<int>> nodeSets;

    vector<Edge> edgeVec;

    for(int i=0; i<N_Capacity; i++)
    {
        for(int k = i+1;k<N_Capacity;k++)
        {
            getValueFromMatrix(i,k,value);
            if(value!=0)
            {
                Edge edge(i,k,value);
                edgeVec.push_back(edge);
            }
        }
    }

    while(edgeCount < N_Capacity-1)
    {
        int minEdgeIndex = getMinEdge(edgeVec);

        edgeVec[minEdgeIndex].N_BSelected = true;

        int nodeAIndex = edgeVec[minEdgeIndex].N_NodeIndexA;
        int nodeBIndex = edgeVec[minEdgeIndex].N_NodeIndexB;

        bool nodeAIsInSet = false;
        bool nodeBIsInSet = false;

        int nodeAInSetLabel = -1;
        int nodeBInSetLabel = -1;

        for(int i = 0;i<(int)nodeSets.size();i++)
        {
            nodeAIsInSet = isInSet(nodeSets[i], nodeAIndex);
            if(nodeAIsInSet)
            {
                nodeAInSetLabel = i;
            }
        }
        for(int i = 0;i<(int)nodeSets.size();i++)
        {
            nodeBIsInSet = isInSet(nodeSets[i], nodeBIndex);
            if(nodeBIsInSet)
            {
                nodeBInSetLabel = i;
            }
        }


        if(nodeAInSetLabel == -1&& nodeBInSetLabel == -1)
        {
            vector<int> vec;
            vec.push_back(nodeAIndex);
            vec.push_back(nodeBIndex);
            nodeSets.push_back(vec);

        }
        else if(nodeAInSetLabel == -1&&nodeBInSetLabel != -1)
        {
            nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
        }
        else if(nodeAInSetLabel != -1&&nodeBInSetLabel == -1)
        {
            nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
        }
        else if(nodeAInSetLabel !=-1&&nodeBInSetLabel!=-1&&nodeAInSetLabel!=nodeBInSetLabel)
        {
            mergeNodeSet(nodeSets[nodeAInSetLabel],nodeSets[nodeBInSetLabel]);
            for(int k = nodeBInSetLabel; k<(int)nodeSets.size()-1; k++)
            {
                nodeSets[k] = nodeSets[k+1];
            }
        }
        else if(nodeAInSetLabel !=-1&&nodeBInSetLabel!=-1&&nodeAInSetLabel==nodeBInSetLabel)
        {
            continue;
        }

        N_pEdge[edgeCount] = edgeVec[minEdgeIndex];
        edgeCount++;

        cout << edgeVec[minEdgeIndex].N_NodeIndexA << "----" <<edgeVec[minEdgeIndex].N_NodeIndexB<<" ";
        cout << edgeVec[minEdgeIndex].N_WeightValue << endl;

    }
}


bool MyGraph::isInSet(vector<int> nodeSet, int target)
{
    for(int i=0;i<(int)nodeSet.size();i++)
    {
        if(nodeSet[i] == target)
        {
            return true;
        }
    }

    return false;
}

void MyGraph::mergeNodeSet(vector<int> &nodeSetA, vector<int> nodeSetB)
{
    for(int i=0; i<(int)nodeSetB.size(); i++)
    {
        nodeSetA.push_back(nodeSetB[i]);
    }
}





