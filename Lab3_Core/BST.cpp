#include "BST.h"

Node::Node(int theKey, std::string theItem)
{
	key = theKey;
	item = theItem;
}

BST::BST()
{
	root = nullptr;
}

void BST::displayEntries()
{
	displayEntriesRec(root);
}

void BST::displayEntriesRec(Node* currentNode)
{
    if (currentNode == nullptr) return;

    // pre-order traversal code goes here
	
    displayEntriesRec(currentNode->leftChild);

    // in-order traversal code goes here
	std::cout << currentNode->key << ": " << currentNode->item << std::endl;

    displayEntriesRec(currentNode->rightChild);

    // post-order traversal code goes here
}

std::string* BST::lookup(int soughtKey)
{
	Node* currentNode = root;
	bool keyFound = false;

	while (!keyFound) {

		if (currentNode->key == soughtKey) {
			keyFound = true;
		}
		else if (currentNode->key > soughtKey) {
			currentNode = currentNode->rightChild;
		}
		else if (currentNode->key < soughtKey) {
			currentNode = currentNode->leftChild;
		}
		else {
			return nullptr;
		}
	}

	return &(currentNode)->item;
}

void BST::insert(int key, std::string item) {
	Node* newNode = new Node(key, item);
	insertRec(newNode, root);
}

void BST::insertRec(Node* newNode, Node*& rootNode)
{
	if (rootNode == nullptr) {
		rootNode = newNode;
	}
	else {
		if (newNode->key < rootNode->key)
		{
			if (rootNode->leftChild == nullptr)
			{
				rootNode->leftChild = newNode;
			}
			else 
			{
				insertRec(newNode, rootNode->leftChild);
			}
		}
		else if (newNode->key > rootNode->key)
		{
			if (rootNode->rightChild == nullptr)
			{
				rootNode->rightChild = newNode;
			}
			else
			{
				insertRec(newNode, rootNode->rightChild);
			}
		}
		else 
		{
			if (rootNode->leftChild != nullptr)
			{
				newNode->leftChild = rootNode->leftChild;
			}
			if (rootNode->rightChild != nullptr)
			{
				newNode->rightChild = rootNode->rightChild;
			}

			rootNode = newNode;
		}
	}
}