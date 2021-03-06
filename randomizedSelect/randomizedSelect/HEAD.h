#include <fstream>
#include <iostream>
#include <time.h>

#define N 100000
#define	INIT 40000

using namespace std;

int randomizedSelect(int A[], int p, int r, int i);
int randomizedPartition(int A[], int p, int r);

int worstCaseSelect(int A[]);
int findMedian(int A[], int p, int r);
int partition(int A[], int x, int p, int r, int temp[]);
int insertionSort(int A[], int p, int r);




