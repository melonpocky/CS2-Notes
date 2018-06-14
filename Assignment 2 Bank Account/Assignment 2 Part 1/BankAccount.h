#pragma once

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

class BankAccount
{
private:

	string ActNum;
	string 	FirstName;
	string 	LastName;	
	double balance;

public:

	BankAccount();
	BankAccount(const string &actN, const string & fname, const string & lname, double bal);
	void deposit(double money);

	string getAccountNumber() const;
	void setAccountNumber(const string & actN);
	
	double getBalance() const;
	
	const string getFirstName() const;

	const string getFullName() const;

	const string getLastName() const;
	void setLastName(const string & lname);
	
	const string toString() const;

	void withdraw(double money);

	void print(ostream & out=cout) const;
	//dont put the rest because there will be issues about that later on 

	static void getInstance(BankAccount & BA);
	static void getInstance(BankAccount & BA, istream & in);

};
#endif // !MONTHLY_H
