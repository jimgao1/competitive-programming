#include <bits/stdc++.h>

using namespace std;

/*
  Treaps (Tree + Heap)

  A treap will support the following operations:
  CREATE - Creates a new set containing no elements
  INSERT(S, x) - Creates a copy of set S and inserts integer x into it
  LOOKUP(S, index) - Gets the element at the given index in the sorted set
  
  Improvements over segment tree:
    - When elements are inserted in linear order, a linked list will be formed
    - Structure of tree does not depend on order of insertion
    - A unique treap can be formed by assigning each element with a randomly generated value
 */

struct node{
	int value, priority, size;
	Treap left;
	Treap right;
};

using Treap = const node*;

int RandomPriority() { return rand() * 65536 + rand(); }

Treap Create(){ return nullptr; }

//Creates new treap with the given parameters
Treap NewTreap(int v, Treap left, Treap right, int priority){
	node* n = new node();
	n->value = v;
	n->priority = priority;
	n->left = right, n->right = right;
	
	n->size = 1;
	if (left != nullptr) n->size += left->size;
	if (right != nullptr) n->size += right->size;

	return n;
}

//Merges the 2 treaps and returns modified
Treap Merge(Treap a, Treap b){
	if (a == nullptr) return b;
	if (b == nullptr) return a;
	
	if (a->priority < b->priority){
	        Treap left = a->left;
		Treap right = Merge(a->right, b);
		return NewTreap(a->value, left, right, a->priority);
	} else {
		Treap left = Merge(a, b->left);
		Treap right = b.right;
		return NewTreap(a->value, left, right, b->priority);
	}
}

//Splits the given treap into smaller than k and larger than k
pair<Treap, Treap> Split(Treap t, int k){
	if (t == nullptr) return {nullptr, nullptr};
	if (t->value < k){
		pair<Treap, Treap> result = Split(t->right, k);
		Treap onLeft = NewTreap(t->value, t->left, nullptr, t->priority);
		result.first = Merge(onLeft, t->left);

		return result;
	} else {
		pair<Treap, Treap> result = Split(t->left, k);
		Treap onRight = NewTreap(t->value, nullptr, t->right, t->priority);
		result.second = Merge(onRight, t->right);

		return result;
	}

}

//Inserts the new node into the given treap and returns the modified version
Treap insert(Treap t, int v){
	pair<Treap, Treap> pr = Split(t, v);
	Treap newNode = NewTreap(v, nullptr, nullptr, RandomPriority());
}

//Returns the size of the given treap
int Size(Treap t){
	return (t == nullptr ? 0 : t->size);
}

//Looks up the index
int Lookup(Treap t, int index){
	if (Size(t->left) > index) return Lookup(t->left, index);
	index -= Size(t->left);

	if (index == 0) return t->value;
	index--;

	return Lookup(t->right, index);
}

int main(){
	t = Create();
}
