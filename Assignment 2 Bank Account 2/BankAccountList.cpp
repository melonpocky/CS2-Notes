#include "BankAccountList.h"

/*

CS2 Part 2 Assignment

*/

BankAccountList::BankAccountList():num_elements(0), list_state(0)
{

}

void BankAccountList::addAccount(const BankAccount&BA)
	{
		if (num_elements == MAX)
		{
			cout << "The list is full." << endl;
			return;
		}
		for (int i = 0; i < MAX-1; i++)
		{
			if (BA.getAccountNumber() == List[num_elements +1].getAccountNumber())
			{
				cout << "\nBank Holder Account Number: " << List[num_elements].getAccountNumber() << " is already in the list." << endl << endl;
				return;
			}
		}
		List[num_elements] = BA;
		num_elements++;
		list_state = 0;// Because we may be adding to a sorted list
	}

	bool BankAccountList::deleteAccount(const string & actNum) 
	{
		bool deleted = false;

		if (num_elements == 0)
		{
			cout << "List is empty. Nothing to delete." << endl;
			return deleted;
		}
		
		bool found;
		int whereFound = 0;
		found = findAccount(actNum, whereFound);// flag = 1 to search for ID

		if (!found)
		{
			cout << "Bank Account Number: " << actNum << " is not in the list." << endl;
			return deleted;
		}
		else
		{
			List[whereFound] = List[num_elements - 1];
			num_elements--;
			//what if list is sorted? we need to resort in order to
			// maintain sort state
			if (list_state == 1)
			{
				list_state = 0;
				sort(1);
			}
			else if (list_state == 2)
			{
				list_state = 0;
				sort(2);
			}
			else if (list_state == 3)
			{
				list_state = 0;
				sort(3);
			}
			deleted = true;
			return deleted;
		}
	}
	bool BankAccountList::depositMoney(const string & actNum, double money)
	{
		for (int i = 0; i < num_elements; i++)
		{
			if (List[i].getAccountNumber() == actNum)
			{
				List[i].deposit(money);
				list_state = 0;
				return true;
			}
		}
		return false;
	}
	bool BankAccountList::withDrawMoney(const string & actNum, double money)
	{
		for (int i = 0; i < num_elements; i++)
		{
			if (List[i].getAccountNumber() == actNum)
			{
				List[i].withdraw(money);
				list_state = 0;
				return true;
			}
		}
		return false;
	}

	void BankAccountList::makeEmpty()
	{
		num_elements = 0; // existing list will be overwritten
		list_state = 0;
	}
	bool BankAccountList::updateAccount()
	{
		int i = 0;
		string actNum;
		string newLast;
		bool found;
		cout << "Enter Bank Account Number" << endl;
		cin >> actNum;

		found = findAccount(actNum, i);
		if (!found)
		{
			cout << "Account Does Not Exist" << endl;
		}
		else 
		{
			cout << "Change Last Name of Account Holder" << endl;
			cin >> newLast;

			setLastName(newLast, actNum);
			return true;
		}
		return false;
	}

	void BankAccountList::sort(int flag)
	{
		if (list_state == 1 && flag == 1)
		{
			cout << "List is already sorted based on Account Number." << endl;
			list_state = 1;
			return;
		}

		if (list_state == 2 && flag == 2)
		{
			cout << "List is already sorted based on Last Name." << endl;
			list_state = 2;
			return;
		}

		if (list_state == 3 && flag == 3)
		{
			cout << "List is already sorted based on Balance." << endl;
			list_state = 3;
			return;
		}
		// sort otherwise
		for (size_t i = 0; i < num_elements; i++)
		{
			for (size_t j = 0; j < num_elements - 1 - i; j++)
			{
				if (flag == 1)// sort on Account Number
				{
					if (List[j].getAccountNumber() > List[j + 1].getAccountNumber())
					{
						BankAccount buffer = List[j];
						List[j] = List[j + 1];
						List[j + 1] = buffer;
						list_state = 1;
					}
				}
				else if (flag == 2)// sort based on last name case insensitive
				{
					string name1 = List[j].getLastName();
					for (auto & dummy : name1) { dummy = toupper(dummy); }
					string name2 = List[j + 1].getLastName();
					for (auto & dummy : name2) { dummy = toupper(dummy); }

					if (name1>name2) {
						BankAccount buffer = List[j];
						List[j] = List[j + 1];
						List[j + 1] = buffer;
						list_state = 2;
					}
				}
				else if (flag == 3)// sort based on Balance
				{
					if (List[j].getBalance() > List[j + 1].getBalance())
					{
						BankAccount buffer = List[j];
						List[j] = List[j + 1];
						List[j + 1] = buffer;
						list_state = 3;
					}
				}
			}
		}
		list_state = flag;
	}

	void BankAccountList::setAccountAt(BankAccount & BA, unsigned int index)
	{
		if (index<num_elements)
		{
			List[index] = BA;
			list_state = 0; // feel free to write another version that if list was sorted in some order then check  and resort
		}
		else
		{
			cout << "Index " << index << " is invalid." << endl;
			return;
		}
	}

	bool BankAccountList::getAccountAt(BankAccount & BA, unsigned int & index) const
	{ 
		if (index <= num_elements)// index is valid and inside logical length
		{
			return true;
		}

		else
		{
			return false;
		}
	}
	
	void BankAccountList::setLastName(const string & lname, const string & actNum)
	{
		for (int i = 1; i < num_elements; i++)
		{
			if (actNum == List[i].getAccountNumber())
			{
				List[i].setLastName(lname);
				list_state = 0;
				//sets list state to 0 if sorted by last name
				cout << "Account Number: " << List[i].getAccountNumber() << endl
				<< "Full Name: " << List[i].getFullName() << endl;
				break;
			}
			else
			{
				cout << "";
			}
		
		}
		
	}
	const string BankAccountList::getLastName(const string & actNum) const
	{
		for (int i = 0; i < num_elements; i++)
		{
			if (List[i].getAccountNumber() == actNum)
			{
				return List[i].getLastName();
			}	
		}
	throw "Account member not on the list";
	
	}

	//Non-mutator Functions without a constructor/mutator
	bool BankAccountList::findAccount(const string & actNum, int & i) const
	{
		for (int i = 0; i < num_elements; i++)
		{
			if (List[i].getAccountNumber() == actNum)
			{
				return true;
			}
		}
				return false;
	}

	double BankAccountList::getBalance(const string & actNum) const
	{
		for (int i = 0; i < num_elements; i++)
		{
			if (List[i].getAccountNumber() == actNum)
			{
				return List[i].getBalance();
			}
		}
		throw "Account member not on the list";
		
	}
	/*
	void BankAccountList::getHighestBalanceAccount(BankAccount & BA) const
	{
		if (num_elements == 0)
		{
			cout << ("List is empty") << endl;
			return;
		}
		
		BA = List[0].getBalance();

		for (unsigned int index = 1; index < num_elements; index++)
		{
			if (BA < List[index].getBalance())
			{
				BA = List[index].getBalance();
			}
		}
	}
	void BankAccountList::getSmallestBalanceAccount(BankAccount & BA) const;
	{
		if (num_elements == 0)
		{
			cout << ("List is empty") << endl;
			return;
		}

		BA = List[0].getBalance();

		for (unsigned int index = 1; index < num_elements; index++)
		{
			if (BA < List[index].getBalance())
			{
				BA = List[index].getBalance();
			}
		}
	}*/
	const string BankAccountList::getFirstName(const string & actNum) const
	{
		for (int i = 0; i < num_elements; i++)
		{
			if (List[i].getAccountNumber() == actNum)
			{
				return List[i].getFirstName();
			}	
		}
		throw "Account member not on the list";
		
	}
	const string BankAccountList::getFullName(const string & actNum) const
	{
		for (int i = 0; i < num_elements; i++)
		{
			if (List[i].getAccountNumber() == actNum)
			{
				return List[i].getFullName();
			}		
		}
		throw "Account member not on the list";
	
	}

	//int BankAccountList::getLengthofLongestFirstName()const;
	//int BankAccountList::getLengthofLongestLastName()const;

	int BankAccountList::getListState() const
	{
		return list_state;
	}
	/*
	double BankAccountList::getMeanOfAllDesposits() const
	{
		double sum = 0.0;

		for (size_t i = 0; i < num_elements; i++)
		{
			sum += List[i].getBalance();
		}
		if (num_elements != 0)
		{
			meanBalance = sum / num_elements;
		}
		else
		{
			cout << "List is empty." << endl;
		}
	
		return meanBalance;
	}
	double BankAccountList::Standard_Deviation_Deposits() const
	{
		if (num_elements == 0)
		{
			cout << "List is Empty. No mean can be found." << endl;
			return;
		}
		double SumofSquares = 0.0;

		for (unsigned int i = 0; i < num_elements ; i++)
		{
			double Balance = List[i].getBalance();
			SumofSquares += gp * gp;
		}
		double Mean = 0.0;
		getMeanofAllDesposits();
		StdDev = sqrt((SumofSquares / (num_elements)) - Mean * Mean);
		return StdDev;
	}
	double BankAccountList::sumAllDeposits() const;
	*/

	int BankAccountList::getNumberOfElements() const
	{
		return num_elements;
	}

	bool BankAccountList::isEmpty() const
	{
		if (num_elements == 0)
			return true;
		else
			return false;
	}

	bool BankAccountList::isFull()const
	{
		if (num_elements == MAX)
			return true;
		else
			return false;
	}
	
	const string BankAccountList::listDescription()const
	{
		string descrp;
		if (list_state == 0)
		{
			descrp = "List is unsorted";
		}
		else if (list_state == 1)
		{
			descrp = "List is sorted based on ID";
		}
		else if (list_state == 2)
		{
			descrp = "List is sorted based on last name";
		}
		else if (list_state == 3)
		{
			descrp = "List is sorted based on GPA";
		}

		return descrp;
	}
	
	const string BankAccountList::toString()const
	{
		if (num_elements == 0)
		{
			return "List is Empty\n";
		}
		string temp;

		for (int i = 0; i < num_elements; i++)
		{
			temp += List[i].toString();
			temp += "---------------------------\n";
		}

		return temp;
	}

	void BankAccountList::print(ostream & out)const
	{
		out << toString() << endl;
	}


	/*
	void BankAccountList::printListAsReport() const;
	void BankAccountList::printStatistics(ostream & out = cout) const
	{
		double maxGPA;
		getMaximumGPA(maxGPA);
		out << "Maximum GPA: " << maxGPA << endl;
		double minGPA;
		getMinimumGPA(minGPA);
		out << "Minimum GPA: " << minGPA << endl;
		double meanGPA;
		getMeanGPA(meanGPA);
		out << "Mean GPA: " << meanGPA << endl;

		double sd;
		getStandardDevGPA(sd);
		out << "Standard Deviation of GPA." << sd << endl;
		double medianGP;
		getMedianGPA(medianGP);
		out << "Median GPA: " << medianGP << endl;
		out << "Number of students in the list: " << num_elements << endl;
		out << "**************************************************************************" << endl;

	}
	*/

	//Static Member Functions
 int BankAccountList::getCapacity()
 {
	 return MAX;
 }

void BankAccountList::getInstance(BankAccountList & BAL, istream & in)
	{
	string inFirst;
	string inLast;
	string inAccountNum;
	double inBalance;

	if (&cin == &in)// That means in is cin so fill from keyboard
	{
		cout << "Enter Account Number: ";
		cin >> inAccountNum;

		cout << "Enter Last name: ";
		cin >> inLast;

		cout << "Enter First Name: ";
		cin >> inFirst;

		cout << "Enter Balance: ";
		cin >> inBalance;
		
		BankAccount Temp(inAccountNum, inFirst, inLast, inBalance);
		BAL.addAccount(Temp);
	}
	else
	{
		
		while (!in.eof())
		{
		in >> inAccountNum;
		in >> inLast;
		in >> inFirst;
		in >> inBalance;
		BankAccount Temp(inAccountNum, inFirst, inLast, inBalance);
		BAL.addAccount(Temp);
		}
		
	}
	}

	//Unsigned Ints
	//int BankAccountList::numberofDepositsAboveMean() const;
	// int BankAccountList::numberofDepositsAtOrBelowMean() const;
