#include "BankAccount.h"

/*

CS2 Part 2 Assignment
March 12, 2018
*/

BankAccount::BankAccount() : ActNum("Account Number not set"), FirstName("First Name not set"), LastName("Last Name not set"), balance(0)
{

}

BankAccount::BankAccount(const string &actN, const string & fname, const string & lname, double bal) :
	ActNum(actN), FirstName(fname), LastName(lname), balance(bal)
{
	if (balance<0.0)
	{
		cout << "Balance cannot be negative and is being set to 0.0" << endl;
		balance = 0.0;
	}
}

void BankAccount::deposit(double money)
{
	balance += money;
}
void BankAccount::withdraw(double money)
{
	if (balance < money)
	{
		cout << "Can't withdraw money, will have negative balance" << endl;
	}
	else
	{
		balance -= money;
	}
	
}

string BankAccount::getAccountNumber() const
{
	return ActNum;
}
void BankAccount::setAccountNumber(const string & actN)
{
	ActNum = actN;
}

double BankAccount::getBalance() const
{
	return balance;
}

const string BankAccount::getFirstName()const
{
	return FirstName;
}

const string BankAccount::getFullName()const
{
	return FirstName +' '+ LastName;
}

void BankAccount::setLastName(const string & lname)
{
	LastName = lname;
}
const string BankAccount::getLastName() const
{
	return LastName;
}

const string BankAccount::toString() const
{
	ostringstream os;
	os	<< fixed << showpoint << setprecision(2);
	os << "Name: "  << FirstName << ' ' << LastName << endl;
	os << "Account Number: "  << ActNum << endl;
	os << "Balance: $" << balance << endl;

	return os.str();
}

void BankAccount::print(ostream & out) const
{
	out << fixed << showpoint << setprecision(2);
	out <<"Name: "  << FirstName << ' ' << LastName << endl;
	out << "Account Number: "  << ActNum << endl;
	out	<< "Balance: $"<< balance << endl;

	//out << fixed << showpoint << setprecision(2);
	//out << "Name: " << setw(20) << FirstName << ' ' << LastName << endl;
	//out << "Account Number: " << setw(20) << ActNum << endl;
	//out << "Balance: " << setw(20) << "$" << balance << endl;
}

void BankAccount::getInstance(BankAccount & BA, istream & in)
{
	string inFirst;
	string inLast;
	string inAccountNum;
	double inBalance;

	if (&cin == &in)// That means in is cin so fill from keyboard
	{
		cout << "Enter Account Number: ";
		cin >> inAccountNum;

		cout << "Enter First Name: ";
		cin >> inFirst;

		cout << "Enter Last name: ";
		cin >> inLast;

		cout << "Enter Balance: ";
		cin >> inBalance;

		BA = BankAccount(inAccountNum, inFirst, inLast, inBalance);
	}
	else
	{
		//put the data in the order and all taht
		in >> inAccountNum;
		in >> inLast;
		in >> inFirst;
		
		in >> inBalance;
		BA = BankAccount(inAccountNum, inFirst, inLast, inBalance);
	}
}

static void getInstance(BankAccount & BA)
{

}


