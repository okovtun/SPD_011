#include<iostream>
using namespace std;

struct Point
{
	//���� ������ - ���������� ����� ������ (members):
	double x;
	double y;
	//�������� ��������� ��� ����� �� ���������� ������� ����� ��� ������
	//����� - ��� ��� ������!!!!!
	//��������� - ��� ��� ������!
};

void main()
{
	setlocale(LC_ALL, "");
	int a;	//����������� ���������� 'a' ���� 'int'
	Point A;//����������� ���������� 'A' ���� 'Point'
			//����������� ������ 'A' ������ 'Point'
			//��������� ��������� 'A' ������ 'Point'
	A.x = 0;
	A.y = 0;
	cout << A.x << "\t" << A.y << endl;
}