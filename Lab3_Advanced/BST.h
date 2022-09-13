#pragma once

#include <string>

class BST
{

public:
    using KeyType = int;
    using ItemType = std::string;

    BST() = default;

    ItemType* lookup(KeyType);
    void insert(KeyType, ItemType);
    void remove(KeyType);
    void displayEntries();
    void displayTree();

private:
    struct Node;

    static Node* leaf();
    static bool isLeaf(Node*);
    Node* root = leaf();

    ItemType* lookupRec(KeyType, Node*);
    void displayEntriesRec(Node*);
    void insertRec(Node* newNode, Node*&);
    void displayTreeRec(Node*, int);
};