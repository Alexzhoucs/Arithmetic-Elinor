#include "HEAD.h"

int main()		//������ɴ�СΪN�����飬����ò�������9.2�㷨��9.3�㷨��õĵ�INITС�������Լ��㷨ִ�е�ʱ��
{
	int A[N], B[N];			//����B������¼ԭ���飬����A�ں����б��ı�
	int p = 0;				//��ʼ�±�
	int r = N - 1;			//�����±�
	int i = INIT;	
	int times = 0;				//��¼9.2�㷨����ʱ��Ƚϴ�Ĵ���

	time_t beginT, endT;	//��ʼʱ�䡢����ʱ��
	time_t during0, during1=0, during2=0;//������������ʱ�䡢9.2�㷨����ʱ�䡢9.3�㷨����ʱ��
	
	ofstream f;
	//f.open("duringTime.csv", ios::binary);

	srand((unsigned)time(NULL));
	
	//for (int k = 1; k <= 5; k++)
	//{
	//	during1 = 0;
	//	during2 = 0;

		for (int j = 1; j <= 3; j++)	//��������
		{


			for (int i = 0; i < N; i++)
				B[i] = rand();	    //B��ʼ��

			//-----------------------------------------

			// ���������������Խ���Ƿ���ȷ
			for (int i = 0; i < N; i++)		//A��ʼ��
				A[i] = B[i];

			beginT = clock();
			insertionSort(A, 0, N - 1);
			endT = clock();					//��¼�㷨��ʼ�ͽ�����ʱ��
			during0 = endT - beginT;
			cout << "result of insertion sort:" << endl;
			cout << A[INIT - 1] << endl;	//�������������iС����
			cout << "runtime:";
			cout << during0;				//����㷨ִ�е�ʱ��
			cout << endl << endl;
			
			//-----------------------------------------

			for (int i = 0; i < N; i++)		//A��ʼ��
				A[i] = B[i];

			beginT = clock();
			int result1 = randomizedSelect(A, p, r, i);//ִ��9.2�㷨�õ���iС����
			endT = clock();					//��¼�㷨��ʼ�ͽ�����ʱ��
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
			

			for (int i = 0; i < N; i++)		//A��ʼ��
				A[i] = B[i];

			beginT = clock();
			int result2 = worstCaseSelect(A);//ִ��9.3�㷨�õ���iС����
			endT = clock();					//��¼�㷨��ʼ�ͽ�����ʱ��
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

