#include "HEAD.h"

void main()
{
	tree T;
	node nil;
	char choice = '1';
	time_t duration;
	nil.color = 'b';
	nil.size = 0;
	T.nil = &nil;
	T.root = &nil;

	ofstream f;
	f.open("duration.csv", ios::binary);
	
	for (int i = 0; i < 10; i++) 
	{

		duration = ConstructRBTree(&T);
		f << duration << endl;
	}
	

	f.close();

	/*
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

	*/
}