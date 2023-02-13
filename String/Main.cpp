#include"String.h"

#define BASE_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	String str(5);
	str.print();

	String str1 = "Hello";	//"Hello" - это строковая константа
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	//cout << "\n-----------------------------------------\n";
	//str1 += str2;
	//cout << str1 << endl;
	//cout << "\n-----------------------------------------\n";

	String str3;
	str3 = str1 + str2;	//Move constructor
	cout << str3 << endl;

	String str4 = str3;	//Copy constructor
	str4.print();
	//str1 = str3;
	//cout << str1 << endl;

	/*
	Deep copy:
	CopyConstructor;
	CopyAssignment
	------------------------------
	Shallow copy:
	MoveConstructor
	MoveAssignment
	other
	Move semantic C++11, C++03
	R-value reference
	------------------------------
	*/
#endif // BASE_CHECK

#ifdef CALLING_CONSTRUCTORS
	String str1;	//Default constructor
	str1.print();
	String str2 = "Hello";	//Single argument constructor
	str2.print();
	String str3 = str2;	//Copy constructor
	str3.print();
	String str4();	//Здесь не вызывается никакой конструктор, потому что НЕ создается объект,
	//Здесь объявлется функция str4(), которая не принимает никаких параметров,
	//и возвращает значение типа String.
//str4.print();	//str4 - это НЕ объект, это функция, а для функции нельзя вызвать метод.
//Если мы хотим явно вызвать конструктор по умолчанию, то это можно сделать так:
	String str5{};	//Явный вызов конструктора по умолчанию.
	str5.print();
	String str6{ 22 };
	str6.print();
	String str7{ "World" };
	str7.print();
	String str8{ str7 };	//Copy constructor  
#endif // CALLING_CONSTRUCTORS

}