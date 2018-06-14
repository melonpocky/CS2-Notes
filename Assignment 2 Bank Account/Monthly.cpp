#include "Monthly.h"

Mortgage::Mortgage() : AccountNum(0), FirstName("First name not set"), LastName("Last name not set"),
rate(4.5), cost(200000), downPymnt(40000), year(30)
{
	int inAccountNum = 0;
	double inRate = 0;
	double inCost = 0;
	double indownPymnt = 0;
	int inYear = 0;

	if (AccountNum < 0)
	{
		cout << "Number cannot be negative" << endl;
		AccountNum = 0;
	}
	else if (rate <= 0)
	{
		cout << "Rate is Invalid" << endl;
		rate = 4.5;
	}
	else if (cost <= 0)
	{
		cout << "Cost is Invalid" << endl;
		cost = 200000;
	}
	else if (downPymnt >= cost)
	{
		cout << "Down Payment Invalid" << endl;
		downPymnt = 20 * cost;
	}
	else if (year <= 0)
	{
		cout << "Years Invalid" << endl;
		year = 30;
	}
}

Mortgage::Mortgage(const int &ActNum, const string &fname, const string &lname,
	double rateParm, double costParm, double downPymntParm, int yearParm) :
	AccountNum(ActNum), FirstName(fname), LastName(lname), rate(rateParm), cost(costParm), downPymnt(downPymntParm), year(yearParm)
{


}

//accesssors and getters nothing else 
void Mortgage::setFirstName(const string &fname)
{
	FirstName = fname;
}
string Mortgage::getFirstName() const
{
	return FirstName;
}

void Mortgage::setLastName(const string &lname)
{
	LastName = lname;
}
string Mortgage::getLastName() const
{
	return LastName;
}

int Mortgage::getAccountNumber() const
{
	return AccountNum;
}
void Mortgage::setAccountNumber(const int &ActNum)
{
	AccountNum = ActNum;
}

double Mortgage::getRate()
{
	return rate;
}
void Mortgage::setRate(double rateParm)
{
	rate = rateParm;
}

double Mortgage::getCost()
{
	return cost;
}
void Mortgage::setCost(double costParm)
{
	cost = costParm;
}

double Mortgage::getYear()
{
	return year;
}
void Mortgage::setYear(int yearParm)
{
	year = yearParm;
}

double Mortgage::getdownPayment()
{
	return downPymnt;
}
void Mortgage::setdownPayment(double downPymntParm)
{
	downPymnt  = downPymntParm;
}

void Mortgage::print()const
{
	cout << "Name: " << FirstName << ' ' << LastName << endl
		<< "Account Number: " << AccountNum << endl
		<< "Rate: " << rate << endl
		<< "Cost: " << cost << endl
		<< "Down Payment: " << downPymnt << endl
		<< "Years: " << year << endl;
}

void Mortgage::print(ofstream & out)const
{
	cout << "Name: " << FirstName << ' ' << LastName << endl
		<< "Account Number: " << AccountNum << endl
		<< "Rate: " << rate << endl
		<< "Cost: " << cost << endl
		<< "Down Payment: " << downPymnt << endl
		<< "Years: " << year << endl;
}

const string Mortgage::toString() const
{
	ostringstream os;
	os << fixed << showpoint << setprecision(2)
		<< "Name: " << FirstName << ' ' << LastName << endl
		<< "Account Number: " << AccountNum << endl
		<< "Rate: " << rate << endl
		<< "Cost: " << cost << endl
		<< "Down Payment: " << downPymnt << endl
		<< "Years: " << year << endl;
	return os.str();
}

double Mortgage::GetMonthlyPayments()
{
	return MonthlyPayment;
}
void Mortgage::getInstance(Mortgage & S, istream & in)
{
	string inFirst;
	string inLast;
	int inAccountNum;
	double inRate;
	double inCost;
	double inDownPymnt;
	int inYear;

	if (&cin == &in)// That means in is cin so fill from keyboard
	{
		cout << "Enter Account Number: ";
		cin >> inAccountNum;

		cout << "Enter First Name: ";
		cin >> inFirst;
		inFirst = toupper(inFirst);

		cout << "Enter Last name: ";
		cin >> inLast;
		inLast = toupper(inLast);

		cout << "Enter Rate: ";
		cin >> inRate;

		cout << "Enter Cost: ";
		cin >> inCost;

		cout << "Enter Down Payment: ";
		cin >> inDownPymnt;

		cout << "Enter Year: ";
		cin >> inYear;
		S = Mortgage(inAccountNum, inFirst, inLast, inRate, inCost, inDownPymnt, inYear);
	}

	else
	{
		in >> inAccountNum;
		in >> inFirst;
		in >> inLast;

		in >> inRate;
		in >> inCost;
		in >> inDownPymnt;
		in >> inYear;

	}
	S = Mortgage(inAccountNum, inFirst, inLast, inRate, inCost, inDownPymnt, inYear);
}

