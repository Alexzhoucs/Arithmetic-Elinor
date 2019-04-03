#include <iostream>
#include <string>
#include <sstream>

#define KEYTYPE		int
#define MAXSIZE		30

using namespace std;

struct node
{
	char color;
	KEYTYPE key;
	node *left;
	node *right;
	node *p;
	char data;
	int size;
};

struct tree
{
	node *root;
	node *nil;
};


void ConstructRBTree(tree T);

