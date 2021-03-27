#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Point	//тип данных Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		this;
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//			Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		//Конструктор с одним параметром создает точку на прямой
		this->x = x;
		this->y = 0;
		cout << "SingleAgrumentConstructor: " << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;//SDK - Software Developer Kit
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
	}

	//			Methods:
	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
};

void function()
{
	//this;
}

//Структура - это тип данных
//Класс - это тип данных

//#define STRUCT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT
	//type name;
	int a;		//Объявляем переменную 'a' типа 'int'
	Point A;	//Объявляем переменную 'A' типа 'Point'
				//Объявляем объект структуры 'Point'
				//Создаем экземпляр структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;	//Создаем указатель на 'Point'. p - Pointer to A
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT

	Point A;	//Default constructor
	/*A.set_x(2);
	A.set_y(3);*/
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();

	Point B(2, 3);
	B.print();

	Point C = 5;	//Single-argument constructor
	C.print();

	Point D = B;	//Copy constructor
	D.print();

	Point E;	//Default constructor
	E = D;		//Copy assignment
	E.print();
}

/*
--------------------------------
. либо ->
.  - оператор прямого доступа (Point operator);
-> - оператор косвенного доступа (Arrow operator);
--------------------------------
*/

/*
--------------------------------
OOP concepts:
1. Encapsulation - это сокрытие определенной части класса от внешнего мира;
	-Модификаторы доступа:
		private:	закрытые поля, доступны только внутри класса.
		public:		открытые поля, доступны из любого места программы.
		protected:	защищенные поля, доступны внутри нашего класса,
					и внутри дочерних классов.
						!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			ЕДИНСТВЕННЫМ ОТЛИЧИЕМ МЕЖДУ КЛАССОМ И СТРУКТУРОЙ ЯВЛЯЕТСЯ ТО,
			ЧТО В КЛАСС ВСЕ ПОЛЯ ЗАКРЫТЫ, ЕСЛИ НЕ УКАЗАНО ОБРАТНОЕ, А В
			СТРУКТУРЕ ВСЕ ПОЛЯ ОТКРЫТЫ, ЕСЛИ НЕ УКАЗАНО ОБРАТНОЕ.
						!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	-get/set - методы
	get (взять) - открывают доступ к переменным членам класса на чтение.
	get-метод позволяет звят значение какой-то переменной
	set (задать, установить) - открывают доступ к переменным членам класса на запись.
	set-методы позволяют задавать значения соответсвующих переменных членов класса.
2. Inheritance;
3. Polymorphism;
--------------------------------
*/

/*
-----------------------------------------------------
Constructor - это метод, который создает объект;
~Destructor - это метод, который уничтожает объект,
			  по истечении его времени жизни;
			  ~ - tilda;
Operator=;
-----------------------------------------------------
*/