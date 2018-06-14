#pragma once
#pragma once
#ifndef MONTHLYLIST_H
#define MONTHLYLIST_H
#include "Monthly.h"
class MortgageList
{
private:
	
	const static double LOAN_AMOUNT;
	const static size_t MAX = 30;// Capacity of the Mortgage array
	Mortgage List[MAX];
	size_t len;// Logical length of the list
	size_t list_state;

public:
	MortgageList();

	bool find(const Mortgage & key, int & whereFound, size_t flag)const;
	bool add(const Mortgage & S);
	const string toString() const;
	
	void bubbleSort(size_t flag);
	void print(ostream & out) const;

	const Mortgage getMortgageAt(size_t index)const;
	bool setMortgageAt(const Mortgage & S, size_t index);

	bool isEmpty() const;
	bool isFull() const;
	void makeEmpty();
	// size_t functions
	size_t getList_State()const;
	static size_t getCapacity();
	size_t getLength() const;

	//Static Functions
	static void getInstance(MortgageList & SL, istream & in);
	
	//Binary Search
	int binSearchLastName(const Mortgage & key) const;
	int binSearchAccountNumber(const Mortgage & key) const;
};
#endif

