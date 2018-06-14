#include "FractionList.h"

FractionList::FractionList() :num_elements(0), isSorted(false)
{
}

void FractionList::addFraction(const Fraction& F)
{
	if (num_elements == MAX)
	{
		cout << "List is full. " << endl;
	}
	else
	{
		List[num_elements++] = F;
	}
	isSorted = false;
}
void FractionList::getInstance(FractionList&FL)
{
	int index = 0;
	bool done = false;
	while (!done && index < MAX) {
		Fraction Temp;
		cin >> Temp;
		FL.addFraction(Temp);
		index++;
		cout << "Enter 0 to continue or 1 to stop." << endl;
		cin >> done;
	}
}
void FractionList::sort()
{
	for (size_t i = 0; i < num_elements; i++)
	{
		for (size_t j = 0; j < num_elements-1; j++)
		{
			Fraction F1(List[j].getTop(), List[j].getBottom());
			Fraction F2(List[j+1].getTop(), List[j+1].getBottom());
			if (F1 > F2)
			{
				Fraction buffer = List[j];
				List[j] = List[j + 1];
				List[j + 1] = buffer;
			}
		}
	}
isSorted = true;
}

const Fraction FractionList::getLargest() const
{
	long max_numerator;
	long max_denominator;

	if (num_elements == 0)
	{
		cout << ("List is empty") << endl;
		return 0;
	}

	max_numerator = List[0].getTop();
	max_denominator = List[0].getBottom();
	Fraction temp(max_numerator, max_denominator);
	Fraction result = temp;
	for (unsigned int index = 1; index < num_elements; index++)
	{	
		Fraction F1(List[index].getTop() , List[index].getBottom());

			if (F1 > temp)
			{
				result = F1;
				temp = F1;
			}
	}

	return result;
}
const Fraction FractionList::getSmallest() const
{
	long min_numerator;
	long min_denominator;

	if (num_elements == 0)
	{
		cout << ("List is empty") << endl;
		return 0;
	}

	min_numerator = List[0].getTop();
	min_denominator = List[0].getBottom();
	Fraction temp(min_numerator, min_denominator);
	Fraction result = temp;
	for (unsigned int index = 1; index < num_elements; index++)
	{
		Fraction F1(List[index].getTop(), List[index].getBottom());

		if (temp > F1)
		{
			result = F1;
			temp = F1;
		}
	}

	return result;
}
const Fraction FractionList::getSumOfFractions() const
{
	Fraction C1 = Fraction{ 0, 1 };

	for (size_t i = 0; i < num_elements; i++)
	{
	 C1 += List[i];
	}

return C1;
}

size_t FractionList::getNumberOfElements() 
{
	return num_elements;
}

bool FractionList::isEmpty()
{
	return num_elements == 0;
}
bool FractionList::isFull()
{
	return num_elements == MAX;
}

const Fraction & FractionList::operator [](size_t index) const
{
	if (index < MAX)
	{
		return List[index];
	}
	throw "Out of bound array index.";
}

const string FractionList::toString() const
{
	string out = "\n";
	for (size_t i = 0; i < num_elements; i++)
	{
		out += (List[i].toString() + "\n");
	}
	out += "\n";
	return out;
}

ostream & operator<<(ostream & out, const FractionList& FL)
{
	for (size_t index = 0; index < FL.num_elements; index++)
	{
		out << FL.List[index] << endl;
	}
	out << "The number of elements in the list = " << FL.num_elements << endl;
	return out;
}
istream & operator>>(istream & in, FractionList& FL)
{
	long InNumerator;
	long InDenominator;
	if (&in == &cin)
	{
		cout << "Enter the numerator part: ";
		in >> InNumerator;
		cout << "Enter the denominator part: ";
		in >> InDenominator;
		Fraction temp(InNumerator, InDenominator);
		FL.addFraction(temp);
	}
	else
	{
		while (!in.eof())
		{
			Fraction temp;
			in >> temp;
			FL.addFraction(temp);
		}
	}
	return in;
}


bool FractionList::getSortState()
{
	if (isSorted == true)
	{
	}
	else
	{
		isSorted = false;
	}
	return isSorted;
}

