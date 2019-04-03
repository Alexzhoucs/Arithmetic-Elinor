#include "HEAD.h"

void main()
{
	tree T;
	node nil;
	char choice = '1';
	nil.color = 'b';
	nil.size = 0;
	T.nil = &nil;
	T.root = &nil;
	
	ConstructRBTree(T);
	
	while (choice)
	{
		cout << "1--插入新节点" << endl;
		cout << "2--由小到大遍历并输出" << endl;
		cout << "3--打印树" << endl;
		cout << "4--求关键字最小的节点" << endl;
		cout << "5--求关键字最大的节点" << endl;
		cout << "6--找后继" << endl;
		cout << "7--找前驱" << endl;
		cout << "8--找秩为x的节点" << endl;
		cout << "9--求节点的秩" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			insert(T);
			break;
		case '2' :
			treeWalk(T.root, T.nil);
			cout << endl;
			break;
		case '3':
			demo(T.root, T.nil, 0);
			break;
		case '4':
			MinKey(T);
			break;
		case '5':
			MaxKey(T);
			break;
		case '6':
			Successor(T);
			break;
		case '7':
			Predecessor(T);
			break;
		case '8':
			Select(T);
			break;
		case '9':
			findRank(T);
			break;
		case '0':
			cout << "程序退出，请按Enter。" << endl;
			getchar();
			break;
		default:
			cout << "输入错误，请重新输入。" << endl;
			cout << "----------------------------------------------------------" << endl;
		}
		
	}


}