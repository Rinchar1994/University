//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
#include <string>
using namespace std;

char name[50][10],num[50][10];
int n;

void input_data()
{
	int i;
	for(i=0; i<n; i++)
	{
		cout << "Input name and NO. of student " << i+1 << ":";
		cin >> name[i] >> num[i];
	}
}

void search(char find_name[])
{
	int i;
	for(i=0; i<n; i++)
	{
		if(strcmp(name[i],find_name)==0)
		{
			cout << name[i] << " has been found,his number is " << num[i] << endl;
			break;
		}
	}
	if(i>=n)
		cout << "The student is not in the class." << endl;
}

int main()
{
	char find_name[10];
	cout << "Please input number of this class: ";
	cin >> n;
	input_data();
	cout << "Please input name you want to find: ";
	cin >> find_name;
	search(find_name);

	return 0;
}

