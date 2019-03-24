#include "HEAD.h"

int main()
{
	int A[N], B[N];
	int p = 0;
	int r = N - 1;
	int i = INIT;

	time_t beginT, endT;
	time_t during1, during2;

	srand((unsigned)time(NULL));
	//srand(426);

	for (int i = 0; i < N ; i++)
		B[i] = rand() %100;	    //B³õÊ¼»¯

	//-----------------------------------------


	//for (int i = 0; i < N; i++)
	//	A[i] = B[i];

	//beginT = clock();
	//int result1 = randomizedSelect(A, p, r, i);
	//endT = clock();
	//during1 = endT - beginT;		//9.2

	//---------------------------------------------


	for (int i = 0; i < N; i++)
		A[i] = B[i];

	beginT = clock();
	int result2 = worstCaseSelect(A);
	endT = clock();
	during2 = endT - beginT;

	//----------------------------------------


	
	getchar();
	return 0;
}

