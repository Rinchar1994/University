#include <iostream>
using namespace std;

typedef struct
{
	int key;
}DATA;//�����������ݣ������ӽṹ��DATA�е�Ԫ��

typedef struct
{
	int length;
	DATA *elem;
}SSTable;

void Creat( SSTable &ST, int n );//������������
void Destroy( SSTable &ST );//��������
int Search_Bin( SSTable ST, int key );//�۰����

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
	cout << "����Ҫ���������ݵ�����" << endl;
	int n;
	cin >> n;
	cout << "����Ҫ����������" << endl;
	Creat( A, n );
	while(1)
	{
		cout << "*****************************************" << endl;
		cout << "*     1.�۰����                       *" << endl;
		cout << "*     2.�˳�                           *" << endl;
		cout << "*****************************************" << endl;
		int i;
		cin >> i;
		switch( i )
		{
		    case 1:
				cout << "����Ҫ���ҵĹؼ���" << endl;
				int key, place;
				cin >> key;
				place = Search_Bin( A, key );
				if( place == 0 )
					cout << "û��������Ԫ��" << endl;
				else
				    cout << "�ؼ������ڵ�λ��Ϊ:" << place << endl;
				Destroy( A );
				break;
			case 2:
				break;
			default:
				cout << "û���������" << endl;
		}
		if( i == 2)
			break;
	}
	return 0;
}