#include "HEAD.h"

int randomizedSelect(int A[], int p, int r, int i)
{
	if (p == r)
		return A[p];
	int x = A[p];
	int q = randomizedPartition(A, p, r);				//��A�������±���p��r֮�������Ϊ<=A[p]��>=A[p]�Ĳ��֣�����<=A[p]���ֵ�����±�
	int k = q - p + 1;									//x������A�е�kС����
	if (i == k+1)										//���x������A�е�iС����
		return(x);
	if (k == 0)											//��ʱA[q+1]��Ŀǰ��Χ������С������Ӧ�ô�A[q+2]��ʼ�ҵ�i-1С����
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
	int flag = 0;			//flag��¼��û�н��н��������û�н�����˵��A[p]����С�������н���������£�x�ǵ�j+2С��������û�н���ʱx�ǵ�j+1С��������������ֵp-1�������֡�
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