#include <iostream>
#include <fstream>

#define TESTNUM		100000
#define REPEATTIME	100
#define MAXSIZE		20
#define INFI		65534

#define INPUTF		"./input.txt"
#define OUTPUTR		"./outputR.txt"
#define OUTPUTT		"./outputT.txt"


using namespace std;

struct range
{
	int low;
	int high;
	int sum;
};