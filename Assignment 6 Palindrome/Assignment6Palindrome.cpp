#include "Arrayqueue.h"
#include "ItemType.h"
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

void testInt();
void testChar();
void testFloat();
void testString();
/*

CS2
Assignment 6

*/
int main()
{
	ArrayQueue string_ArrayQueue;

	bool done = false;
	string val = string();
	int stringCount;
	bool isPalindrome = false;
	char character;
	Stack stack;
	char stackChar;
	ItemType item;
	ItemType item2;
	
	string stringInput;
	char endChar;

	cout << "Enter the amount of strings that you want to test " ;
	cin >> stringCount;
	cin.clear();
	cin.ignore(128, '\n');
	for (int i = 0; i < stringCount; i++)
	{
		cout << "Please enter an string to be added to the Queue \n";
		
		getline(cin, stringInput);
		cout << endl << stringInput << endl;

		for (int i = 0; i < stringInput.length(); i++)
		{
			character = stringInput.at(i);

			if (isalpha(character))
			{
					item.Character = tolower(character);
					stack.push(item);
					string_ArrayQueue.enqueue(item);
			}
		}
		while (!string_ArrayQueue.isEmpty())
		{

			item2 = stack.top();
			stackChar = item2.Character;
			stack.pop();

			endChar = (string_ArrayQueue.dequeue()).Character; //dequeuing is first in first out

			if (endChar == stackChar)
			{
				isPalindrome = true;
			}
			else
			{
				isPalindrome = false;
			}
		}
		if (isPalindrome == true)
		{
			cout << "*Is a Palindrome*" << endl << endl;
		}
		else if (isPalindrome == false)
		{
			cout << "*Is NOT a Palindrome*" << endl << endl;
		}
	}

	system("pause");
	return 0;
}

int main2()
{

	//testInt();
	//testChar();
	//testFloat();
	testString();

	return 0;
}

void testInt()
{
	ArrayQueue Int_ArrayQueue;
	cout<<"We will enqueue some integers on the queue now.\n";
	bool done = false;
	int val = int();
	while(!Int_ArrayQueue.isFull()&&!done)
	{
		cout<<"Please enter an integer to be enqueued : ";
		cin>>val;
		ItemType Value;
		Value.Integer = val;
		Int_ArrayQueue.enqueue(Value);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the integers in the Queue.\n";

	while(!Int_ArrayQueue.isEmpty())
	{
		cout<<(Int_ArrayQueue.dequeue()).Integer<<"  ";
	}

	cout<<endl;
}
//---------------------------------------------------------------
void testChar()
{
	ArrayQueue Char_ArrayQueue;
	cout<<"We will enqueue some characters in the Queue now.\n";
	bool done = false;
	char val = char();
	while(!Char_ArrayQueue.isFull()&&!done)
	{
		cout<<"Please enter an character to be put in the Queue : ";
		cin>>val;
		ItemType Value;
		Value.Character = val;
		Char_ArrayQueue.enqueue(Value);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the characters in the Queue.\n";

	while(!Char_ArrayQueue.isEmpty())
	{
		cout<<(Char_ArrayQueue.dequeue()).Character<<"  ";
	}
	cout<<endl;
	system("pause");
}
//-------------------------------------------------------------
void testFloat()
{
	ArrayQueue Float_ArrayQueue;
	cout<<"We will enqueue some floating point numbers in the Queue now.\n";
	bool done = false;
	float val = float();
	while(!Float_ArrayQueue.isFull()&&!done)
	{
		cout<<"Please enter a floating point number to be added to the Queue : ";
		cin>>val;
		ItemType Value;
		Value.Float = val;
		Float_ArrayQueue.enqueue(Value);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the floating point numbers  in the Queue.\n";

	while(!Float_ArrayQueue.isEmpty())
	{
		cout<<(Float_ArrayQueue.dequeue()).Float<<"  ";
	}
	cout<<endl;
	system("pause");
}
//-------------------------------------------------------------
void testString()
{
	ArrayQueue string_ArrayQueue;
	cout<<"We will enqueue some strings in the Queue now.\n";
	bool done = false;
	string val = string();
	while(!string_ArrayQueue.isFull()&&!done)
	{
		cout<<"Please enter an string to be added to the Queue : ";
		cin>>val;
		ItemType Value;
		Value.string_data = val;
		string_ArrayQueue.enqueue(Value);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the strings in Queue.\n";

	while(!string_ArrayQueue.isEmpty())
	{
		cout<<(string_ArrayQueue.dequeue()).string_data<<"  ";
	}
	cout<<endl;

	system("pause");
}
//---------------------------------------------------------------

/*
We will enqueue some integers on the queue now.
Please enter an integer to be enqueued : 1
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 2
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 3
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 4
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 5
More data? Enter 0 to continue and 1 to exit: 1
Now printing the integers in the Queue.
1  2  3  4  5

*/