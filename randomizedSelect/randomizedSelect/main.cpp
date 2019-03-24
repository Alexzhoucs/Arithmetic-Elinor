#include "HEAD.h"

int main()
{
	int A[N], B[N];
	int p = 0;
	int r = N - 1;
	int i = INIT;

	time_t beginT, endT;
	time_t during1, during2;
	
	//srand(457);
	srand((unsigned)time(NULL));

	for (int i = 0; i < N; i++)
		B[i] = rand();	    //B初始化

	//-----------------------------------------


	for (int i = 0; i < N; i++)		//A初始化
		A[i] = B[i];

	beginT = clock();
	int result1 = randomizedSelect(A, p, r, i);
	endT = clock();
	during1 = endT - beginT;		//9.2

	cout << "result1:" << endl;
	for (int i = 0; i < N; i++)
		cout << A[i] << endl;
	cout << endl << endl;
	//---------------------------------------------

	
	for (int i = 0; i < N; i++)		//A初始化
		A[i] = B[i];

	beginT = clock();
	int result2 = worstCaseSelect(A);
	endT = clock();
	during2 = endT - beginT;		//9.3

	cout << "result2" << endl;
	for (int i = 0; i < N; i++)
		cout << A[i] << endl;
	
	//---------------------------------------------
	

		
	getchar();
	return 0;
}

