#include "HEAD.h"

void main()
{
	tree T;
	node nil;
	char choice = '1';
<<<<<<< Updated upstream
=======
	time_t duration=0;
	time_t longestdu = 0;
	time_t totaldu = 0;
>>>>>>> Stashed changes
	nil.color = 'b';
	nil.size = 0;
	T.nil = &nil;
	T.root = &nil;
	
<<<<<<< Updated upstream
	ConstructRBTree(&T);
	
=======
	for (int i = 0; i < 1000; i++) 
	{
		T.nil = &nil;
		T.root = &nil;
		duration = ConstructRBTree(&T);
		if (duration > longestdu)
			longestdu = duration;
		totaldu += duration;
	}
	f << totaldu << endl;
	f << longestdu << endl;
	f.close();

	/*
>>>>>>> Stashed changes
	while (choice)
	{
		cout << "1--�����½ڵ�" << endl;
		cout << "2--��С������������" << endl;
		cout << "3--��ӡ��" << endl;
		cout << "4--��ؼ�����С�Ľڵ�" << endl;
		cout << "5--��ؼ������Ľڵ�" << endl;
		cout << "6--�Һ��" << endl;
		cout << "7--��ǰ��" << endl;
		cout << "8--����Ϊx�Ľڵ�" << endl;
		cout << "9--��ڵ����" << endl;
		cout << "------------------------------------------------------------------------------------------";
		cout << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			insert(&T);
			break;
		case '2' :
			treeWalk(T.root, T.nil);
			cout << endl;
			break;
		case '3':
			demo(T.root, T.nil, 0);
			break;
		case '4':
			minKey(T);
			break;
		case '5':
			maxKey(T);
			break;
		case '6':
			successor(T);
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
			cout << "�����˳����밴Enter��" << endl;
			getchar();
			break;
		default:
			cout << "����������������롣" << endl;
			cout << "----------------------------------------------------------" << endl;
		}
		
	}


}