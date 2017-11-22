
#include <iostream>
#include "OrderedLinkedList.h"
#include "Passenger.h"
using namespace std;

bool isFlightNumber(string flightNumber) { // Determines if flight number entered is a valid one
	if (flightNumber != "100" && flightNumber != "200" && flightNumber != "300" && flightNumber != "400") {
		return false;
	} else {
		return true;
	}
}

bool hasNoNumbers(string name) { //Determines if name has any numbers in it
	if (name.find("0") && name.find("1") && name.find("2") && name.find("3") && name.find("4") &&
		name.find("5") && name.find("6") && name.find("7") && name.find("8") && name.find("9")) {
		return true;
	} else {
		return false;
	}
}

int main() {
	OrderedLinkedList<Passenger>* flight100 = new OrderedLinkedList<Passenger>(); //Linked list for flight 100
	OrderedLinkedList<Passenger>* flight200 = new OrderedLinkedList<Passenger>(); //Linked list for flight 200
	OrderedLinkedList<Passenger>* flight300 = new OrderedLinkedList<Passenger>(); //Linked list for flight 300
	OrderedLinkedList<Passenger>* flight400 = new OrderedLinkedList<Passenger>(); //Linked List for flight 400
	cout<<"***DELTA	AITLINES ***"<<endl;
	cout<<"Please	choose	an	operation:"<<endl;
	cout<<"A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit): ";
	char decision;
	cin>>decision;
	while (decision != 'Q' && decision != 'q') { // As long as user doesn't enter 'q'
		if (decision == 'A' || decision == 'a') {
			Passenger a; // Creates new passenger object
			string flightNumber;
			cout<<"Enter flight number: ";
			cin>>flightNumber;
			cout<<endl;
			while (!isFlightNumber(flightNumber)) { //Makes sure flight number is valid
				cout<<"There is no flight with this number. Try again"<<endl;
				cout<<"Enter flight number: ";
				cin>>flightNumber;
			}
			cout<<"Enter first name: ";
			string firstName;
			cin>>firstName;
			while (!hasNoNumbers(firstName)) { //If it has numbers in name, ask user to try again
				cout<<"Name cannot have any numbers. Please try again."<<endl;
				cout<<"Enter first name: ";
				cin>>firstName;
				cout<<endl;
			}
			a.setFirstName(firstName); // sets first name given for the passenger object
			cout<<endl;
			cout<<"Enter last name: ";
			string lastName;
			cin>>lastName;
			while (!hasNoNumbers(lastName)) { //If it has numbers in name, ask user to try again
				cout<<"Name cannot have any numbers. Please try again."<<endl;
				cout<<"Enter last name: ";
				cin>>lastName;
				cout<<endl;
			}
			a.setLastName(lastName); // sets last name given for the passenger object
			cout<<endl;
			cout<<"Enter address: ";
			string address;
			cin>>address;
			a.setAddress(address); // sets address given for the passenger object
			cout<<endl;
			cout<<"Enter phone: ";
			string phoneNumber;
			cin>>phoneNumber;
			a.setPhoneNumber(phoneNumber); // sets phone number given for the passenger object
			if (flightNumber=="100") {
				flight100->addNode(a);
			} else if (flightNumber=="200") {
				flight200->addNode(a);
			} else if (flightNumber=="300") {
				flight300->addNode(a);
			} else if (flightNumber=="400") {
				flight400->addNode(a);
			}
		}
		if (decision =='S' || decision == 's') {
			Passenger s; //Creates new passenger
			cout<<"Enter flight number: ";
			string flightNumber;
			cin>>flightNumber;
			cout<<endl;
			while (!isFlightNumber(flightNumber)) { //Makes sure flight number is valid
				cout<<"There is no flight with this number. Try again"<<endl;
				cout<<"Enter flight number: ";
				cin>>flightNumber;
			}
			cout<<"Enter first name: ";
			string firstName;
			cin>>firstName;
			s.setFirstName(firstName); //Sets first name given for the passenger object
			cout<<endl;
			cout<<"Enter last name: ";
			string lastName;
			cin>>lastName;
			s.setLastName(lastName); //Sets last name given for the passenger object
			cout<<endl;
			if (flightNumber == "100") {
				flight100->searchList(s);
			} else if (flightNumber == "200") {
				flight200->searchList(s);
			} else if (flightNumber == "300") {
				flight300->searchList(s);
			} else if (flightNumber == "400") {
				flight400->searchList(s);
			}
			cout<<"Flight number: "<<flightNumber<<endl;
			cout<<"First name: "<<s.getFirstName()<<endl;
			cout<<"Last name: "<<s.getLastName()<<endl;
			cout<<"Address: "<<s.getAddress()<<endl;
			cout<<"Phone: "<<s.getPhoneNumber()<<endl;
			cout<<endl;
		}
		if (decision == 'L' || decision == 'l') {
			cout<<"Enter flight number: ";
			string flightNumber;
			cin>>flightNumber;
			while (!isFlightNumber(flightNumber)) { //Makes sure flight number is valid
				cout<<"There is no flight with this number. Try again"<<endl;
				cout<<"Enter flight number: ";
				cin>>flightNumber;
			}
			if (flightNumber=="100") {
				flight100->printList();
			}
			if (flightNumber == "200") {
				flight200->printList();
			}
			if (flightNumber == "300") {
				flight300->printList();
			}
			if (flightNumber == "400") {
				flight400->printList();
			}
		}
		if (decision == 'D' || decision == 'd') {
			cout<<"Enter flight number: ";
			Passenger d; //Creates new passenger object
			string flightNumber;
			cin>>flightNumber;
			cout<<endl;
			while (!isFlightNumber(flightNumber)) { //Makes sure flight number is valid
				cout<<"There is no flight with this number. Try again"<<endl;
				cout<<"Enter flight number: ";
				cin>>flightNumber;
			}
			cout<<"Enter first name: ";
			string firstName;
			cin>>firstName;
			d.setFirstName(firstName); //Sets first name given for the passenger object
			cout<<endl;
			cout<<"Enter last name: ";
			string lastName;
			cin>>lastName;
			d.setLastName(lastName); //Sets last name given for the passenger object
			cout<<endl;
			if (flightNumber=="100") {
				flight100->deleteNode(d);
				cout<<firstName<<" "<<lastName<<" deleted."<<endl;
			} else if (flightNumber=="200") {
				flight200->deleteNode(d);
				cout<<firstName<<" "<<lastName<<" deleted."<<endl;
			} else if (flightNumber=="300") {
				flight300->deleteNode(d);
				cout<<firstName<<" "<<lastName<<" deleted."<<endl;
			} else if (flightNumber=="400") {
				flight400->deleteNode(d);
				cout<<firstName<<" "<<lastName<<" deleted."<<endl;
			}
		}
		cout<<"A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit): "; //Repeats introduction until
																					 // user enters 'q'
		cin>>decision;
	}
	return 0;
}


