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
        Node* newnode = new Node(key);
        return newnode;
    }

    if (root->item == key)
        return root;

    if (root->item < key) { // recursive approach to insert nodes by recursing down the node
        root->right = insert(root->right, key);
    } else {
        root->left = insert(root->left, key);
    }
    
    return root;
}
Node* Node::Search(Node* root, int key) {
    if(root == nullptr)
        return nullptr;

    if(root->item == key)
        return root;

    if(root->item > key)
        return Search(root->left, key);
    else
        return Search(root->right, key);
}

Node* Node::Delete(Node* root, int key) {
    if (root == nullptr)
        return root;
    
    if(root->item > key) {
        root->left = Delete(root->left, key);
    } else if(root->item < key) {
        root->right = Delete(root->right, key);
    }

    else { // Case if item == key
        if(root->left == nullptr) {
            Node* del = root->right;
            delete root;
            return del;
        }

        if(root->right == nullptr) {
            Node* del = root->left;
            delete root;
            return del;
        }

        // Returns if either right or left node are null
        // Continues if both arent
        Node* successor = root->right;
        while (successor != NULL && successor->left != NULL)
            successor = successor->left;
        root->item = successor->item;
        root->right = Delete(root->right, successor->item);
    }
    return root;
};

Tree::Tree(int key) {
    root = new Node(key);
}

void Tree::insert(int key) {
    root = root->insert(root, key);
}

bool Tree::search(int key)
{
    if(root->Search(this->root, key) != nullptr)
        return true;
    return false;
}

void Tree::del(int key) {
    root->Delete(root, key);
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

Tree::~Tree() {
    while(root!=nullptr) {
        root->Delete(root, root->item);
    }
}
