﻿#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);
class String
{
	int size;  // размер строки
	char* str; // адрес строки в динамическом массиве
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	// Constructers:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DegConstructor:\t\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1ArgConstructor:\t" << this << endl;
	}
	String(String&& other)noexcept
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr; // -- Указатель на 0
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	//Operators:
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << endl;
	}
	String& operator=(String&& other)noexcept
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr; // -- Указатель на 0
		cout << "MoveAssignment:\tt" << this << endl;
		return *this;
	}
	

	// Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String cat (left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

void main()
{
	setlocale(LC_ALL, "");
	//String str1(5);
	//str1.print();

	String str1 = "Hello";
	cout << str1 << endl; str1 = str1;

	String str2 = "World";
	cout << str2 << endl;

	String str3;
	str3 = str1 + " " + str2;
	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;

	String str4 = str1 + str2;
	cout << str4 << endl;

}