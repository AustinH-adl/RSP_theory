#include "BST.h"

int main() {
    Tree* tree = new Tree(5);
    tree->insert(10);
    tree->insert(14);
    tree->insert(2);
    tree->insert(3);
    tree->insert(1);
    tree->PreOrder();
    return 0;
}