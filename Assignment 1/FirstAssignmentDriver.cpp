
#include "Employees.h"

using namespace std;
const int CAP = 30;

struct Employee {
	string     	FirstName, LastName;
	char  		EmployeeCode;
	int	      	IDnumber;
	int 		jobClassification;
	int 		yearsService;
	int 		educationCode;
	double		grossSalary;
	string		jobType;
};

void assignmentName()
{
	cout << "First Assignment" << endl;
	//Feb 18 2018
}

double jobClass(int jobClassification, int basePay)
{
	double jobClassPay = 0;

	if (jobClassification == 1)
	{
		jobClassPay = (basePay * .05) + basePay;
	}
	if (jobClassification == 2)
	{
		jobClassPay = (basePay * .1) + basePay;
	}
	if (jobClassification == 3)
	{
		jobClassPay = (basePay * .2) + basePay;
	}

	return jobClassPay;
}

double yearsPay(int yearsService, int basePay)
{
	double totalyearsPay = 0;
	double yearsServed = 0;

	if (yearsService> 0 && yearsService <= 10)
	{
		totalyearsPay = (basePay* .05);
	}
	if (yearsService > 10)
	{
		totalyearsPay = basePay*.05;
		yearsServed = yearsService - 10;
		totalyearsPay += (basePay *(yearsServed * .01));
	}

	if (yearsService < 0 || yearsService > 50)
	{
		totalyearsPay = 0;
		basePay = 0;
	}

	return totalyearsPay;
}

double EducationCode(int educationCode, int basePay)
{
	double basePayEdu = 0;

	if (educationCode == 1)
	{
		basePayEdu = basePay;
	}
	if (educationCode == 2)
	{
		basePayEdu = basePay*.05;
	}
	if (educationCode == 3)
	{
		basePayEdu = basePay*.12;
	}
	if (educationCode == 4)
	{
		basePayEdu = basePay*.2;
	}

	return basePayEdu;
}


bool open_file(ifstream &Fin);					//utility function
bool output_file(ofstream &Fout);				//utility function
void read_emp(ifstream & fin, Employee  &Temp); //utility function
int read_emp_List(Employee list[], int size);	//utility function

void Print_EmployeeOne(Employee List[], int size);
void Print_list(Employee list[], int size);
void foutPrint_list(Employee list[], int size, ofstream &fout);


void B_Sort(Employee List[], int size);
void A_Sort(Employee List[], int size);
void C_Sort(Employee List[], int size);
void ABsort(Employee List[], int size);
void foutABsort(Employee List[], int size, ofstream &fout);
int Search(Employee List[], int size, string Target);


char menu()
{
	char numberMenu;
	cout << endl << endl;
	cout << "Please press a Letter for which option you want to do\n";

	cout << "C.Sort List of Employees from File \n";

	cout << "E.Search and Print Employee Details \n";
	cout << "\tMust input Last Name and ID number of Employee\n";

	cout << "I.Exit\n";

	cout << "Enter response here: ";
	cin >> numberMenu;
	cout << endl;
	return numberMenu;
}

int main()
{
	
	Employee list[CAP]; //array
	int		size;
	ofstream fout;
	char numberMenu;
	assignmentName();
	size = read_emp_List(list, CAP);
	do
	{
		numberMenu = menu();
		switch (numberMenu)
		{
`
		case 'C':
		case 'c':
			cout << "This is case C/c" << endl;
			cin.ignore(10, '\n');

			if (size > 0)
			{
				output_file(fout);
				ABsort(list, size);
				foutABsort(list, size, fout);
			}

			else
				cout << "\nNo data, file was empty.\n\n";

			system("pause");
			break;

		case 'E':
		case 'e':
			cout << "This is case E/e" << endl;
			cout << "Searches the list of employee and prints all the details of an employee to the monitor \n";
			cout << "(Prompt user for last name and ID of employee)\n";

			cin.ignore(10, '\n');
			Print_EmployeeOne(list, size);
			break;

		case 'I':
		case 'i':

			cout << "\n\n\t\tEnd of Program.\n";
			break;

		default:
			cout << "\n\n\t\tNot a valid choice.\n"
				<< "Try again.\n";
		}
		cout << "\n\n";
		cin.ignore(10, '\n');
		cout << "Press enter to continue\n";
		getchar();
		system("cls");

	} while (numberMenu != 'I' && numberMenu != 'i');

	return 0;
}

void Print_list(Employee list[], int size)
{
	int i = 0;
	int basePay = 0;
	string jobClassficationError;
	string employeeCodeError;
	string EducationCodeError;
	string yearsServiceError;
	
	double jobClassFunction = 0;
	double educationFunction = 0;
	double yearsPayFunction = 0;

	cout << left << setprecision(2) << fixed << showpoint;
	cout << endl;
	cout << setw(20) << "Name" << setw(10) << "ID#" << setw(20) << "Job Type" << "Gross Salary" << endl << endl;
	
	for (int i = 0; i < size; i++)
	{
		string full = list[i].FirstName + ' ' + list[i].LastName;
		
		if (list[i].FirstName == "")
		{
			cout << "";
		}
		
		else if (list[i].yearsService >= 50)
		{
			yearsServiceError = "Invalid Years Served";
			string full = list[i].FirstName +' '+ list[i].LastName;
			cout << setw(20) << full << setw(10) << list[i].IDnumber << setw(20)  << yearsServiceError << "\n\n";
			list[i].grossSalary = 0;
		}

		else if (list[i].EmployeeCode != 'S' &&
			list[i].EmployeeCode != 'O' 
			&& list[i].EmployeeCode != 'M' )
		{
			employeeCodeError = "Invalid Employee Code";
			cout << setw(20) << full << setw(10) << list[i].IDnumber << setw(20) << employeeCodeError << "\n\n";
			list[i].grossSalary = 0;
		}

		else if (list[i].jobClassification <= 0 || list[i].jobClassification > 3)
		{
			jobClassficationError = "Invalid Job Classification";
			cout << setw(20) << full << setw(10) << list[i].IDnumber << setw(20) << jobClassficationError << "\n\n";
			list[i].grossSalary = 0;
		}

		else if (list[i].educationCode <= 0 || list[i].educationCode > 4)
		{
			EducationCodeError = "Invalid Education Code";
			cout << setw(20) << full << setw(10) << list[i].IDnumber << setw(20) << EducationCodeError << "\n\n";
			list[i].grossSalary = 0;
		}
		

		else if (list[i].EmployeeCode == 'S' ||
			list[i].EmployeeCode == 'O' ||
			list[i].EmployeeCode == 'M')
		{
			if (list[i].EmployeeCode == 'S')
			{
				basePay = 800;
				list[i].jobType = "Factory Worker";

				jobClassFunction = jobClass(list[i].jobClassification, basePay);
				yearsPayFunction = yearsPay(list[i].yearsService, basePay);
				educationFunction = EducationCode(list[i].educationCode, basePay);

				list[i].grossSalary = jobClassFunction + yearsPayFunction + educationFunction;
			}

			else if (list[i].EmployeeCode == 'O')
			{
				basePay = 1000;
				list[i].jobType = "Office Worker";

				jobClassFunction = jobClass(list[i].jobClassification, basePay);
				yearsPayFunction = yearsPay(list[i].yearsService, basePay);
				educationFunction = EducationCode(list[i].educationCode, basePay);

				list[i].grossSalary = jobClassFunction + yearsPayFunction + educationFunction;
			}

			else if (list[i].EmployeeCode == 'M')
			{
				basePay = 1500;
				list[i].jobType = "Management";

				jobClassFunction = jobClass(list[i].jobClassification, basePay);
				yearsPayFunction = yearsPay(list[i].yearsService, basePay);
				educationFunction = EducationCode(list[i].educationCode, basePay);

				list[i].grossSalary = jobClassFunction + yearsPayFunction + educationFunction;
			}

			cout << left << setprecision(2) << fixed << showpoint;
			cout	<< setw(20) << full 
					<< setw(10) << list[i].IDnumber
					<< setw(20) << list[i].jobType
					<< "$" << list[i].grossSalary << endl;

			cout << endl;

		}
	}
}


void foutPrint_list(Employee list[], int size, ofstream &fout)
{
	int i = 0;
	int basePay = 0;
	string jobClassficationError;
	string employeeCodeError;
	string EducationCodeError;
	string yearsServiceError;
	double jobClassFunction = 0;
	double educationFunction = 0;
	double yearsPayFunction = 0;

	fout << left << setprecision(2) << fixed << showpoint;
	fout << endl;
	fout << setw(20) << "Name" << setw(10) << "ID#" << setw(20) << "Job Type" << "Gross Salary" << endl;

	for (int i = 0; i < size; i++)
	{
		string full = list[i].FirstName + ' ' + list[i].LastName;

		if (list[i].FirstName == "")
		{
			fout << "";
		}

		else if (list[i].yearsService >= 50)
		{
			yearsServiceError = "Invalid Years Served";
			string full = list[i].FirstName + ' ' + list[i].LastName;
			fout << setw(20) << full << setw(10) << list[i].IDnumber << setw(20) << yearsServiceError << "\n\n";
			list[i].grossSalary = 0;
		}

		else if (list[i].EmployeeCode != 'S' &&
			list[i].EmployeeCode != 'O'
			&& list[i].EmployeeCode != 'M')
		{
			employeeCodeError = "Invalid Employee Code";
			fout << setw(20) << full << setw(10) << list[i].IDnumber << setw(20) << employeeCodeError << "\n\n";
			list[i].grossSalary = 0;
		}

		else if (list[i].jobClassification <= 0 || list[i].jobClassification > 3)
		{
			jobClassficationError = "Invalid Job Classification";
			fout << setw(20) << full << setw(10) << list[i].IDnumber << setw(20) << jobClassficationError << "\n\n";
			list[i].grossSalary = 0;
		}

		else if (list[i].educationCode <= 0 || list[i].educationCode > 4)
		{
			EducationCodeError = "Invalid Education Code";
			fout << setw(20) << full << setw(10) << list[i].IDnumber << setw(20) << EducationCodeError << "\n\n";
			list[i].grossSalary = 0;
		}


		else if (list[i].EmployeeCode == 'S' ||
			list[i].EmployeeCode == 'O' ||
			list[i].EmployeeCode == 'M')
		{
			if (list[i].EmployeeCode == 'S')
			{
				basePay = 800;
				list[i].jobType = "Factory Worker";

				jobClassFunction = jobClass(list[i].jobClassification, basePay);
				yearsPayFunction = yearsPay(list[i].yearsService, basePay);
				educationFunction = EducationCode(list[i].educationCode, basePay);

				list[i].grossSalary = jobClassFunction + yearsPayFunction + educationFunction;
			}

			else if (list[i].EmployeeCode == 'O')
			{
				basePay = 1000;
				list[i].jobType = "Office Worker";

				jobClassFunction = jobClass(list[i].jobClassification, basePay);
				yearsPayFunction = yearsPay(list[i].yearsService, basePay);
				educationFunction = EducationCode(list[i].educationCode, basePay);

				list[i].grossSalary = jobClassFunction + yearsPayFunction + educationFunction;
			}

			else if (list[i].EmployeeCode == 'M')
			{
				basePay = 1500;
				list[i].jobType = "Management";

				jobClassFunction = jobClass(list[i].jobClassification, basePay);
				yearsPayFunction = yearsPay(list[i].yearsService, basePay);
				educationFunction = EducationCode(list[i].educationCode, basePay);

				list[i].grossSalary = jobClassFunction + yearsPayFunction + educationFunction;
			}

			fout << left << setprecision(2) << fixed << showpoint;
			fout << setw(20) << full
				<< setw(10) << list[i].IDnumber
				<< setw(20) << list[i].jobType
				<< "$" << list[i].grossSalary << endl;

			fout << endl;
		}
	}
}
int Search(Employee List[], int size, string Target, int TargetNum)
{
	for (int i = 0; i < size; i++)
		if (List[i].LastName == Target)
			return i;
		else if (List[i].IDnumber == TargetNum)
			return i;
	return -1;
}

void Print_EmployeeOne(Employee List[], int size)
{
	string LastName;
	int IDnum;
	int		i;

	cout << "\nEnter Last Name of Employee: ";
	getline(cin, LastName);
	cout << "\nEnter ID Number of Employee: ";
	cin >> IDnum;

	i = Search(List, size, LastName, IDnum);
	if (i == -1)
		cout << LastName << " is not on the list.\n";
	else
	{
		cout << left << setprecision(2) << fixed << showpoint;
		cout << endl;
		cout << setw(20) << "Name" << setw(10) << "ID#" << setw(20) << "Job Type" << "Gross Salary" << endl;

		cout << setw(20) << List[i].FirstName + " " + LastName << setw(10) << List[i].IDnumber << setw(20) << List[i].jobType << "$" << List[i].grossSalary << endl;

		cout << endl;
	}
}

int read_emp_List(Employee list[], int size) //used in main employee menu
{
	ifstream	fin;
	int	i = 0;
	int excess = 0;
	if (open_file(fin))
	{
		read_emp(fin, list[i]);

		while (!fin.eof())
		{
			i++;

			if (fin.eof())
				break;
			else if (i == size)
				break;
			
			read_emp(fin, list[i]);
		
		}

		for (int i = 0; i < size; i++)
			//size_t can also be used in replacement of int
		{

			if (list[i].FirstName != "")
			{
				break;
			}
			else
				cout << "No Data in file" << endl;
			cout << "Please Press I to exit" << endl;
			return 0;
		}
		system("pause");
		fin.close();
	}
	return i;
}

bool open_file(ifstream &Fin) //used in main employee menu
{
	string    file_name;
	cout << "Enter file name: ";
	cin >> file_name;
	Fin.open(file_name);
	if (Fin.fail())
		return false;
	else
		return true;
}
bool output_file(ofstream &Fout)
{
	string file_Name;
	cout << "\nEnter output file name(Don't make it the same name as input file):";
	getline(cin, file_Name);
	Fout.open(file_Name.c_str());
	if (Fout.fail())
		return false;
	else
		return true;
}

void read_emp(ifstream & fin, Employee  &Temp) //used in main employee menu
{
	fin >> Temp.FirstName;
	fin >> Temp.LastName;

	fin >> Temp.EmployeeCode;
	fin >> Temp.IDnumber;
	fin >> Temp.jobClassification;
	fin >> Temp.yearsService;
	fin >> Temp.educationCode;
}

//need fout absort
void foutABsort(Employee List[], int size, ofstream &fout) {

	fout << "\n\t Unsorted List\n\n";
	foutPrint_list(List, size, fout);

	B_Sort(List, size);
	fout << "\n\t Sorted List - By Last Name\n\n";
	foutPrint_list(List, size, fout);

	A_Sort(List, size);
	fout << "\n\t Sorted List- By Gross Income\n\n";
	foutPrint_list(List, size, fout);

	C_Sort(List, size);
	fout << "\n\t Sorted List- By ID Number\n\n";
	foutPrint_list(List, size, fout);
}
void ABsort(Employee List[], int size) {
		cout << "\n\t Unsorted List\n\n";
		Print_list(List, size);

		B_Sort(List, size);
		cout << "\n\t Sorted List - By Last Name\n\n";
		Print_list(List, size);

		A_Sort(List, size);
		cout << "\n\t Sorted List- By Gross Income\n\n";
		Print_list(List, size);

		C_Sort(List, size);
		cout << "\n\t Sorted List- By ID Number\n\n";
		Print_list(List, size);
}

void A_Sort(Employee List[], int size) //sorts by income
{
	double netSalary = 0;
	double incomeTax = 0;
	bool	flag;
	Employee  Temp;
	do {
		flag = false;
		size--;
		for (int i = 0; i < size; i++)
		{
			if (List[i].grossSalary > List[i + 1].grossSalary)
			{
				Temp = List[i];
				List[i] = List[i + 1];
				List[i + 1] = Temp;
				flag = true;
			}
		}

	} while (flag);
}

void B_Sort(Employee List[], int size) //sorts by last name
{
	bool	flag;
	Employee  Temp;
	do {
		flag = false;
		size--;
		for (int i = 0; i < size; i++)
			if (List[i].LastName > List[i + 1].LastName) {
				Temp = List[i];
				List[i] = List[i + 1];
				List[i + 1] = Temp;
				flag = true;
			}
	} while (flag);
}

void C_Sort(Employee List[], int size) //sorts by ID Number
{
	bool	flag;
	Employee  Temp;
	do {
		flag = false;
		size--;
		for (int i = 0; i < size; i++)
			if (List[i].IDnumber > List[i + 1].IDnumber) {
				Temp = List[i];
				List[i] = List[i + 1];
				List[i + 1] = Temp;
				flag = true;
			}
	} while (flag);
}
