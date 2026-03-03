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

  bool empty() const
  {
    return head == nullptr;
  }

  void push_back(const T& value) {
    Node* newNode = new Node(value);

      if (empty()) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        } else {
    Node* tail = head->prev;

      newNode->next = head;
      newNode->prev = tail;

      tail->next = newNode;
      head->prev = newNode;

        }
    }
};

#endif
