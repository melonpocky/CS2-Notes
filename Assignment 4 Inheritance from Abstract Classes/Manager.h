#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
/*

CS2
Assignment 4

*/
class Manager : public Employee
{
protected:
	double salary;
	string TitleOfBoss;

public:
	Manager(string Fname = "First Name not set", string Lname = "Last name not set", double sal = 0.0, string BTitle = "Boss'es Title not set");
	virtual const string getBossTitle() const;
	virtual const string getFirstName() const;
	virtual	const string getFullName() const;
	virtual	const string getLastName() const;
	virtual	double getSalary() const;

	virtual	void setBossTitle(const string & Title);
	virtual	void setFirstName(const string & Fname);
	virtual	void setLastName(const string & Lname);
	virtual	void setSalary(double sal);

	virtual	const string toString() const;
};
#endif