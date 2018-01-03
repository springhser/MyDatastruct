/*
	���װ�ջ 
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
		int getLength();	//���ջ�ĳ��� 
		bool isEmpty();		//�ж�ջ�Ƿ�Ϊ�� 
		bool isFull();		//�ж�ջ�Ƿ�Ϊ�� 
		void push(T elem); //��ջ����
		T pop(T &temp);			//��ջ����
		void stackTraverse(bool fromBottom);//����ջ
		void clearStack(); 	//���ջ 
	
	private:
		T *m_pBuffer;	//ջ�ռ�ָ�� 
		int m_iTop;		//ջ�� ��ջ��Ԫ�صĸ��� 
		int m_iSize; 	//ջ������ 
		
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
	m_iTop = 0;		//������µ�Ԫ�ؽ������򽫾ɵ�Ԫ�ظ��Ǿ���	
} 

template <typename T>
int MyStack<T>::getLength()
{
	return m_iTop; //������ջ����ֵ���д��� 
} 

template <typename T>
void MyStack<T>::push(T elem)//��ջ����
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
T MyStack<T>::pop(T &temp)			//��ջ����
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