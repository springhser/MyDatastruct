#ifndef __ARRLIST__H__
#define __ARRLIST__H__
#include "List.h"

template <class T>
class arrList:public List<T>{
private:
	T *aList;
	int maxSize;
	int curLen;
	int position;
public:
	arrList(const int size){
		maxSize = size;
		aList = new T[maxSize];
		curlen = postion = 0;
	}
	
	~arrList(){
		delete [] aList;
	}
	
	void clear(){
		delete [] aList;
		curLen = postion = 0;
		aList = new [maxSize];
	}								//clear the List
//	bool isEmpty();								//return true if List is Empty
	bool append(const T value);					//add a element at the end of the List
	bool insert(const int p,const T value);		//
	bool delete(const int p);
	bool getPos(int &p,const T value);
	bool getValue(const int p,T& value);
	bool setValue(const int p,const T value);
}
#endif
