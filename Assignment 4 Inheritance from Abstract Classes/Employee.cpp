/*

CS2
Assignment 4

*/
#include "Employee.h"

Employee::Employee(const string & Fname, const string & Lname) : FirstName(Fname), LastName(Lname)
{
	if (FirstName.length() < MIN_NUM_CHARS_NAMES)
	{
		cout << "\nThe first name " << FirstName << " does not have enough characters." << endl
			<< "We will set first name to a default value of \"First name not set.\"" << endl;
		FirstName = "First name not set";
	}
	if (LastName.length() < MIN_NUM_CHARS_NAMES)
	{
		cout << "\nThe last name " << LastName << " does not have enough characters." << endl
			<< "We will set last name to a default value of \"Last name not set.\"" << endl;
		LastName = "Last name not set";
	}
}

