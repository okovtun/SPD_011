https://github.com/okovtun/SPD_011
https://www.youtube.com/watch?v=yPB-sWkSuLE&list=PLeqyOOqxeiINLry6Ho7Xa0xBGZ-YwSsal

TODO:
В класс ForwardList добавить методы:
1. void erase(int index);		//Удаляет значение по заданному индексу
2. Написать деструктор таким образом, чтобы он очищал список 
	(удалял из него све элементы) перед удалением;				DONE
3. Оптимировать методы добавления элементов и проходы по списку;
4. CopyMethods		DONE
5. MoveMethods		DONE
6. Перегрузить оператор + таким образом, чтобы он выполнял конкатенацию списков; DONE
7. (Hardcore-чик)Обеспечить создание списка следующим образом:		DONE
	ForwardList list = { 3, 5, 8, 13, 21 };
8. (Hardcore)Обеспечить вывод списка на экран следующим образом:	DONE
	for(int i:list)
		cout << i << tab;
	cout << endl;


MATH:
https://drive.google.com/drive/folders/1PtH0LBlm7PpmBcaE6mwBnkftAcEui32y?usp=sharing

Regex:
https://www.cplusplus.com/reference/regex/
https://www.cplusplus.com/reference/regex/ECMAScript/
https://www.cplusplus.com/reference/regex/regex_match/

Assembler:
https://drive.google.com/drive/folders/1mIhAKMp5-Jpy6s5X8u924tRCXFEdHE_z?usp=sharing


DONE:
1. В проекте Academy для всех классов перегрузить оператор вывода (<<) и вывести группу на экран с его использованием;
	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		cout << *group[i] << endl;
	}
2. Построить иерархию объектов игры GTA;

DONE:
1. В проект Academy добавить класс Teacher;
2. Для всех классов написать set-методы с фильтрацией данных;

DONE:
1. Разделить класс Fraction на файлы. Сделать это в ветке fraction_separated;
2. Создать проект Academy, в которм реализовать классы Student, Teacher и Graduate (Дипломник)
   Подумать, как сюда применить наследование.

DONE:
1. В новом проекте реализовать класс String, и все необходимые методы в этом классе;
2. В класс String добавить оператор [], и с его помощию упростить оператор +
3. В класс String добавить MoveAssignment;
4. Для класса String перегрузить операторы сравнения;
----------------------------------------------
Реадизовать класс Matrix, описывающий матрицу, 
и обеспечивающий все операции над матрицами:
-determinant()
-operator+
-operator-
-operator*

DONE:
1. В классе Fraction добить конструктор с одним параметром типа double;	DONE
Реализовать класс Fraction, описывающий простую дробь. 
В классе должны быть все обязательные методы, а так же методы:
	- to_proper();		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
	- to_improper();	//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
	- reduce();			//Сокращает дробь: 5/10 => 1/2;
1. Арифметические операторы: +, -, *, /;
2. Составные присваивания: +=, -=, *=, /=;
3. Increment/Decrement (++/--);
4. Операторы сравнения: ==, !=, >, <, >=, <=;
5. Операторы для работы с потоками: <<, >>

DONE:
0. Выучить теорию!!!
1. В классе Point реализовать МЕТОД ??? distance(???), который возвращает расстояние до указанной точки;
2. Реализовать ФУНКЦИЮ ??? distance(???), которая возвращает расстояние между двумя точками;