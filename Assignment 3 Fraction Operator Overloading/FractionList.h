#pragma once
#ifndef FRACTIONLIST_H
#define FRACTIONLIST_H
#include "Fraction.h"

class FractionList
{
private:
	static const int MAX = 30;
	bool isSorted;
	Fraction List[MAX];
	size_t num_elements;

public:
	void addFraction(const Fraction& F);
	FractionList();
	static void getInstance(FractionList&FL);
	const Fraction getLargest() const;
	const Fraction getSmallest() const;
	size_t getNumberOfElements();
	bool getSortState();
	const Fraction getSumOfFractions() const;

	bool isEmpty();
	bool isFull();

	const Fraction & operator [](size_t index) const;
	void sort();
	const string toString() const;

	friend ostream & operator << (ostream & out, const FractionList& FL);
	friend istream & operator >> (istream & in, FractionList& FL);
};
#endif