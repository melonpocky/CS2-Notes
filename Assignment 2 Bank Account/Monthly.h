#pragma once

#ifndef MONTHLY_H
#define MONTHLY_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

class Mortgage
{
private:

	int 	AccountNum;		//Account Number
	string 	FirstName;		//First Name of borrower
	string 	LastName;		//Last Name of borrower
	double 	rate; 			//Fixed annual interest rate in percent only
	double 	cost; 			//Cost of the house to be bought
	double 	downPymnt;		//Down payment made by the buyer
	int		year; 			//Number of years for which mortgage is taken
	double 	MonthlyPayment; //Monthly Payment

public:
	Mortgage();

	Mortgage(const int &ActNum, const string &fname, const string &lname,
		double rateParm, double costParm, double downPymntParm, int yearParm);

	string getFirstName() const;
	void setFirstName(const string &fname);
	
	string getLastName() const;
	void setLastName(const string &lname);
	

	int getAccountNumber() const;
	void setAccountNumber(const int &ActNum);

	double getRate();
	void setRate(double rateParm);

	double getCost();
	void setCost(double costParm);

	double getYear();
	void setYear(int yearParm);

	double getdownPayment();
	void setdownPayment(double downPymntParm);

	void print()const;
	void print(ofstream & out)const;
	const string toString() const;
	void print(ostream & printStream);
	
	static double GetMonthlyPayments();
	static void getInstance(Mortgage & Temp, istream & input);

};
#endif // !MONTHLY_H
