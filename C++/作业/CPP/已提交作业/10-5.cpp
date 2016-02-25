/* 1252366 蒋凌超 电子一班 */
#include <iostream.h>    //视情况可按需修改
#include <iomanip.h>     //视情况可按需修改
//using namespace std;   //视情况可按需修改

class matrix {
    private:
        int value[2][3];
    public:
        matrix operator+(matrix &b);
        /* ----根据需要添加其它成员函数的定义---- */
		friend istream& operator >> ( istream &in, matrix &a);
		friend ostream& operator << ( ostream &out, matrix &a );
		matrix();
    };

/* ----给出类成员函数的体外实现---- */
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

/* ----main函数不准动---- */
int main()
{
    matrix m1, m2, m3;

    cout << "请输入矩阵m1的值(共2行3列，按先行后列的顺序输入)" << endl;
    cin >> m1;
    cout << "请输入矩阵m2的值(共2行3列，按先行后列的顺序输入)" << endl;
    cin >> m2;
	
    cout << "初始矩阵m1的值：" << endl;
    cout << m1 << endl;
    cout << "初始矩阵m2的值：" << endl;
    cout << m2 << endl;
    cout << "相加后矩阵m3的值：" << endl;
    cout << (m3=m1+m2) << endl;

    return 0;
}
