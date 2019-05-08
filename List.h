#ifndef LIST_H
#define LIST_H

#include "Course.h"
#include <iostream>
using namespace std;

template <class T>
class List {
  public:
    List(); //default constructor
    ~List(); //destructor
    /*
      Function: overloaded += operator
      Purpose: adds a course to the linked list, added in increasing order
      in: course pointer to be added
    */
    List<T>& operator+=(T);
    /*
      Function: print
      Purpose: prints the list
    */
    void print();
  private:

  protected:
    class Node { // node nested class
      friend class List; // give Node access to all List members
      public:
        T data;
        Node* next;
    };

    Node* head; // used internally, for node
    Node* tail; // used internally, for node
};

template <class T>
List<T>::List() : head(0), tail(0) { } // init head, tail to null at first

template <class T>
List<T>::~List() {
    Node* currNode = head;
    Node* nextNode;

    while (currNode != NULL) {
      nextNode=currNode->next;
      delete currNode->data;
      delete currNode;
      currNode = nextNode;
    }
}

template <class T>
List<T>& List<T>::operator+=(T thing) {
  Node* nuNode = new Node();
  nuNode->data = thing;
  nuNode->next = 0;

  Node* currNode = head;
  Node* prevNode = NULL;

  // saves currNode as nuNode's next, or last node in list
  while(currNode != NULL) {
    // insert before
    if (thing->lessThan(currNode->data))
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  // nuNode goes to front
  if (prevNode == NULL) {
    head = nuNode;
  } else { // middle case
      prevNode->next = nuNode;
  }
  // used for front and middle case, does nothing for end case
  nuNode->next = currNode;
  // nuNode added to end
  if (currNode == NULL && prevNode != NULL and prevNode == tail) {
    prevNode->next = nuNode;
    tail = nuNode;
  }

  // empty list case
  if (tail == NULL) {
    tail = nuNode;
  }

  return *this;
}

template <class T>
void List<T>::print() {
  //cout << endl << "LIST: " << endl << endl;
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
  if (head != NULL) {
    cout << endl << "Head: ";
    head->data->print();
    cout << endl << "Tail: ";
    tail->data->print();
    cout << endl;
  }
}

#endif
