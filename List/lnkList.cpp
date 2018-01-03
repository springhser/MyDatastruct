#include "lnkList.h"
#include <iostream.h>
using namespace std;

template <typename T>
LnkList<T>::LnkList(int defSize){
	head = tail = new LinkNode<T>;
}

template <typename T>
LnkList<T>::~LnkList(){
	LinkNode<T> *tmp;
	while(head != nullptr){
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <typename T>
LinkNode<T> *LnkList<T>::setPos(int i){
	int count = 0;
	if(i == -1){
		return head;
	}
	LinkNode<T> *p = new LinkNode<T>(head->next);
	while(p != nullptr && count < i){
		p = p->next;
		count++;
	};
	
	return p;
}

template <typename T>
bool LinList<T>::insert(const int i,const T value){
	LinkNode<T> *p,*q;
	
	if((p = setPos(i-1)) == nullptr){
		cout << "illegal" << endl;
		return false;
	}
	q = new LinkNode<T>(value,p->next);
	p->next = q;
	if(p == tail){
		tail = q;
	}
	return true;
}

template <typename T>
bool LinList<T>::delete(const int i,const T value){
	LinkNode<T> *p,*q;
	
	if((p = setPos(i-1)) == nullptr || p == tail){
		cout << "illegal" << endl;
		return false;
	}
	q = p->next;
	if(q == tail){
		tail = p;
		p->next = nullptr;
		delete = p;
	}else if(q != nullptr){
		p->next = q->next;
		delete q;
	}
	return true;
}














