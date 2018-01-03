//#include <QCoreApplication>
#include <iostream>
#include "mygraph.h"
#include "node.h"
using namespace std;

int main()
{
//    QCoreApplication a(argc, argv);
//    MyGraph *pGraph = new MyGraph(8);
    MyGraph *pGraph = new MyGraph(6);

    Node *pNodeA = new Node('A');
    Node *pNodeB = new Node('B');
    Node *pNodeC = new Node('C');
    Node *pNodeD = new Node('D');
    Node *pNodeE = new Node('E');
    Node *pNodeF = new Node('F');
//    Node *pNodeG = new Node('G');
//    Node *pNodeH = new Node('H');

    pGraph->addNode(pNodeA);
    pGraph->addNode(pNodeB);
    pGraph->addNode(pNodeC);
    pGraph->addNode(pNodeD);
    pGraph->addNode(pNodeE);
    pGraph->addNode(pNodeF);
//    pGraph->addNode(pNodeG);
//    pGraph->addNode(pNodeH);

    pGraph->setValueToMatrixUndirectedGraph(0, 1, 6);
    pGraph->setValueToMatrixUndirectedGraph(0, 4, 5);
    pGraph->setValueToMatrixUndirectedGraph(1, 2, 3);
    pGraph->setValueToMatrixUndirectedGraph(0, 5, 1);
    pGraph->setValueToMatrixUndirectedGraph(1, 5, 2);
    pGraph->setValueToMatrixUndirectedGraph(2, 5, 8);
    pGraph->setValueToMatrixUndirectedGraph(2, 3, 7);
    pGraph->setValueToMatrixUndirectedGraph(3, 5, 4);
    pGraph->setValueToMatrixUndirectedGraph(3, 4, 2);
    pGraph->setValueToMatrixUndirectedGraph(4, 5, 9);


//    pGraph->printMatrix();
    cout << "print depthFirstTraverse:" << endl;
//    cout << endl;
//    pGraph->depthFirstTraverse(0);
//    cout << endl;
//    pGraph->resetNode();
//    cout << "breadthFirstTraverse " << endl;
//    pGraph->breadthFirstTraverse(0);
//    cout << endl;
    pGraph->kruskalTree();
    return 0;
}
