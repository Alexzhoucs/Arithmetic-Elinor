#include "HEAD.h"

node* OSSelect(node* x, int i)
{
	int r = x->left->size + 1;
	if (i == r)
		return(x);
	else
		if (i < r)
			return OSSelect(x->left, i);
		else
			return(OSSelect(x->right, i - r));
}

void Select(tree T)
{
	int k;
	cout << "please input the rank of the node you want to find" << endl;
	cin >> k;
	node* x = OSSelect(T.root, k);
	cout << "秩为" << k << "的结点是";
	printout(x);
}
