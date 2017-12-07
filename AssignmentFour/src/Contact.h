#ifndef CONTACT_H_
#define CONTACT_H_
#include <iostream>
using namespace std;
class Contact {
	string name; //Contact's name
	int number; //Contact's phone number
public:
	Contact(); //Initial contact constructor
	string getName();
	void setName(string);
	int getNumber();
	void setNumber(int);
	bool operator ==(Contact&);
	bool operator !=(Contact&);
	bool operator >=(Contact&);
	bool operator <(Contact&);
	friend ostream& operator<<(ostream&, Contact&);
};

	Contact::Contact() { //Contact constructor
		name = ""; //Sets name variable to empty string
		number = NULL; //Sets number variable to NULL
	}

	string Contact::getName() { //Returns the name
		return name;
	}

	void Contact::setName(string name) { //Sets the name variable to the one given
		this->name = name;
	}

	int Contact::getNumber() { //Returns the number
		return number;
	}

	void Contact::setNumber(int number) { //Sets the number variable to the one given
		this->number = number;
	}

	bool Contact::operator ==(Contact& c) { //Determines if 2 names are equal to each other
		return c.name == this->name;
	}

	bool Contact::operator !=(Contact& c) { //Determines if 2 names are not equal to each other
		return c.name != this->name;
	}

	bool Contact::operator >=(Contact& c) { //Determines if 1 name is greater or equal to another
		return c.name >= this->name;
	}

	bool Contact::operator <(Contact& c) { //Determines if 1 name is less than another
		return c.name < this->name;
	}

	ostream& operator<<(ostream& updatedFile, Contact& c) { //Function that sets the form in which
															//the name and number should be displayed
		updatedFile << c.name << " :" << c.number;
		return updatedFile;
	}





#endif /* CONTACT_H_ */
