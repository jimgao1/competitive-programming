#include <iostream>

#define null NULL

using namespace std;

struct node{
	int value;
	node *left;
	node *right;
};

node* create_node(int data){
	node *newNode = new node();
	newNode->value = data;
	newNode->left = null;
	newNode->right = null;

	return newNode;
}

node* insert(node* current, int data){
	if (current == null){
		current = create_node(data);
	}
	else if (data <= current->value)
		current->left = insert(current->left, data);
	else
		current->right = insert(current->right, data);

	return current;
}

node* find_minimum(node* current){
	while (current->left != null)
		current = current->left;

	return current;
}

node* delete_node(node* current, int data){
	/*
		If the current node is null, then there is no tree
		under the current node

		else, use recursion to find the node
	*/
	if (current == null) return current;
	
	if (data < current->value)
		current = delete_node(current->left, data);
	else if (data > current->value)
		current = delete_node(current->right, data);
	else {
		/*
			Case 1: If the current node has no child
				Delete the current node

			Case 2: If there is one child
				Promote the left/right child to current
				position, and delete current node

			Case 3: Neither the left nor the right is NULL
				Find the minimum of the right sub-tree, 
				promote it to the current position, and
				delete the minimum node on the right
		*/

		if (current->left == null && current->right == null){
			delete current;
			current = null;
		}
		else if (current->left == null || current->right == null){
			if (current->left == null){
				node* temp = current;
				current = current->right;
				delete temp;
			}
			else {
				node* temp = current;
				current = current->left;
				delete temp;
			}
		}
		else {
			node* min = find_minimum(current->right);
			current->value = min->value;
			current->right = delete_node(current->right, min->value);
		}
	}

	return current;
}

bool search(node* current, int data){
	if (current == null) return false;
	if (current->value == data) return true;

	if (data < current->value)
		return search(current->left, data);
	else
		return search(current->right, data);
}

void in_order(node* n){
	if (n == null) return;

	in_order(n->left);
	cout << n->value << " ";
	in_order(n->right);
}

int main(){
	node *root = null;

	/*
		Operations go here...
	*/
}
