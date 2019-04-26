//输入txt文件，共100k个数据，改写成1k行，每行100个数据的csv文件

#include <iostream>
#include <fstream>

#define INPUTFILE		"./result.txt"
#define OUTPUTFILE		"./result.csv"

using namespace std;

int main()
{
    //std::cout << "Hello World!\n"; 
	int data[100];
	ifstream in;
	in.open(INPUTFILE, ios::binary);
	ofstream out;
	out.open(OUTPUTFILE, ios::binary);

	int lines = 0;

	while (!in.eof())
	{
		for (int times = 0; times < 100; times++)
		{
			int data;
			in >> data;
			out << data << ',';
		}
		out << "\n";
		lines++;
	}

	cout << "number of lines: " << lines << endl;
	
	in.close();
	out.close();
}

