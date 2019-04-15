#include <iostream>
#include <fstream>
#include <time.h>

#define TESTNUM		10000
#define REPEATTIME	100
#define MAXSIZE		20
#define INFI		65534

#define INPUTF		"./input.txt"
#define OUTPUTR		"./outputR.txt"
#define OUTPUTT		"./outputT.csv"


using namespace std;

struct range
{
	int low;
	int high;
	int sum;
};

range* divideAndConquer(int A[], int low, int high);
range* greedy(int A[], int n);