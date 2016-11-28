#include "PostCodeList.h"
#include <iostream>

PostCodeList :: PostCodeList(){
  first = NULL;
  last = NULL;
  size = 0;
}

PostCodeList :: ~PostCodeList(){
  PostCodeNode *currNode = first;
  PostCodeNode *delNode = NULL;
  while(currNode != NULL){
    delNode = currNode;
    currNode = currNode->next;
    delete delNode;
  }
  std :: cout << "Deleted a PostCodeList" << std :: endl;
}

bool PostCodeList :: empty(){
  if(first == NULL)
    return true;
  else
    return false;
}

bool PostCodeList :: exists(int postcode){
  bool returnValue = false;
  PostCodeNode *currNode = first;
  while(currNode != NULL){
    if(currNode->postcode == postcode){
      returnValue = true;
      break;
    }
    currNode = currNode->next;
  }
  return returnValue;
}

void PostCodeList :: add(int postcode){
  PostCodeNode *newNode = new PostCodeNode;
  newNode->postcode = postcode;
  newNode->next = NULL;
  if(first == NULL){
    first = newNode;
    last = newNode;
  }else{
    last->next = newNode;
    last = last->next;  //O(1)
  }
}

void PostCodeList :: remove(int postcode){
  PostCodeNode *currNode = first;
  PostCodeNode *previous = NULL;
  PostCodeNode *delNode = NULL;
  if(!empty()){
    if(first->postcode == postcode){ //remove first element
      delNode = first;
      first = first->next;
      if(last == delNode)
	last = first;
    }else{
      while(currNode != NULL){
	previous = currNode;
	currNode = currNode->next;
	if(currNode->postcode == postcode){
	  delNode = currNode;
	  previous->next = currNode->next;
	  if(last == delNode){
	    last = previous;
	  }
	}
      }
    }
  }
}

PostCodeNode* PostCodeList :: getFirst(){
  return first;
}

PostCodeIterator* PostCodeList :: iterator(){
  PostCodeIterator *postCodeIterator = new PostCodeIterator(*this);
  return postCodeIterator;
}

PostCodeIterator :: PostCodeIterator(PostCodeList& postCodeList){
  currNode = new PostCodeNode;
  currNode->postcode = -1;
  currNode->next = postCodeList.getFirst();
  firstNode = currNode;
}

PostCodeIterator :: ~PostCodeIterator(){
  delete firstNode;
}

bool PostCodeIterator :: hasNext(){
  if(currNode->next != NULL)
    return true;
  else
    return false;
}

int PostCodeIterator :: next(){
  currNode = currNode->next;
  return currNode->postcode;
}
