#include "HEAD.h";

int inputTree(KEYTYPE c[]);


void ConstructRBTree(tree T)
{
	KEYTYPE C[MAXSIZE];
	KEYTYPE scanner;
	char d[MAXSIZE];

	inputTree(C);
	cout << C << endl;


	/*do
	{
		cin >> scanner;

	} while ();*/

	while (1)
	{
		cin >> scanner;
		cout << scanner;
	}

}

int inputTree(KEYTYPE c[])
{
	string s;
	stringstream ss;
	int i = 0;

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
		i++;
	}
	//	c[i] = '\0';
	return 0;
}