
#include "LinkedStack.h"
#include "BarberShop.h"
#include "Customer.h"
#include <iostream>
#include<string>
using namespace std;

void reverseDigits(int number) { // Part-IV
	if (number==0) { //If there are no more digits to process
		return;	//Ends the recursive function
	} else {
		cout<<number%10; //Prints out the last digit
		return reverseDigits(number/10); //Divides the number by 10 to get to the next digit
	}
}

int main() {
	cout<<"Part 3:"<<endl;
	string number1;
	string number2;
	LinkedStack<int> *numberOneStack = new LinkedStack<int>(); //Creates stack
	LinkedStack<int> *numberTwoStack = new LinkedStack<int>(); //Creates second stack
	LinkedStack<int> *sum = new LinkedStack<int>(); //Creates third stack for the sum of the 2 stacks
	cout<<"Enter a very large number: ";
	cin>>number1;
	cout<<"Enter a very large number: ";
	cin>>number2;
	int j;
	char ch;
	string bigNumber;
	string littleNumber;
	if (number1.length() >= number2.length()) { //Determines which number is bigger
		bigNumber = number1;
		littleNumber = number2;
	} else {
		bigNumber = number2;
		littleNumber = number1;
	}
	for (int i = 0; i < bigNumber.length(); i++) { //Puts the bigger number into the first stack
		ch = bigNumber[i];
		j = ch-'0';
		numberOneStack->push(j);
	}
	for (int k = 0; k < littleNumber.length(); k++) { //Puts the smaller number into the second stack
		ch = littleNumber[k];
		j = ch-'0';
		numberTwoStack->push(j);
	}
	int x;
	int count = 0;
	bool addOne = false;
	while (!numberOneStack->isEmpty()) { //Since numberOneStack has the bigger number, only depends on this stack
		if (numberTwoStack->isEmpty()) { //Once numberTwoStack gets empty
			x = numberOneStack->pop(); //Only pop digits from the first stack
		} else {
		x = numberOneStack->pop() + numberTwoStack->pop(); //x is last digit of first stack +
														   //the last digit of the second stack
		}
		if ((count + 1) == bigNumber.length()) { //If it's the last time going through the loop
			if (addOne) {
				x = x + 1; //Adds one to the sum
			} else {
			x = x + 0; //x is equal to x
			}
		} else if (count < 1) {
			if (x > 9) { //So that two digits don't get printed at once
				x = x % 10;
				addOne = true; //Makes next digit get another 1 added
			}
		} else {
			if (addOne) {
				x = x + 1;
			}
			if (x > 9 && count > 0) { //If it's not the first time through the loop
				x = x % 10;
				addOne = true;
			} else if (x <= 9 && count > 0) {
				addOne = false;
			}
		}
		count++;
		sum->push(x); //Pushes value of x to the sum stack
	}
	cout<<"sum= ";
	while (!sum->isEmpty()) {
		cout<<sum->pop(); //Pops the last digit in the sum stack
	}
	cout<<endl;
	cout<<"Part 4:"<<endl;
	int number;
	cout <<"Enter a number: ";
	cin>>number;
	reverseDigits(number);

	return 0;
}
