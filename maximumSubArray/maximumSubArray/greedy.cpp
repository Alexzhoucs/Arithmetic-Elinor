#include "HEAD.h"

range* greedy(int A[], int n)
{
	int B = A[0];
	range* maxArray = (range*)malloc(sizeof(range));
	range* present = (range*)malloc(sizeof(range));
	maxArray->high = 0;
	maxArray->low = 0;
	maxArray->sum = A[0];
	present->high = 0;
	present->low = 0;
	present->sum = A[0];

	for (int i = 0; i < n; i++)
	{
		B += A[i];
		present->high = i;
		if (B < present->sum)
		{
			present->low = i;
			present->sum = A[i];
		}
		else
			present->sum += A[i];
		if (present->sum > maxArray->sum)
		{
			maxArray->high = present->high;
			maxArray->low = present->low;
			maxArray->sum = present->sum;
		}
	}
	return maxArray;
}