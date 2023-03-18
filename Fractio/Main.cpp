#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left,const Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numenator)
	{
		this->numerator = numenator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "DefultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		//cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		//cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		//cout << "Destructor:\t\t" << this << endl;
	}

	//!!!!!!!!!!!!!!!!!!!!!!!!!! Operators:
	Fraction operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "CpoyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction& operator++()
	{
		integer++;
		numerator++;
		denominator++;
		return *this;
	}
	Fraction& operator++(int) 
	{
		Fraction last = *this;
		integer++;
		numerator++;
		denominator++;
		return last;
	}
	Fraction& operator--() 
	{
		integer--;
		numerator--;
		denominator--;
		return *this;
	}
	Fraction& operator--(int) 
	{
		Fraction last = *this;
		integer--;
		numerator--;
		denominator--;
		return last;
	}

	//!!!!!!!!!!!!!!!!!!!!!!!!!! Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper() 
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest = 0;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	/*Fraction result
	(
		left.get_numerator() *  right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left,const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}

//////////////// Comparison Operators//////////////////

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return 
		left.get_numerator() * right.get_denominator() == 
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction left, const Fraction right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >=
		right.get_numerator() * left.get_denominator();
}
bool operator<=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <=
		right.get_numerator() * left.get_denominator();
}

std::istream& operator>>(std::istream& input, Fraction& fraction)
{
	int integer, numerator, denominator;
	input >> integer >> numerator >> denominator;
	fraction = Fraction(integer, numerator, denominator);
	return input;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(2, 3);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
	Fraction E = D;
	E.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();

	//A = A * B;
	A *= B;
	A /= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

	cout << (Fraction(1, 2, 3) == Fraction(1, 2, 3)) << endl;
	cout << (Fraction(1, 2, 3) != Fraction(1, 2, 3)) << endl;
	Fraction A(1, 2, 3);
	++A; A.print();
	A++; A.print();
	--A; A.print();
	A--; A.print();
	cout << (Fraction(2, 2, 3) > Fraction(1, 2, 3)) << endl;
	cout << (Fraction(1, 1, 4) < Fraction(1, 2, 3)) << endl;
	cout << (Fraction(2, 2, 3) >= Fraction(1, 2, 3)) << endl;
	cout << (Fraction(1, 1, 4) <= Fraction(1, 2, 3)) << endl;
	cin >> A; A.to_proper();
	A.print();
}