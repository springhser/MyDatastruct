#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree{
	public:
		Tree();  //������
		~Tree();                            //������
		Node * SearchNode(int nodeindex);//�������
		bool AddNode(int nodeindex,int direction,Node *pNode);//��ӽ��
		bool DeleteNode(int nodeindex,Node * pNode);//ɾ�����
		void PreorderTravers();//ǰ�����
		void InorderTravers(); //�������
	    void PostorderTravers();//�������
	private:
		Node *pRoot;
};
#endif


