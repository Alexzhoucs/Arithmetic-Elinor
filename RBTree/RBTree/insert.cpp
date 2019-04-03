#include "HEAD.h"

void insertFixUp(tree T, node* z);
void LeftRotate(tree T, node* z);

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
			if (y->color == 'r')
			{
				z->p->color = 'b';
				y->color = 'b';
				z->p->p->color = 'r';
				z = z->p->p;
			}
			else
			{
				if (z == z->p->right)
				{
					z = z->p;
					LeftRotate(T, z);
				}
				z->p->color = 'b';
				z->p->p->color = 'r';
				RightRotate(T, z->p->p);
			}
		}
		else
		{
			y = z->p->p->left;
			if (y->color == 'r')
			{
				z->p->color = 'b';
				y->color = 'b';
				z->p->p->color = 'r';
				z = z->p->p;
			}
			else
			{
				if (z == z->p->left)
				{
					z = z->p;
					RightRotate(T, z);
				}
				z->p->color = 'b';
				z->p->p->color = 'r';
				LeftRotate(T, z->p->p);
			}

		}
	}
	T.root->color = 'b';
}

void LeftRotate(tree T, node* x)
{
	node* y;
	y = x->right;
	x->right = y->left;
	if (y->left != T.nil)
		y->left->p = x;
	y->p = x->p;
	if (x->p == T.nil)
		T.root = y;
	else if (x == x->p->left)
		x->p->left = y;
	else
		x->p->right = y;
	y->left = x;
	x->p = y;
	y->size = x->size;
	x->size = x->left->size + x->right->size + 1;
}

void RightRotate(tree T, node* y)
{
	node* x = y->left;
	y->left = x->right;
	if (x->right != T.nil)
		x->right->p = y;
	x->p = y->p;
	if (y->p == T.nil)
		T.root = x;
	else if (y == y->p->left)
		y->p->left = x;
	else
		y->p->right = x;

	x->right = y;
	y->p = x;
	x->size = y->size;
	y->size = y->left->size + y->right->size + 1;
}