#include <iostream>
#include <string>
#include <fstream>
#define CAP 0
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using namespace std;
struct Employee {
	string     	FirstName, LastName;
	char  		status;
	int	      	grossSalary;
};
bool open_file(ifstream &Fin);

bool Equal(Employee S1, Employee S2);
void Print_info(Employee);		 //  Prototype
void Read_info1(Employee &);	 //  Prototype
Employee Read_info(void);	//  Prototype

							//char grade_it(float);

void read_emp(ifstream & fin, Employee  &Temp);
int read_emp_List(Employee list[], int size);
void Print_list(Employee list[], int size);


void ProcessList(Employee list[], int size);
int main()
{
	struct

	vector <Employee> EmployeevectorName ; //treat like an array add and delete things
    struct Employee input;
    string FirstName;
	string LastName;
int i =0;
    int size;

	char status;
	int grossSalary;

	Employee	s1, list[CAP];
    size = read_emp_List(list, CAP);


	cout << "Adding a New Employee" << endl;
	cout << "\nEnter New Employee First Name:\t\t";
	cin >> input.FirstName;
	cout << "\nEnter New Employee Last Name:\t\t";
	cin >> input.LastName;
	cout << "\nEnter New Employee Tax Status:\t\t";
	cin >> input.status;
	cout << "\nEnter New Employee Gross Salary:\t";
	cin >> input.grossSalary;

    //cout << EmployeevectorName[0].FirstName << endl;


if (EmployeevectorName[i].FirstName     == s1.FirstName  &&
    EmployeevectorName[i].LastName      == s1.LastName &&
    EmployeevectorName[i].status        == s1.status &&
    EmployeevectorName[i].grossSalary   == s1.grossSalary)
cout << "Already have Employee here" << endl;

else
	EmployeevectorName.push_back({input });

	return 0;
}


bool Equal(Employee S1, Employee S2)
{
	if (S1.LastName == S2.LastName  &&
		S1.FirstName == S2.FirstName &&
		S1.status == S2.status&&
		S1.grossSalary == S2.grossSalary
		)
		return true;
	else
		return false;
}

void Print_info(Employee temp) //used in main employee menu
{
	double incomeTax = 0;
	double netSalary = 0;

	string statusSoJ;

	if (temp.status == 'J' || temp.status == 'j')
	{
		statusSoJ = "Joint";

		if (temp.grossSalary > 0 && temp.grossSalary < 3420)
		{
			netSalary = temp.grossSalary;
			incomeTax = 0;
		}
		if (temp.grossSalary > 3420 && temp.grossSalary < 47120)
		{
			incomeTax = 330.00 + ((.04*(temp.grossSalary - 3420)));
			netSalary = temp.grossSalary - incomeTax;
		}
		if (temp.grossSalary > 47120 && temp.grossSalary < 57580)
		{
			incomeTax = 1905.00 + ((.09*(temp.grossSalary - 47120)));
			netSalary = temp.grossSalary - incomeTax;
		}
		if (temp.grossSalary > 57580)
		{
			incomeTax = 2899.20 + ((.11*(temp.grossSalary - 57580)));
			netSalary = temp.grossSalary - incomeTax;
		}


	}
	if (temp.status == 'S' || temp.status == 's')
	{
		statusSoJ = "Single";

		if (temp.grossSalary >= 0 && temp.grossSalary < 1710)
		{
			netSalary = temp.grossSalary;
			incomeTax = 0;
		}
		if (temp.grossSalary > 1710 && temp.grossSalary < 20930)
		{
			incomeTax = 87.00 + ((.03*(temp.grossSalary - 1710)));
			netSalary = temp.grossSalary - incomeTax;

		}
		if (temp.grossSalary > 20930 && temp.grossSalary < 28790)
		{
			incomeTax = 742.40 + ((.08*(temp.grossSalary - 20930)));
			netSalary = temp.grossSalary - incomeTax;
		}
		if (temp.grossSalary > 28790)
		{
			incomeTax = 1449.60 + ((.11*(temp.grossSalary - 28790)));
			netSalary = temp.grossSalary - incomeTax;
		}

	}
	if (temp.status != 'S' && temp.status != 's' && temp.status == 'J' && temp.status == 'j')
		statusSoJ = "Invalid Tax Status";

	cout << "\nEmployee name:\t\t\t";
	cout << temp.FirstName << " " << temp.LastName;
	cout << "\nEmployee Tax Status:\t\t" << statusSoJ;
	cout << "\nEmployee Gross Salary:\t\t";
	cout << temp.grossSalary;
	cout << "\nEmployee Income Tax:\t\t" << incomeTax;

	cout << "\nEmployee Net Salary:\t\t" << netSalary;

}
Employee Read_info(void) //used in main employee menu
{
	Employee  Temp;
	cout << "Enter first name: ";
	getline(cin, Temp.FirstName);
	cout << "Enter last name: ";
	getline(cin, Temp.LastName);
	cout << "Enter Tax Status (S/s for Single, J/j for joint): ";
	cin >> Temp.status;
	cout << "Enter Gross Salary: ";
	cin >> Temp.grossSalary;

	cin.ignore(10, '\n');
	return(Temp);
}
void Read_info1(Employee  &Temp) //used in main employee menu
{
	cout << "Enter first name: ";
	getline(cin, Temp.FirstName);
	cout << "Enter last name: ";
	getline(cin, Temp.LastName);
	cout << "Enter Tax Status (S/s for Single, J/j for joint): ";
	cin >> Temp.status;
	cout << "Enter Gross Salary: ";
	cin >> Temp.grossSalary;

	cin.ignore(10, '\n');
}

int read_emp_List(Employee list[], int size) //established in main file
{
	ifstream	fin;
	int	i = 0;
	if (open_file(fin))
	{

		read_emp(fin, list[i]);
		while (!fin.eof())
		{
			i++;
			if (i == size)
				break;
			read_emp(fin, list[i]);
		}
		fin.close();
	}
	return i;
}
bool open_file(ifstream &Fin) //used in main employee menu
{
	string    file_name;
	cout << "Enter file name: ";
	cin >> file_name;
	cin.ignore(10, '\n');
	Fin.open(file_name.c_str());
	if (Fin.fail())
		return false;
	else
		return true;
}

void read_emp(ifstream & fin, Employee  &Temp) //used in main employee menu
{

	getline(fin, Temp.FirstName, ' ');

	getline(fin, Temp.LastName, ' ');

	fin >> Temp.status;

	fin >> Temp.grossSalary;

	fin.ignore(10, '\n');
}
