//1252366 ���賬 ����һ��
#include <iostream>
using namespace std;

class student {
    private:
        int num;
        float score;
    public:
        void display();  //���ѧ�źͳɼ�
        void get(void);  //��������ѧ�źͳɼ�
    //���в�����������κ����ݳ�Ա�ͳ�Ա����
};

/* �ڴ˸������Ա����������ʵ�� */
void student::display()
{
	cout << num << "  " << score << endl;
}

void student::get()
{
	cin >> num >> score;
}

int main()
{
    /* ��ע�⣺�������в������ٶ����κ����͵ı���(����ȫ�ֱ���) */
    student *p, s[5];
    /* ��������5���˵�ѧ�ż��ɼ�
      ��Ҫ�󣺡����������ȷ��������ʾ�����硰�������**����ѧ�źͳɼ��� */
	p=s;
	for( int i=0; i<5; i++)
	{
		cout << "�������" << i+1 << "����ѧ�źͳɼ�:";
		p[i].get();
	}
    /* �����1��3��5���˵���Ϣ */
	p[0].display();
	p[2].display();
	p[4].display();


    return 0;
}