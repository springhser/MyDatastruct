#ifndef __LNKLIST__H__
#define __LNKLIST__H__
template <typename T>
class LnkList : public List<T>{
private:
	LinkNode<T> *head ,*tail;
	LinkNode<T> *setPos(const int p); 
public:
	LnkList(int s);
	~LnkList();
	int length();
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
