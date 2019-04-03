#include "HEAD.h";



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
}

void rank(tree T)
{
	KEYTYPE key;
	cout << "Please input the rank of the node that you want." << endl;
	cin >> key;
	node* x = findNode(T, key);
	int k = OSRank(T, x);
	printout(x);
}

