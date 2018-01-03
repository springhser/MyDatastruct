#include "MyQueue.h"

MyQueue::MyQueue(int size)
{
	q_size = size;
	m_pQueue = new int[size];
	q_length = 0;
	iHead = 0;
	iTail = 0;
}

MyQueue::~MyQueue()
{
	delete [] m_pQueue;
}

void MyQueue::ClearQueue()
{
	q_length = 0;
	iHead = 0;
	iTail = 0;
}

int MyQueue::QueueLength()
{
	return q_length;	
}

bool MyQueue::QueueEmpty()
{
	if(0 == q_length)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MyQueue::QueueFull()
{
	if(q_length == q_size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MyQueue::EnQueue(int elem)
{
	if(QueueFull())
	{
		return false;	
	}
	else
	{
		m_pQueue[iTail] = elem;
		iTail++;
		iTail = iTail % p_size;
		q_length++;
		return true;
	}
}
	
bool MyQueue::DeQueue(int &elem)
{
	if(QueueEmpty())
	{
		return false;
	}
	else
	{
		elem = m_pQueue[iHead];
		iHead++;
		iHead = iHead % q_size;
		q_length--;
		return true;
	}
}
void MyQueue::QueueTraverse()
{
	for(int i = iHead; i < q_length + iHead; i++)
	{
		cout << m_pQueue[i % q_size] << ",";
	}
}


