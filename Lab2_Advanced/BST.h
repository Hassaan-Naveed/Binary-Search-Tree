#pragma once

#include <string>
#include <iostream>

class BST
{

public:
    using KeyType = int;
    using ItemType = std::string;

    BST() = default;

    ItemType* lookup(KeyType);
    void insert(KeyType, ItemType);
    void remove(KeyType);

private:
    struct Node;
    static Node* leaf();
    static bool isLeaf(Node*);
    Node* root = leaf();

    ItemType* lookupRec(KeyType, Node*);
    void insertRec(Node* newNode, Node*&);
};