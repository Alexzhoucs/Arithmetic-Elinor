#include "HEAD.h"

#include "HEAD.h"

int lookupChain(long(*m)[MAX + 1], int(*s)[MAX + 1], int size[], int i, int j);

int memoizedMatrixChain(int size[],int(*s)[MAX + 1])
{
	int n;

	for (n = 0; size[n] > 0; n++);
	n--;

	long m[MAX + 1][MAX + 1];

	for (int i = 0; i <= n; i++)
		for (int j = i; j <= n; j++)
			m[i][j] = INFI;

	long a = lookupChain(m, s, size, 1, n);
	return a;
}


int lookupChain(long(*m)[MAX + 1], int(*s)[MAX + 1], int size[], int i, int j)
{
	if (m[i][j] < INFI)
		return(m[i][j]);

	if (i == j)
		m[i][j] = 0;
	else
		for (int k = i; k <= j - 1; k++)
		{
			long q = lookupChain(m, s, size, i, k) + lookupChain(m, s, size, k + 1, j) + size[i - 1] * size[k] * size[j];
			if (q < m[i][j])
			{
				m[i][j] = q;
				s[i][j] = k;
			}
		}
	return(m[i][j]);
}

int printOptimalParens(int(*s)[MAX + 1], int i, int j, string * result)
{
	if (i == j)
	{
		char str[MAX];
		(*result).append("A");
		_itoa_s(i, str,MAX, 10);
		(*result).append(str);
	}
	else
	{
		(*result).append("( ");
		printOptimalParens(s, i, s[i][j], result);
		(*result).append(" ");
		printOptimalParens(s, s[i][j] + 1, j, result);
		(*result).append(" )");
	}
	return 0;
}