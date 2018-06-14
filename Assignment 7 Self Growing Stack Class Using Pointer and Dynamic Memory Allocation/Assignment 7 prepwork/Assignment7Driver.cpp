#include "Employee.h"


//In real software must be passed by reference
//Passing by value to confirm that copy constructor works - Use pass by value of large objects only in educational setting
void printEmployee(Employee E);


int main()
{
	{
		Employee S1 = Employee("John", "Smith", 12, 12,12);
		Employee S2 = Employee();
		
		cout << "\nPrinting Employee S1.\n";
		cout << S1.toString();
		cout << "\nPrinting Employee S2.\n";
		cout << S2.toString();
		cout << "\nSetting Employee S1=S2.\n";
		S2 = S1;
		cout << "\nPrinting Employee S2 again.\n";
		cout << S2.toString();
		cout << "\nPrinting Employee S1 again.\n";
		cout << S1.toString();
		cout << "\nFrom Print Function\n";
		cout << "\nPrinting Employee S1.\n";
		printEmployee(S1);
		cout << "\nPrinting Employee S2.\n";
		printEmployee(S2);

	}
	system("pause");
	return 0;
}

void printEmployee(Employee E)
{
	cout << E.toString()  << endl;
}