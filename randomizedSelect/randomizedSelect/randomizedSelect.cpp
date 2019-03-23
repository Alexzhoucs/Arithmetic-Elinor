#include "HEAD.h"

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