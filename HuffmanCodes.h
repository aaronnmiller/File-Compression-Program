#include <iostream>
#include <map>
#include <sstream>
#include "BinaryTree.h"
#include "Node.h"
using namespace std;

bool isLeaf(Node* n);

using HuffmanCodes = map<char, string>;
void getCodes(HuffmanCodes& table, Node* node, string code = "") {
    if (!node->left && !node->right) {
        if (code != "") {
            table.insert(pair<char, string>(node->letters[0], code));
        } else {
            table.insert(pair<char, string>(node->letters[0], "0"));
        }
    } else {
        if (node->left) {
            getCodes(table, node->left, code+'0');
        }
        if (node->right) {
            getCodes(table, node->right, code+'1');
        }
    }
}

HuffmanCodes buildCodeTable(BinaryTree& tree) {
    HuffmanCodes table;
    getCodes(table, tree.getRoot());
    return table;
}

string binary(const string& text) {
    stringstream ss;

    for (char c : text) {
        ss << bitset<8>(c);
    }
    return ss.str();
}

string encode(HuffmanCodes table, const string& input) {
    string encoded;
    for(char c : input) {
        encoded += table[c];
    }
    return encoded;
}

string decode(const string& encoded, BinaryTree tree) {
    string decoded;
    Node* n = tree.getRoot();

    for (int i = 0; i < encoded.length(); i++) {
        if (isLeaf(n)) {
            decoded += n->letters;
            n = tree.getRoot();
        }
        else if (encoded[i] == '0') {
            n = n->left;
            if (isLeaf(n)) {
                decoded+=n->letters;
                n = tree.getRoot();
            }
        }
        else if (encoded[i] == '1') {
            n = n->right;
            if (isLeaf(n)) {
                decoded+=n->letters;
                n = tree.getRoot();
            }
        }
    }
    return decoded;
}

bool isLeaf(Node* n) {
    return (!n->left && !n->right);
}
