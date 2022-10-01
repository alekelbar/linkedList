
#pragma once

#include <iostream>
using namespace std;

class Node
{

private:
  int data;
  Node *next;
  Node *before;

  friend class LinkedList;
};

class List
{
private:
  Node *start;
  Node *end;

  friend class LinkedList;
};

class LinkedList
{
private:
  List *list;
  // metodo auxiliar para crear nodos..
  Node *createNode(int x)
  {
    // cout << "Creando nodo..." << endl;
    Node *node = new Node();
    node->data = x;
    node->next = NULL;
    node->before = NULL;
    return node;
  }

  // Metodo auxiliar para inicializar la lista...
  void inicialize()
  {
    // cout << "Inicializando..." << endl;
    this->list->start = NULL;
    this->list->end = NULL;
  }

  // metodo auxiliar para insertar al inicio...
  void insertStart(int x)
  {
    // cout << "Insertar inicio..." << endl;
    Node *node = createNode(x);
    // lista no vacia..
    if (list->start)
    {
      node->next = list->start;
      (list->start)->before = node;
      list->start = node;
    }
    else
    {
      list->start = list->end = node;
    }
  }

  // metodo auxiliar para insertar al final...
  void insertEnd(int x)
  {
    // cout << "Insertar final..." << endl;
    Node *node = createNode(x);
    // lista no vacia..
    if (list->start)
    {
      node->before = list->end;
      (list->end)->next = node;
      list->end = node;
    }
    else
    {
      list->start = list->end = node;
    }
  }

  // metodo auxiliar para eliminar al inicio...
  void deleteStart()
  {
    // cout << "Borrando al inicio..." << endl;
    if (list->start)
    {
      Node *node = list->start;
      list->start = (list->start)->next;
      delete node;

      if (list->start == NULL)
      {
        list->end = NULL;
      }
    }
  }

  // metodo auxiliar para eliminar al inicio...
  void deleteEnd()
  {
    // cout << "Borrando al final..." << endl;
    if (list->end)
    {
      Node *node = list->end;
      list->end = (list->end)->before;
      delete node;

      if (list->end == NULL)
      {
        list->start = NULL;
      }
    }
  }

public:
  // constructor para definir la list...
  LinkedList()
  {
    inicialize();
  }

  // metodo para saber si una lista esta vacia...
  bool empty() { return !this->list->start; }

  // metodo para agregar un elemento a la lista...
  void at(int x, int p)
  {
    // cout << "Agregando..." << endl;
    Node *aux, *node = createNode(x);
    int idx{0};

    // lista no vacia...
    if (list->start)
    {
      aux = list->start;
      // NOTA: no considerar que p sea mayor que n elementos...
      while (aux && idx < p)
      {
        aux = aux->next;
        idx++;
      }
      if (p == 0) // si es cero...
        insertStart(x);
      else
      {
        if (aux == NULL)
          insertEnd(x);
        else
        {
          node->before = aux->before;
          node->next = aux;
          (aux->before)->next = node;
          aux->before = node;
        }
      }
    }
    else
    {
      list->start = list->end = createNode(x);
    }
  }

  // metodo para eliminar un elemento en una posición...
  void removeAt(unsigned p)
  {
    // cout << "Eliminando..." << endl;
    Node *aux;
    int idx = 0;
    // lista no vacia...
    if (list->start != NULL)
    {
      aux = list->start;
      while (aux->next != NULL && idx < p)
      {
        aux = aux->next;
        idx++;
      }
      if (p == 0)
      {
        deleteStart();
      }
      else
      {
        if (aux->next == NULL)
        {
          deleteEnd();
        }
        else
        {
          (aux->before)->next = aux->next;
          (aux->next)->before = aux->before;
          delete aux;
        }
      }
    }
    else
    {
      // lista vacia... nada que eliminar..
      cout << "Lista vacia..." << endl;
    }
  }

  // metodo para observar los elementos de la lista...
  void watch()
  {
    // cout << "Mostrar..." << endl;
    Node *aux = list->start;
    while (aux)
    {
      cout << aux->data << " ";
      aux = aux->next;
    }
    cout << endl;
  }

  // metodo para observar los elementos de la lista de manera inversa...
  void watchReverse()
  {
    // cout << "Mostrar reverso..." << endl;
    Node *aux = list->end;
    while (aux)
    {
      cout << aux->data << " ";
      aux = aux->before;
    }
    cout << endl;
  }
};