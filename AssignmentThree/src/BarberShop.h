#ifndef BARBERSHOP_H_
#define BARBERSHOP_H_
#include <iostream>
#include <string>
#include "LinkedStack.h"
#include "Customer.h"
#include <sstream>
using namespace std;
class BarberShop {

	LinkedStack<Customer> s1;
	LinkedStack<Customer> s2;
public:
	//Customer();
	void addCustomer(Customer&);
	Customer& nextCustomer();

};







/*#endif /* BARBERSHOP_H_ */

