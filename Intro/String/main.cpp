#pragma warning(disable:4326)
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------------------\n"

/////////////////////////////////////////////////////////////////////////////////////////////////
//////////////				CLASS DECLARATION - ���������� ������				/////////////////

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//������ ������ � ������
	char* str;	//��������� �� ������ � ������������ ������
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//			Constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//			Operators:
	String& operator=(const String& other);
	String& operator+=(const String& other);

	//			Methods:
	void print() const;
};

//////////////						CLASS DECLARATION END						/////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////
//////////////				CLASS DEFINITION - ����������� ������				/////////////////

int String::get_size()const
{
	return size;
}
/* v ���������� ����������� ��������� (������ �������� �������� �� ������)*/
const char* String::get_str()const//���������� ��� ��� ����������� �����
{
	return str;
}
char* String::get_str()
{
	return str;
}
//			Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
}
String::String(const char str[]) : String(strlen(str) + 1)
{
	/*
	this->size = strlen(str) + 1;
	this->str = new char[size] {};	//��� �������� ������ �����������
	*/
	for (int i = 0; str[i]; i++)
		this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];*/
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)//
{
	/*this->size = other.size;
	this->str = other.str;*/
	other.str = nullptr;//��������� �� ���� (NULL pointer) - ��������� � ������.
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

//			Methods:
void String::print() const
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);	//-1 ������� ������ ���� �� �����
	for (int i = 0; i < left.get_size(); i++)
		*(result.get_str() + i) = *(left.get_str() + i);
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
	//		CPU/RAM
}

bool operator==(const String& left, const String& right)
{
	return strcmp(left.get_str(), right.get_str());
}
bool operator!=(const String& left, const String& right)
{
	return !(left == right);
}

//////////////						CLASS DEFINITION END						/////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define OPERATOR_PLUS_CHECK
//#define CONSTRUCTORS_CALLING

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	String str;		//Default constructor
	str.print();

	String str1 = "Hello";	//Single argument constructor
	str1.print();
	cout << "str1:" << str1 << endl;
	String str2 = str1;		//Copy constructor
	cout << "str2:" << str2 << endl;

	str = str2;		//Copy assignment
	cout << str << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	str1.print();
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;

	int a = 2;
	a = a;
	cout << a << endl;
#endif // ASSIGNMENT_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;//Operator + ����� ��������� ������������ (�������, �����������) �����
	cout << delimiter << endl;
	cout << str3 << endl;
	String str4 = str3;
	cout << str4 << endl;
#endif // OPERATOR_PLUS_CHECK

	//cout << delimiter << endl;
	//str1 += str2;
	//cout << delimiter << endl;
	//cout << str1 << endl;
	//String str3 = str1;//Copy constructor
	//String str4;
	//str4 = str2;	//Operator=

	/*int a = 2;
	int* pa = &a;
	int** ppa = &pa;
	int*** pppa = &ppa;
	cout << ***pppa << endl;*/

#ifdef CONSTRUCTORS_CALLING
	String str;		//Default constructor
	str.print();
	String str1(5);
	str1.print();
	String str2 = "Hello";	//Single-argument constructor
	str2.print();
	String str3("Hello");	//Single-argument constructor
	str3.print();

	String str4();	//����� �� ���������� ����������� �� ���������, 
					//����� ����������� ������� str4, ������� ������ �� ��������, 
					//� ���������� �������� ���� String.
	//str4.
	String str5;	//������� ����� ������������ �� ���������
	str5.print();
	String str6{};	//����� ����� ����������� �� ���������
	str6.print();

	String str7(String str);
	//str7("Hello");
	String("������") == str3;	//����� ����� ������������ ��� �������� ���������� ���������� �������.  
#endif // CONSTRUCTORS_CALLING

}