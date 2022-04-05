#pragma once
#include <iostream>

using namespace std;

struct Node {
    //Using curly braces for the constructor did not compile, only parenthesis worked
    Node(string letters, int frequency, Node* next=nullptr,
    Node* left=nullptr , Node* right=nullptr)
    :letters(letters), frequency(frequency), next(next),
    left(left), right(right) {};

    string letters;
    int frequency;
    Node* next, *left, *right;
};
