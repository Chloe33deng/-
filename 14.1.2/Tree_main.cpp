#include<iostream>
using namespace std;

#include"Tree.h"

int main()
{
	Tree t1;
	TNode* p = t1.Getroot( );
	t1.PreOrder(p);
	cout << endl;
	t1.PostOrder(p);
	cout << endl;
	return 0;
}
