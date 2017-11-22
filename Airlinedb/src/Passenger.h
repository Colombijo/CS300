
#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Passenger {
	string firstName;
	string lastName;
	string phoneNumber;
	string address;

public:
	//void newPassenger();
	bool operator>(Passenger&);
	bool operator==(Passenger&);
	bool operator!=(Passenger&);
	friend ostream& operator<<(ostream&, const Passenger&);
	void setFirstName(string&);
	string& getFirstName();
	void setLastName(string&);
	string& getLastName();
	void setAddress(string&);
	string& getAddress();
	void setPhoneNumber(string&);
	string& getPhoneNumber();
	bool hasNoNumbers(string&);
};

bool Passenger::operator>(Passenger& p1) { //Overloads the > operator for passenger last names
	if (this->lastName > p1.getLastName()) { //If last name is greater than the one passed in, returns true
		return true;
	} else {
		return false;
	}
}

bool Passenger::operator==(Passenger& p1) { //Overloads the == operator for passenger last names
	if (p1.getLastName()==this->lastName) { //If the last names equal each other, return true
		return true;
	}
	return false;
}

bool Passenger::operator!=(Passenger& p1) { //Overloads != operator for passenger last names
	if (p1.getLastName()==this->lastName) { //If the last names don't equal each other, return true
		return false;
	}
	return true;
}

ostream& operator<<(ostream& os, Passenger& p) { //Prints the passenger variables in the appropriate format
	os << p.getFirstName() << " " << p.getLastName() << " [" << p.getAddress() << "] [" << p.getPhoneNumber()<<"]";
	os <<endl;
	return os;
}

string& Passenger::getAddress()  {
	return address;
}

void Passenger::setAddress(string& address) {
	this->address = address;
}

string& Passenger::getFirstName()  {
	return firstName;
}

void Passenger::setFirstName(string& firstName) {
	this->firstName = firstName;
}

string& Passenger::getLastName()  {
	return lastName;
}

void Passenger::setLastName(string& lastName) {
	this->lastName = lastName;
}

string& Passenger::getPhoneNumber()  {
	return phoneNumber;
}

void Passenger::setPhoneNumber(string& phoneNumber) {
	this->phoneNumber = phoneNumber;
}

#endif /* PASSENGER_H_ */
