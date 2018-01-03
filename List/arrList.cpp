#include <iostream.h>
#include "arrList.h"
using namespace std;

template <class T>
bool arrList<T> :: getPos(int &p,const T value){
	int i;
	for(i=0;i<n;i++){
		if(value == aList[i]){
			p = i;
			return true;
		}
	}
	return false;
}

template <typename T>
bool arrList<T>::insert(const int p,const T value){
	int i;
	if(curLen >= maxSize){
		cout << "The list is overflow" << endl;
		return false;
	}
	if(p < 0 || p > curLen){
		cout << "Insertion point is illegal" << endl;
		return false;
	}
	if(i = curLen;i > p;i--){
		aList[i] = aList[i-1];
	}
	aList[p] = value;
	curLen++;
	return true;
}

template <typename T>
bool arrList<T>::delete(const int p){
	int i ;
	if(curLen <= 0){
		cout << "No element to delete" << endl;
		return false;
	}
	if(p < 0 || p > curLen-1){
		cout << "deletion is illegal" << endl;
		return false;
	}
	if(i = p;i > curLen-1;i++){
		aList[i] = aList[i+1];
	}
	
	curLen--;
	return true;
}

template <typename T>
bool arrList<T>::append(const T value){
	if(curLen >= maxSize){
		cout << "The list is overflow" << endl;
		return false;
	}
	aList[curlen] = value;
	return true;
}

template <typename T>
bool arrList<T> :: setValue(const int p,const T value){
	if(p < 0 || p > curLen-1){
		cout << "point is illegal" << endl;
		return false;
	}
	aList[p] = value;
	return true;
}

template <typename T>
bool arrList<T> :: getValue(const int p,T& value){
	if(p < 0 || p > curLen-1){
		cout << "point is illegal" << endl;
		return false;
	}
	value = aList[p];
	return true;
}









