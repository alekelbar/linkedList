
#pragma once

#include <iostream>
using namespace std;

class Node {

private:
  int data;
  Node *next;
  Node *before;

  friend class LinkedList;
};

class LinkedList {
private:
  Node *list;

public:
  // constructor para definir la dataType de la list...
  LinkedList(int data) {
    this->list = new Node();
    this->list->data = data;
    list->next = NULL;
    list->before = NULL;
  }

  // metodo para saber si una lista esta vacia...
  bool empty() { return !this->list; }

  // constructor para definir la lista por defecto...
  LinkedList() { this->list = new Node(); }

  // metodo para agregar un elemento a la lista...
  void append(int x) {
    Node *node = new Node();
    node->data = x;

    if (empty()) {
      // algoritmo para cuando la lista esta vacia...
      cout << "lista vacia..." << endl;
      list = node;
      node->before = NULL;
      node->next = NULL;
    } else {
      // Algoritmo para cuando la lista no esta vacia...
      node->next = list->next;
      list->next = node;
      node->before = list;
      if (node->next) {
        node->next->before = node;
      }
    }
  }

  void remove() {}

  void watch() {
    Node *node = list;
    // volver al primer elemento de la lista...
    while (node->before)
      node = node->before;
    while (node) {
      cout << node->data << ", ";
      node = node->next;
    }
  }
};