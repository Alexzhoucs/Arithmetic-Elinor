#include "HEAD.h"


void minKey(tree T)
{
	node* x = findMin(T);
	cout << "the node of the minimum key is \t";
	printout(x);
}

node* findMin(tree T)
{
	node* x = T.root;
	if (x == T.nil)
	{
		cout << "The tree is empty" << endl;
		return(T.nil);
	}
	while (x->left != T.nil)
		x = x->left;
	return(x);
}

void maxKey(tree T)
{
	node* x = findMax(T);
	cout << "the node of the maximum key is \t";
	printout(x);
}

node* findMax(tree T)
{
	node* x = T.root;
	if (x == T.nil)
	{
		cout << "The tree is empty" << endl;
		return(T.nil);
	}
	while (x->right != T.nil)
		x = x->right;
	return(x);
}