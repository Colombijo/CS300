
#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Passenger.h"
using namespace std;
template <class T>

class OrderedLinkedList: public LinkedList<T> {
public:
	void addNode(T& item);
	bool deleteNode(T& item);
	void printList();
	bool hasNode(T& item);
	void searchList(T& item);
};

template <class T>
void OrderedLinkedList<T>::addNode(T& item) {
	node<T> *newNode = new node<T>; //Creates new node
	newNode->data = item; //Sets new node's data to the item passed in
	newNode->next = NULL; //Initializes new node's next to be node
	node<T> *left; //Creates a pointer that will point to the left of the current pointer
	node<T> *current = this->head; //Creates a pointer that initially points to head
	if (current == NULL) { //If the list is empty
		this->head = this->last = newNode; //new node is the first and the last node in list
		this->count++; // Updates count
	} else { //If the list is not empty
		node<T> *right = current->next; //Creates a new pointer that will point to the right of the current pointer
		int iterator = 0; // Counts how many times it goes through the while loop
		while (right != NULL && newNode->data > current->data) {
			if (iterator > 0) {
				left = current; //Updates left pointer to be left of current if it can exist
			}
			current = right; //Updates current pointer to be next one
			right = right->next; //Updates right to be next one
			iterator++; //Updates iterator
		}
		if (iterator == 1 && current->data > newNode->data) { //If item needs to be placed right after head
			this->head->next = newNode; //Makes newNode connect to head
			newNode->next = current; //Makes newNode connect to what was previously the second node in list
			this->count++; //Updates count
		} else if (right != NULL && newNode->data > current->data) {
			current->next = newNode;
			newNode->next = right;
			this->count++;
		} else if (this->head->data > newNode->data) { //If newNode belongs at front of list
			this->head = newNode; //Makes newNode the new head
			newNode->next = current; //Connects newNode to the original head
			this->count++; //Updates count
		} else if (newNode->data > current->data) { //If newNode belongs in the middle of list
			current->next = newNode; //Connects current to newNode
			newNode->next = right; //Connects newNode to right
			this->count++; //Updates count
		} else if (iterator > 1 && current->data > newNode->data) { //Makes newNode in between left pointer
																    //and current pointer
			left->next = newNode;
			newNode->next = current;
			this->count++; //Updates count
		} else { //If newNode belongs at the end of the list
			this->last = newNode; //Makes last now newNode
			newNode->next = right; //Connects newNode to the right pointer
			this->count++; //Updates count
		}
	}
}

template <class T>
bool OrderedLinkedList<T>::deleteNode(T& item) {
	node<T> *current = this->head; //Creates new pointer and initializes it to front of list
	node<T> *right; //Creates new pointer called "right"
	if (current == NULL) { //If the list is empty
		cout<<"There is no one on this flight. Please try again.";
		return false;
	} else if (current->data == item) { //If the head is equal to the item
		this->head = current->next; //Makes the head the one to the right
		delete current; //Deletes the head
		this->count--; //Updates count
		return true;
	} else if (current->data != item) { //If head isn't equal to item
		right = current->next; //Updates current pointer to the next one on its right
		while (right != NULL && item > right->data) { //Goes through to list until it finds the item,
													  //or where it would be
			current = right; //Updates current to the next one on its right
			right = right->next; //Updates right to the next one on its right
		}
		if (item == right->data) { //If item is equal to what right is pointing to
			current->next = right->next; //Makes the node to the left of right connect
										 //to the node to the right of node
			delete right;	//Deletes node that matches the item passed in
			this->count--; //Updates count
			return true;
		}
	} else {
		cout<<"Passenger not found."; //Item not found, so returns false
		return false;
	}
}

template <class T>
void OrderedLinkedList<T>::printList() {
	if (this->head != NULL) { //If list isn't empty
		node<T> *temp = this->head; //Creates pointer and initializes it to front of list
		while (temp != NULL) { //While the list doesn't reach the end
			cout<<temp->data; //Prints out current node in list
			temp = temp->next; //Updates temp pointer to the next node
		}
		delete temp;
	}
}

template <class T>
void OrderedLinkedList<T>::searchList(T& item) {
	node<T> *current = this->head; //Creates new pointer and initializes it pointing to front of list
	while (current != NULL && item > current->data) { //Goes through list until it finds either the item,
													  //or where it would be
		current = current->next;
	}
	if (current != NULL) {
		item= current->data; //Out of the while loop and list isn't at the end, so item is found
	} else {
		cout<<"Passenger not found."<<endl;
	}
}

#endif /* ORDEREDLINKEDLIST_H_ */
