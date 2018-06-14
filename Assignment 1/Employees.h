#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class Employees {
private:

	string     	FirstName, LastName;
	char  		EmployeeCode;
	int	      	IDnumber;
	int 		jobClassification;
	int 		yearsService;
	int 		educationCode;
	double		grossSalary;
	string		jobType;

public:

	//all set functions void setting variables not returning
	void setFirstName(string newFirstName);
	string getFirstName();

	void setLastName(string newLastName);
	string getLastName();

	int getIDNumber();
	void setIDNumber(int IDNumber);

	int getjobClassificiation();
	void setjobClassification(int jobClassification);

	int getYearsService();
	void setYearsService(int yearsService);

	int geteducationCode();
	void seteducationCode(int educationCode);

	Employees::Employees() {

		FirstName = "No First Name";
		LastName = "No Last Name";
		EmployeeCode = 0;
		IDnumber = 0000;
		jobClassification = 0;
		yearsService = 0;
		educationCode = 0;
		grossSalary = 0;
		jobType = "none";
		
	}
	Employees::Employees(string FS, string LS, int EC, int IDN, int JC, int YS ,double GS, string JT) {
		FirstName = FS;
		LastName = LS;
		EmployeeCode = EC;
		IDnumber = IDN;
		jobClassification = JC;
		yearsService = YS;
		educationCode = EC;
		grossSalary = GS;
		jobType = JT;
	
	}


};

//constrcutor takes in the argument and takes in all the variables within the class
#endif // !EMPLOYEE_H
