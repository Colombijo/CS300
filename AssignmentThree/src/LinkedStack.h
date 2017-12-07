#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <string>
using namespace std;
#include <iostream>

template <class T>
struct node {
    T data;
    node<T>* next;
};

template <class T>
class LinkedStack{
      node<T> *top;
   public:
      //provide function prototypes for a Stack here
      void push(T& item);
      T pop();
      T stop();
      bool isEmpty();
      void destroy();
      ~LinkedStack();



};
//provide function implementations here

template <class T>
void LinkedStack<T>::destroy() {
	while (!isEmpty()) { //Destroys stack
		pop();
	}
}

template <class T>
LinkedStack<T>::~LinkedStack() { //Destructor
	this->destroy();
}

template <class T>
void LinkedStack<T>::push(T& item) {
	node<T> *newNode = new node<T>; //Creates new node
	newNode->data = item; //Sets new nodes data to be item passed in
	newNode->next = NULL; //Initializes newNode's data to be NULL
	if (isEmpty()) { //If the current stack is empty
		top = newNode; //newNode is the top node
	} else { //If the current stack is not empty
		newNode->next = top; //Connects newNode to the previous top node
		top = newNode;
	}
}

template <class T>
T LinkedStack<T>::pop() {
	if (top != NULL) { //If the stack is not empty
		node<T> *poppedNode = top; //Assigns popped node pointer to top
		top = top->next; //Sets top to be the one next to it
		T temp = poppedNode->data; //Creates temporary node that's equal to node being popped
		delete poppedNode; //Removes the top node
		return temp; //Deletes the temporary node
	}
}

template <class T>
T LinkedStack<T>::stop() {
	if (top != NULL) { //If the stack is not empty
		return top->data; //Return the node at the top
	}
}

template <class T>
bool LinkedStack<T>::isEmpty() {
	return top == NULL; //Return whether the top has a value or not
}





#endif /* LINKEDSTACK_H_ */
