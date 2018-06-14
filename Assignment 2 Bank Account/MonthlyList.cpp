#include "MonthlyList.h"

const  double MortgageList::LOAN_AMOUNT = 0.0;

MortgageList::MortgageList() :len(0), list_state(0)
{
}

bool MortgageList::find(const Mortgage & key, int & whereFound, size_t flag)const
{
	bool found = false;
	whereFound = -1;

	for (size_t i = 0; i < len; i++)
	{
		if (flag == 1)// searching for match of ID in the key
		{
			if (key.getAccountNumber() == List[i].getAccountNumber())
			{
				found = true;
				whereFound = i;
				break;// efficiency
			}
		}
		else if (flag == 2)// searching for match of last name in the key
		{
			string keyLName = key.getLastName();

			for (auto & ch : keyLName)
			{
				ch = toupper(ch);
			}

			string currentLname = List[i].getLastName();

			for (auto & ch : currentLname)
			{
				ch = toupper(ch);
			}

			if (keyLName == currentLname)// case insensitive comparison
			{
				found = true;
				whereFound = i;
				break;// efficiency
			}
		}//second else if
	}//for loop

	return found;
}//function

bool MortgageList::add(const Mortgage & M)
{
	if (len == MAX)
	{
		cout << "The list is full." << endl;
		return false;
	}
	// Find if S is already in the list or not
	// add if not there.
	bool found;
	int whereFound = -1;
	found = find(M, whereFound, 1);

	if (!found)// not there. add it
	{
		List[len] = M;
		len++;
		list_state = 0;// Because we may be adding to a sorted list
		return true;
	}
	else
	{
		cout << "Mortgage with Account Number: " << M.getAccountNumber() << " is already in the list." << endl;
		return false;
	}

}

const string MortgageList::toString() const
{
	if (len == 0)
	{
		return "List is Empty\n";
	}

	string temp;

	for (size_t i = 0; i < len; i++)
	{
		temp += List[i].toString();
		temp += "---------------------------\n";
	}

	return temp;
}
void MortgageList::print(ostream & out) const
{
	out << toString() << endl;
}

void MortgageList::bubbleSort(size_t flag)
{
	if (list_state == 1 && flag == 1)
	{
		cout << "List is already sorted based on Account Number." << endl;
		return;
	}

	if (list_state == 2 && flag == 2)
	{
		cout << "List is already sorted based on Last Name." << endl;
		return;
	}

	if (list_state == 3 && flag == 3)
	{
		cout << "List is already sorted based on Loan Amount." << endl;
		return;
	}
	// sort otherwise
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < len - 1 - i; j++)
		{
			if (flag == 1)// sort on Account Number
			{
				if (List[j].getAccountNumber() > List[j + 1].getAccountNumber())
				{
					Mortgage buffer = List[j];
					List[j] = List[j + 1];
					List[j + 1] = buffer;
				}
			}
			else if (flag == 2)// sort based on last name case insensitive
			{
				string name1 = List[j].getLastName();
				for (auto & dummy : name1) { dummy = toupper(dummy); }
				string name2 = List[j + 1].getLastName();
				for (auto & dummy : name2) { dummy = toupper(dummy); }

				if (name1>name2) {
					Mortgage buffer = List[j];
					List[j] = List[j + 1];
					List[j + 1] = buffer;
				}
			}
			else if (flag == 3)// sort based on Loan Amount this part will have errors 
			{
				if (List[j].GetMonthlyPayments() > List[j + 1].GetMonthlyPayments())
				{
					Mortgage buffer = List[j];
					List[j] = List[j + 1];
					List[j + 1] = buffer;
				}
			}
		}
	}
	list_state = flag;
}

void MortgageList::getInstance(MortgageList & ML, istream & in)
{
	Mortgage Temp;

	if (&cin == &in)// Filling Mortgage list from keyboard
	{
		bool done = false;
		size_t count = 0;

		while (!done && count<MAX)
		{
			Mortgage::getInstance(Temp, cin);
			ML.add(Temp);
			count++;
			cout << "More data? Enter 0 to continue or 1 to stop data entry: ";
			cin >> done;
		}
	}
	else
	{
		size_t count = 0;

		while (/*Exit when end of file is reached*/in.peek() != EOF && count<MAX)
		{
			Mortgage::getInstance(Temp, in);
			ML.add(Temp);
			count++;
		}
	}
}

const Mortgage MortgageList::getMortgageAt(size_t index)const
{
	if (index<len)// index is valid and inside logical length
	{
		return List[index];
	}

	throw "Invalid array Index.";
}
bool MortgageList::setMortgageAt(const Mortgage & S, size_t index)
{
	if (index<len)
	{
		List[index] = S;
		list_state = 0; // feel free to write another version that if list was sorted in some order then check  and resort
		return true;
	}
	else
	{
		cout << "Index " << index << " is invalid." << endl;
		return false;
	}
}

bool MortgageList::isEmpty() const
{
	return len == 0;
}
void MortgageList::makeEmpty()
{
	len = 0; // existing list will be overwritten
	list_state = 0;
}
bool MortgageList::isFull() const
{
	return len == MAX;
}

// Size_t functions
size_t MortgageList::getList_State()const
{
	return list_state;
}
size_t MortgageList::getCapacity()
{
	return MAX;
}
size_t MortgageList::getLength() const
{
	return len;
}

//Search Functions
int MortgageList::binSearchLastName(const Mortgage & key) const
{
	if (list_state != 2)
	{
		cout << "List is not sorted on last name. Binary search cannot be done." << endl;
		return -1;
	}

	int index = -1;
	int lowest_index = 0;
	int highest_index = static_cast<int>(len - 1);

	while (highest_index >= lowest_index)
	{
		int middle_index = (lowest_index + highest_index) / 2;

		if (List[middle_index].getLastName() == key.getLastName())
		{
			index = middle_index;
			break;
		}

		else if (List[middle_index].getLastName()>(key.getLastName()))
			highest_index = middle_index - 1;

		else if (List[middle_index].getLastName()<(key.getLastName()))
			lowest_index = middle_index + 1;
	}

	return index;
}
int MortgageList::binSearchAccountNumber(const Mortgage & key) const
{
	if (list_state != 1)
	{
		cout << "List is not sorted on Account Number. Binary search cannot be done." << endl;
		return -1;
	}

	int index = -1;
	int lowest_index = 0;
	int highest_index = static_cast<int>(len - 1);

	while (highest_index >= lowest_index)
	{
		int middle_index = (lowest_index + highest_index) / 2;

		if (List[middle_index].getAccountNumber() == key.getAccountNumber())
		{
			index = middle_index;
			break;
		}

		else if (List[middle_index].getAccountNumber()>(key.getAccountNumber()))
			highest_index = middle_index - 1;

		else if (List[middle_index].getAccountNumber()<(key.getAccountNumber()))
			lowest_index = middle_index + 1;
	}

	return index;
}
