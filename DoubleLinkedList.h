#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "StudentEntry.h"

typedef struct Node Node;

struct Node{
  Node *next;
  Node *previous;
  StudentEntry *studentEntry;
};

class DoubleLinkedList{
 private:
  Node *first;
  Node *last;
  int size;
  
 public:
  DoubleLinkedList();
  ~DoubleLinkedList();
  void add(StudentEntry *studentEntry);
  void bubbleSort();
  Node* getNnode(int position);
  void swap(Node* previous, Node* next);
  void print(int k);
  void printReverse(int k);
};

#endif
