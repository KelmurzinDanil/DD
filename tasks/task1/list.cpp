#include "list.h"
List::List() : first(nullptr), last(nullptr) {}

bool List::is_empty() { return first == nullptr; }

void List::clear() {
    Node* current = first;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    first = nullptr;
    last = nullptr;
}

void List::push_front(int _val) {
    Node* newNode = new Node(_val);
    if (is_empty()) {
        first = newNode;
        last = newNode;
    } else {
        newNode->next = first;
        first = newNode;
    }
}

void List::push_back(int _val) {
    Node* newNode = new Node(_val);
    if (is_empty()) {
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

Node* List::find(int _val) {
    Node* current = first;
    while (current != nullptr) {
        if (current->val == _val) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void List::remove_front() {
    if (is_empty()) { return; }

    Node* temp = first;
    if (first == last) {
        first = nullptr;
        last = nullptr;
    } else {
        first = first->next;
    }
    delete temp;
}

void List::remove_back() {
  if (is_empty()) {
      return;
  }
  if (first == last) {
      delete first;
      first = nullptr;
      last = nullptr;
      return;
  }
  Node* current = first;
  while (current->next != last) {
      current = current->next;
  }
  delete last;
  last = current;
  last->next = nullptr;
}

bool List::remove(const Node* _node) {
    if (is_empty() || _node == nullptr) {
        return false;
    }
    if (_node == first) {
        remove_front();
        return true;
    }
    if (_node == last) {
        remove_back();
        return true;
    }
    Node* current = first;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current == _node) {
          if (prev) {
             prev->next = current->next;
             }
          delete current;
           return true;
          }
        prev = current;
        current = current->next;
        }
       return false;
    }