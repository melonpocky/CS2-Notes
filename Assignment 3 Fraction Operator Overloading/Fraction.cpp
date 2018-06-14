#include "Fraction.h"

Fraction::Fraction(long Top, long Bottom) : numerator{Top}, denominator{Bottom}
{
	if (denominator == 0)
	{
		//cout << "Denominator cannot be set to 0" << endl;
		denominator = 1;
	}
		normalize();
}

long Fraction::gcd(long a, long b)
{
	int findGCD;
	if (b == 0 && a != 0)
	{
		cout << "Cannot divide by 0" << endl;
	}

	while (b != 0)
	{
		if (a < 0)
		{
			a = -1 *a;
		}
		else if (b < 0)
		{
			b = -1 * b;
		}
		findGCD = a % b;
		a = b;
		b = findGCD;
	}
	return a;
}
long Fraction::getBottom() const
{
	return denominator;
}
long Fraction::getTop() const
{
	return numerator;
}

const string Fraction::toString() const
{
	ostringstream os;

	os << fixed << showpoint << setprecision(4);
	if (denominator == 1)
	{
		os << numerator << endl;
	}
	else
	{
	os << numerator << "/"<< denominator << endl;
	}
	return os.str();
}
const Fraction Fraction::operator-()
{
	return Fraction(-numerator, -denominator);
}
const Fraction Fraction::operator--()
{
	numerator -= denominator;
	return *this;
}

const Fraction Fraction::operator ++()
{
	numerator += denominator;
	return *this;
}
const Fraction Fraction::operator ++(int maker) //postfix increment
{
	Fraction temp = *this;
	numerator += denominator;

	return temp;
}
const Fraction Fraction::operator --(int maker) //postfix increment
{	
	Fraction temp = *this;
	numerator -= denominator;

	return temp;
}

const Fraction operator+(const Fraction & num1, const Fraction  & num2)
{
	long number1;
	long number2;

	number1 = ((num1.numerator * num2.denominator) + (num2.numerator*num1.denominator));
	number2 = (num1.denominator*num2.denominator);

	return Fraction(number1, number2);
}
const Fraction operator-(const Fraction & num1, const Fraction  & num2)
{
	Fraction F;
	long number1;
	long number2;
	
	number1 = ((num1.numerator * num2.denominator) - (num2.numerator*num1.denominator));
	number2  = (num1.denominator*num2.denominator);

	return Fraction(number1, number2);
}
const Fraction operator*(const Fraction & num1, const Fraction  & num2)
{
	double num = (num1.numerator * num2.numerator);
	double den = (num1.denominator*num2.denominator);

	return Fraction(num, den);
}
const Fraction operator/(const Fraction & num1, const Fraction  & num2)
{
	double num = num1.numerator*num2.denominator;
	double den = num1.denominator*num2.numerator;

	return Fraction(num, den);
}

bool operator == (const Fraction & num1, const Fraction  & num2)
{
	return ((num1.numerator == num2.numerator) && (num1.denominator== num2.denominator));
}
bool operator != (const Fraction & num1, const Fraction  & num2)
{
	return !((num1.numerator == num2.numerator) && (num1.denominator == num2.denominator));
}
bool operator>(const Fraction& left, const Fraction& right)
{
	Fraction F;
	long num1;
	long denom1;
	long num2;
	long denom2;
	long LCD;
	int GCD = F.gcd(left.denominator, right.denominator);
	
	if (left.denominator == right.denominator)
	{
		return (left.numerator> right.numerator);
	}
	denom1 = left.denominator;
	denom2 = right.denominator;
	LCD = (denom1*denom2) / GCD;
	num1 = (LCD / denom1)*left.numerator;
	num2 = (LCD / denom2)*right.numerator;

	return (num1>num2);
}

ostream & operator<<(ostream & output, const Fraction & num)
{
	output << num.toString();
	return output;
}
istream & operator>>(istream & input, Fraction & num)
{
	double InNumerator = 0.0;
	double InDenominator = 0.0;

	if (&input == &cin)// populating the object from the keyboard
	{
		cout << "Enter the numerator part: ";
		input >> InNumerator;
		cout << "Enter the denominator part: ";
		input >> InDenominator;
	}
	else
	{
		input >> InNumerator >> InDenominator;
	}
	num = Fraction(InNumerator, InDenominator);

	return input;
}

const Fraction& Fraction::operator-= (const Fraction& num)
{
	numerator -= num.numerator;
	denominator -= num.denominator;
	return *this;
}
const Fraction& Fraction::operator+= (const Fraction& num)
{
	if (denominator == num.getBottom())
	{
		numerator += num.getTop();
	}
	else 
	{
		numerator = (numerator * num.getBottom()) + (num.getTop() * denominator);
		denominator *= num.getBottom();
	}
	normalize();
	return *this;
}

double Fraction::toDouble() const
{
	double num = static_cast<double> (numerator);
	double den = static_cast<double> (denominator);
	return num/den;
}

void Fraction::normalize() 
{
	int c;
	double f;
	c = gcd(numerator, denominator);
	
	
	if (numerator% c == 0 && denominator% c == 0)
	{
		denominator = denominator / c;
		numerator = numerator / c;
	
		if (numerator < 0 && denominator < 0)
		{
			numerator = -1 * numerator;
			denominator = -1 * denominator;
		}
		else if (numerator < 0 && denominator > 0)
		{
			numerator = numerator;
			denominator = denominator;
		}
		else if (numerator > 0 && denominator < 0)
		{
			numerator = -1 * numerator;
			denominator = -1 * denominator;
		}
		f = numerator / denominator;
	}
	else
	{
		if (numerator < 0 && denominator < 0)
		{
			numerator = -1 * numerator;
			denominator = -1 * denominator;
		}
		else if (numerator < 0 && denominator > 0)
		{
			numerator = numerator;
			denominator = denominator;
		}
		else if (numerator > 0 && denominator < 0)
		{
			numerator = -1 * numerator;
			denominator = -1 * denominator;
		}
		f = numerator / denominator;
	}
}