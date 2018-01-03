#ifndef __LINKNODE__H__
#define __LINKNODE__H__
template <class T> 
class LinkNode{
public:
	T data;
	LinkNode<T> *next;
	
	LinkNode(const T info,const LinkNode<T> *nextValue=nullptr){
		data = info;
		next = nextValue;
	}
	LinkNode(const LinkNode<T> *nextValue){
	 	next = nextValue;
	}
};
#endif
