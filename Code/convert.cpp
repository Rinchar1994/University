#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	char line[10] = {0};
	ifstream fin;
	fin.open( "source.txt", ios::in );
	ofstream fout;
	fout.open( "des.txt", ios::out );
	fout << "memory_initialization_radix=16;" << endl;
	fout << "memory_initialization_vector=" << endl;
	while( fin.getline( line, 10 ) )
	{
		line[8] = ',';
		fout << line << endl;
	}
	system("pause");
}