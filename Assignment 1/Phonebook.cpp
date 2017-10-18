#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Contact.h"

void intro() {
	cout<<"Please choose an operation:"<<endl;
	cout<<"A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit): ";
}

ofstream& operator<<(ofstream& updatedFile, const Contact& c) {
	updatedFile << c.getName() << " " << c.getNumber();
	return updatedFile;
}
int main () {
string line;
    int counter = 0; // counts the number of contacts in the file
    ifstream myfile ("phonebook.txt");
    while (getline(myfile,line)) {
    	counter++;
    }
    myfile.clear();
    myfile.seekg(0,myfile.beg);
    cout<<"***MY	PHONEBOOK	APPLICATION***"<<endl;
    intro();
    char decision;
    cin >>decision;
    Contact *array = new Contact[counter * 2]; //creates new array of contact objects
    string nameFirst;
    string nameSecond;
    int number;
    for (int i = 0; i < counter; i++) {
    	myfile >> nameFirst >> nameSecond >> number;
    	array[i].setName(nameFirst + " " + nameSecond); // makes the name variables into 1 name
    	array[i].setNumber(number);
    }
    while (decision != 'q' && decision != 'Q') {
    	if (decision=='a' || decision=='A') {
    		counter++;
    		cout<<"Enter name: ";
    		string newNameFirst;
    		cin>>newNameFirst;
    		string newNameLast;
    		cin>>newNameLast;
    		cout<<"Enter phone: ";
    		int newNumber;
    		cin>>newNumber;
    		array[counter-1].setName(newNameFirst + " " + newNameLast);
    		array[counter-1].setNumber(newNumber);
    		cout<<endl;
    	} else if (decision=='l' || decision=='L') {
    		for (int i = 0; i < counter; i++) {
    			cout<<array[i].getName()<<" "<<array[i].getNumber()<<endl;
    		}
    		cout<<endl;
    	} else if (decision=='s' || decision=='S') {
    		cout<<"Enter name: ";
    		string searchNameFirst;
    		cin>>searchNameFirst;
    		string searchNameSecond;
    		cin>>searchNameSecond;
    		string searchName = searchNameFirst + " " + searchNameSecond;
    		for (int i = 0; i < counter; i++) {
    			if (array[i].getName()==searchName) {
  				cout<<"Phone number: "<<array[i].getNumber();
    			}
    		}
    		cout<<endl<<endl;
  		} else if (decision=='d' || decision=='D') {
  			cout<<"Enter name:";
  			string deleteNameFirst;
  			cin>>deleteNameFirst;
  			string deleteNameSecond;
  			cin>>deleteNameSecond;
  			string deleteName = deleteNameFirst + " " + deleteNameSecond;
  			for (int i = 0; i < counter; i++) {
  				if (array[i].getName()==deleteName) {
  					counter--;
  					for (int j = i; j < counter; j++) {
  						array[j].setName(array[j+1].getName());
  						array[j].setNumber(array[j+1].getNumber());
  					}
  				}
  			}
  			cout<<endl;
  		} else if (decision=='q' || decision=='Q') {
  			for (int i = 0; i < counter; i++) {
  				break;
    		}
  		}
    	cout<<"A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit): ";
    	cin >>decision;
  	}

    ofstream updatedFile("phonebook.txt");
    	for (int i = 0; i < counter; i++) {
    		updatedFile << array[i] <<endl;
     }
     return 0;

}

