#include <iostream>
#include <fstream>

#include <iomanip>
#include <string>

#include <stdio.h>
#include <stdlib.h>

using namespace std;
double taxSingle(double grossSalarySingle)
{

	double singlenetSalary = 0;
	double singleincomeTax = 0;
	if (grossSalarySingle >= 0 && grossSalarySingle < 1710)
	{
		singlenetSalary = grossSalarySingle;
		singleincomeTax = 0;
	}
	if (grossSalarySingle > 1710 && grossSalarySingle < 20930)
	{
		singleincomeTax = 87.00 + ((.03*(grossSalarySingle - 1710)));
		singlenetSalary = grossSalarySingle - singleincomeTax;

	}
	if (grossSalarySingle > 20930 && grossSalarySingle < 28790)
	{
		singleincomeTax = 742.40 + ((.08*(grossSalarySingle - 20930)));
		singlenetSalary = grossSalarySingle - singleincomeTax;
	}

	if (grossSalarySingle > 28790)
	{
		singleincomeTax = 1449.60 + ((.11*(grossSalarySingle - 28790)));
		singlenetSalary = grossSalarySingle - singleincomeTax;
	}
	cout << setw(15) <<"Single" << "$"
				<< setw(19) << grossSalarySingle << "$"
				<< setw(14) << singleincomeTax << "$"
				<< singlenetSalary << endl;
	return 0;
}

double taxJoint(double grossSalaryJoint)
{
    double jointnetSalary = 0;
	double jointincomeTax = 0;
    if (grossSalaryJoint > 0 && grossSalaryJoint < 3420);
		{
			jointnetSalary = grossSalaryJoint;
		}
		if (grossSalaryJoint > 3420 && grossSalaryJoint < 47120)
		{
			jointincomeTax = 330.00 + ((.04*(grossSalaryJoint - 3420)));
			jointnetSalary = grossSalaryJoint - jointincomeTax;

		}
		if (grossSalaryJoint > 47120 && grossSalaryJoint < 57580)
		{
			jointincomeTax = 1905.00 + ((.09*(grossSalaryJoint - 47120)));
			jointnetSalary = grossSalaryJoint - jointincomeTax;
		}

		if (grossSalaryJoint > 57580)
		{
			jointincomeTax = 2899.20 + ((.11*(grossSalaryJoint - 57580)));
			jointnetSalary = grossSalaryJoint - jointincomeTax;

		}
		cout << setw(15) <<"Joint" << "$"
				<< setw(19) << grossSalaryJoint << "$"
				<< setw(14) << jointincomeTax << "$"
				<< jointnetSalary << endl;
	return 0;
}


void PrintHeading()
{
cout << left << showpoint << setprecision(2) << left << fixed << endl;
cout << setw(20) << "Name" << setw(15) << "Status" << setw(20) << "Gross Salary" << setw(15) << "Taxes" << setw(15) << "Net Salary" << endl;

}
void PrintPattern()
{
	char printPattern = '=';
	cout << printPattern << printPattern << printPattern << printPattern;
	cout << printPattern << printPattern << printPattern << printPattern;
	cout << printPattern << printPattern << printPattern << printPattern;
	cout << printPattern << printPattern << printPattern << printPattern;
	cout << printPattern << printPattern << printPattern << printPattern;

}

int main() {
	string firstName;
	string lastName;

	double grossSalary;
	double incomeTax;
	double netSalary;

	char status;
	netSalary = 0;
	incomeTax = 0;

	cout << "\tProgramming Assignment" << endl;
	cout << "\tMaya Zeng" << endl;
	cout << "\tComputer Science 1\n" << endl;

	cout << "Enter your name: ";
	getline(cin, firstName, ' ');
	getline(cin, lastName);

	cout << firstName << ", enter your taxable income: $";
	cin >> grossSalary;
	while (grossSalary < 0)

	{

		cout << "Taxable Income must be a positive integer" << endl;
		cout << "Enter your taxable income: $";
		cin >> grossSalary;

	}

	cout << "What is your filing status? (Enter S for single or J for joint):";
	cin >> status;

	while (status != 'J' && status != 'j' && status != 'S' && status != 's')

	{

		cout << "Must write S or J for status" << endl;
		cout << "What is your filing status? (Enter S for single or J for joint):";
		cin >> status;

	}


	/***Single Taxpayers***/

	if (status == 'S' || status == 's')
	{

		PrintHeading();

		PrintPattern();
		PrintPattern();
		PrintPattern();
		PrintPattern();
		cout << "\n";
		cout << setw(20) << lastName + "," + firstName;

		cout << taxSingle(grossSalary)<< endl;
	}


	/***Joint Taxpayer***/

	if (status == 'J' || status == 'j')
	{


		PrintHeading();

		PrintPattern();
		PrintPattern();
		PrintPattern();
		PrintPattern();
		cout << "\n";
		cout << setw(20) << lastName + "," + firstName;

		cout << taxJoint(grossSalary)<< endl;

	}

	cout << "Press Enter to continue" << endl;
	cin.ignore();
	getchar();
	return 0;

}
