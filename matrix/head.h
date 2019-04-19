#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <cstring>


using namespace std;

#define INPUTF		"./matrixinput.txt"
#define ADDRESSOUTT		"./matrixoutputT.csv"
#define ADDRESSOUTR		"./matrixoutputR.txt"
#define LARGESTSIZE		30
#define MAX 30
#define INFI 2000000


int inputCreate(int n);
int memoizedMatrixChain(int size[], int(*s)[MAX + 1]);
int printOptimalParens(int(*s)[MAX + 1], int i, int j, string * result);
