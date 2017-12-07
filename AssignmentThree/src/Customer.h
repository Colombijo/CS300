
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>
#include <string>
using namespace std;

class Customer {
	Customer();
private:
	string firstName;
	string lastName;

public:
	void newCustomer();
	void setFirstName(string firstName);
	string getFirstName();
	void setLastName(string lastName);
	string getLastName();
	string getName();
	friend ostream& operator<<(ostream&, const Customer&);
	Customer(string firstName, string lastName);
};

Customer::Customer(string firstName, string LastName) {
	setFirstName(firstName);
	setLastName(lastName);
}

void Customer::setFirstName(string firstName) {
	this->firstName = firstName;
}

string Customer::getFirstName() {
	return firstName;
}

ostream& operator<<(ostream& os, Customer& c) {
	os << c.getFirstName() << " " << c.getLastName() << endl;
	return os;
}


void Customer::setLastName(string lastName) {
	this->lastName = lastName;
}

string Customer::getLastName() {
	return lastName;
}

string Customer::getName() {
	return firstName + lastName;
}


#endif /* CUSTOMER_H_ */
