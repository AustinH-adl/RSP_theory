#include "LinkedList.h"
#include <iostream>

Node::Node(int i) {
    data = i;
    next = nullptr;
}

void LinkedList::InsertFront(int i)
{
    Node* oldroot = root;

    root = new Node(i);

    root->next = oldroot;
}

void LinkedList::DeleteFront()
{
    if (root !=nullptr) {
        Node* newroot = root->next;
        delete root;
        root = newroot;
        return;
    }
    delete root;
}

void LinkedList::printRoot()
{
    std::cout << root->data << std::endl;
}

void LinkedList::InsertIndex(int i, int index) {
    if (index == 0) {
        InsertFront(i);
        return;
    }
    Node* curr, *prev, *next;
    curr = root;
    int x = 0;
    while (curr != nullptr && x < index) {
        x++;
        prev = curr;
        curr = next;
        next = next->next;
    }
    prev->next = new Node(i, curr);
    prev->next->next = curr;
    return;
}

void LinkedList::DeleteIndex(int i, int index)
{
    if (index == 0) {
        InsertFront(i);
        return;
    }
    Node* curr, *prev, *next;
    curr = root;
    int x = 0;
    while (curr != nullptr && x < index) {
        x++;
        prev = curr;
        curr = curr->next;
    }
    if (curr ==nullptr)
        return;
    next = curr->next;
    delete curr;
    prev->next = next;
}

bool LinkedList::Empty()
{
    if(root!=nullptr) 
        return false;
    else 
        return true;
    
}

LinkedList::LinkedList()
{
    root = nullptr;
}

LinkedList::LinkedList(int i) {
    root = new Node(i);
}

LinkedList::~LinkedList()
{
    Node* curr;
    while(root!=nullptr) {
        curr = root;
        root = root->next;
        delete curr;
    }
    delete root;
}

Node::Node(int i, Node *n)
{
    data = i;
    next = n;
}
