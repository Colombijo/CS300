#ifndef CONTACT_H_
#define CONTACT_H_
#include <iostream>
using namespace std;
class Contact {
	string name;
	int number;
public:

	const string& getName() const {
		return name;
	}

	void setName(const string& name) {
		this->name = name;
	}

	int getNumber() const {
		return number;
	}

	void setNumber(int number) {
		this->number = number;
	}

	friend ofstream& operator<<(ofstream& updatedFile, const Contact& c);
};





#endif /* CONTACT_H_ */
