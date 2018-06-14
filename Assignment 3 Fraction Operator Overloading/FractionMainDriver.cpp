#include "FractionList.h"
#include "Fraction.h"
/*

CS2
Assignment 3 


*/
/*
1. Outout using << is missing. -1
Grade: 22/23
*/
int main()
{	FractionList FL;
	Fraction F1;
	Fraction F2;
	long numerator1;
	long numerator2;
	long denominator1;
	long denominator2;
	bool done = false;
	int index1;
	
	while (!done)
	{
		cout << "*************Main Menu*************" << endl
			<< "1. Fill Fraction array from keyboard data entry" << endl
			<< "2. Fill Fraction  array from input file" << endl
			<< "3. Print Fraction array to console" << endl
			<< "4. Print Fraction List to output file" << endl
			<< "5. Sort and Displays Fraction List to Console" << endl
			<< "6. Sum of all Fractions in list, Largest Fraction, and Sort State" << endl
			<< "7. Add, Multiply, Divide, Subtract two fractions" << endl
			<< "8. Pre and Post Incrementing Functions" << endl
			<< "9. Location of Fraction" << endl
			<< "10. Exit" << endl;
		int choice;
		cout << "Enter menu choice and press enter key: ";
		cin >> choice;
		if (choice == 10)
		{
			done = true;
		}
		else if (choice == 1) //Fill Fraction array from keyboard data entry
		{
			FractionList::getInstance(FL); 
		}
		else if (choice == 2)//Fill Fraction  array from input file
		{ cin.ignore();// ignores enter key from choice input
			//1. Get full path to file name using getline
			string inFile;
			cout << "Enter full path to input file: ";
			
			getline(cin, inFile);
			ifstream in(inFile);// will open file if exists
								// Must do file opening validation for 
								// all files that are opened
			if (!in.is_open())
			{
				cout << "Could not open file " << inFile << endl;
				continue;
			}
			in >> FL;
			in.close();
		}
		else if (choice == 3)//Print Fraction array to console
		{
			cout << FL.toString() << endl;
		}
		else if (choice == 4)//Print fraction array to output file
		{
			
			cin.ignore();
		
			cout << "Enter full path to file to which to output the Fractions: ";

			string outFile;
			getline(cin, outFile);
			ofstream out(outFile);
			if (!out.is_open())
			{
				cout << "Failed to create output file. Exiting program." << endl;
				system("pause");
				exit(0);
			}
			cout << "The fraction list outputted to console: " << endl;
			cout << FL << endl;
			cout << "Now writing fraction list to an output file." << endl;
			out << FL << endl;
			out.close();

			system("pause");
		}
		else if (choice == 5) //Sort and Displays Fraction List to Console
		{
			FL.sort();
			cout << FL.toString() << endl; 
			
		}
		else if (choice == 6) // Sum of all Fractions in list, Largest Fraction, and Sort State
		{
			FL.getSumOfFractions();
			FL.getSortState();
			FL.getLargest();
			cout << boolalpha;
			cout << "\nSum of All Fractions: " << FL.getSumOfFractions() << endl;
			cout << "Sort State: " << FL.getSortState() << endl;
			cout << "Largest Fraction: " << FL.getLargest() << endl;
		}
		else if (choice == 7) //Add, Multiply, Divide, Subtract two fractions
		{
			cout << "Enter Numerator" << endl;
			cin >> numerator1;
			cout << "Enter Denominator" << endl;
			cin >> denominator1;
			cout << "Enter Numerator you want to Add/Multiply/Divide/Subtract with" << endl;
			cin >> numerator2;
			cout << "Enter Denominator you want to Add/Multiply/Divide/Subtract with" << endl;
			cin >> denominator2;

			Fraction F2(numerator1, denominator1);
			Fraction F3(numerator2, denominator2);

			cout << "F2 = " << F2.toString() << endl;
			cout << "F3 = " << F3.toString() << endl;
			cout << "F2 + F3 = " << (F2 + F3).toString() << endl;
			cout << "F2 -F3 = " << (F2 - F3).toString() << endl;
			cout << "F2 * F3 = " << (F2* F3).toString() << endl;
			cout << "F2 / F3 = " << (F2 / F3).toString() << endl;
			cout << "F2 + 2 = " << (F2 + 2).toString() << endl;
			cout << " 2 + F2 = " << (2 + F2).toString() << endl;
			cout << "F2 -2 = " << (F2 - 2).toString() << endl;
			cout << "2 - F2 = " << (2 - F2).toString() << endl;
			cout << "F2 * 2 = " << (F2 * 2).toString() << endl;
			cout << " 2 * F2 = " << (2 * F2).toString() << endl;
			cout << "F2 / 2 = " << (F2 / 2).toString() << endl;
			cout << " 2 / F2 = " << (2 / F2).toString() << endl;

		}
		else if (choice == 8) //Pre and Post Incrementing Functions
		{
			cout << "Enter Numerator" << endl;
			cin >> numerator1;
			cout << "Enter Denominator" << endl;
			cin >> denominator1;
			cout << "Enter Numerator you want to Add/Multiply/Divide/Subtract with" << endl;
			cin >> numerator2;
			cout << "Enter Denominator you want to Add/Multiply/Divide/Subtract with" << endl;
			cin >> denominator2;

			Fraction F(numerator1, denominator1);
			Fraction F1(numerator2, denominator2);

			cout << "F = " << F << endl;
			cout << --F << endl;
			cout << F-- << endl;
			cout << F << endl;
			
			cout << "F1 = " << F1 << endl;
			cout << ++F1 << endl;
			cout << F1++ << endl;
			cout << F1 << endl;
		}
		else if (choice == 9) //Location of Fraction
		{
			cout << "Enter Index of where the Fraction you want to get" << endl;
			cin >> index1;

			while (index1 > FL.getNumberOfElements() || index1 < 0)
			{
				cout << "Index not Available" << endl;
				cout << "Enter new index" << endl;
				cin >> index1;
			}
			cout << "Fraction on Index " << index1 << " :" << FL[index1] << endl;
		}
		else
		{
			cout << "Choice Invalid, enter new choice number" << endl;
			cin >> choice;
		}
	}
		return 0;
}
int main2()
{
	Fraction F1(-8, -16);
	Fraction F2(6, -12);
	Fraction F3(9, -12);
	Fraction F4(5, 6);
	Fraction F5(-11, 17);
	if (F1 > F2) {
		cout << "Bigger" << endl;
	}
	if (F4 > F1) {
		cout << "Smaller" << endl;
	}
	FractionList FL;
	FL.addFraction(F1);
	FL.addFraction(F2);
	FL.addFraction(F3);
	FL.addFraction(F4);
	FL.addFraction(F5);
	cout << "The Fraction List is: " << endl << FL.toString() << endl;

	system("pause");
	
	cout << "Sort, isEmpty, isFull, getNumberofElements" << endl;
	//Add Source code of previous table plus below
	FL.sort();
	cout << "After ascending order sort, the FractionList is:" << endl << FL.toString() << endl;
	cout << boolalpha;
	cout << "It is " << FL.isEmpty() << " that list is empty()" << endl;
 	cout << "It is " << FL.isFull() << " that list is full()" << endl;
	cout << "The list has " << FL.getNumberOfElements() << " fractions." << endl;

	system("pause");
	return 0;
}

int main3()
{
	cout << "friend functions, istream, ostream" << endl;
	FractionList FL;
	cout << "Enter full path to file from which to read the fractions: ";
	//cin.ignore();
	string inputFile;
	getline(cin, inputFile);
	cout << inputFile << endl;
	ifstream in;
	in.open(inputFile.c_str());
	if (!in.is_open())
	{
		cout << "Failed to open input file. Exiting program." << endl;
		system("pause");
		exit(0);
	}
	in >> FL;
	cout << "Enter full path to file to which to output the Fractions: ";
	//cin.ignore();
	
	string outFile;
	getline(cin, outFile);
	ofstream out(outFile);
	if (!out.is_open())
	{
		cout << "Failed to create output file. Exiting program." << endl;
		system("pause");
		exit(0);
	}
	cout << "The fraction list outputted to console: " << endl; 
		cout << FL << endl;
	cout << "Now writing fraction list to an output file." << endl;
	out << FL << endl;
	in.close();
	out.close();

	system("pause");
	return 0;
}
int main4()
{
	cout << "getLargest, getSumOfFractions, getSortState, and operator[]" << endl;
	Fraction F1(-8, -16);
	Fraction F2(6, -12);
	Fraction F3(9, -12);
	Fraction F4(5, 6);
	Fraction F5(-11, 17);
	FractionList FL;
	FL.addFraction(F1);
	FL.addFraction(F2);
	FL.addFraction(F3);
	FL.addFraction(F4);
	FL.addFraction(F5);
	cout << "The Fraction List is: " << endl << FL.toString() << endl;
	cout << "The largest fraction is:" << FL.getLargest() << endl;
	cout << "The very first fraction in the array is :" << FL[0] << endl;
	cout << "The very last fraction in the array is :" << FL[FL.getNumberOfElements() - 1] << endl;
	cout << "The sum of all Fractions is: " << FL.getSumOfFractions() << endl;
	cout << boolalpha;
	cout << "It is " << FL.getSortState() << " that Fraction List is sorted." << endl;
	FL.sort();
	cout << "It is " << FL.getSortState() << " that Fraction List is sorted." << endl;
	FL.sort();

	system("pause");
	return 0;

}
/******Tests For Fraction is Below******/

int main10()
{
	Fraction F1(9, 0);
	cout << F1.toString() << endl;
	Fraction F2(-6, -12);
	cout << F2.toString() << endl;
	Fraction F3(9, -12);
	cout << F3.toString() << endl;
	Fraction F4(8, 16);
	cout << F4.toString() << endl;
	Fraction F5(5, 16);
	cout << F5.toString() << endl;
	Fraction F6(-5);
	cout << F6.toString() << endl;
	Fraction F7(5, -1);
	cout << F7.toString() << endl;
	system("pause");
	return 0;
}
int main11()
{
	cout << "\nFriend Functions that Perform Fraction Arithmetic" << endl;
	Fraction F2(6, -12);
	Fraction F3(-9, 12);
	cout << "F2 = " << F2.toString() << endl;
	cout << "F3 = " << F3.toString() << endl;
	cout << "F2 + F3 = " << (F2 + F3).toString() << endl;
	cout << "F2 -F3 = " << (F2 - F3).toString() << endl;
	cout << "F2 * F3 = " << (F2* F3).toString() << endl;
	cout << "F2 / F3 = " << (F2 / F3).toString() << endl;
	cout << "F2 + 2 = " << (F2 + 2).toString() << endl;
	cout << " 2 + F2 = " << (2 + F2).toString() << endl;
	cout << "F2 -2 = " << (F2 - 2).toString() << endl;
	cout << "2 -F2 = " << (2 - F2).toString() << endl;
	cout << "F2 * 2 = " << (F2 * 2).toString() << endl;
	cout << " 2 * F2 = " << (2 * F2).toString() << endl;
	cout << "F2 / 2 = " << (F2 / 2).toString() << endl;
	cout << " 2 / F2 = " << (2 / F2).toString() << endl;

	system("pause");
	return 0;
}
int main12()
{
	cout << "\nFriend Functions with operator == and !=" << endl;
	Fraction F1(1, 3);
	Fraction F2(2, 6);
	Fraction F3(5, 5);
	cout << boolalpha;
	cout << "F1 = " << F1.toString() << endl;
	cout << "F2 = " << F2.toString() << endl;
	cout << "F3 = " << F3.toString() << endl;
	cout << "F1 == F2 is : " << (F1 == F2) << endl;
	cout << "F1 != F2 is : " << (F1 != F2) << endl;
	cout << "F1 != F3 is : " << (F1 != F3) << endl;
	cout << "F1 == F3 is : " << (F1 == F3) << endl;
	cout << "F3 == 1 is : " << (F3 == 1) << endl;
	cout << "1 == F3 is : " << (1 == F3) << endl;
	cout << "F3 == 2 is : " << (F3 == 2) << endl;
	cout << "2 == F3 is : " << (2 == F3) << endl;
	cout << "F1 == F1 is : " << (F1 == F1) << endl;
	cout << "(F1+1) == (1+F1) is : " << ((F1 + 1) == (1 + F1)) << endl;
	cout << "(F1*F2) == (F1*F2) is : " << ((F1*F2) == (F1*F2)) << endl;
	cout << "(F1/F2) == (F1/F2) is : " << ((F1 / F2) == (F1 / F2)) << endl;
	cout << "(F1-F2) == (F1-F2) is : " << ((F1 - F2) == (F1 - F2)) << endl;
	cout << "(F1+1) == (F1+2) is : " << ((F1 + 1) == (F1 + 2)) << endl;
	cout << "(F1*F2) == (F1*F3) is :" << ((F1*F2) == (F1*F3)) << endl;
	cout << "(F1/F2) == (F1/F3) is : " << ((F1 / F2) == (F1 / F3)) << endl;
	cout << "(F1-F2) == (F1-F3) is : " << ((F1 - F2) == (F1 - F3)) << endl;

	system("pause");
	return 0;
}
int main13()
{
	cout << "\nFriend Functions that are istream and ostream operators" << endl;
	Fraction F1;
	Fraction F2;
	Fraction F3;
	cin >> F1 >> F3;//Tests cascaded input
	cout << F1 << endl << F3 << endl;//Tests cascaded output
	system("pause");
	cout << "Enter full path to file from which to read the fraction: ";
	cin.ignore();//Use ignore on Mac
	string inputFile;
	getline(cin, inputFile);
	ifstream in(inputFile);

	if (!in.is_open())
	{
		cout << "Failed to open input file. Exiting program." << endl;
		exit(0);
	}
	in >> F2;//Tests input from file
	cout << "Enter full path to file to which to output the Fraction: ";
	cin.sync();//Use ignore on Mac
	string outFile;
	getline(cin, outFile);
	ofstream out(outFile);
	if (!out.is_open())
	{
		cout << "Failed to create output file. Exiting program." << endl;
		exit(0);
	}
	cout << "The fraction read from file is: " << F2 << endl;
	cout << "Now wrting to file." << endl;
	out << F2;//Tests output to file
	in.close();
	out.close();

	system("pause");
	return 0;
}
int main14()
{
	cout << "\nMember Functions pre and post fix increment and decrement operators" << endl;
	Fraction F1(-8, -16);
	Fraction F2(6, -12);
	cout << "F1 = " << F1 << endl;
	cout << "operator++() "<<++F1 << endl;
	cout << "operator++(intmaker)"<<F1++ << endl;
	cout << F1 << endl;
	cout << "F2 = " << F2 << endl;
	cout << "operator--() " << --F2 << endl;
	cout << "operator--(intmaker) " << F2-- << endl;
	cout << F2 << endl;
	
	system("pause");
	return 0;
}
int main15()
{
	cout << "\nNon mutator member functions" << endl;
	Fraction F(-8, -16);
	cout << "Fraction is: " << F << endl;
	cout << "The numerator is: " << F.getTop() << endl;
	cout << "The denominator is: " << F.getBottom() << endl;
	cout << "The double value is: " << F.toDouble() << endl;
	system("pause");
	return 0;
}
