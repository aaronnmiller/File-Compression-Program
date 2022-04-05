#pragma once
#include <functional>
#include "Node.h"

using namespace std;

bool insertNode(Node* node, string letters, int frequency);

class BinaryTree {
public:
    BinaryTree(){
        root = nullptr;
    }
    BinaryTree(Node* node) {
        root = node;
    }

    void insert(string letters, int frequency) {
        if (root) {
            insertNode(root, letters, frequency);
        } else {
            root = new Node(letters, frequency);
        }
    }

    Node* getRoot() {
        return root;
    }
private:
    Node* root;
};

bool insertNode(Node* node, string letters, int frequency) {
    if (!node) {
        return false;
    }
    if (frequency <= node->frequency) {
        if (!insertNode(node->left, letters, frequency)) {
            node->left = new Node(letters, frequency);
        }
    } else {
        if (!insertNode(node->right, letters, frequency)) {
            node->right = new Node(letters, frequency);
        }
    }
    return true;
}

void prettyPrint(Node* node, int depth = 0) {
    if (!node) {
        return;
    }

    string spaces = "";
    for (int i = 0; i < depth; i++) {
        spaces += "     ";
    }

    prettyPrint(node->right, depth+1);
    cout << spaces << "(" << node->letters << ", " << node->frequency << ")" << endl;
    prettyPrint(node->left, depth+1);
}
