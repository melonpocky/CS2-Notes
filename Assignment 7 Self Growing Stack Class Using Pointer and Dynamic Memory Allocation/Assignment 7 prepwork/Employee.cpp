#include "Employee.h"


Employee::Employee() : firstName("First Name not set"), lastName(new string("Last Name not set"))  ,hourWorked(0), PayRate(0), Salary(0)
{
	//lastName = new string("Last Name not set");
	cout << "From default constructor." << endl;
}
Employee::Employee(string fname , string lname ,int hrsWorked, double payR, double sal): firstName(fname), lastName(new string (lname)), hourWorked(hrsWorked), PayRate(payR), Salary(sal)
{
	//lastName = new string(lname);
	cout << "From explicit constructor." << endl;
}

void Employee::copy(const Employee & Other)
{
	//cout << "From Copy function.\n";
	if (this != &Other)
	{
		lastName = new string(*Other.lastName);
		firstName = Other.firstName;
		hourWorked = Other.hourWorked;
		PayRate = Other.PayRate;
		Salary = Other.Salary;
	}
}
//------------------------------------------------------------------
Employee::Employee(const  Employee & Other)
{
	cout << "From Copy constructor.\n";
	if (this != &Other)
	{
		copy(Other);
	}
}

//------------------------------------------------------------------
Employee& Employee::operator = (const Employee & Other)
{
	cout << "From assignment operator.\n";
	if (this != &Other)
	{
		delete lastName;
		copy(Other);
	}

	return *this;
}
//-----------------------------------------------------------------
Employee::~Employee()
{
	cout << "From destructor.\n";
	delete lastName;

}
//---------------------------------------------------------------------
const string Employee::toString() const
{
	ostringstream os;
	os << "Name = " << firstName << " " << *lastName << endl;
	os << "Pay Rate = " << PayRate << endl;
	os << "Hours Worked = " << hourWorked << endl;
	os << "Salary = " << Salary << endl;
	return os.str();

}
