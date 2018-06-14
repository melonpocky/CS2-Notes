#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;
/*

CS2
Assignment 4

*/
class Employee
{
protected:
	string FirstName;
	string LastName;
	//static const size_t MIN_NUM_CHARS_NAMES = 3;
	static const int MIN_NUM_CHARS_NAMES = 2;
public:
	Employee(const string & Fname = "First name not set", const string & Lname = "Last name not set");
	
	/**Pure Virtual Functions**/
	virtual const string getFirstName() const = 0;
	virtual const string getLastName()const = 0;
	virtual const string getFullName()const = 0;
	
	virtual const string toString()const = 0;

	virtual void setFirstName(const string & Fname) = 0;
	virtual void setLastName(const string & Lname) = 0;

};
#endif