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
	~Tree(){Release(root);}
	TNode * Getroot( );
	void PreOrder(TNode *root);
	void PostOrder(TNode *root); 
private:
	TNode* root;
	void Release(TNode * bt);
};

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
			if (p->data != ch1)
				front++;
			else {
				if (q->firstchild == NULL)
					q->firstchild = p;
				else {
					while (q->rightsib != NULL)
						q = q->rightsib;
					q->rightsib = p;
				}
				break;
			}
		}
		cout << "请输入结点对，以空格分离：";
		fflush(stdin);
		ch1 = getchar(); getchar(); ch2 = getchar();
	}
}

void Tree::Release(TNode* bt)
{
	if (bt == NULL)return;
	else {
		Release(bt->firstchild);
		Release(bt->rightsib);
		delete bt;
	}
}

TNode* Tree::Getroot( )
{
	return root;
}

void Tree::PreOrder(TNode* bt)
{
	if (bt == NULL)return;
	else {
		cout << bt->data;
		PreOrder(bt->firstchild);
		PreOrder(bt->rightsib);
	}
}

void Tree::PostOrder(TNode* bt)
{
	if (bt == NULL)return;
	else {
		PostOrder(bt->firstchild);
		PostOrder(bt->rightsib);
		cout << bt->data;
	}
}

#endif
