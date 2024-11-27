#include "BST.h"

#include <iostream>
#include <queue>

Node::Node(int key) {
    item = key;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

Node* Node::insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (root->item == key)
        return root;

    if (root->item < key) { // recursive approach to insert nodes by recursing down the node
        root->right = insert(root->right, key);
    } else {
        root->left = insert(root->left, key);
    }
    
    return root;
};



Tree::Tree(int key) {
    root = new Node(key);
}

void Tree::insert(int key) {
    root = root->insert(root, key);
}

void Tree::printInOrder(Node* node) {
    if (node == nullptr) {
        return;
    }

    printInOrder(node->left);
    std::cout << node->item << " ";
    printInOrder(node->right);
}

void Tree::printLevelOrder(Node* node) {
    if (node == nullptr) {
        return;
    }

    std::queue<Node*> queue;
    queue.push(node);
    Node* temp = node;
    
    while(!queue.empty()) {
        Node* temp = queue.front();
        queue.pop();
        
        if(temp->left != nullptr)
            queue.push(temp->left);
        
        if(temp->right != nullptr)
            queue.push(temp->right);

        std::cout << temp->item << " ";
    }
    return;
}

void Tree::printPostOrder(Node *node){
    if (node == nullptr)
        return;

    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->item << " ";
}

void Tree::printPreOrder(Node *node) {
    if (node == nullptr)
        return;

    std::cout << node->item << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void Tree::InOrder() {
    printInOrder(root);
}

void Tree::LevelOrder() {
    printLevelOrder(root);
}

void Tree::PostOrder() {
    printPostOrder(root);
}

void Tree::PreOrder() {
    printPreOrder(root);
}
