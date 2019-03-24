#include "HEAD.h"

int worstCaseSelect(int A[])
{
	int p = 0;
	int r = N - 1;
	while (1)
	{
		if (r - p < 5)
		{
			insertionSort(A, p, r);
			return(A[INIT - 1]);
		}
		int x = findMedian(A, p, r);
		int k = partition(A, x, p, r) + 1;
		if (INIT == k)
			return(x);
		if (INIT < k)
			r = k;
		else
			p = k;
	}
}

int findMedian(int A[], int p, int r)
{
	int i;
	int n = r - p + 1;
	int B[(N / 5) + 1];
	if (n <= 5)
		return(insertionSort(A, p, r));
	for (i = 0; i < (n / 5); i++)
	{
		B[i] = insertionSort(A, p + 5 * i, p + 5 * i + 4);
	}
	if (5 * i != n)
	{
		B[i] = insertionSort(A, p + 5 * i, r);
		i++;
	}
	return(findMedian(B, 0, i - 1));
}

int partition(int A[], int x, int p, int r)
{
	int flag = 0;
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
		} while (A[i]<x);
		if (i < j)
		{
			if (x == A[j])
				flag = 1;

			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		else
		{
			if (flag == 1)
				return (j);
			else
				return(j + 1);
		}
	}
}

int insertionSort(int A[], int p, int r)
{
	for (int i = p + 1; i <= r; i++)
	{
		int j = i - 1;
		int x = A[i];
		while (j >= p && A[j] > A[i])
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
	return(A[(p + r) / 2]);
}