#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <fstream>

#define KEYTYPE		int
#define MAXSIZE		10000

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


void ConstructRBTree(tree* T);
node* findNode(tree T, KEYTYPE key);
void printout(node* x);
void findRank(tree T);
void insertNode(tree* T, node* z);
void insert(tree* T);
void treeWalk(node* x, node* nil);
void demo(node* x, node* nil, int i);
void minKey(tree T);
node* findMin(tree T);
void maxKey(tree T);
node* findMax(tree T);
void successor(tree T);
void Select(tree T);
void Predecessor(tree T);




