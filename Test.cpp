using namespace std;
#include "BinarySearchTree.h"
#include <iostream>
int main() {
	BinarySearchTree<int> tree;
	int x;
	cout<<"Enter a number(0 to exit):";
	cin>>x;
	while (x != 0) {
		tree.insert(x);
		cout<<"Enter a number(0 to exit):";
		cin>>x;
	}
	cout<<"inorder traversal:";
	tree.inOrder();
	cout<<endl;
	cout<<"preorder traversal:";
	tree.preOrder();
	cout<<endl;
	cout<<"postorder traversal:";
	tree.postOrder();
	cout<<endl;
	cout<<"Node count:"<<tree.nodeCount()<<endl;
	cout<<"Leaves count:"<<tree.leaveCount()<<endl;
	cout<<"Height:"<<tree.height()<<endl;
}




