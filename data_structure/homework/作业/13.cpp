#include <iostream>
using namespace std;

typedef struct
{
	int key;
}DATA;//若有其他数据，则增加结构体DATA中的元素

typedef struct
{
	int length;
	DATA *elem;
}SSTable;

void Creat( SSTable &ST, int n );//建立数据数组
void Destroy( SSTable &ST );//销毁数组
int Search_Bin( SSTable ST, int key );//折半查找

void Creat( SSTable &ST, int n )
{
	ST.length = n;
	ST.elem = new DATA[ST.length];
	DATA *p = ST.elem;
	for ( int i = 0; i < n; i++ )
	{
		cin >> p->key;
		p++;
	}
}

void Destroy( SSTable &ST )
{
	if( ST.length != 0 )
		delete ST.elem;
}

int Search_Bin( SSTable ST, int key )
{
	int low = 1, high =  ST.length, mid;
	while ( low <= high )
	{
		mid = ( low + high )/2;
		if( key == ST.elem[mid-1].key )
			return mid;
		else if( key < ST.elem[mid-1].key )
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int main()
{
	SSTable A;
	cout << "输入要操作的数据的项数" << endl;
	int n;
	cin >> n;
	cout << "输入要操作的数据" << endl;
	Creat( A, n );
	while(1)
	{
		cout << "*****************************************" << endl;
		cout << "*     1.折半查找                       *" << endl;
		cout << "*     2.退出                           *" << endl;
		cout << "*****************************************" << endl;
		int i;
		cin >> i;
		switch( i )
		{
		    case 1:
				cout << "输入要查找的关键字" << endl;
				int key, place;
				cin >> key;
				place = Search_Bin( A, key );
				if( place == 0 )
					cout << "没有所查找元素" << endl;
				else
				    cout << "关键字所在的位置为:" << place << endl;
				Destroy( A );
				break;
			case 2:
				break;
			default:
				cout << "没有这项操作" << endl;
		}
		if( i == 2)
			break;
	}
	return 0;
}