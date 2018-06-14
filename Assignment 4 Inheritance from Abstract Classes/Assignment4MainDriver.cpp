#include "Employee.h"
#include "Manager.h"
/*

CS2
Assignment 4 

*/

int main()
{
	Manager M1;
	string FN;
	string LN;
	string BT;
	double salary;

	bool done = false;
	bool option = false;
while (!done)
{
	cout << "*************Main Menu*************" << endl
		<< "1. Create Manager instance from Keyboard" << endl
		<< "2. Print Manager to Console" << endl
		<< "3. Change Manager's Last Name" << endl
		<< "4. Change Manager's Salary" << endl
		<< "5. Change Manager's Bosses Title" << endl
		<< "6. Print only Manager's Name and Salary to Console" << endl
		<< "7. Print only Manager's Bosses Title to Console" << endl
		<< "8. Exit" << endl;
	int choice;

	cout << "Enter menu choice and press enter key: ";
	cin >> choice;


	if (choice == 1 || choice == 8)
	{
		option = true;
	}

	while (option != true)
	{
		cout << "Instance has not been created yet" << endl
			<< "Press 1 for creating Instance using Keyboard" << endl;

		cin >> choice;
		if (choice == 1 || choice == 8)//create account from keyboard entry
		{
			option = true;
		}
	}
	if (choice == 8)
	{
		done = true;
	}
	else if (choice == 1) //Create Manager instance from Keyboard
	{
		cout << "Enter First Name of Manager" << endl;
		cin >> FN;
		M1.setFirstName(FN);
		cout << "Enter Last Name of Manager" << endl;
		cin >> LN;
		M1.setLastName(LN);
		cout << "Enter Salary of Manager" << endl;
		cin >> salary;
		M1.setSalary(salary);
		if (salary < 0)
		{
			cout << "Negative Salary entered, going to be changed to positive" << endl;
		}
		cout << "Enter Title of Manager" << endl;
		cin >> BT;
		
		M1.setBossTitle(BT);
	}
	else if (choice == 2)//Print Manager to Console
	{
		cout << M1.toString() << endl;
	}
	else if (choice == 3)//Change Manager's Last Name
	{
		cout << "Enter new last name for Manager" << endl;
		cin >>  LN;
		M1.setLastName(LN);

		M1.toString();
	}
	else if (choice == 4)//Change Manager's Salary
	{
		cout << "Enter new salary for Manager" << endl;
		cin >> salary;
		M1.setSalary(salary);
		if (salary < 0)
		{
			cout << "Negative Salary entered, going to be changed to positive salary" << endl;
		}
		M1.toString();
	}
	else if (choice == 6) //Print only Manager's Name and Salary to Console
	{
		
		cout <<"Manager's Name: "<< M1.getFullName() << endl;
		cout << "Manager's Salary: $" << M1.getSalary() << endl;

	}
	else if (choice == 5) //Change Manager's Bosses Title
	{
		cout << "Enter new Title for Manager" << endl;
		cin >> BT;
		M1.setBossTitle(BT);
		
		M1.toString();
	}
	else if (choice == 7) //Print only Manager's Bosses Title to Console
	{
		cout << "Manager's Title: " << M1.getBossTitle() << endl;
	}

	else
	{
		cout << "Choice Invalid, enter new choice number" << endl;
		cin >> choice;
	}
}
return 0;
}
/*Testing Classes Below*/
int main4()
{
	Manager M1;
	cout << M1.toString() << endl;
	Manager M2("F", "L", -200.0, "T");
	cout << M2.toString() << endl;
	Manager M3("Fran", "Lamar", 4000.99, "Vice President");
	cout << M3.toString() << endl;
	system("pause");

	//Test setLastName
	cout << "\nTesting setLastName" << endl;

	Manager M4("Fran", "Lamar", 4000.99, "Vice President");
	cout << M4.toString() << endl;
	M4.setLastName("P");
	cout << M4.toString() << endl;
	M4.setLastName("Prichard");
	cout << M4.toString() << endl;
	system("pause");

	//Test setFirstName
	cout << "\nTesting setFirstName" << endl;
	Manager M5("Fran", "Lamar", 4000.99, "Vice President");
	cout << M5.toString() << endl;
	M5.setFirstName("M");
	cout << M5.toString() << endl;
	M5.setFirstName("Lisa");
	cout << M5.toString() << endl;
	system("pause");

	//Test Pure Virtual 
	cout << "\nTesting Pure Virtual" << endl;
	Manager M6("Fran", "Lamar", 4000.99, "Vice President");
	cout << "First Name: " << M6.getFirstName() << endl;
	cout << "Last Name: " << M6.getLastName() << endl;
	cout << "Full Name: " << M6.getFullName() << endl;
	system("pause");

	// Test Boss Title
	cout << "\nTesting Boss Title" << endl;
	Manager M7("Fran", "Lamar", 4000.99, "Vice President");
	M7.setSalary(-6000.55);
	M7.setBossTitle("X");
	cout << "Current Salary: $" << M7.getSalary() << endl;
	cout << "Current title of boss: " << M7.getBossTitle() << endl;
	M7.setBossTitle("Executive Manager");
	cout << "Current title of boss: " << M7.getBossTitle() << endl;
	system("pause");
	return 0;
}