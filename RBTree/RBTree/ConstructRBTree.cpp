#include "HEAD.h";

int inputTree(KEYTYPE c[]);


void ConstructRBTree(tree T)
{
	KEYTYPE C[MAXSIZE];
	KEYTYPE scanner;
	char d[MAXSIZE];
	int n;

	n = inputTree(C);
	cout << C << endl;

	cout << "Please input datas." << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}



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
	//	c[i] = '\0';
	return n;
}