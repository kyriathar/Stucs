#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

DoubleLinkedList :: DoubleLinkedList(){
  first = NULL;
  last = NULL;
  size = 0;
}

DoubleLinkedList :: ~DoubleLinkedList(){
  Node *currNode = first;
  Node *delNode = NULL;
  while(currNode != NULL){
    delNode = currNode;
    currNode = currNode->next;
    delete delNode;
  }
}

void DoubleLinkedList :: add(StudentEntry *studentEntry){
  Node *newNode = new Node;
  newNode->studentEntry = studentEntry;
  newNode->next = NULL;
  newNode->previous = NULL;
  
  if(first == NULL){
    first = newNode;
    size++;
  }
  else{
    Node *currNode = first;
    while(currNode->next != NULL)
      currNode = currNode->next;
    currNode->next = newNode;
    newNode->previous = currNode;
    size++;
  }
  last = newNode;
}

Node* DoubleLinkedList :: getNnode(int position){
  Node* currNode = first;
  int i = 0;
  while(i < position){
    currNode = currNode->next;
    i++;
  }
  return currNode;
}

void DoubleLinkedList :: swap(Node* first, Node* second){
  if(first->previous == NULL){  //case for first Node
    this->first = first->next;
    first->next = second->next;
    second->next->previous = second->previous;
    second->previous = NULL;
    second->next = first;
    first->previous = second;
  }
  else if(second->next == NULL){  //last Node
    first->previous->next = first->next;
    first->next = second->next;
    second->previous = first->previous;
    second->next = first;
    first->previous = second;
  }
  else{
    first->previous->next = first->next;
    first->next = second->next;
    second->next->previous = second->previous;
    second->previous = first->previous;
    second->next = first;
    first->previous = second;
  }
}

void DoubleLinkedList :: bubbleSort(){
  for(int i = 0; i < size-1; i++){
    for(int j = 0; j < size-1-i; j++){
      if(getNnode(j)->studentEntry->getGpa() < getNnode(j+1)->studentEntry->getGpa()){
	swap(getNnode(j), getNnode(j+1));
	if(getNnode(j) == last)
	  last = getNnode(j+1);
      }
    }  
  }
}

void DoubleLinkedList :: print(int k){
  int i = 0;
  string firstname;
  string lastname;
  float gpa;
  Node *currNode = first;
  cout << "taverage :" << endl;
  cout << "postcode : " << first->studentEntry->getPostCode() <<endl;
  cout << "firstname\t" << "lastname\t" << "gpa" << endl;
  while(currNode != NULL && i<k){
    firstname = currNode->studentEntry->getFirstname();
    lastname = currNode->studentEntry->getLastname();
    gpa = currNode->studentEntry->getGpa();
    cout << firstname << "\t"<< lastname << "\t" << gpa << endl;
    currNode = currNode->next;
    i++;
  }
  cout << endl;
}

void DoubleLinkedList :: printReverse(int k){
  int i = 0;
  string firstname;
  string lastname;
  float gpa;
  Node *currNode = last;
  cout << "bottom :" << endl;
  cout << "firstname\t" << "lastname\t" << "gpa" << endl;
  while(currNode != NULL && i<k){
    firstname = currNode->studentEntry->getFirstname();
    lastname = currNode->studentEntry->getLastname();
    gpa = currNode->studentEntry->getGpa();
    cout << firstname << "\t"<< lastname << "\t" << gpa << endl;
    currNode = currNode->previous;
    i++;
  }
  cout << endl;  
}
