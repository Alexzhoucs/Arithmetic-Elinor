#include "HEAD.h"

range* maxCrossing(int A[], int low, int mid, int high);

range* divideAndConquer(int A[], int low, int high)
{
	if (high == low)
	{
		range* subArray = (range*)malloc(sizeof(range));
		subArray->low= low;
		subArray->high = high;
		subArray->sum = A[low];
		return subArray;
	}

	int mid = (low + high) / 2;
	range* left = divideAndConquer(A, low, mid);
	range* right = divideAndConquer(A, mid + 1, high);

	range* cross = maxCrossing(A, low, mid, high);
	if (left->sum > right->sum)
	{
		if (left->sum > cross->sum)
			return left;
		else
			return cross;
	}
	else
	{
		if (right->sum > cross->sum)
			return right;
		else
			return cross;
	}
}

range* maxCrossing(int A[], int low, int mid, int high)
{
	int leftSum = INFI * (-1);
	int sum = 0;
	int maxLeft;

	for (int i = mid; i >= low; i--)
	{
		sum += A[i];
		if (sum > leftSum)
		{
			leftSum = sum;
			maxLeft = i;
		}
	}

	int rightSum = INFI * (-1);
	sum = 0;
	int maxRight;

	for (int i = mid + 1; i <= high; i++)
	{
		sum += A[i];
		if (sum > rightSum)
		{
			rightSum = sum;
			maxRight = i;
		}
	}

	range* subArray = (range*)malloc(sizeof(range));
	subArray->low = maxLeft;
	subArray->high = maxRight;
	subArray->sum = leftSum + rightSum;

	return subArray;
}