#include "HEAD.h"

node* findNode(tree T, KEYTYPE key)
{
	if (T.nil == T.root)
		return(T.nil);

	node* x = T.root;
	while (x != T.nil)
	{
		if (key == x->key)
			break;
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

void printout(node* x)
{
	cout << x->key << "|" << x->data << "|" << x->color << "|" << x->size << endl;
}

void treeWalk(node* x, node* nil)
{
	if (x != nil)
	{
		treeWalk(x->left, nil);
		cout << x->key << "\t";
		treeWalk(x->right, nil);
	}
}

void demo(node* x, node* nil, int i)
{
	if (x == nil)
	{
		for (int j = 0; j < i; j++)
			cout << "\t\t";
		cout << "nil | " << x->color << " | " << x->size << endl;
		return;
	}
	else
	{
		demo(x->right, nil, i + 1);
		printout(x);
		demo(x->left, nil, i + 1);
	}
}