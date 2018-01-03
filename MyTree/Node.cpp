#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(){
	index = 0;
	data = 0;
	pRChild = nullptr;
	pLChild = nullptr;
	pParent = nullptr;
}

Node::~Node(){
}

Node *Node::SearchNode(int nodeindex){
	if(this->index == nodeindex){
		return this;
	}
	Node *temp = new Node();
	if(this->pLChild != nullptr){
		if(this->pLChild->index == nodeindex){
			return this->pLChild;
		}else{
			temp = this->pLChild->SearchNode(nodeindex);
			if(temp != nullptr){
				return temp;
			}
		}
	}
	if(this->pLChild != nullptr){
		if(this->pRChild->index == nodeindex){
			return this->pRChild;
		}else{
			temp = this->pRChild->SearchNode(nodeindex);
			if(temp != nullptr){
				return temp;
			}
		}	
	}
	
	return nullptr;
}
void Node::DeleteNode(){
	if(this->pLChild != nullptr){
		this->pLChild->DeleteNode();
	}
	if(this->pRChild != nullptr){
		this->pRChild->DeleteNode();
	}
	if(this->pParent != nullptr){
		if(this == this->pParent->pLChild){
			this->pParent->pLChild = nullptr;
			//��Ϊɾ������ָ�룬��ôָ����ָ���λ�õ�ֵ��û�иı�
			//����Ҫ����Ӧ���ڵ���ӽڵ�ָ�����Ϊ�� 
		}
		if(this == this->pParent->pRChild){
			this->pParent->pRChild = nullptr;
		}
	}
	delete this;
}

void Node::PreorderTravers(){
	cout << this->index << " ," << this->data << endl;
	if(this->pLChild != nullptr){
		this->pLChild->PreorderTravers();
	}
	if(this->pRChild != nullptr){
		this->pRChild->PreorderTravers();
	}
}

void Node::InorderTravers(){
	if(this->pLChild != nullptr){
		this->pLChild->InorderTravers();
	}
	
	cout << this->index << " ," << this->data << endl;
	
	if(this->pRChild != nullptr){
		this->pRChild->InorderTravers();
	}
} //�������
void Node::PostorderTravers(){
	if(this->pLChild != nullptr){
		this->pLChild->PostorderTravers();
	}
	if(this->pRChild != nullptr){
		this->pRChild->PostorderTravers();
	}
	cout << this->index << " ," << this->data << endl;
}//�������

