/*
 * BinarySearchTree.h
 *
 *  Created on: Oct 30, 2017
 *      Author: fatma.serce
 *
 *  Updated on: December 03, 2017
 *  	Co-author: Joey Colombi
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include "Contact.h"
#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node<T>* left;
	node<T>* right;
};

template <class T>
class BinarySearchTree{
private:
	node<T>* root;

	void filter(node<T>*, string); //For filter option
	bool search(node<T>*, string); //For search option
	void inOrder(node<T>*);
	void preOrder(node<T>*);
	void postOrder(node<T>*);
	void destroy(node<T>*);
	int height(node<T>*);
	int max(int, int);
	int nodeCount(node<T>*);
	int leaveCount(node<T>*);
	void insert(node<T>*&, T&);


public:
	BinarySearchTree();
	void insert(T& name){insert(root, name);}
	void filter(string name){filter(root, name);}
	void inOrder(){inOrder(root);}
	void preOrder(){preOrder(root);}
	void postOrder(){postOrder(root);}
	int height(){return height(root);}
	int nodeCount(){return nodeCount(root);}
	int leaveCount(){return leaveCount(root);}
	bool search(string item){return search(root, item);}
//	void insert(T&); //non-recursive function call
	~BinarySearchTree(){destroy(root);}


};

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	root = NULL;
}

template <class T>
void BinarySearchTree<T>::filter(node<T> *p, string name) { //Recursion function for filter function
	if (p != NULL) { //If node is not null
		filter(p->right, name); //Goes to the right of the node
		if (name > p->data.getName()) { //If name given is later alphabetically than current node in tree
			cout<<p->data<<endl; //Prints out name and number for contact
		}
		filter(p->left, name); //Goes to the left child of the current node
	}
}

template <class T>
bool BinarySearchTree<T>::search(node<T> *p, string name) { //Recursion function for search function
	if (p == NULL) { //Base case: If the tree is either empty or reached the end of the tree with no match
		cout<<"There is no contact with this name."<<endl;
		return false;
	} else if (p->data.getName() > name) { //If name at node is greater than name user entered
		return search(p->right, name); //Traverses to the right child of the node
	} else if (name > p->data.getName()) { //If name user entered is greater than name at node
		return search(p->left, name); //Traverses to the left child of the node
	}
	cout<<p->data.getNumber()<<endl; //Exits the if statements without node being NULL means current node is the match
									 //Prints out the number at that node
	return true;
}

template <class T>
void BinarySearchTree<T>::inOrder(node<T>* p){
	if(p!=NULL){
		inOrder(p->right);
		cout<<p->data<<endl;
		inOrder(p->left);
	}
}

//inorder traversal without recursion
//template <class T>
//void BinarySearchTree<T>::inOrder(){
//	stack< node<T>* > s;
//	while(p!= NULL || !s.isEmpty())
//	if(p!= NULL){
//		s.push(p);
//		p = p->left;
//	}else{
//		p = s.pop();
//		cout<<p->data:
//		p = p->right;
//	}
//}

template <class T>
void BinarySearchTree<T>::preOrder(node<T>* p){
	if(p!=NULL){
		cout<<p->data;
		preOrder(p->left);
		preOrder(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::postOrder(node<T>* p){
	if(p!=NULL){
		postOrder(p->left);
		postOrder(p->right);
		cout<<p->data;
	}
}
template <class T>
int BinarySearchTree<T>::max(int x, int y){
	if (x>y)
		return x;
	return y;
}

template <class T>
int BinarySearchTree<T>::height(node<T>* p){
	if(p!=NULL){
		return 1 + max(height(p->left),height(p->right));
	}
	return 0;
}

template <class T>
int BinarySearchTree<T>::nodeCount(node<T>* p){
	if(p==NULL)
		return 0;
	else
		return 1 + nodeCount(p->left) + nodeCount(p->right);
}
template <class T>
int BinarySearchTree<T>::leaveCount(node<T>* p){
	if(p==NULL)
		return 0;
	else if(p->left==NULL && p->right==NULL)
		return 1;
	else
		return leaveCount(p->left) + leaveCount(p->right);
}
template <class T>
void BinarySearchTree<T>::destroy(node<T>* p){
	if(p!= NULL){
		destroy(p->left);
		destroy(p->right);
		delete p;
		p= NULL;
	}
}
//non recursive insert function
//template <class T>
//void BinarySearchTree<T>::insert(T& item){
//	node<T>* newnode = new node<T>();
//	newnode->data = item;
//	newnode->left = newnode->right = NULL;
//	if(root == NULL){
//		root = newnode;
//	}
//	else{
//		node<T>* p = root;
//		node<T>* q;
//		while(p!=NULL){
//			q = p;
//			if(item==p->data){
//				cout<<p->data;
//				cout<<"error"<<endl;
//				return;
//			}
//			else if (item<p->data)
//				p = p->left;
//			else
//				p = p->right;
//		}
//		if(item<q->data)
//			q->left = newnode;
//		else
//			q->right = newnode;
//	}
//
//}
template <class T>
void BinarySearchTree<T>::insert(node<T>*& p, T& item){
	if(p == NULL){
		p = new node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if(item < p->data){
		insert(p->left, item);
	}else{
		insert(p->right, item);
	}

}

#endif /* BINARYSEARCHTREE_H_ */
