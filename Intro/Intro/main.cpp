#include<iostream>
using namespace std;

struct Point
{
	//Поля класса - переменные члены класса (members):
	double x;
	double y;
	//Создавая структуру или класс мы фактически создаем новый тип данных
	//КЛАСС - ЭТО ТИП ДАННЫХ!!!!!
	//СТРУКТУРА - ЭТО ТИП ДАННЫХ!
};

void main()
{
	setlocale(LC_ALL, "");
	int a;	//Объявляется переменная 'a' типа 'int'
	Point A;//Объявляется переменная 'A' типа 'Point'
			//Объявляется объект 'A' класса 'Point'
			//Создается экземпляр 'A' класса 'Point'
	A.x = 0;
	A.y = 0;
	cout << A.x << "\t" << A.y << endl;
}