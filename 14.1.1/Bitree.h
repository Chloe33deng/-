#pragma once
#ifndef Bitree_H
#define Bitree_H

struct BiNode
{
	char data;
	BiNode* lchild, * rchild;
};

class Bitree
{
public:
	Bitree() { root = Creat(root); }
	~Bitree() { Release(root); }
	void PreOrder(){ PreOrder(root); }
	void  InOrder() { InOrder(root); }
	void PostOrder() { PostOrder(root); }
private:
	BiNode* root;
	BiNode* Creat(BiNode* bt);
	void Release(BiNode* bt);
	void PreOrder(BiNode* bt);
	void InOrder(BiNode* bt);
	void PostOrder(BiNode* bt);
};

BiNode* Bitree::Creat(BiNode* bt)
{
	char ch;
	cout << "请输入创建一棵二叉树的结点数据" << endl;
	cin >> ch;
	if (ch == '#')return NULL;
	else {
		bt = new BiNode;
		bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}

void Bitree::Release(BiNode* bt)
{
	if (bt != NULL) {
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}

void Bitree::PreOrder(BiNode* bt)
{
	if (bt == NULL)return;
	else {
		cout << bt->data << " ";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void Bitree::InOrder(BiNode* bt)
{
	if (bt == NULL)return;
	else
	{
		InOrder(bt->lchild);
		cout << bt->data << " ";
		InOrder(bt->rchild);
	}
}

void Bitree::PostOrder(BiNode* bt)
{
	if (bt == NULL)return;
	else {
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout << bt->data << " ";
	}
}

#endif
