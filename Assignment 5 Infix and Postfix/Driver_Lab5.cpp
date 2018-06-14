#include "ItemType.h"
#include "PostFixEval.h"
#include "Stack.h"
#include "StackInterface.h"
#include "ReversePolishNotation.h"
#include "TokenizerParser.h"

/*

CS2
Assignment 5
Date of Successful Run: 4/17/18

*/
//PostFixEval.h
//PostFixEval.cpp
//Driver_Lab5.cpp
using namespace std;
	// 5/5

int main()
	{
		
		string expression;
		bool done = false;
		bool numeric = false;
		
		cout <<
			"Expression must be parenthetically balanced and enclosed in squared brackets" << endl
			<< "Parsing Algorithm only works if more than one space is left between the characters in the inputted expression" << endl <<
			"Evaluated Value for Numeric Expression is going to be a Floating Point Value" << endl
			<< "Enter Infix Expression" << endl;

		getline(cin, expression);

		while (!done)
		{
			cout << "\nEnter your choice.\n"
				<< "1. Print Results to Console and Data File\n"
				<< "2. Print Results to Console\n"
				<< "3. Enter New Expression\n"
				<< "4. Exit" << endl;
			int choice;
			cin >> choice;

			if (choice == 4)
			{
				done = true;
			}
			else if (choice == 1) // Print Results to Console and Data File
			{
				PostFixEval PFE(expression, numeric);

				string OutFileName;
				cin.ignore(128, '\n');
				cout << "Enter full path to output file: ";
				getline(cin, OutFileName);
				ofstream out(OutFileName);

				if (!out.is_open())
				{
					cout << "Error in opening output file. Try again." << endl;
					continue;
				}
				PFE.print(out);
				out.close();
			}
			else if (choice == 2) //Print Results to Console
			{
				
				PostFixEval PFE(expression, numeric);
				
			}
			else if (choice == 3) //Print Results to Console
			{
				cin.ignore(128, '\n');
				cout <<
					"Expression must be parenthetically balanced and enclosed in squared brackets" << endl
					<< "Parsing Algorithm only works if more than one space is left between the characters in the inputted expression" << endl <<
					"Evaluated Value for Numeric Expression is going to be a Floating Point Value" << endl
					<< "Enter Infix Expression" << endl;

				getline(cin, expression);
				PostFixEval PFE(expression, numeric);
			}
		}
	system("pause");
		return 0;
	}

int main25()
	{
		
		//PostFixEval PH2("[3+4*5/2-10]");
		//PostFixEval PH3("[A*B-C/D+E/F]");
		//PostFixEval PH4("[1*2-3/2+9/F]");
		
		system("pause");

	ItemType itm;
	itm.Integer = 5;
	cout << itm.Integer << endl;
	itm.Double = 10.9;
	cout << itm.Double << endl;
	//write down output
	ItemType Itm;
	Itm.string_data = "Jim";
	cout << Itm.string_data << endl;
	//write down output
	Stack stkNames;
	//	ItemType Itm; 
	Itm.string_data = "Zack";
	stkNames.push(Itm);
	Itm.string_data = "Sam";
	stkNames.push(Itm);
	Itm.string_data = "Adam";
	stkNames.push(Itm);

	while (!stkNames.isEmpty())
	{
		ItemType IN;
		IN = stkNames.top();
		cout << IN.string_data << endl;
		stkNames.pop();
	}

	ReversePolishNotation RPN1("[ 3 + 4 * 5 /2 - 10 ]");
	RPN1.convert();
	cout << RPN1.getOutput() << endl;
	ReversePolishNotation RPN2("[ A + B * C /D - E ]");
	RPN2.convert();
	cout << RPN2.getOutput() << endl;

	////write down output
	ReversePolishNotation RPN3("[ A * B - C /D + E/F ]");
	RPN3.convert();
	cout << RPN3.getOutput() << endl;

	system("pause");
	
	const int MAX = 200; 
	string num = "-.33"; 
	
	double val = TokenizerParser::parseDouble(num); 
	cout << val << endl; 
	
	string number = "-35";
	int value = TokenizerParser::parseInt(number);
	cout << value << endl;
	
	string longnum = "-200000000";
	long num1 = TokenizerParser::parseLong(longnum);
	cout << num1 << endl; 
	
	string Str_Arr[MAX];
	string exp = " 4 2 + 3 5 1 - * + "; 
	size_t count = 0;
	TokenizerParser::getStringArray(Str_Arr, exp, MAX, count); 
	for (int index = 0; index < count; index++)
	{
		cout << Str_Arr[index] << endl; 
		cout << endl;
	}
		
	system("pause");
	return 0;
	}
int main30()
	{
		double value;
		string expression;
		cout << "Enter post-fix expression: ";
		getline(cin, expression);
		size_t count = 0;
		const int MAX = 200;
		string Str_Arr[MAX];

		TokenizerParser TP;
		Stack S;
		ItemType num;
		ReversePolishNotation RPN(expression);
		RPN.convert();
		string exp = RPN.getOutput();
	
		TP.getStringArray(Str_Arr, expression, MAX, count);
		for (int i = 0; i < count; i++)
		{
			double num1 = TP.parseDouble(Str_Arr[i]);
			num.Double = num1;

			if (num1 > 0)
			{
				S.push(num);
			}
			else if (num1 == 0)
			{
				if (Str_Arr[i] == "+")
				{
					for (int i = 0; i < 1; i++)
					{
						double add = S.top().Double;
						ItemType add1;

						S.pop();
						double add2 = add + S.top().Double;
						add1.Double = add2; //Depending on where you put this changes things

						S.pop();
						S.push(add1);
						//cout << "Add " << add2 << " " << S.top().Double << endl;
					}
				}
				else if (Str_Arr[i] == "/")
				{
					for (int i = 0; i < 1; i++)
					{
						double divide = S.top().Double;
						ItemType divide1;

						S.pop();
						double divide2 = S.top().Double / divide;
						divide1.Double = divide2;

						S.pop();
						S.push(divide1);
					}
				}
				else if (Str_Arr[i] == "-")
				{
					for (int i = 0; i < 1; i++)
					{
						double subtract = S.top().Double;
						ItemType subtract1;

						S.pop();
						double subtract2 = S.top().Double - subtract;
						subtract1.Double = subtract2;

						S.pop();
						S.push(subtract1);
					}
				}
				else if (Str_Arr[i] == "*")
				{

					for (int i = 0; i < 1; i++)
					{
						double multiply = S.top().Double;
						ItemType multiply1;

						S.pop();
						double multiply2 = multiply * S.top().Double;
						multiply1.Double = multiply2;

						S.pop();
						S.push(multiply1);
					}
				}
			}


		}
		value = S.top().Double;
		cout << value << endl;

		system("pause");
		return 0;
	}