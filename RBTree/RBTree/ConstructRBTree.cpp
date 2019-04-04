#include "HEAD.h"

int inputTree(KEYTYPE c[]);


void ConstructRBTree(tree* T)
{
	KEYTYPE c[MAXSIZE];
	char d[MAXSIZE];
	int n;
	time_t begint, endt,duration;
	
	srand(time);
	for (int i = 0; i < MAXSIZE; i++)
	{
		c[i] = rand();
		d[i] = 'd';
	}
	begint = clock();

	for (int i = 0; i < MAXSIZE; i++)
	{
		//node z;
		node* z = (node*)malloc(sizeof(node));
		z->key = c[i];
		z->data = d[i];
		z->color = 'r';
		z->left = T->nil;
		z->right = T->nil;
		z->size = 1;
		insertNode(T, z);
	}
	endt = clock();
	duration = endt - begint;
	cout << duration;
	getchar();
}

int inputTree(KEYTYPE c[])
{
	string s;
	stringstream ss;
	int i = 0;
	int n = 0;

	cout << "Please input the keys." << endl;
	getline(cin, s);
	ss.clear();
	ss.str(s);
	
	while (1)
	{
		KEYTYPE a;
		ss >> a;
		if (ss.fail())
		{
			break;
		}
		c[i] = a;
		n++;
		i++;
	}
	return n;
}