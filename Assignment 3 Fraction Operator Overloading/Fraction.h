#pragma once

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

class Fraction
{
private:
	long numerator;
	long denominator;
	
public:
	Fraction(long Top = 0, long Bottom= 1);
	long gcd(long a, long b);
	long getBottom() const;
	long getTop() const;
	double toDouble() const;
	void normalize();
	const string toString() const;

	const Fraction operator-() ;
	const Fraction operator--() ;
	
	const Fraction operator ++() ;
	const Fraction operator ++(int maker) ;
	const Fraction operator --(int maker) ;
	
	const Fraction& operator-= (const Fraction& num);
	const Fraction& operator+= (const Fraction& num);
	

	
	friend const Fraction operator+(const Fraction & num1, const Fraction  & num2);
	friend const Fraction operator-(const Fraction & num1, const Fraction  & num2);
	friend const Fraction operator*(const Fraction & num1, const Fraction  & num2);
	friend const Fraction operator/(const Fraction & num1, const Fraction  & num2);

	friend bool operator == (const Fraction & num1, const Fraction  & num2);
	friend bool operator != (const Fraction & num1, const Fraction  & num2);
	friend bool operator>(const Fraction& left, const Fraction& right);

	friend ostream & operator <<(ostream & output, const Fraction & num);
	friend istream & operator >>(istream & input, Fraction & num);
};
#endif