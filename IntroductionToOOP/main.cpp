#include<iostream>
using namespace std;

//#define DISTACE_CHECK

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
	// Constructor:
	/*
	Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	*/
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Methods:
	/*
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;
	}
	*/
	double Distance(Point other)
	{
		double xDist = this->x - other.x;
		double yDist = this->y - other.y;
		double dist = sqrt(xDist * xDist + yDist * yDist);
		return dist;
	}
	void Print()const
	{
		cout << "\tX = " << x << "\tY = " << y << endl;
	}
	Point(double x =0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	
};
double Distance(Point A, Point B)
{
	double xDist = A.GetX() - B.GetX();
	double yDist = A.GetY() - B.GetY();
	double dist = sqrt(xDist * xDist + yDist * yDist);
	return dist;
}

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
#ifdef DISTACE_CHECK
	Point A;
	A.SetX(2); A.SetY(3);
	Point B;
	B.SetX(7); B.SetY(8);
	Point C;
	C.SetX(10); C.SetY(12);
	cout << A.GetX() << "\t" << A.GetY() << "\t" << endl;
	cout << "The disnance between A and B: " << A.Distance(B) << endl;
	cout << "The disnance between A and C: " << A.Distance(C) << endl;
	cout << "The disnance between B and C: " << B.Distance(C) << endl;
	cout << "The disnance between B and C: " << Distance(A, B) << endl;
#endif // DISTACE_CHECK

	Point A; // Default constructor
	//cout << A.GetX() << "\t" << A.GetY() << endl;
	A.Print();

	Point B(2, 3);
	B.Print();

	Point C = 4; // Single-Argument constructor
	C.Print();
}