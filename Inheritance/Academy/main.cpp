#include<iostream>
#include<string>
#include<regex>
using namespace std;

#define delimiter "\n-------------------------------------------------------\n"

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
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//			Methods:
	virtual void info()
	{
		cout << last_name << " " << first_name << " " << age << " ���" << endl;
	}

	virtual void duty() = 0;	//�����������
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
	) :Human(last_name, first_name, age)
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
		cout << "�������������:\t" << speciality << ",\t������:\t" << group << ",\t������������:" << rating << ";\n";
	}
	void duty()
	{
		cout << "�������� �����������: �������" << endl;
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
		cout << "���� ���������� �������: " << diploma_theme << endl;
	}
};

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		if (speciality.length() > 0 && speciality.length() < 51) this->speciality = speciality;
		else if (speciality.empty() == true) cout << "������������� �� ����� ���� �����, ��������� ����..." << endl;
		else if (speciality.length() > 50) cout << "������������� ������� �������, ��������� ����..." << endl;
	}
	void set_experience(unsigned int experience)
	{
		if (experience >= 0 && experience <= 80) this->experience = experience;
		else cout << "���� ������� �� ������� �����������, ��������� ����..." << endl;
	}
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()
	{
		Human::info();
		cout << speciality << " ���� " << experience << " ���." << endl;
	}
	void duty()
	{
		cout << "�������� �����������: ������� ���������" << endl;
	}
};

//#define INHERITANCE
//#define REGEX
#ifdef REGEX
//#define RGX_NAME_CHECK
#define RGX_EMAIL_CHECK  
#endif // REGEX
#define POLYMORPHISM

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	Human human("�������", "�������", 18);
	human.info();

	Student ivan("����������", "����", 19, "��������� ���������", "OST_01", 4.9);
	ivan.info();

	Graduate jesse("Pinkman", "Jesse", 25, "Methamphitamine manufacturing", "WithWalter", 4.5, "Methamphitamine distribution");
	jesse.info();
#endif // INHERITANCE

#ifdef REGEX
	/*
https://www.cplusplus.com/reference/regex/
https://www.cplusplus.com/reference/regex/ECMAScript/
https://www.cplusplus.com/reference/regex/regex_match/
*/

#ifdef RGX_NAME_CHECK
	regex name_template("[A-Z][a-z]{1,30}");
	string name;
	cout << "������� ���: "; cin >> name;
	//regex_match(����_������, ����������_���������, ������_��������);
	cout << regex_match(name.c_str(), name_template, std::regex_constants::match_any) << endl;
#endif // RGX_NAME_CHECK

#ifdef RGX_EMAIL_CHECK
	regex rgx("([A-Za-z0-9].){3,20}@[A-Za-z]{1,10}.[A-Za-z]{2,3}");
	string email = "vasya....tupenko@mail.ru";
	cout << regex_match(email, rgx, std::regex_constants::match_any) << endl;
#endif // RGX_EMAIL_CHECK

#endif // REGEX

	//��������� - Generalization
	/*Teacher teacher("Einstein", "Albert", 140, "Astronomy", 80);
	Student student("���������", "������", 100, "Phisics", "SPD_011", 99);

	Human* p_teacher = &teacher;
	Human* p_student = &student;

	p_teacher->info();
	p_student->info();
	cout << delimiter << endl;*/
	int arr[] = { 3, 5, 8, 13, 21 };
	//Human h("�����", "�������", 20);
	Human* group[] =
	{
		new Teacher("Einstein", "Albert", 140, "Astronomy", 80),
		new Student("��������", "�������", 35, "��������", "SPD_011", 99),
		new Teacher("���������", "������", 100, "Phisics", 75),
		new Student("��������", "�����", 36, "�������", "SPD_011",98),
		new Graduate("��������", "������", 18, "���", "SPD_011", 98, "���������� ������������� ����������")
	};
	cout << sizeof(group) << endl;
	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		cout << typeid(*group[i]).name() << endl;
		group[i]->duty();
		group[i]->info();
		cout << delimiter << endl;
	}

	/*Student* group[] =
	{
		new Student("��������", "�����", 36, "�������", "SPD_011",98),
		new Graduate("��������", "������", 18, "���", "SPD_011", 98, "���������� ������������� ����������"),
		new Student("��������", "�������", 35, "��������", "SPD_012", 99)
	};*/
	/*for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		if(group[i]->get_group() == "SPD_011")group[i]->info();
		cout << delimiter << endl;
	}*/
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}

}