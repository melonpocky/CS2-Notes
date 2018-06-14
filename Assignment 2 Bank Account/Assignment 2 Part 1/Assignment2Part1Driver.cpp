#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "BankAccount.h"

using namespace std;

int main1()// test member functions of BankAccount class
{

	BankAccount Default;
	BankAccount Test("1000", "Joe", "Smith", 20);
	
	cout << "Default Accessors" << endl;
	cout << "Default Account Number: " << Default.getAccountNumber() << endl
		<< "Default First Name: " << Default.getFirstName() << endl
		<< "Default Last Name: " << Default.getLastName() << endl
		<< "Default Account Balance: " << Default.getBalance() << endl;

	cout << "Default Mutators" << endl;
	
	Default.setAccountNumber("1234");
	Default.setLastName("DefaultLastName");
	cout << "Default Account Number: " << Default.getAccountNumber() << endl
		<< "Default Last Name: " << Default.getLastName() << endl;

	cout << "Test Accessors" << endl;
	cout << "Test Account Number: " << Test.getAccountNumber() << endl
		<< "Test First Name: " << Test.getFirstName() << endl
		<< "Test Last Name: " << Test.getLastName() << endl
		<< "Test Account Balance: " << Test.getBalance() << endl;

	cout << "Test Mutators" << endl;

	Test.setAccountNumber("0000");
	Test.setLastName("TestLastName");
	cout << "Test Account Number: " << Test.getAccountNumber() << endl
		<< "Test Last Name: " << Test.getLastName() << endl;


	system("pause");
	return 0;
}


void print(const BankAccount & BA)
{
	BA.print();
}


int main() //we have to write two main functions which is a loop to do the following, other main1 function is to test that all lines of the code are executed
{
	BankAccount BA;
	double money;
	bool done = false;
	bool option = false;
	cout << fixed << showpoint << setprecision(2);

	while (!done)
	{
		cout << "\nEnter your choice.\n"
			<< "1. Create Bank Account from Keyboard Entry\n"
			<< "2. Create Bank Account from File Entry\n"
			<< "3. Print account balance to console\n"
			//needs $ sign and 2 digits output
			<< "4. Withdraw Money\n"
			<< "5. Deposit Money\n"
			<< "6. Print account details to console\n"
			<< "7. Print account details to output file\n"
			<< "8. Print full name to console only\n"
			<< "9. Print account number only of the account holder to console\n"
			<< "10. Exit" << endl;
		//if user tries 3-8 before using 1 & 2 , program should tell them that an instance of Bank Account is yet to be created
		//Done using Boolean flags

		int choice;
		cin >> choice;
		

		if (choice == 1 || choice == 2 || choice == 10)
		{
			option = true;
		}

	while (option != true)
		{
			cout << "Instance has not been created yet" << endl
				<< "Press 1 for creating Instance using Keyboard" << endl
				<< "Press 2 for creating Instance using Output File" << endl;

			cin >> choice;
			if (choice == 1 || choice == 2 || choice == 10)//create account from keyboard entry
			{
				option = true;
			}
		}


		if (choice == 1)//create account from keyboard entry
		{
			BankAccount::getInstance(BA, cin);
			cin.ignore(10, '\n');
		}
		else if (choice == 2)
		{
			string file;
			cout << "Enter full path to input file: ";
			cin.ignore(128, '\n');
			getline(cin, file);
			ifstream in(file);

			if (!in.is_open())
			{
				cout << "Could not open file " << file << endl;
				continue;
			}
			BankAccount::getInstance(BA, in);
			in.close();
		}

		if (choice == 10)
		{
			done = true;
		}

		else if (choice == 3)
		{
			cout << showpoint << setprecision(2) << fixed;
			cout << "\nBank Holder's Balance: $" << BA.getBalance() << endl;
		}

		else if (choice == 4) //Withdraw Money
		{
			cout << left << showpoint << setprecision(2);
			cout << "\nCurrent Account Balance: $" << BA.getBalance() << endl;
			cout << "Enter how much money you want to withdraw" << endl;

			cin >> money;
			BA.withdraw(money);
			cout << "\nCurrent Account Balance: $"<< BA.getBalance() << endl;
		}

		else if (choice == 5) //Deposit Money
		{
			cout << left << showpoint << setprecision(2);
			cout << "\nCurrent Account Balance: $" << BA.getBalance() << endl;
			cout << "Enter how much money you want to deposit" << endl;

			cin >> money;
			BA.deposit(money);
			cout << "\nCurrent Account Balance: $" << BA.getBalance() << endl;
		}

		else if (choice == 6) //Account details to console
		{
			BA.print();
		}
		else if (choice == 7) //print student data to output file case 7 for Bank Account
		{
			string outFile;
			cin.ignore(128, '\n');
			cout << "Enter full path to output file: ";
			getline(cin, outFile);
			ofstream out(outFile);

			if (!out.is_open())
			{
				cout << "Error in opening output file. Try again." << endl;
				continue;
			}
			BA.print(out);
			out.close();
		}
		else if (choice == 8)
		{
			cout << "\nBank Holder's Name: " << BA.getFullName() << endl;
		}

		else if (choice == 9)
		{
			cout << "\nBank Holder's Account Number: " << BA.getAccountNumber() << endl;
		}
	}//loop

	system("pause");
	return 0;
}