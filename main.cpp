/*
    Name: Aaron Miller
    Assignment: CSC 311 Final Project
    Date: 9 December 2020
*/

#include <iostream>
#include <map>
#include <sstream>

#include "FrequencyTable.h"
#include "priorityQueue.h"
#include "BinaryTree.h"
#include "HuffmanCodes.h"

using namespace std;
int main() {
    try {
        cout << "Enter text: " << endl;
        string text;
        getline(cin, text);

        FrequencyTable table;

        table = build_frequency_table(text);
        cout << "Frequency Table: " << endl;
        map<char, int>::iterator it;
        for (it = table.begin(); it!= table.end(); it++) {
            cout << it->first << ": " << it->second << endl;
        }

        PriorityQueue pq;
        for (it = table.begin(); it != table.end(); it++) {
            stringstream ss;
            ss << it->first;
            Node* n = new Node(ss.str(), it->second);
            pq.insert(n);
        }
        cout << endl << pq << endl;

        cout << endl << "Huffman Encoding Tree: " << endl;
        Node* left = pq.getHead();
        Node* right;
        while (left->next) {
            string letters = left->letters;
            int frequency = left->frequency;
            right=left->next;
            letters += right->letters;
            frequency += right->frequency;
            pq.remove();
            pq.remove();
            Node* n = new Node(letters, frequency);
            n->left = left;
            n->right = right;
            pq.insert(n);
            left = pq.getHead();
        }
        BinaryTree tree(left);
        prettyPrint(tree.getRoot());

        cout << endl <<"Huffman Codes: " << endl;
        HuffmanCodes codeTable = buildCodeTable(tree);
        map<char, string>::iterator itb;
        for (itb = codeTable.begin(); itb!= codeTable.end(); itb++) {
            cout << itb->first << ": " << itb->second << endl;
        }

        string uncompressed = binary(text);
        cout << endl << "Uncompressed Bit Sequence" << endl << uncompressed << endl;

        string encoded = encode(codeTable, text);
        cout << endl <<"Encoded: " << endl << encoded << endl;

        string decoded = decode(encoded, tree);
        cout << endl << "Decoded: " << endl << decoded << endl;

        double uncompressedLength = uncompressed.length();
        double encodedLength = encoded.length();

        cout << endl << "Compressed to " << ((encodedLength / uncompressedLength) * 100) << "% of original size" << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

}
