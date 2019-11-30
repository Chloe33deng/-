// Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include "Tree.h"

Tree::Tree()
{
	TNode* Q[Max] = { NULL };
	int front = -1, rear = -1;
	char ch1 = '#', ch2 = '#';
	TNode* p = NULL, * q = NULL;
	cout << "请输入根结点：";
	cin >> ch1;
	p = new TNode; p->data = ch1;
	p->firstchild = p->rightsib = NULL;
	root = p;
	Q[++rear] = p;
	cout << "请输入结点对，以空格分隔：";
	fflush(stdin);
	ch1 = getchar(); getchar(); ch2 = getchar();
	while (ch1 != '#' || ch2 != '#')
	{
		p = new TNode; p->data = ch2;
		p->firstchild = p->rightsib = NULL;
		Q[++rear] = p;
		while (front != rear)
		{
			q = Q[front + 1];
			if (q->data != ch1)
				front++;
			else
			{
				if (q->firstchild == NULL)
					q->firstchild = p;
				else
				{
					while (q->rightsib != NULL)
						q = q->rightsib;
					q->rightsib = p;
				}
				break;
			}
		}
		cout << "请输入结点对，以空格分隔：";
		fflush(stdin);
		ch1 = getchar(); getchar(); ch2 = getchar();
	}
}

void Tree::Release(TNode* bt)
{
	if (bt == NULL)return;
	else
	{
		Release(bt->firstchild);
		Release(bt->rightsib);
		delete bt;
	}
}

void Tree::PreOrder(TNode* bt)
{
	if (bt == NULL)return;
	else
	{
		cout << bt->data;
		PreOrder(bt->firstchild);
		PreOrder(bt->rightsib);
	}
}

void Tree::PostOrder(TNode* bt)
{
	if (bt == NULL)return;
	else
	{
		PostOrder(bt->firstchild);
		PostOrder(bt->rightsib);
		cout << bt->data;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
