#include "HEAD.h"

node* findSuccessor(node* x, node* nil);

void successor(tree T)
{
	KEYTYPE key;
	cout << "Please input the key of x for its successor" << endl;
	cin >> key;
	node* x = findNode(T, key);
	if (x == T.nil)
	{
		cout << "Cannot find this key." << endl;
		return;
	}
	printout(x);
	x = findSuccessor(x, T.nil);		
	cout << "µÄºó¼ÌÊÇ\t";
	printout(x);
}

node* findSuccessor(node* x, node* nil)
{
	node* y;
	
	if (x->right != nil)
	{
		tree t;
		t.nil = nil;
		t.root = x->right;
		y = findMin(t);
	}
	else
	{
		y = x->p;
		while (y != nil && x == y->right)
		{
			x = y;
			y = y->p;
		}
	}
	return y;
}