/* 1252366 ���賬 ����һ�� */
#include <iostream.h>    //������ɰ����޸�
#include <iomanip.h>     //������ɰ����޸�
//using namespace std;   //������ɰ����޸�

class matrix {
    private:
        int value[2][3];
    public:
        matrix operator+(matrix &b);
        /* ----������Ҫ���������Ա�����Ķ���---- */
		friend istream& operator >> ( istream &in, matrix &a);
		friend ostream& operator << ( ostream &out, matrix &a );
		matrix();
    };

/* ----�������Ա����������ʵ��---- */
matrix::matrix()
{
	for( int i=0; i<2; i++)
		for( int j=0; j<3; j++)
			value[i][j]=0;
}

ostream& operator << ( ostream &out, matrix &a )
{
	for( int i=0; i<2; i++)
	{
		for( int j=0; j<3; j++)
			out << setw(4) << a.value[i][j] << ' ';
	    out << endl;
	}
	return out;
}

istream& operator >> ( istream &in, matrix &a )
{
	for( int i=0; i<2; i++)
		for( int j=0; j<3; j++)
			in >> a.value[i][j];
	return in;
}

matrix matrix::operator+(matrix &b)
{
	matrix a;
	for( int i=0; i<2; i++)
		for( int j=0; j<3; j++)
			a.value[i][j] = value[i][j] + b.value[i][j];
	return a;
}

/* ----main������׼��---- */
int main()
{
    matrix m1, m2, m3;

    cout << "���������m1��ֵ(��2��3�У������к��е�˳������)" << endl;
    cin >> m1;
    cout << "���������m2��ֵ(��2��3�У������к��е�˳������)" << endl;
    cin >> m2;
	
    cout << "��ʼ����m1��ֵ��" << endl;
    cout << m1 << endl;
    cout << "��ʼ����m2��ֵ��" << endl;
    cout << m2 << endl;
    cout << "��Ӻ����m3��ֵ��" << endl;
    cout << (m3=m1+m2) << endl;

    return 0;
}
