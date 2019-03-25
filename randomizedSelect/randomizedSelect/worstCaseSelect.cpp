#include "HEAD.h"

int worstCaseSelect(int A[])	//返回数组中第i小的数
{
	int p = 0;
	int r = N - 1;
	int temp[2];
	while (1)
	{
		if (r - p < 5)					//如果确定第i小的数下标范围为r到p，且p-r<5，直接插入排序这一段
		{
			insertionSort(A, p, r);
			return(A[INIT - 1]);
		}
		int x = findMedian(A, p, r);	//x为中位数的中位数的中位数...的中位数
		partition(A, x, p, r, temp);	//temp[0]表示x是第几小的数，temp[1]为分界点下标
		int k = temp[0];				//x是第k小的数
		int j = temp[1];				//该段数组以j为分界再分为两段
		if (INIT == k)
			return(x);
		if (INIT < k)
			r = j;
		else
			p = j+1;
	}
}

int findMedian(int A[], int p, int r)	//返回数组A下标在p到r的这一段中的中位数的中位数...的中位数
{
	int i;
	int n;
	int B[(N / 5)];
	n = r - p + 1;
	if (n <= 5)
		return(insertionSort(A, p, r));
	for (i = 0; i < (n / 5); i++)	////中位数的个数>5时，迭代
	{
		B[i] = insertionSort(A, p + 5 * i, p + 5 * i + 4);
	}
	while (true) {
		n = i;
		if (n <= 5)		//中位数的个数<=5时，插入排序取中间值
			return(insertionSort(B, 0, n-1));
		for (i = 0; i < (n / 5); i++)	////中位数的个数>5时，迭代
		{
			B[i] = insertionSort(B, 5 * i, 5 * i + 4);
		}
	}
}

int partition(int A[], int x, int p, int r,int temp[])//temp用来返回x是第几小的数，以及分界点下标
{
	int flag1 = 0;		
	int flag2 = 0;		//记录x在partition后分在左边一组还是右边一组
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
				flag1 = 1;	//x在partition后分在左边一组
			if (x == A[i])
				flag2 = 1;	//x在partition后分在右边一组
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		else
		{
			if (flag1 == 1)		//x在左边一组
			{
				temp[0] = j + 1;
				temp[1] = j;
			}
			else 
				if (flag2 == 1)		//x在右边一组
				{
				temp[0] = j +2;
				temp[1] = j;
				}
				else
				{					//x没有移动，说明x的位置与x的大小相符。此时j是x的下标，x是第j+1小的数
					temp[0] = j + 1;
					if (j == p)		
						temp[1] = j;	//j是x的下标。如果x是这段数组中最小的，本次partition排除x自己。
					else
						temp[1] = j-1;//只要x不是这段数组中最小的，下次迭代可以以j-1为分界
				}
			return(0);
		}
		
	}
}

int insertionSort(int A[], int p, int r)//对下表为p到r的部分插入排序，返回中间值
{
	for (int i = p + 1; i <= r; i++)
	{
		int j = i - 1;
		int x = A[i];
		while (j >= p && A[j] > x)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
	return(A[(p + r) / 2]);
}