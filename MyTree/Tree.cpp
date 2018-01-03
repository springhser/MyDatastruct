#include <iostream>
#include "Tree.h"
#include "Node.h"
using namespace std;

Tree::Tree(){
	pRoot = new Node();
}  //创建树
Tree::~Tree(){
	pRoot->DeleteNode();
}                       //销毁树
Node * Tree::SearchNode(int nodeindex){
	return pRoot->SearchNode(nodeindex);
}//搜索结点
bool Tree::AddNode(int nodeindex,int direction,Node *pNode){
	//判断索引nodeindex下有没有节点
	Node *temp = this->SearchNode(nodeindex);
	if(temp == nullptr){
		return false;
	} 
	//构造一个临时节点保存传入的*pNode，避免*pNode被改变
	Node *node = new Node();
	if(node == nullptr){
		return false;
	}
	
	node->data = pNode->data;
	node->index = pNode->index;
	node->pParent = temp;
	//若为插入左节点 
	if(direction == 0){
		temp->pLChild = node;
		return true;
	}
	//若为插入右节点
	if(direction == 1){
		temp->pRChild = node;
		return true;
	}
}//添加结点
bool Tree::DeleteNode(int nodeindex, Node* pNode){
	//pNode 可以不要，用来保存删除的节点的值 
	//判断索引nodeindex下有没有节点
	Node *temp = this->SearchNode(nodeindex);
	if(temp == nullptr){
		return false;
	} 
	
	if(pNode != nullptr){
		pNode->data = temp->data;
	}
	
	temp->DeleteNode();
	return true; 
}//删除结点
void Tree::PreorderTravers(){
	pRoot->PreorderTravers();
}//前序遍历
void Tree::InorderTravers(){
	pRoot->InorderTravers();
} //中序遍历
void Tree::PostorderTravers(){
	pRoot->PostorderTravers();
}//后序遍历
	
