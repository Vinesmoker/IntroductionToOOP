#include<iostream>
using namespace std;

//#define DISTANCE
//#define DISTANCE_CHECK
//#define CONSTRUCTOR_CHECK
//#define ASSIGNMENT_CHECK_1
//#define ASSIGNMENT_CHECK_2

constexpr auto delimiter = "_______________________________________________________________\n";

class Point
{
private:
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
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
	/*
	void print()
	{
		cout << x << "\t" << y << endl;
	}
	*/
	/*
	double distance()
	{
		double dist_to = sqrt(pow(get_x(), 2) + pow(get_y(), 2));
		return dist_to;
	}
	*/

	// Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copyconstructor:" << this << endl;
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
	Point& operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	Point& operator--()
	{
		x--;
		y--;
		return *this;
	}
	Point& operator--(int)
	{
		Point old = *this;
		x--;
		y--;
		return old;
	}
	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}

	// Methods:
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
	return distance;
}
    //Operators
Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}
Point operator-(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() - right.get_x());
	res.set_y(left.get_y() - right.get_y());
	return res;
}
Point operator*(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() * right.get_x());
	res.set_y(left.get_y() * right.get_y());
	return res;
}
Point operator/(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() / right.get_x());
	res.set_y(left.get_y() / right.get_y());
	return res;
}
    //Comparison operators:
bool operator==(const Point& left, const Point& right)
{
	if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;
}
bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
	/*if (left.get_x() != right.get_x() && left.get_y() != right.get_y())
		return true;
	else
		return false;*/
}

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}
std::istream& operator>>(std::istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj(x, y);
	return is;
}

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello OOP!" << "\n\n";

#ifdef DISTANCE
	Point A;
	cout << "Point A coordinates:\t";
	A.set_x(2);
	A.set_y(3);
	A.print();
	cout << "The distance to point A:\t" << A.distance() << endl;

	cout << endl;
	//	Point* pA = &A;
	//	A.print();

	Point B;
	cout << "Point B coordinates:\t";
	B.set_x(6);
	B.set_y(9);
	B.print();
	cout << "The distance to point B:\t" << B.distance() << "\n\n";

	cout << "The distance between point A and B is: " << B.distance() - A.distance() << endl;
#endif // DISTANCE

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2); A.set_y(3);
	cout << "Point A coordinates: " << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7); B.set_y(8);
	cout << "Point B coordinates: " << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "The distance from A to B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "The distance from B to A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "The distance between B and A: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "The distance between B and B: " << distance(B, B) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTOR_CHECK
	Point A; // Default constructor
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B(2, 3);
	B.print();

	Point C = 4; // Single-Argument constructor
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTOR_CHECK

#ifdef ASSIGNMENT_CHECK_1
	//CopyAssignment
	Point A(2, 3);
	A.print();
	Point B = A; //CopyConstructor
	B.print();
	Point C; //DefaultConstrucnor
	C = B; //Assignment operator
	C.print();
#endif // ASSIGNMENT_CHECK_1

#ifdef ASSIGNMENT_CHECK2
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	cout << delimiter;
	A = B = C = Point(2, 3);
	cout << delimiter;
	A.print();

	cout << "Begin" << endl;
	Point(2, 3);
	cout << "End" << endl;
#endif // ASSIGNMENT_CHECK2

	
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(4, 5);
	cout << delimiter;
	Point C = A + B; C.print();
	cout << delimiter;
	Point D = B - A; D.print();
	cout << delimiter;
	C++; C.print();
	cout << delimiter;
	C--; C.print();
	cout << delimiter;
	cout << (A == B) << endl;
	cout << delimiter;
	cout << (A != B) << endl;
	cout << delimiter;
	A(22, 23); A.print();
	cout << delimiter;
	cout << A << endl;
	cout << delimiter;
	cout << "¬ведите координаты точки: "; cin >> A;
	cout << A << endl;
	cout << delimiter;
}