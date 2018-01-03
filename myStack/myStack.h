/*
	简易版栈 
	2016.5.14
*/
#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
//#include "Coordinate.h"
using namespace std;

template <typename T>

class MyStack
{
	public:
		MyStack(int size);
		~MyStack();
		int getLength();	//获得栈的长度 
		bool isEmpty();		//判断栈是否为空 
		bool isFull();		//判断栈是否为满 
		void push(T elem); //入栈操作
		T pop(T &temp);			//出栈操作
		void stackTraverse(bool fromBottom);//遍历栈
		void clearStack(); 	//清空栈 
	
	private:
		T *m_pBuffer;	//栈空间指针 
		int m_iTop;		//栈顶 ，栈中元素的个数 
		int m_iSize; 	//栈的容量 
		
}; 

template <typename T>
MyStack<T>::MyStack(int size)
{
	m_iSize = size; 
	m_pBuffer = new T[size];
	m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack()
{
	delete [] m_pBuffer;
}

template <typename T>
bool MyStack<T>::isEmpty()
{
	if(0 == m_iTop)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
bool MyStack<T>::isFull()
{
	if(m_iSize == m_iTop)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void MyStack<T>::clearStack()
{
	m_iTop = 0;		//如果有新的元素进来，则将旧的元素覆盖就行	
} 

template <typename T>
int MyStack<T>::getLength()
{
	return m_iTop; //可以用栈顶的值进行代替 
} 

template <typename T>
void MyStack<T>::push(T elem)//入栈操作
{
	if(isFull())
	{
		cout << "we can't enter the element!" << endl;
	}
	else
	{
		m_pBuffer[m_iTop] = elem;
		m_iTop++;
	}
	
}

template <typename T>
T MyStack<T>::pop(T &temp)			//出栈操作
{
	if(isEmpty())
	{
		cout << "There is nothing in the stack!" << endl; 
		return 0;
	}
	else
	{
		temp = m_pBuffer[m_iTop-1];
		m_iTop--;
		return temp;
	}
}

template <typename T>
void MyStack<T>::stackTraverse(bool fromBottom)
{
	if(isEmpty())
	{
		cout << "There is nothing !" << endl; 
	}
	int i;
	if(fromBottom)
	{
		for(i=0; i<m_iTop; i++)
		{
			cout << m_pBuffer[i] ;
		}
	}
	else
	{
		for(i=m_iTop-1; i>=0; i--)
		{
			cout << m_pBuffer[i] ;
		}
	}
	
}
#endif
