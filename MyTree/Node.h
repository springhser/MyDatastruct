#ifndef NODE_H
#define NODE_H
class Node{
	public:
		Node();
		~Node();
		Node *SearchNode(int nodeindex); 
		void DeleteNode();
		void PreorderTravers();
		void InorderTravers(); //�������
	    void PostorderTravers();//�������
		int index;
		int data;
		Node *pRChild;
		Node *pLChild;
		Node *pParent;
};
#endif
