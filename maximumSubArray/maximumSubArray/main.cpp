#include "HEAD.h"

int main()
{
	int A[MAXSIZE];
	int size;
	int i;
	ifstream inF;
	inF.open(INPUTF, ios::binary);


	for (i = 0; i < MAXSIZE; i++)		//��������
	{
		if (inF.eof())
			break;

		inF >> A[i];
	}
	size = i;

	range* fz = 

	inF.close();

	
	return 0;
}