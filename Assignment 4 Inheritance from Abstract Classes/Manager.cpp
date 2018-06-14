/*

CS2
Assignment 4

*/
#include "Manager.h"

Manager::Manager(string Fname, string Lname, double sal, string BTitle) : Employee(Fname, Lname) ,salary(sal), TitleOfBoss(BTitle)
{
	if (sal < 0)
	{
		cout << "Salary is negative, making it to positive" << endl;
		salary = sal * -1;
	}
	if (BTitle.length() < MIN_NUM_CHARS_NAMES)
	{
		cout << "\nTitle of boss cannot be less than 2 characters. " << endl << "The default value is used." << endl << endl;
		TitleOfBoss = "Boss'es Title not set";
	}
}

	const string Manager::getBossTitle() const
	{
		return TitleOfBoss;
	}
	const string Manager::getFirstName() const
	{
		return FirstName;
	}
	const string Manager::getFullName() const
	{
		return FirstName + ' ' + LastName;
	}
	const string Manager::getLastName() const
	{
		return LastName;
	}
	double Manager::getSalary() const
	{
		return salary;
	}
	void Manager::setBossTitle(const string & Title)
	{
		if (Title.length() < MIN_NUM_CHARS_NAMES)
		{
			cout << "Title of boss cannot be less than 2 characters. " << endl << "No change is made."  << endl;
			TitleOfBoss = TitleOfBoss;
		}
		else
		{
		TitleOfBoss = Title;
		}
		
	}
	void Manager::setFirstName(const string & Fname)
	{
		if (Fname.length() < MIN_NUM_CHARS_NAMES)
		{
			cout << "The new first name " << Fname << " is too short. There is no change."  << endl;
		}
		else
		{
		FirstName = Fname;
		}
		
	}
	void Manager::setLastName(const string & Lname)
	{
		if (Lname.length() < MIN_NUM_CHARS_NAMES)
		{
			cout << "The new last name " << Lname << " is too short. There is no change." << endl;
		}
		else
		{
		LastName = Lname;
		}
		
	}
	void Manager::setSalary(double sal)
	{
		if (sal < 0)
		{
			salary = sal * -1;
		}
		else
		{
		salary = sal;
		}
	}

	const string Manager::toString() const
	{
		ostringstream os;
		os << fixed << showpoint << setprecision(2);
		os << "-----------------------------" << endl;
		os << "Manager's Data:" << endl;
		os << "-----------------------------" << endl;
		os << "Name: " << FirstName << " " << LastName << endl;
		os << "Boss'es Title: " << TitleOfBoss << endl;
		os << "Salary: $" << salary << endl;
		os << "-----------------------------" ;
		return os.str();
	}

