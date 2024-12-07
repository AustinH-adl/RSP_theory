#pragma once

class Node {
    private:
    friend class LinkedList;
    int data;
    Node* next;
    public:
    Node(int i);
    Node(int i, Node* n);
};

class LinkedList {
    private:
        Node* root;

    public:
        void InsertFront(int i);
        void DeleteFront();

        void printRoot();
        
        void InsertIndex(int i, int index);
        void DeleteIndex(int i, int index);

        bool Empty();

        LinkedList();
        LinkedList(int i);
        ~LinkedList();
};