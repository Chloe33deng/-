#pragma once
#ifndef Tree_H
#define Tree_H

const int Max = 20;

struct TNode
{
	char data;
	TNode* firstchild, * rightsib;
};

class Tree
{
public:
	Tree();
	~Tree() { Release(root); }
	void PreOrder() { PreOrder(root); }
	void PostOrder() { PostOrder(root); }
private:
	TNode* root;
	TNode* Creat(TNode* bt);
	void Release(TNode* bt);
	void PreOrder(TNode* bt);
	void PostOrder(TNode* bt);
};
#endif // !Tree_H
