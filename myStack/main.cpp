#include <iostream>
#include "myStack.h"
#include "Coordinate.h"
#include "MyQueue.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define BINARY 2
#define OCTONARY 8
#define HEXADECIMAL 16


int main(int argc, char** argv) {
	
	//进制转换例子 
//	char num[] = "0123456789ABCDEF";
//	
//	MyStack<int> *mystack1 = new MyStack<int>(40);
//	
//	int N ,mod;
//	cout << "Please enter the number: " ;
//	cin >> N;
//	
//	while(N != 0)
//	{
//		mod = N % HEXADECIMAL;
//		mystack1->push(mod);
//		N = N / HEXADECIMAL;
//	}
	
//	mystack1->stackTraverse(false);
//	int elem = 0;
//	
//	while(!mystack1->isEmpty())
//	{
//		mystack1->pop(elem);
//		cout << num[elem]; 
//	}
//	
//	delete mystack1;
//	mystack1 = NULL;
//	
//	MyQueue
	return 0;

/**
用类模板测试 
*/	
//	MyStack<Coordinate> *mystack1 = new MyStack<Coordinate>(5);
//	if(mystack1->isEmpty())
//	{
//		cout <<"hehe"<< endl; 
//	}
//	mystack1->push(Coordinate(1,2));
//	mystack1->push(Coordinate(3,4));
////	mystack1->push(3);
////	mystack1->push(4);
////	mystack1->push(5);
//	
//	if(mystack1->isFull())
//	{
//		cout << "Is full" << endl;
//	}
//	
////	mystack1->clearStack();
//	Coordinate temp;
//	temp = mystack1->pop(temp);
//	cout << temp << endl;
////	cout << mystack1->pop(temp) << endl;//此时如果直接用函数形式执行cout，则<< 不再是重载后的<<  
//	
//	int stacklength = mystack1->getLength();
//	cout << stacklength << endl;
//	
//	mystack1->stackTraverse();
//	
//	cout << endl;
//	MyStack<int> *mystack2 = new MyStack<int>(5);
//	mystack2->push(1);
//	mystack2->push(2);
//	mystack2->stackTraverse();
//	
//	MyStack<char> *mystack3 = new MyStack<char>(5);
//	mystack3->push('c');
//	mystack3->push('j');
//	mystack3->push('b');
//	mystack3->stackTraverse();
//		
//	delete mystack1,mystack2,mystack3;
//	mystack1 = NULL;
//	mystack1 = NULL;
//	mystack1 = NULL;

}
