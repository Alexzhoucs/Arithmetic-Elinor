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