#include "HEAD.h"

int main()
{
	int A[MAXSIZE];
	int B[TESTNUM];
	/*
	int size;
	int i;
	ifstream inF;
	inF.open(INPUTF, ios::binary);


	for (i = 0; i < MAXSIZE; i++)		//读入数据
	{
		if (inF.eof())
			break;

		inF >> A[i];
	}
	size = i;

	range* fz = divideAndConquer(A, 0, size - 1);
	range* tx = greedy(A, size);

	inF.close();
	*/

	/*
	time_t starttime1, endtime1, duration1,maxdu1,totaldu1;
	time_t starttime2, endtime2, duration2,maxdu2,totaldu2;
	srand(145);

	ofstream outT;
	outT.open(OUTPUTT, ios::binary);
	for (int j = 1;j<=REPEATTIME;j++)
	{
		maxdu1 = 0;
		totaldu1 = 0;
		maxdu2 = 0;
		totaldu2 = 0;
		for (int i = 0; i <TESTNUM; i++)
			B[i] = rand();
		starttime1 = clock();
		for (int k = 1; k <= 10; k++)
		{
			range* fz = divideAndConquer(B, 0, TESTNUM - 1);
		}
		endtime1 = clock();
		duration1 = endtime1 - starttime1;
		if (duration1 > maxdu1)
			maxdu1 = duration1;
		totaldu1 += duration1;

		starttime2 = clock();
		for (int k = 1; k <= 10; k++)
		{
			range* tx = greedy(B, TESTNUM);
		}
		endtime2 = clock();
		duration2 = endtime2 - starttime2;
		if (duration2 > maxdu2)
			maxdu2 = duration2;
		totaldu2 += duration2;

		//把四个时间输出到excel文件
		outT << maxdu1 << ',' << totaldu1 << ',' << maxdu2 << ',' << totaldu2 << endl;

	}
	outT.close();
	
	*/
	return 0;
}



