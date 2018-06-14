#include "PostFixEval.h"
#include "TokenizerParser.h"
#include "Stack.h"
#include "ReversePolishNotation.h"
#include <iostream>

using namespace std;


//PostFixEval::PostFixEval(string exp = "")
//{
//	expression = exp; 
//	isNumeric();
//	if (isNumeric() == true)
//	{
//	
//	cout << "\nOriginal Postfix Expression: " << expression << endl;
//	ReversePolishNotation RPN(expression);
//	RPN.convert();
//	cout << "The postfix form is: " << RPN.getOutput() << endl;
//	
//	findValue();
//	}
//
//	
//	value = 0;
//	return ;
//}

PostFixEval::PostFixEval(string Exp = "", bool numeric = false )
{
	expression = Exp;
	value = 0;	
		cout << "\nOriginal Postfix Expression: " << expression << endl;
		ReversePolishNotation RPN(expression);
		RPN.convert();
		cout << "The postfix form is: " << RPN.getOutput() << endl;
		//findValue();
		try
		{
			findValue();
		}
		catch(char *msg)
		{
			cout << msg << endl;
			cout << "No value can be evaluated" << endl;
		}
		if (isNumeric() == true)
		{
		numeric = true;
		}
		
		return ;
}
double PostFixEval::evaluate()
{
	size_t count = 0;
	const int MAX = 200;
	string Str_Arr[MAX];

	TokenizerParser TP; 
	Stack S;
	ItemType num;
	/*ReversePolishNotation RPN(expression);
	RPN.convert();
	string exp = RPN.getOutput();*/

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
					double divide2 =  S.top().Double / divide;
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
					double subtract2 = S.top().Double - subtract ;
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

return value;
}
void PostFixEval::findValue()
{

	if (isNumeric() == true)
	{
		value = evaluate();
		cout << "The evaluated value of the above expression is : " << value << endl;
	}
	else
	{
		cout << "Not pure numeric expression. Value cannot be found" << endl;
	}
}

bool PostFixEval::isNumeric()
{
	if (expression.length() == 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < expression.length(); i++)
		{
			char nextCh = expression[i];
			if (isalpha(nextCh))
			{
				return false;
			}
		}
	}
return true;
}

void PostFixEval::print(ostream & out) const
{
	out << "Original Postfix Expression: " << expression << endl;
	ReversePolishNotation RPN(expression);
	RPN.convert();
	out << "The postfix form is: " << RPN.getOutput() << endl; 
	
	if (value == 0)
	{
		out << "Not pure numeric expression. Value cannot be found" << endl;
	}
	else
	{
		out << "The evaluated value of the above expression is : " << value << endl;
	}
	
	
}
