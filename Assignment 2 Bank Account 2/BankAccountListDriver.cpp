#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "BankAccount.h"
#include "BankAccountList.h"

/*

CS2 Part 2 Assignment
March 12, 2018
*/

using namespace std;

int main1()// test member functions of StudentList class
{
	BankAccount Default;
	BankAccountList DefaultList;

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

void print(const BankAccountList & BAL)
{
	BAL.print();
}
int main() //we have to write two main functions which is a loop to do the following, other main1 function is to test that all lines of the code are executed
{
	BankAccount BA;
	BankAccountList BAL;
	bool done = false; 
	bool option = false;
	string actNum;
	double money;
	cout << fixed << showpoint << setprecision(2);

	while (!done)
	{
		cout << "\nEnter your choice.\n"
			<< "1. Create Bank Account from Keyboard Entry\n"
			<< "2. Create Bank Account from File Entry MAX = 30 accounts\n"
			<< "3. Update an Account\n"
			<< "4. Close/Delete an Account\n"
			<< "5. Write currently account list to an output file in append mode\n"
			<< "6. Print Current Account List(Console)\n"
			<< "7. Withdraw Money from an Account\n"
			<< "8. Deposit Money from an Account\n"
			<< "9. Balance Enquiry\n"
			<< "10. Search Account and Show Details(Console)\n"
			<< "11. Print Current List Description(Console)\n"
			<< "12. Print List Sorted by Account Number(Console)\n"
			<< "13. Print List Sorted by Last Name(Console)\n"
			<< "14. Print List Sorted by Balance(Console)\n"
			/*
			<< "15. Print Statistics(Console)\n"
			<< "16. Print Report in Table Form to a Report File\n"
			<< "17. Print list to an Output File Readable as New Input File\n"
			*/
			<< "18. Exit" << endl;
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

		if (choice == 18)
		{
			done = true;
		}
		else if (choice == 1)
		{
			
			BankAccountList::getInstance(BAL, cin);
		}
		else if (choice == 2)// Fill from file build student object from input file
		{
			//1. Get full path to file name using getline
			string inFile;
			cout << "Enter full path to input file: ";
			cin.ignore(128, '\n');// ignores enter key from choice input
			getline(cin, inFile);
			ifstream in(inFile);// will open file if exists
								// Must do file opening validation for 
								// all files that are opened
			if (!in.is_open())
			{
				cout << "Could not open file " << inFile << endl;
				continue;
			}

			BankAccountList::getInstance(BAL, in);
			
			
			in.close();
		}
		else if (choice == 3) //Update Account
		{
			BAL.updateAccount();
		}
		
		else if (choice == 4) //Close/Delete an Account
		{
			cout << "\nEnter Account Number to Delete" << endl;
			cin >> actNum;

			BAL.deleteAccount(actNum);
		}
		else if (choice == 5) //Write currently account list to an output file in append mode
		{
		string OutFileName;
			cin.ignore(128, '\n');
			cout << "Enter full path to output file: ";
			getline(cin, OutFileName);
			ofstream out(OutFileName);

			if (!out.is_open())
			{
				cout << "Error in opening output file. Try again." << endl;
				continue;
			}
			BAL.print(out);
			out.close();
		}
		else if (choice == 6) //Print Current Account List(Console)
		{
			BAL.print();
		}
		else if (choice == 7) //Withdraw Money from an Account
		{
			cout << "\nEnter Account Number to withdraw money from" << endl;
			cin >> actNum;

			cout << "\nEnter money you want to withdraw" << endl;
			cin >> money;

			BAL.withDrawMoney(actNum, money);
		}
		else if (choice == 8) //Deposit Money from an Account
		{
			cout << "\nEnter Account Number to deposit money from" << endl;
			cin >> actNum;

			cout << "\nEnter money you want to deposit" << endl;
			cin >> money;

			BAL.depositMoney(actNum, money);
		}
		else if (choice == 9)// Balance Enquiry
		{
			int i = 0;
			bool found;
			cout << "\nEnter Account Number for the Balance you want to see" << endl;
			cin >> actNum;
			found = BAL.findAccount(actNum, i);
			if (!found)
			{
				cout << "Account Does Not Exist" << endl;
			}
			
				cout 
					<< "\nAccount Number: " << actNum << endl
					<< "Balance: " << BAL.getBalance(actNum) << endl;
			
		} 
		else if (choice == 10)//Search Account and Show Details(Console)
		{
			cout << "\nEnter Account Number" << endl;
			cin >> actNum;
			int i = 0;
			bool found;
			found = BAL.findAccount(actNum, i);
			if (!found)
			{
				cout << "Account Does Not Exist" << endl;
			}
			
				cout << "\nFull Name: " << BAL.getFullName(actNum) << endl
				<< "Account Number: " << actNum << endl
				<< "Balance: " << BAL.getBalance(actNum) << endl;
			
		}
		else if (choice == 11)//Print Current List Description(Console)
		{
			BAL.getListState();
		cout<< 	BAL.listDescription();
		}
		else if (choice == 12)//Print List Sorted by Account Number(Console)
		{
			cout << "\nSort by Account Number" << endl;
			BAL.sort(1);
			BAL.print();
		}
		else if (choice == 13)//Print List Sorted by Last Name(Console)
		{
			cout << "\nSort by Last Name" << endl;
			BAL.sort(2);
			BAL.print();
		}
		else if (choice == 14)//Print List Sorted by Balance(Console)
		{
			cout << "\nSort by Balance" << endl;
			BAL.sort(3);
			BAL.print();
		}
		/* OPTIONAL
		else if (choice == 15)//Print Statistics(Console)
		{

		}
		else if (choice == 16)// Print Report in Table Form to a Report File
		{

		}
		else if (choice == 17) //Print list to an Output File Readable as New Input File
		{

		}
		*/

	}//loop

	system("pause");
	return 0;
}
