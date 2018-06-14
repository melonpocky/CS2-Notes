#pragma once
#ifndef BANKACCOUNTLIST_H
#define BANKACCOUNTLIST_H
#include "BankAccount.h"
#include <cmath>

/*

CS2 Part 2 Assignment

*/

class BankAccountList
{
private:
	const static int MAX = 30;
	int list_state;
	int num_elements = 0;
	BankAccount List[MAX];
	//data type Name(Declaration) - Design Description
public:
	// Constructors and Mutators 
	BankAccountList();
	void addAccount(const BankAccount&BA);
	bool deleteAccount(const string & actNum);

	bool depositMoney(const string & actNum, double money);
	bool withDrawMoney(const string & actNum, double money);

	void makeEmpty();
	bool updateAccount();
	void sort(int flag);

	void setAccountAt(BankAccount & BA, unsigned int index);
	bool getAccountAt(BankAccount & BA, unsigned int & index) const;

	void setLastName(const string & lname, const string & actNum);
	const string getLastName(const string & actNum) const;

	//Non-mutator Functions without a constructor/mutator
	bool findAccount(const string& actNum, int & i) const;

	double getBalance(const string & actNum) const;
	//void getHighestBalanceAccount(BankAccount & BA) const;
	//void getSmallestBalanceAccount(BankAccount & BA) const;

	const string getFirstName(const string & actNum) const;
	const string getFullName(const string & actNum) const;

	//int getLengthofLongestFirstName()const;
	//int getLengthofLongestLastName()const;

	int getListState() const;
	/*
	double getMeanOfAllDesposits() const;
	double Standard_Deviation_Deposits() const;
	double sumAllDeposits() const;
	*/
	int getNumberOfElements() const;

	bool isEmpty() const;
	bool isFull()const;

	const string listDescription()const;
	const string toString()const;
	//void writeToNewInputFile(ostream & out) const;

	void print(ostream & out = cout)const;
	//void printListAsReport() const;
	//void printStatistics(ostream & out = cout) const;


	//Static Member Functions
	static int getCapacity();
	//static void getInstance(BankAccountList & BAL);
	static void getInstance(BankAccountList & BAL, istream & in);

	//Unsigned Ints
	//unsigned int numberofDepositsAboveMean() const;
	//unsigned int numberofDepositsAtOrBelowMean() const;

};
#endif