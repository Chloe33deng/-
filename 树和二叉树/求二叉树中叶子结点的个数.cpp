#include<iostream>
#define N 63
 
using namespace std;
 
char str[] = "ab#d##c#e##";
int i = -1;
 
typedef struct node
{
	struct node *leftChild;
	struct node *rightChild;
	char data;
}BiTreeNode, *BiTree;
 
BiTreeNode *createNode(int i)
{
	BiTreeNode * q = new BiTreeNode;
	q->leftChild = NULL;
	q->rightChild = NULL;
	q->data = i;
 
	return q;
}
 
BiTree createBiTree1()
{
	BiTreeNode *p[N] = {NULL};
	int i;
	for(i = 0; i < N; i++)
		p[i] = createNode(i + 1);
 
	// 把结点连接成树
	for(i = 0; i < N/2; i++)
	{
		p[i]->leftChild = p[i * 2 + 1];
		p[i]->rightChild = p[i * 2 + 2];
	}
 
	return p[0];
}
 
void createBiTree2(BiTree &T)
{
	i++;
	char c;
	if(str[i] && '#' == (c = str[i]))
		T = NULL;
	else
	{
		T = new BiTreeNode;
		T->data = c;
		createBiTree2(T->leftChild);
		createBiTree2(T->rightChild);
	}
}
 
int getLeafNode(BiTree T)
{
	if(NULL == T)
		return 0;
 
	if(NULL == T->leftChild && NULL == T->rightChild)
		return 1;
 
	return getLeafNode(T->leftChild) + getLeafNode(T->rightChild);
}
 
int main()
{
	BiTree T1;
	T1 = createBiTree1();
	cout << getLeafNode(T1) << endl;
 
	BiTree T2;
	createBiTree2(T2);
	cout << getLeafNode(T2) << endl;
 
	return 0;
}

