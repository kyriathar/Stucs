#include "StudentEntryList.h"
#include <iostream>

using namespace std;

StudentEntryList :: StudentEntryList(){
  first = NULL;
  size = 0;
}

StudentEntryList :: ~StudentEntryList(){
  cout << "Destroying a StudentEntryList" << endl;
}

int StudentEntryList :: getSize(){
  return size;
}

void StudentEntryList :: insert(StudentEntry *studentEntry){
  if(studentEntry == NULL){
    cout << "StudentEntryList :: studentEntry == NULL" << endl;
    return;
  }else{
    StudentEntryNode *newNode= new StudentEntryNode;
    newNode->studentEntry = studentEntry;
    if(first == NULL){
      first = newNode;
      size++;
    }else{
      StudentEntryNode *currNode = first;
      while(currNode->next != NULL){
	currNode = currNode->next;
      }
      currNode->next = newNode;
      currNode = currNode->next;
      currNode->next = NULL;
      size++;
    }
  }
}

void StudentEntryList :: remove(int studid){
  if(first == NULL)
    return;
  else{
    StudentEntryNode *delNode = NULL;
    if(first->studentEntry->getStudid() == studid){
      delNode = first;
      first = first->next;
      size--;
    }else{
      StudentEntryNode *currNode = first;
      StudentEntryNode *previous = NULL;
      while(currNode->next != NULL){
	previous = currNode;
	currNode = currNode->next;
	if(currNode->studentEntry->getStudid() == studid){
	  delNode = currNode;
	  previous->next = currNode->next;
	  currNode = previous;
	  size--;
	  break;
	}
      }
    }
    if(delNode != NULL)
      delete delNode;
  }
}

StudentEntry* StudentEntryList :: search(int studid){
  StudentEntryNode *currNode = first;
  while(currNode != NULL){
    if(studid == currNode->studentEntry->getStudid())
      return currNode->studentEntry;
    currNode = currNode->next;
  }
  return NULL;
}

StudentEntryNode* StudentEntryList :: getFirst(){
  return first;
}

void StudentEntryList :: print(){
  if(size == 0){
    cout << "List is empty!" << endl;
  }else{
    StudentEntryNode *currNode = first;
    while(currNode != NULL){
      cout << (currNode->studentEntry)->getLastname();
      if(currNode->next != NULL)
	cout << " -> ";
      currNode = currNode->next;
    }
    cout << endl;
  }
}

StuIterator* StudentEntryList :: iterator(){
  StuIterator *it = new StuIterator(*this);
  return it;
}

StuIterator :: StuIterator(StudentEntryList& studentEntryList){
  currNode = new StudentEntryNode;
  currNode->studentEntry = NULL;
  currNode->next = studentEntryList.getFirst();
}

bool StuIterator :: hasNext(){
  if(currNode->next != NULL)
    return true;
  else
    return false;
}

StudentEntry* StuIterator :: next(){
  currNode = currNode->next;
  return currNode->studentEntry;
}
