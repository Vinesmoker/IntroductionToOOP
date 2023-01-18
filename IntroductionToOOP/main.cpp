#include<iostream>
using namespace std;

class Point   // —оздава€ структуру или класс, мы создаем новый тип данных.
{//  лассы и струткры еще называют пользовательскими или составными типами данных.
	double x;
	double y;
public:
	double GetX()const
	{
		return x;
	}
	double GetY()const
	{
		return y;
	}
	void SetX(double x)
	{
		this->x = x;
	}
	void SetY(double y)
	{
		this->y = y;
	}
	// Methods:
	double Distance(Point other)
	{
		double xDist = this->x - other.x;
		double yDist = this->y - other.y;
		double dist = sqrt(xDist * xDist + yDist * yDist);
		return dist;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*
	Point A; // ќбъ€вление структуры (экземпл€ра) 'ј' структруры Point;
	//ќбъекты часто называют экземпл€рами класса или структуры.
	A.x = 2;
	A.y = 3;
	cout << A.x << '\t' << A.y << endl;

	Point* pA = &A;
	cout << pA->x << '\t' << pA->y << endl;
	*/
	Point A;
	A.SetX(2);A.SetY(3);
	Point B;
	B.SetX(7);B.SetY(8);
	cout << A.GetX() << "\t" << A.GetY() << "\t" << endl;
	cout << "The disnance between A and B: " << A.Distance(B) << endl;
}