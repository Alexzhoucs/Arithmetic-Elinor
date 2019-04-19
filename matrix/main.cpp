#include "HEAD.h"

int main()
{
	int size[MAX+1];
	int s[MAX+1][MAX+1];
	string result;
	/*
	int n;
	ifstream finput;					//读取数据
	finput.open(INPUTF, ios::binary);
	int i;
	for (i = 0; i < MAX+1; i++)
	{
		if (finput.eof())
			break;
		finput >> size[i];
		if (size[i] <= 0)
			i--;
	}
	finput.close();
	n = i-1;		//矩阵个数，=size长度-1

	if (n < 1)
	{
		cout << "矩阵个数为0" << endl;
		return 0;
	}

	for (int i = 0; i < MAX; i++)			//初始化数组s
		for (int j = 0; j < MAX; j++)
			s[i][j] = 0;
	
	int effort = memoizedMatrixChain(size, s);		//effort为计算次数
	printOptimalParens(s, 1, n, &result);		//将乘法顺序储存在result中

	cout << "最佳乘法顺序为" << endl;
	cout << result << endl;
	cout << "代价为 " << effort << endl;
	*/
	
	//复杂度
	time_t beginTime1, endTime1, duration1;
	time_t beginTime2, endTime2, duration2;
	time_t totaldu1=0, maxdu1=0;
	time_t totaldu2=0, maxdu2=0;
	ofstream foutputT, foutputR;
	foutputT.open(ADDRESSOUTT, 0);
	foutputR.open(ADDRESSOUTR, 0);
	srand((unsigned)time(NULL));
	for (int t = 1; t <= 10; t++)
	{
		for (int i = 0; i < MAX + 1; i++)
			size[i] = rand() % LARGESTSIZE + 1;
		foutputR << endl;
		for (int i = 0; i < MAX; i++)			//初始化数组s
			for (int j = 0; j < MAX; j++)
				s[i][j] = 0;
		result.clear();
		beginTime1 = clock();
		for (int times = 1; times <= 1; times++)
			int effort = memoizedMatrixChain(size, s);		//effort为计算次数
		endTime1 = clock();
		duration1 = endTime1 - beginTime1;

		beginTime2 = clock();
		for (int times = 1; times <= 1; times++)
			printOptimalParens(s, 1, MAX, &result);
		endTime2 = clock();
		duration2 = endTime2 - beginTime2;
	
		totaldu1 += duration1;
		totaldu2 += duration2;
		if (maxdu1 < duration1)
			maxdu1 = duration1;
		if (maxdu2 < duration2)
			maxdu2 = duration2;

		foutputR << result << endl << endl;
	}
	
	foutputT << maxdu1 << ',' << totaldu1 << ',' << maxdu2 << ',' << totaldu2 << endl;

	return 0;	
}