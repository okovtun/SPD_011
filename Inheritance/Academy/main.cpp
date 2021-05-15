#include<iostream>
#include<string>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//			Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//			Methods:
	void info()
	{
		cout << last_name << " " << first_name << " " << age << " лет" << endl;
	}
};

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}

	//		Constructors:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,	//Human parameters
		const string& speciality, const string& group, double rating			//Student parameters
	):Human(last_name, first_name, age)
	{
		this->speciality = speciality;
		this->group = group;
		this->rating = rating;
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//			Methods:
	void info()
	{
		Human::info();
		cout << "Специальность:\t" << speciality << ",\tгруппа:\t" << group << ",\tуспеваемость:" << rating << ";\n";
	}
};

class Graduate :public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme()const
	{
		return diploma_theme;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,	//Human parameters
		const string& speciality, const string& group, double rating,			//Student parameters
		const string& diploma_theme
	) :
		Student
		(
			last_name, first_name, age,
			speciality, group, rating
		)
	{
		this->diploma_theme = diploma_theme;
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//			Methos:
	void info()
	{
		Student::info();
		cout << "Тема дипломного проекта: " << diploma_theme << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("Тупенко", "Василий", 18);
	human.info();

	Student ivan("Остроумный", "Иван", 19, "Китайская философия", "OST_01", 4.9);
	ivan.info();

	Graduate jesse("Pinkman", "Jesse", 25, "Methamphitamine manufacturing", "WithWalter", 4.5, "Methamphitamine distribution");
	jesse.info();
}