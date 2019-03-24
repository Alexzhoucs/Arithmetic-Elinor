#include "HEAD.h"

int randomizedSelect(int A[], int p, int r, int i)
{
	if (p == r)
		return A[p];
	int x = A[p];
	int q = randomizedPartition(A, p, r);
	int k = q - p + 1;
	if (i == k+1)
		return(x);
	else if (i < k+1)
		return(randomizedSelect(A, p, q, i));
	else
		return(randomizedSelect(A, q + 1, r, i - k));
}

int randomizedPartition(int A[], int p, int r)
{
	int x = A[p];
	int i = p - 1;
	int j = r + 1;
	int flag = 0;
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
		if (i < j)
		{
			flag = 1;
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