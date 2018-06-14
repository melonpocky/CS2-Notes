#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


#include <stdio.h>
#include <stdlib.h>
using namespace std;

/**

11/14/17
**/
/** Program Statement
*This program will calculate the tax from the inputted gross
income of an individual alongside with the individual's salary after the tax reduction
From assignment sheet
"Write a program to read a person's name, filing status, and taxable income and write their state income tax.
Verify salary (positive numbers only) and status (can only be joint or single), if invalid data is entered terminate
the program with an error message. Pay special attention as how the tax is calculated."

*
***Analysis***

Data needed

**How much tax is deducted within a range of gross salary
How much money a single individual makes for single taxes
How much money individuals make for joint taxes
The name of the individual


Constants Given

Computed tax formula for various of ranges of Gross Salaries

Calculations

Assumptions

All numbers are assumed to be positive integers
The heading of our name and programming assignment is assumed to be in each printout
The user will input 'S','s','J','j' for filing status


Calculate

Calculate the amount of taxes owed after user inputs gross salary
Calculate net salary from the gross salary and taxes

Print Results

Name of the Individual
Filing Status of their tax form
Gross Salary of the Individual
Taxes that they owe (income tax)
Salary after taxes (net salary)
***End of Analysis***
/************************ Algorithm *****************************

Prompt user for file name and location
open file and verify
file is open
if verification failed
print error
if verified:
read name or first value of file
initialization
sum = 0
count = 0
print heading:
"Name"          setw (25)
"Status"        setw (13)
"Gross Salary"  setw (15)
"Total Taxes"   setw (15)
"Net Salary"    setw (15)

loop until the end of file
Read status and gross income
Verify status to be valid character (S/s/J/j)
Verify gross income to be valid number >= 0
If data verified

If filing status is single (using 'S' or 's'):
(Gross Salary > 0 and Gross Salary < 1710)
income tax = 0
Net Salary = Gross Salary - (income tax)

(Gross Salary > 1710 and Gross Salary < 20930)

income tax = 87.00 + (.03)(Gross Salary - 1710)
Net Salary = Gross Salary - (income tax)

(Gross Salary > 20930 and Gross Salary < 28790)

income tax = 742.00 + (.08)(Gross Salary - 20930)
Net Salary = Gross Salary - (income tax)

(Gross Salary > 28790)

income tax = 1449.60 + (.11)(Gross Salary - 28790)
Net Salary = Gross Salary - (income tax)

If filing status is joint(using 'J' or 'j'):
(Gross Salary > 0 and Gross Salary < 3420)

income tax = 0
Net Salary = Gross Salary - (income tax)

(Gross Salary > 3420 and Gross Salary < 47120)

income tax = 330.00 + (.04)(Gross Salary - 3420)
Net Salary = Gross Salary - (income tax)

(Gross Salary > 47120 and Gross Salary < 57580)

income tax = 1905.00 + (.09)(Gross Salary - 47120)
Net Salary = Gross Salary - (income tax)

(Gross Salary > 57580)

income tax = 2899.20 + (.11)(Gross Salary - 57580)
Net Salary = Gross Salary - (income tax)

print:
Name          setw (25)
Status        setw (13)
Gross Salary  setw (14)
Total Taxes   setw (14)
Net Salary
newline

totalGross += grossSalary;
totalNet += netSalary;
totalIncome += incomeTax;********

increase count by 1 (Read next value)

else
print
name    setw(25)
status  setw(13)
error   setw(15)

read name
end loop
if count > o
find and print averages for
grossSalary
netSalary
incomeTax
print
"Program terminated by request"
newline
"Thank you for using tax program.
newline
"Have a nice day."
else
print out to file of custom named in project folder and into monitor

************************ End of Algorithm *****************************/
/*output file doesnt have these character prints because we are not there yet*/
void PrintPattern()
{
	char printPattern = '=';
	cout << printPattern << printPattern << printPattern << printPattern;
	cout << printPattern << printPattern << printPattern << printPattern;
	cout << printPattern << printPattern << printPattern << printPattern;
	cout << printPattern << printPattern << printPattern << printPattern;
	cout << printPattern << printPattern << printPattern << printPattern;

}
void PrintLine()
{
	char printLine = '-';
	cout << printLine << printLine << printLine << printLine;
	cout << printLine << printLine << printLine << printLine;
	cout << printLine << printLine << printLine << printLine;
	cout << printLine << printLine << printLine << printLine;
	cout << printLine << printLine << printLine << printLine;
}

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


	}
	if (grossSalarySingle > 20930 && grossSalarySingle < 28790)
	{
		singleincomeTax = 742.40 + ((.08*(grossSalarySingle - 20930)));

	}

	if (grossSalarySingle > 28790)
	{
		singleincomeTax = 1449.60 + ((.11*(grossSalarySingle - 28790)));

	}


	return singleincomeTax;
}

double taxJoint(double grossSalaryJoint)
{
    double jointnetSalary = 0;
	double jointincomeTax = 0;
	double totalJNSalary = 0;
	double totalJITax = 0;
	double totalGSJoint = 0;

    if (grossSalaryJoint > 0 && grossSalaryJoint < 3420);
		{
			jointnetSalary = grossSalaryJoint;
		}
		if (grossSalaryJoint > 3420 && grossSalaryJoint < 47120)
		{
			jointincomeTax = 330.00 + ((.04*(grossSalaryJoint - 3420)));

		}
		if (grossSalaryJoint > 47120 && grossSalaryJoint < 57580)
		{
			jointincomeTax = 1905.00 + ((.09*(grossSalaryJoint - 47120)));

		}

		if (grossSalaryJoint > 57580)
		{
			jointincomeTax = 2899.20 + ((.11*(grossSalaryJoint - 57580)));

		}


return jointincomeTax;

}

void assignmentName()
{

	cout << "\t11/14/17\n" << endl;
}

bool fileVerify(ifstream& fin)
{
bool flag;
{
    string fileName;

    cout << "\nEnter file name (include path if necessary): ";
	getline(cin, fileName);
	fin.open(fileName.c_str());
    if (fin.fail())
	{
		return false;
	}
	else
	{
	    return true;
	}


}
}

int main() {

	string		First_Name, Last_Name;
	string		Name, fileName;
	string		Error;
	string      status;

	ofstream	fout;
	ifstream	fin;

	double grossSalary, totalGross, averageGrossSal;
	double incomeTax, totalIncome, averageIncome;
	double netSalary, totalNet, averageNetSal;
	double sum = 0;

    double totalIncomeJoint;
    double totalIncomeSingle;
	long count = 0;

	grossSalary = 0;
	netSalary = 0;
	incomeTax = 0;
	averageIncome = 0;
	averageGrossSal = 0;
	averageNetSal = 0;
	totalNet = 0;
	totalIncome = 0;
	totalGross = 0;

assignmentName();

fileVerify(fin);
getline(fin, Name);



cout << left << setprecision(2) << fixed << showpoint;
	cout << "\n" << setw(25) << "Name"
		<< setw(13) << "Status"
		<< setw(15) << "Gross Salary"
		<< setw(15) << "Total Taxes"
		<< setw(15) << "Net Salary" << endl;
	PrintPattern();
	PrintPattern();
	PrintPattern();
	PrintPattern();
	cout << "\n";


	while (!fin.eof())
	{
		fin >> status;
		fin >> grossSalary;

		if (status != "J" && status != "j" && status != "S" && status != "s")
		{
			Error = "is invalid input";
		}

		else if (grossSalary < 0)
		{
			if (status == "S" || status == "s")
			{
				status = "Single";
			}
			if (status == "J" || status == "j")
			{
				status = "Joint";
			}
			Error = "Negative Salary is invalid.";
		}

		else {

			if (status == "S" || status == "s")
			{
                status = "Single";
				float taxSingle(grossSalary);
				netSalary = grossSalary - taxJoint(grossSalary);
			}
			if (status == "J" || status == "j")
			{
                status = "Joint";
                float taxJoint(grossSalary);
                netSalary = grossSalary - taxSingle(grossSalary);
			}

			Error = "";
			totalGross += grossSalary;
            totalNet  += netSalary;
            totalIncomeJoint += taxJoint(grossSalary);
            totalIncomeSingle += taxSingle(grossSalary);

			count++;

		}/**else**/
		if (Error == "")
		{

			cout << endl << setw(25) << Name
				<< setw(13) << status;

				if (status == "Joint")
				{
				    cout    << "$" << setw(14) << grossSalary
                            << "$" << setw(14) << taxJoint(grossSalary)
                            << "$" << netSalary << endl;
				}

                if (status == "Single")
				{
				    cout    << "$" << setw(14) << grossSalary
                            << "$" << setw(14) << taxSingle(grossSalary)
                            << "$" << netSalary << endl;
				}

		}
		else
		{
			cout << endl << setw(25) << Name << setw(13) << status << setw(15) << Error << endl;

		}

		fin.ignore(10, '\n');
		getline(fin, Name);

	}
	if (count > 0)
	{


		double averageGrossSal = totalGross / count;
        double averageIncome = (totalIncomeJoint+totalIncomeSingle)/count;
        double averageNetSal = totalNet / count;

		PrintLine();
		PrintLine();
		PrintLine();
		PrintLine();

		cout << endl << setw(38) << "Averages: "
                << "$" << setw(14) << averageGrossSal
                << "$" << setw(14) <<   averageIncome
                << "$" <<  averageNetSal << endl;

		cout << "\nProgram terminated on request.\n";
		cout << "Thank you for using tax program.\n";
		cout << "\n" << "Have a nice day.";


		fin.close();
	}
	else
	{
		cout << "No data was processed, data file is empty.\n" << endl;

	}

	cin.ignore(10, '\n');
	getchar();
	return 0;

}

