#pragma once

#include <string>
#include <iostream>

struct Node {
	Node(int, std::string);
	int key;
	std::string item;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
};

class BST {
public:
	BST();
	std::string* lookup(int);
	void insert(int, std::string);
private:
	Node* root;
	void insertRec(Node*, Node*&);
};
