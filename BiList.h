#ifndef BILIST_H
#define BILIST_H

#include <iostream>

template <class T>
class BiList {
private:
  struct Node {
    T val;
    Node* next;
    Node* prev;

    Node(const T& value) : val(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;

public:
    BiList() : head(nullptr) {}

    bool empty() const {
        return head == nullptr;
    }
};

#endif
