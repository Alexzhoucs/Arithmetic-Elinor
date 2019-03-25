#include "HEAD.h"

int randomizedSelect(int A[], int p, int r, int i)
{
	if (p == r)
		return A[p];
	int x = A[p];
	int q = randomizedPartition(A, p, r);				//把A数组中下标在p到r之间的数分为<=A[p]和>=A[p]的部分，返回<=A[p]部分的最大下标
	int k = q - p + 1;									//x是数组A中第k小的数
	if (i == k+1)										//如果x是数组A中第i小的数
		return(x);
	if (k == 0)											//这时A[q+1]是目前范围内中最小的数，应该从A[q+2]开始找第i-1小的数
		return(randomizedSelect(A, q + 2, r, i - 1));
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
	int flag = 0;			//flag记录有没有进行交换，如果没有交换，说明A[p]是最小的数。有交换的情况下，x是第j+2小的数，但没有交换时x是第j+1小的数，返回特殊值p-1用来区分。
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
			if (flag == 1)
				return(j);
			else
				return(j - 1);
		}
	}
}