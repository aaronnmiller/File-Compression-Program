#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class PriorityQueue {
protected:
    Node* head;

public:
    PriorityQueue()
        :head(nullptr) {}
    ~PriorityQueue() {
        while (!empty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty() const {
        return (head == nullptr);
    }

    void insert(Node* node) {
        if (empty()) {
            node->next = nullptr;
            head = node;
        } else if (node->frequency < head->frequency) {
            node->next = head;
            head = node;
        } else {
            Node* temp = head;
            while (temp->next && node->frequency >= temp->next->frequency) {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
    }

    void remove() {
        if (!empty()) {
            head = head->next;
        } else {
            throw runtime_error("Attempted to remove from empty queue");
        }
    }

    Node* getHead() {
        if (!empty()) {
            return head;
        }
    }
};

std::ostream& operator<<(std::ostream& os, PriorityQueue& queue) {
    Node* current = queue.getHead();
    os << "PriorityQueue: head";
    while (current) {
        os << " -> " << current->letters << ", " << current->frequency;
        current = current->next;
    }
    return os << " -> nullptr";
}
