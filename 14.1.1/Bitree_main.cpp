#include<iostream>
using namespace std;
#include "Bitree.h"

int main()
{
	Bitree T;
	cout << "-----ǰ�����-----" << endl;
	T.PreOrder();
	cout << endl;
	cout << "-----�������-----" << endl;
	T.InOrder();
	cout << endl;
	cout << "-----�������-----" << endl;
	T.PostOrder();
	cout << endl;
	return 0;
}