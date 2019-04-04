#include "HEAD.h"

int main()		//随机生成大小为N的数组，输出用插入排序、9.2算法和9.3算法求得的第INIT小的数，以及算法执行的时间
{
	int A[N], B[N];			//数组B用来记录原数组，数组A在函数中被改变
	int p = 0;				//起始下标
	int r = N - 1;			//结束下标
	int i = INIT;	
	int times = 0;				//记录9.2算法运行时间比较大的次数

	time_t beginT, endT;	//开始时间、结束时间
	time_t during0, during1=0, during2=0;//插入排序运行时间、9.2算法运行时间、9.3算法运行时间
	
	ofstream f;
	//f.open("duringTime.csv", ios::binary);

	srand((unsigned)time(NULL));
	
	//for (int k = 1; k <= 5; k++)
	//{
	//	during1 = 0;
	//	during2 = 0;

		for (int j = 1; j <= 3; j++)	//运行三次
		{


			for (int i = 0; i < N; i++)
				B[i] = rand();	    //B初始化

			//-----------------------------------------

			// 插入排序用来测试结果是否正确
			for (int i = 0; i < N; i++)		//A初始化
				A[i] = B[i];

			beginT = clock();
			insertionSort(A, 0, N - 1);
			endT = clock();					//记录算法开始和结束的时间
			during0 = endT - beginT;
			cout << "result of insertion sort:" << endl;
			cout << A[INIT - 1] << endl;	//插入排序，输出第i小的数
			cout << "runtime:";
			cout << during0;				//输出算法执行的时间
			cout << endl << endl;
			
			//-----------------------------------------

			for (int i = 0; i < N; i++)		//A初始化
				A[i] = B[i];

			beginT = clock();
			int result1 = randomizedSelect(A, p, r, i);//执行9.2算法得到第i小的数
			endT = clock();					//记录算法开始和结束的时间
			during1 = endT - beginT;
		
			//during1 += endT - beginT;	
			
			/*if (during1 > 16)
				times ++;
			*/
			
			cout << "result1:";
			cout << result1 << endl;
			cout << "runtime:";
			cout << during1;
			cout << endl << endl;
			
			//f << during1;

			//---------------------------------------------
			

			for (int i = 0; i < N; i++)		//A初始化
				A[i] = B[i];

			beginT = clock();
			int result2 = worstCaseSelect(A);//执行9.3算法得到第i小的数
			endT = clock();					//记录算法开始和结束的时间
			during2 = endT - beginT;
			//during2 += endT - beginT;
	
			cout << "result2:";
			cout << result2 << endl;
			cout << "runtime:";
			cout << during2;
			cout << endl << endl;
			
			//f << "," << during2 << endl;
			

			//---------------------------------------------

		};
	//	cout << times << endl;
	//	cout << during1 << endl;
	//	cout << during2 << endl;
	//}
	//f.close();
		
	getchar();
	return 0;
}

