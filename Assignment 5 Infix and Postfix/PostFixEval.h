#pragma once
#ifndef POSTFIXEVAL_H
#define POSTFIXEVAL_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "TokenizerParser.h"
#include "Stack.h"

using namespace std;
class PostFixEval
	{
private:
		string expression;
		bool numeric;
		double value;
		
		//bool hasValidValue;
		//bool isValidExp;
		//string source;
protected:
		double evaluate();
		bool isNumeric();
	
		//bool isOperator(char c, wstr);
public:
	PostFixEval(string Exp, bool numeric);
		void findValue();
		//PostFixEval(string exp);
		void print(ostream & out) const;
	};
#endif