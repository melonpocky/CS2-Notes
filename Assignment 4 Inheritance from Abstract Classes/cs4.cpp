/**Make skeleton function for these things**/


class Employee
{
private:
	string FirstName;	//protected
	string LastName;	//protected
	/**Pure Virtual***/
	getFirstName
	getLastName
	getFullName
	setLastName
	setFirstName
	toString
	/********/
	static const int MIN_NUM_CHARS_NAMES; // static and protected

public:

	Employee(const string & Fname = "First name not set", const string & Lname= "Last name not set");
	virtual const string getFirstName() const = 0;
	virtual const string getFullName()const = 0;
	virtual const string getLastName()const = 0;
	virtual const string toString()const = 0;
	
	virtual void setFirstName(string Fname)= 0;
	virtual void setLastName(string Lname) = 0;
Employee::Manager
{
private:
	double salary;
	string TitleOfBoss;
public:

	string getBossTitle();
	string getFirstName();
	string getFullName();
	string getLastName();
	double getSalary();

	Manager(string Fname, string Lname, double sal, string BTitle);
	void setBossTitle(string Title);
	void setFirstName(string Fname);
	void setLastName(string Lname);
	void setSalary(double sal);
	string toString();
}
};

/***EXAMPLE OF PURE VIRTUAL FUNCTION***/

class Employee
{
protected:
	//protected data members are declared here.
public:
	virtual const string getFirstName() const = 0; //Example of declaration of pure virtual function.
};

/***END OF EXAMPLE OF PURE VIRTUAL FUNCTION***/

/*SUMMARY OF PROTECTED ATTRIBUTES OR DATA MEMBERS**/
string FirstName;
string LastName;

static const int MIN_NUM_CHARS_NAMES = 2;

/***MEMBER FUNCTIONS OF EMPLOYEE CLASS CONSTRUCTORS***/

Employee(const string & Fname = "First Name not set", const string & Lname = "Last Name not set")

virtual const string getFirstName() const[pure virtual]

virtual const string getFullName() const[pure virtual]

virtual const string getLastName() const[pure virtual]

virtual void setFirstName(const string & Fname)[pure virtual]

virtual void setLastName(const string & Lname)[pure virtual]

virtual const string toString() const[pure virtual]
/****Summary of Public Member Functions of Manager Class****/

Manager(const string & Fname = "First Name not set", const string & Lname = "Last name not set", double
	sal = 0.0, const string & BTitle = "Boss'es Title not set")
	const string getFirstName() const
	const string getLastName() const
	const string getFullName() const
	const string toString() const
	void setFirstName(const string & Fname)
	void setLastName(const string & Lname)
	double getSalary() const
	const string getBossTitle() const
	void setSalary(double sal)
	void setBossTitle(const string & Title)


	/*****Summary of Protected Attributes or Data members of Manager Class*/
	double salary
	string TitleOfBoss

	Manager(string Fname = "First Name not set", string Lname = "Last name not set", double sal = 0.0, string
		BTitle = "Boss'es Title not set");

	/**Parameters**/
	Fname
	Lname
	sal
	BTitle
	/*****/

	const string getBossTitle() const[virtual]
	const string getFirstName() const[virtual]
	const string getFullName() const[virtual]
	const string getLastName() const[virtual]
	double getSalary() const[virtual]
	
	void setBossTitle(const string & Title)[virtual]
	void setFirstName(const string & Fname)[virtual]
	void setLastName(const string & Lname)[virtual]
	void setSalary(double sal)[virtual]

	const string toString() const[virtual]
	/****Test Source Code****/

Manager M1;
cout << M1.toString() << endl;
Manager M2("F", "L", -200.0, "T");
cout << M2.toString() << endl;
Manager M3("Fran", "Lamar", 4000.99, "Vice President");
cout << M3.toString() << endl;

//Test setLastName

Manager M1("Fran", "Lamar", 4000.99, "Vice President");
cout << M1.toString() << endl;
M1.setLastName("P");
cout << M1.toString() << endl;
M1.setLastName("Prichard");
cout << M1.toString() << endl;

//Test setFirstName

Manager M1("Fran", "Lamar", 4000.99, "Vice President");
cout << M1.toString() << endl;
M1.setFirstName("M");
cout << M1.toString() << endl;
M1.setFirstName("Lisa");
cout << M1.toString() << endl;

//Test Pure Virtual 

Manager M1("Fran", "Lamar", 4000.99, "Vice President");
cout << "First Name: " << M1.getFirstName() << endl;
cout << "Last Name: " << M1.getLastName() << endl;
cout << "Full Name: " << M1.getFullName() << endl;

// Test Boss Title
Manager M1("Fran", "Lamar", 4000.99, "Vice President");
M1.setSalary(-6000.55);
M1.setBossTitle("X");
out << "Current Salary: $" << M1.getSalary() << endl;
cout << "Current title of boss: " << M1.getBossTitle() << endl;
M1.setBossTitle("Executive Manager");
cout << "Current title of boss: " << M1.getBossTitle() << endl;
