#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree{
	public:
		Tree();  //创建树
		~Tree();                            //销毁树
		Node * SearchNode(int nodeindex);//搜索结点
		bool AddNode(int nodeindex,int direction,Node *pNode);//添加结点
		bool DeleteNode(int nodeindex,Node * pNode);//删除结点
		void PreorderTravers();//前序遍历
		void InorderTravers(); //中序遍历
	    void PostorderTravers();//后序遍历
	private:
		Node *pRoot;
};
#endif


