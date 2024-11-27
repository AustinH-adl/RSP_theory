#pragma once

class Node {
    public:
        int item;
        Node* parent;
        Node* left;
        Node* right;
        Node(int key);
        Node* inorderchild(Node* node);
        Node* insert(Node* root, int key);
        Node* Search(Node* root, int key);
        Node* Delete(Node* root, int key);
};

class Tree {
    private:
        Node* root;
        void printInOrder(Node* node);
        void printLevelOrder(Node* node);
        void printPostOrder(Node* node);
        void printPreOrder(Node* node);
    public:
        Tree(int key);
        void insert(int key);
        bool search(int key);
        void del(int key);

        void InOrder();
        void LevelOrder();
        void PostOrder();
        void PreOrder();
        ~Tree();
};