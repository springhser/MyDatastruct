#ifndef __LIST__H__
#define __LIST__H__
template <class T>
class List{
	void clear();								//clear the List
	bool isEmpty();								//return true if List is Empty
	bool append(const T value);					//add a element at the end of the List
	bool insert(const int p,const T value);		//
	bool delete(const int p);
	bool getPos(int &p,const T value);
	bool getValue(const int p,T& value);
	bool setValue(const int p,const T value);
};


#endif
