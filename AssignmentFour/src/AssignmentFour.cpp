#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"
#include "Contact.h"
using namespace std;

int main() {
	BinarySearchTree<Contact> *tree = new BinarySearchTree<Contact>(); //Creates new BinarySearchTree
	string line; //Variable for getting into the input file
	string nameFirst;
	string nameSecond;
	int number;
	string name; //Makes first name and last name one variable
	int counter = 0; // counts the number of contacts in the file
	ifstream myFile ("Phonebook.txt");
	while (getline(myFile,line)) {
		counter++; //Counts how many lines there are in the file
	}
	myFile.clear();
	myFile.seekg(0,myFile.beg); //Resets the file to the beginning
	for (int i = 0; i < counter; i++) { //For the amount of lines in the file
		Contact c; //Creates new contact object
		myFile >> nameFirst >> nameSecond >> number; //Sets the data in the file into the contact variables
		name = nameFirst + " " + nameSecond; //Makes the two name variables one
		c.setName(name); //Sets the name given to the contact object's name
		c.setNumber(number); //Sets the number given to the contact object's number
		tree->insert(c); //Inserts contact object into the binary search tree
	}
	cout <<"***MY	PHONEBOOK	APPLICATION***"<<endl; //Introduction
	cout<<"Please choose an operation:"<<endl; //Asks for user input
	cout<<"A(Add) |	S(Search)	| P(Print)	|F(Filter)	|Q(Quit): "; //Asks for user input
	char decision; //User input
	cin>>decision;
	while (decision != 'q' && decision != 'Q') { //While user didn't enter 'Q'
		if (decision == 'A' || decision == 'a') { //If user would like to add a contact
			Contact c; //Creates contact object
			counter++; //Updates counter
			string name; //variable for contact's name
			cout<<"Enter name: ";
			string newFirstName; //Contact's first name
			cin>>newFirstName;
			string newLastName; //Contact's last name
			cin>>newLastName;
			name = newFirstName + " " + newLastName; //Makes name variable from first and last name
			cout<<"Enter phone: ";
			int newNumber; //Contact's phone number
			cin>>newNumber;
			c.setName(name); //Sets contact's objects name to one given
			c.setNumber(newNumber); //Sets contact's objects number to one given
			tree->insert(c); //Insert new object into tree
		} else if (decision == 's' || decision == 'S') { //If user would like to search tree
			cout<<"Enter name: ";
			string searchNameFirst;
			cin>>searchNameFirst;
			string searchNameSecond;
			cin>>searchNameSecond;
			string searchName = searchNameFirst + " " + searchNameSecond; //Makes name one variable
			tree->search(searchName); //Searches tree with name given
		} else if (decision == 'p' || decision == 'P') { //If user would like to print the list of contacts
			tree->inOrder(); //Prints the list of contacts in alphabetical order
			cout<<endl;
		} else if (decision == 'f' || decision == 'F') { //If user would like to filter the
														 //list of contacts
			cout<<"Enter name: ";
			string name;
			string firstName;
			cin>>firstName; //Sets first text given as firstName variable
			string lastName;
			cin>>lastName; //Sets second text given as lastName variable
			name = firstName + " " + lastName; //Makes name one variable
			tree->filter(name); //Filters contact list from the name given
		}
		cout<<"A(Add)	|	S(Search)	| P(Print)	|F(Filter)	|Q(Quit): "; //Goes back to the menu
		cin>>decision; //Asks user for input
		cout<<endl;
	}
	return 0;
}
