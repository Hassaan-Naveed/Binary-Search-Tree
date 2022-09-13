#include "BST.h"

struct BST::Node
{
	Node(KeyType, ItemType);

	KeyType key;
	ItemType item;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
};

BST::Node::Node(KeyType theKey, ItemType theItem) 
{
	key = theKey;
	item = theItem;
}

BST::Node* BST::leaf()
{
	return nullptr;
}

bool BST::isLeaf(Node* n)
{
	return (n == nullptr);
}

/*
BST::ItemType* BST::lookup(KeyType soughtKey)
{
	Node* currentNode = root;
	bool keyFound = false;

	while (!keyFound) {

		if (currentNode->key == soughtKey) {
			keyFound = true;
		}
		else if (isLeaf(currentNode))
		{
			return nullptr;
		}
		else
		{
			if (currentNode->key > soughtKey) {
				currentNode = currentNode->rightChild;
			}
			else {
				currentNode = currentNode->leftChild;
			}
		}
	}
	return &(currentNode)->item;
}
*/


BST::ItemType* BST::lookup(KeyType soughtKey)
{
	return lookupRec(soughtKey, root);	
}


BST::ItemType* BST::lookupRec(KeyType soughtKey, Node* currentNode)
{
	if (currentNode->key == soughtKey) {
		return &(currentNode)->item;
	}
	else if (isLeaf(currentNode))
	{
		return nullptr;
	}
	else
	{
		if (currentNode->key > soughtKey) {
			lookupRec(soughtKey, currentNode->rightChild);
		}
		else {
			lookupRec(soughtKey, currentNode->leftChild);
		}
	}
}


void BST::insert(KeyType key, ItemType item) {
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