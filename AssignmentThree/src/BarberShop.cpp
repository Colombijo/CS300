//BarberShop.cpp

#include <iostream>
#include "LinkedStack.h"
#include "BarberShop.h"
using namespace std;

     public:
     LinkedStack<Customer> s1;
     LinkedStack<Customer> s2;
     void addCustomer(Customer);
     Customer nextCustomer();
	BarberShop::BarberShop<Customer> s1;
	BarberShop::BarberShop<Customer> s2;


void BarberShop::addCustomer(Customer& customer){
	s1.push(customer);

}
Customer BarberShop:: nextCustomer(){
	Customer nextCustomer; //Creates new customer
	while (!s1.isEmpty()) { //
		s2.push(s1.pop()); //Pushes the s1 values in reverse order to s2
	}
	nextCustomer = s2.pop(); //Gives the value of the next customer
	while (!s2.isEmpty()) {
		s1.push(s2.pop()); //Pushes the s2 values back into s1
	}
	return newCustomer;
}



