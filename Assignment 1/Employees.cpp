#include "Employees.h"

void Employees::setFirstName(string newFirstName)
{
	FirstName = newFirstName;
}
string Employees::getFirstName()
{
	return FirstName;
}

void Employees::setLastName(string newLastName)
{
	LastName = newLastName;
}
string Employees::getLastName()
{
	return LastName;
}

int Employees::getIDNumber()
{
	return IDnumber;
}
void Employees::setIDNumber(int IDNumber)
{
	IDnumber = IDNumber;
}

int Employees::getjobClassificiation()
{
	return jobClassification;
}
void Employees:: setjobClassification(int JobClassification)
{
	jobClassification = JobClassification;
}

int Employees::getYearsService()
{
	return yearsService;
}
void Employees::setYearsService(int YearsService)
{
	yearsService = YearsService;
}


int Employees::geteducationCode()
{
	return educationCode;
}
void Employees::seteducationCode(int EducationCode)
{
	educationCode = EducationCode;
}
