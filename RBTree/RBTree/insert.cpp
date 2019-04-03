#include "HEAD.h"

void insertFixUp(tree T, node* z);

void insert(tree T)
{
	node z;
	cout << "Please input the data you want to insert." << endl;
	cin >> z.data;

	cout << "Please input its key." << endl;
	cin >> z.key;

	z.size = 1;
	z.color = 'r';
	z.left = T.nil;
	z.right = T.nil;

	insertNode(T, &z);
	cout << "Insert complete" << endl;
}

void insertNode(tree T, node* z)
{
	node* y;

	if (T.root == T.nil)
	{
		T.root = z;
		z->p = T.nil;
		z->color = 'b';
	}

	node* x = T.root;
	while (x != T.nil)
	{
		x->size++;
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->p = y;

	if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

	insertFixUp(T, z);
}

void insertFixUp(tree T, node* z)
{
	while (z->p->color == 'r')
	{
		node* y;
		if (z->p == z->p->p->left)
		{
			y = z->p->p->right;

		}
	}
}