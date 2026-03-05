#ifndef BILIST_H
#define BILIST_H

#include <iostream>

template <class T>
class BiList {
private:
  // Структура узла двусвязного списка
  struct Node 
  {
    T val;
    Node* next;
    Node* prev;

    Node(const T& value) : val(value), next(nullptr), prev(nullptr) {}
  };

  Node* head;

public:

  // Создание пустого списка
  BiList() : head(nullptr) {}

  // Деструктор (освобождение памяти)
  ~BiList() 
  {
    clear();
  }

  // Проверка, пустой ли список
  bool empty() const 
  {
    return head == nullptr;
  }

  // Добавление элемента в конец списка
  void push_back(const T& value) 
  {
    Node* newNode = new Node(value);

    if (empty()) 
    {
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

  // Добавление элемента в начало списка
  void push_front(const T& value) 
  {
    push_back(value);
    head = head->prev;
  }

  // Удаление элемента с конца списка
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

  // Удаление элемента из начала списка
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

  // Вывод элементов списка
  void print() const 
  {
    if (empty()) 
    {
      std::cout << "Список пуст\n";
      return;
    }

    Node* current = head;

    do {
      std::cout << current->val << " ";
      current = current->next;
    } while (current != head);

    std::cout << std::endl;
  }

  // Очистка списка
  void clear() 
  {
    while (!empty()) 
    {
      pop_front();
    }
  }
};

#endif