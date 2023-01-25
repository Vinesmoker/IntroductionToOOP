#include<iostream>
using namespace std;

constexpr auto delimiter = "_______________________________________________________________\n";

//#define DISTANCE_CHECK
//#define CONSTRUCTOR_CHECK
//#define ASSIGNMENT_CHECK_1
//#define ASSIGNMENT_CHECK_2
#define OPERATOR_RELOAD


class Point   // �������� ��������� ��� �����, �� ������� ����� ��� ������.
{// ������ � �������� ��� �������� ����������������� ��� ���������� ������ ������.
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
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return *this;
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
	double Distance(const Point& other)
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
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
};

double Distance(const Point& A, const Point& B)
{
	double xDist = A.GetX() - B.GetX();
	double yDist = A.GetY() - B.GetY();
	double dist = sqrt(xDist * xDist + yDist * yDist);
	return dist;
}
Point operator+(const Point& left, const Point& right)
{
	Point Res;
	Res.SetX(left.GetX() + right.GetX());
	Res.SetY(left.GetY() + right.GetY());
	return Res;
}
Point operator*(const Point& left, const Point& right)
{
	Point Res2;
	Res2.SetX(left.GetX() * right.GetX());
	Res2.SetY(left.GetY() * right.GetY());
	return Res2;
}

void main()
{
	setlocale(LC_ALL, "");
	/*
	Point A; // ���������� ��������� (����������) '�' ���������� Point;
	//������� ����� �������� ������������ ������ ��� ���������.
	A.x = 2;
	A.y = 3;
	cout << A.x << '\t' << A.y << endl;

	Point* pA = &A;
	cout << pA->x << '\t' << pA->y << endl;
	*/
#ifdef DISTANCE_CHECK
	Point A;
	A.SetX(2); A.SetY(3);
	Point B;
	B.SetX(7); B.SetY(8);
	Point C;
	C.SetX(10); C.SetY(12);
	cout << A.GetX() << "\t" << A.GetY() << "\t" << endl;
	cout << delimiter << endl;
	cout << "The distance between A and B: " << A.Distance(B) << endl;
	cout << delimiter << endl;
	cout << "The distance between A and C: " << A.Distance(C) << endl;
	cout << delimiter << endl;
	cout << "The distance between B and C: " << B.Distance(C) << endl;
	cout << delimiter << endl;
	cout << "The distance between B and C: " << Distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "The distance between B and C: " << Distance(B, C) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTOR_CHECK
	Point A; // Default constructor
	//cout << A.GetX() << "\t" << A.GetY() << endl;
	A.Print();

	Point B(2, 3);
	B.Print();

	Point C = 4; // Single-Argument constructor
	C.Print();

	Point D = C; // Copy constructor
	D.Print();
#endif // CONSTRUCTOR_CHECK

#ifdef ASSIGNMENT_CHECK_1
	//CopyAssignment
	Point A(2, 3); A.Print();
	Point B = A; B.Print();//CopyConstructor
	Point C; C = B; C.Print(); //Assignment operator  
#endif // ASSIGNMENT_CHECK_1

#ifdef ASSIGNMENT_CHECK_2
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	//Point(2, 3) - ����� ����� ������������ � �� ������� ��������� ���������� ������
	// ��������� ���������� ������� ���������� � �������� ������ ���������.
	cout << delimiter << endl;
#endif // ASSIGNMENT_CHECK2

#ifdef OPERATOR_RELOAD

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.Print();
	++C;
	C.Print();
	C++;
	C.Print();

#endif // OPERATOR_RELOAD

}