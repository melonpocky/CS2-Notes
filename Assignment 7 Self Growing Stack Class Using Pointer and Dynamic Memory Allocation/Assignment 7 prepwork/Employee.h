#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <fstream> // IO to files
#include <iomanip>
#include <sstream>
using namespace std;

/*

CS2
Assignment 7 Prepwork
Date of Successful Run: 4/25/18

*/
class Employee {
private: 
	string firstName; 
		 
	string * lastName; 
	int hourWorked; 
	double PayRate; 
	double Salary; 

public: 
	//1. write separate default and explicit constructors. The memory allocation for 
	//pointer lastName is done inside the constructor. 
	//2. Write a copy constructor that makes deep copy. 
	//3. Write an assignment operator that makes deep copy and deletes the memory 
	//allocated to the pointer which is being given a new pointee. 
	//4. Write a virtual destructor that de-allocates the memory allocated by 
	//constructors. 
	//5. Write a toString function that causes no mutation in the object and returns a 
	//const object. 
	//All constructors, copy constructor, assignment operator, and destructor must 
	//have an output statement. Example is: 
	//cout<<”From Employee destructor”<<endl; 


	Employee();
	Employee(string fname , string lname ,int hrsWorked ,
		double payR, double sal );
	void copy(const  Employee & Other);
	//1. Copy constructor
	Employee(const  Employee & Other);
	//2. Assignment operator
	Employee& operator =(const Employee & Other);
	//3. Destructor
	virtual ~Employee();


	const string toString() const;

	}; 

#endif
/*
	Write separate .h and .cpp files. 
		In main function create an object of Employee, print it. 
		Then create two employee objects, 
		one created by default and other by explicit constructor call. 
		Set first object equal to second using assignment operator and then print both. 
		Write the following stand-alone function: 
	void print(Employee E); 
	print, 
		simply prints E to console. 
		Place all your main function code in a pair of curly braces as below: 
	{ 
	//code in main function 
	} 
	Prove to yourself that number of constructor, 
		and copy constructor calls are equal to the number of destructor calls. 
		If not then something is not correct in code. 
		*/