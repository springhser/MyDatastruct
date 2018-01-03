#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
	BinaryTreeNode()
	{
		leftChild = nullptr;
		rightChild = nullptr;
	}
	BinaryTreeNode(const T& theElement):element(theElement)
	{
		leftChild = nullptr;
		rightChild = nullptr;
	}
	BinaryTreeNode(const T& theElement,
					BinaryTreeNode *theLeftChild,
					BinaryTreeNode *theRightChild):element(theElement)
	{
		leftChild = theLeftChild;
		rightChild = theRightChild; 
	}
private:
	T element;			//���ڵ��ֵ
	BinaryTreeNode<T>  *leftChild,*rightChild;
};
#endif
