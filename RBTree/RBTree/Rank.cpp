#include "HEAD.h"



int OSRank(tree T, node* x)
{
	int r;
	node *y;

	r = x->left->size + 1;
	y = x;
	while (y != T.root)
	{
		if (y == y->p->right)
			r += y->p->left->size + 1;
		y = y->p;
	}
	return(r);
}

void findRank(tree T)
{
	KEYTYPE key;
	cout << "Please input the key." << endl;
	cin >> key;
	node* x = findNode(T, key);
	if (x == T.nil)
	{
		cout << "cannot find the node" << endl;
		return;
	}
	int k = OSRank(T, x);
	cout << k << endl;
}

