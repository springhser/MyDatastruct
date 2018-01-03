#ifndef NODE_H
#define NODE_H
class Node{
	public:
		Node();
		~Node();
		Node *SearchNode(int nodeindex); 
		void DeleteNode();
		void PreorderTravers();
		void InorderTravers(); //中序遍历
	    void PostorderTravers();//后序遍历
		int index;
		int data;
		Node *pRChild;
		Node *pLChild;
		Node *pParent;
};
#endif
