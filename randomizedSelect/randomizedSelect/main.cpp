#include "HEAD.h"

int main()
{
	int A[N];
	int p = 0;
	int r = N - 1;
	int i = INIT;

	time_t beginT, endT;
	time_t during;

	// srand((unsigned)time(NULL));
	srand(426);

	for (int i = 0; i < N ; i++)
		A[i] = rand();				//A³õÊ¼»¯

	beginT = clock();
	int result = randomizedSelect(A, p, r, i);
	endT = clock();
	during = endT - beginT;

	
	getchar();
	return 0;
}

int randomizedSelect(int A[], int p, int r, int i)
{
	if (p == r)
		return A[p];
	int q = randomizedPartition(A, p, r);
	int k = q - p + 1;
	if (i == k)
		return(A[q]);
	else if (i < k)
		return(randomizedSelect(A, p, q, i));
	else
		return(randomizedSelect(A, q + 1, r, i - k));
}

int randomizedPartition(int A[], int p, int r)
{
	int x = A[p];
	int i = p - 1;
	int j = r + 1;
	while (1)
	{
		do
		{
			j--;
		} while (A[j] > x);
		do
		{
			i++;
		} while (A[i] < x);

/*
		for (; A[j] > x; j--);
		for (; A[i] < x; i++);*/
		if (i < j)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		else
		{
			return j;
		}
	}
}