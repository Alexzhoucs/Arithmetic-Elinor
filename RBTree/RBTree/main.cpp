#include "HEAD.h"

void main()
{
	tree T;
	node nil;
	nil.color = 'b';
	nil.size = 0;
	T.nil = &nil;
	T.root = &nil;

	ConstructRBTree(T);


}