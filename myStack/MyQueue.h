#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue
{
public:
	MyQueue(int size);
	virtual ~MyQueue();
	void ClearQueue();
	bool QueueEmpty();
	bool QueueFull();
	int QueueLength();
	bool EnQueue(int elem);
	bool DeQueue(int &elem);
	void QueueTraverse();
private:
	int *m_pQueue;
	int q_length;
	int q_size;
	int iHead;
	int iTail;
	 
}
#endif
