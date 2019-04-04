#include "HEAD.h"

node* findPredecessor(node* x, node* nil);

void Predecessor(tree T)
{
	KEYTYPE key;
	cout << "Please input the key of x for its predecessor" << endl;
	cin >> key;
	node* x = findNode(T, key);
	if (x == T.nil)
	{
		cout << "Cannot find this key in the nodes." << endl;
		return;
	}
	printout(x);
	x = findPredecessor(x, T.nil);
	cout << "µÄÇ°ÇýÊÇ\t";
	printout(x);
}

node* findPredecessor(node* x, node* nil)
{
	node* y;

	if (x->left != nil)
	{
		tree t;
		t.nil = nil;
		t.root = x->left;
		y = findMax(t);
	}
	else
	{
		y = x->p;
		while (y != nil && x == y->left)
		{
			x = y;
			y = y->p;
		}
	}
	return y;
}