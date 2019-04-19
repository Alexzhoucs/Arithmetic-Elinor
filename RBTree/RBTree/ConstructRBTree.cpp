#include "HEAD.h"

int inputTree(KEYTYPE c[]);


time_t ConstructRBTree(tree* T)
{
	KEYTYPE c[MAXSIZE];
	char d[MAXSIZE];
	int n;
<<<<<<< Updated upstream

	n = inputTree(c);

	cout << "Please input datas." << endl;
	for (int i = 0; i < n; i++)
=======
	time_t begint, endt,duration;
	
	srand((unsigned)time (NULL));
	for (int i = 0; i < MAXSIZE; i++)
>>>>>>> Stashed changes
	{
		cin >> d[i];
	}

	for (int i = 0; i < n; i++)
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
<<<<<<< Updated upstream
=======
	endt = clock();
	duration = endt - begint;
	return(duration);
>>>>>>> Stashed changes
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