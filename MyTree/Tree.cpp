#include <iostream>
#include "Tree.h"
#include "Node.h"
using namespace std;

Tree::Tree(){
	pRoot = new Node();
}  //������
Tree::~Tree(){
	pRoot->DeleteNode();
}                       //������
Node * Tree::SearchNode(int nodeindex){
	return pRoot->SearchNode(nodeindex);
}//�������
bool Tree::AddNode(int nodeindex,int direction,Node *pNode){
	//�ж�����nodeindex����û�нڵ�
	Node *temp = this->SearchNode(nodeindex);
	if(temp == nullptr){
		return false;
	} 
	//����һ����ʱ�ڵ㱣�洫���*pNode������*pNode���ı�
	Node *node = new Node();
	if(node == nullptr){
		return false;
	}
	
	node->data = pNode->data;
	node->index = pNode->index;
	node->pParent = temp;
	//��Ϊ������ڵ� 
	if(direction == 0){
		temp->pLChild = node;
		return true;
	}
	//��Ϊ�����ҽڵ�
	if(direction == 1){
		temp->pRChild = node;
		return true;
	}
}//��ӽ��
bool Tree::DeleteNode(int nodeindex, Node* pNode){
	//pNode ���Բ�Ҫ����������ɾ���Ľڵ��ֵ 
	//�ж�����nodeindex����û�нڵ�
	Node *temp = this->SearchNode(nodeindex);
	if(temp == nullptr){
		return false;
	} 
	
	if(pNode != nullptr){
		pNode->data = temp->data;
	}
	
	temp->DeleteNode();
	return true; 
}//ɾ�����
void Tree::PreorderTravers(){
	pRoot->PreorderTravers();
}//ǰ�����
void Tree::InorderTravers(){
	pRoot->InorderTravers();
} //�������
void Tree::PostorderTravers(){
	pRoot->PostorderTravers();
}//�������
	
