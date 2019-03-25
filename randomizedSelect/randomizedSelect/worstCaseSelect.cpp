#include "HEAD.h"

int worstCaseSelect(int A[])	//���������е�iС����
{
	int p = 0;
	int r = N - 1;
	int temp[2];
	while (1)
	{
		if (r - p < 5)					//���ȷ����iС�����±귶ΧΪr��p����p-r<5��ֱ�Ӳ���������һ��
		{
			insertionSort(A, p, r);
			return(A[INIT - 1]);
		}
		int x = findMedian(A, p, r);	//xΪ��λ������λ������λ��...����λ��
		partition(A, x, p, r, temp);	//temp[0]��ʾx�ǵڼ�С������temp[1]Ϊ�ֽ���±�
		int k = temp[0];				//x�ǵ�kС����
		int j = temp[1];				//�ö�������jΪ�ֽ��ٷ�Ϊ����
		if (INIT == k)
			return(x);
		if (INIT < k)
			r = j;
		else
			p = j+1;
	}
}

int findMedian(int A[], int p, int r)	//��������A�±���p��r����һ���е���λ������λ��...����λ��
{
	int i;
	int n;
	int B[(N / 5)];
	n = r - p + 1;
	if (n <= 5)
		return(insertionSort(A, p, r));
	for (i = 0; i < (n / 5); i++)	////��λ���ĸ���>5ʱ������
	{
		B[i] = insertionSort(A, p + 5 * i, p + 5 * i + 4);
	}
	while (true) {
		n = i;
		if (n <= 5)		//��λ���ĸ���<=5ʱ����������ȡ�м�ֵ
			return(insertionSort(B, 0, n-1));
		for (i = 0; i < (n / 5); i++)	////��λ���ĸ���>5ʱ������
		{
			B[i] = insertionSort(B, 5 * i, 5 * i + 4);
		}
	}
}

int partition(int A[], int x, int p, int r,int temp[])//temp��������x�ǵڼ�С�������Լ��ֽ���±�
{
	int flag1 = 0;		
	int flag2 = 0;		//��¼x��partition��������һ�黹���ұ�һ��
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
				flag1 = 1;	//x��partition��������һ��
			if (x == A[i])
				flag2 = 1;	//x��partition������ұ�һ��
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		else
		{
			if (flag1 == 1)		//x�����һ��
			{
				temp[0] = j + 1;
				temp[1] = j;
			}
			else 
				if (flag2 == 1)		//x���ұ�һ��
				{
				temp[0] = j +2;
				temp[1] = j;
				}
				else
				{					//xû���ƶ���˵��x��λ����x�Ĵ�С�������ʱj��x���±꣬x�ǵ�j+1С����
					temp[0] = j + 1;
					if (j == p)		
						temp[1] = j;	//j��x���±ꡣ���x�������������С�ģ�����partition�ų�x�Լ���
					else
						temp[1] = j-1;//ֻҪx���������������С�ģ��´ε���������j-1Ϊ�ֽ�
				}
			return(0);
		}
		
	}
}

int insertionSort(int A[], int p, int r)//���±�Ϊp��r�Ĳ��ֲ������򣬷����м�ֵ
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