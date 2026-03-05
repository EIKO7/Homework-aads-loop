#ifndef BILIST_H
#define BILIST_H

#include <iostream>

template <class T>
class BiList {
private:
  struct Node 
  {
    T val;
    Node* next;
    Node* prev;

    Node(const T& value)
      : val(value), next(nullptr), prev(nullptr) {}
  };

  Node* head;

public:
  BiList() : head(nullptr) {}

  ~BiList() 
  {
    clear();
  }

  bool empty() const 
  {
    return head == nullptr;
  }

  void push_back(const T& value) 
  {
    Node* newNode = new Node(value);

    if (empty()) 
    {
      newNode->next = newNode;
      newNode->prev = newNode;
      head = newNode;
    } else 
    {
      Node* tail = head->prev;

      newNode->next = head;
      newNode->prev = tail;

      tail->next = newNode;
      head->prev = newNode;
    }
  }

  void push_front(const T& value) 
  {
    push_back(value);
    head = head->prev;
  }

  void pop_back() 
  {
    if (empty()) return;

    Node* tail = head->prev;

    if (head == tail) 
    {
      delete head;
      head = nullptr;
    } else {
      Node* newTail = tail->prev;

      newTail->next = head;
      head->prev = newTail;

      delete tail;
    }
  }

  void pop_front() 
  {
    if (empty()) return;

    Node* tail = head->prev;

    if (head == tail) 
    {
      delete head;
      head = nullptr;
    } else {
      Node* newHead = head->next;

      tail->next = newHead;
      newHead->prev = tail;

      delete head;
      head = newHead;
    }
  }

  void print() const 
  {
    if (empty()) 
    {
      std::cout << "List is empty\n";
      return;
    }

    Node* current = head;

    do {
      std::cout << current->val << " ";
      current = current->next;
    } while (current != head);

    std::cout << std::endl;
  }

  void clear() {
    while (!empty()) {
      pop_front();
    }
  }
};

#endif