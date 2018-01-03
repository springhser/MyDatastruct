#include <iostream>
#include "Tree.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Node *node1 = new Node();
	node1->index = 1;
	node1->data = 11;
	Node *node2 = new Node();
	node2->index = 2;
	node2->data = 14;
	
	Node *node3 = new Node();
	node3->index = 3;
	node3->data = 21;
	
	Node *node4 = new Node();
	node4->index = 4;
	node4->data = 31;
	
	Node *node5 = new Node();
	node5->index = 5;
	node5->data = 38;
	
	Node *node6 = new Node();
	node6->index = 6;
	node6->data = 89;
	
	Node *node7 = new Node();
	node7->index = 7;
	node7->data = 90;
	
	Tree *tree = new Tree();
	tree->AddNode(0, 0, node1);
	tree->AddNode(0, 1, node2);
	tree->AddNode(1, 0, node3);
	tree->AddNode(1, 1, node4);
	tree->AddNode(2, 0, node5);
	tree->AddNode(2, 1, node6);
	tree->AddNode(3, 0, node7);
	
	tree->PreorderTravers();
	
	tree->DeleteNode(7, nullptr);
	
	cout << "after delete" << endl;
	
	tree->PreorderTravers();
//	tree->AddNode(1, 1, node4);
	return 0;
}
