#include "SkipList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

SkipList :: SkipList(int maxLevel, int maxValue){
  header = new SkipNode;
  header->key = -1;
  header->studentEntry = NULL;
  header->forward = new SkipNode*[maxLevel];
  header->forward[0] = new SkipNode;
  for(int i = 1; i < maxLevel; i++)            //link pointers...
    header->forward[i] = header->forward[0];   //...to last node

  SkipNode *terminatingNode = header->forward[0];
  terminatingNode->key = maxValue;
  terminatingNode->studentEntry = NULL;
  terminatingNode->forward = new SkipNode*[maxLevel];
  for(int i = 0; i < maxLevel; i++)
    terminatingNode->forward[i] = NULL;
  this->maxLevel = maxLevel;
  this->terminatingNode = terminatingNode;
  this->maxValue = maxValue;
  this->size = size;
}

SkipList :: ~SkipList(){
  SkipNode *currNode = header;
  SkipNode *delNode = NULL;
  while(currNode != NULL){
    delNode = currNode;
    currNode = currNode->forward[0];
    delete[] delNode->forward;
    delete delNode;
  }
  cout << "Deleted a SkipList" << endl;
}

int SkipList :: randomLevel(){
  return rand() % (this->maxLevel);
}

void SkipList ::  makeNode(SkipNode *skipNode,
		 int lvl, int searchKey, StudentEntry *studentEntry){
  skipNode->key = searchKey;
  skipNode->studentEntry = studentEntry;
  skipNode->forward = new SkipNode*[maxLevel];
  for(int i = 0; i < lvl; i++)
    skipNode->forward[i] = this->terminatingNode;
  for(int i = lvl; i < maxLevel; i++)
    skipNode->forward[i] = NULL;
}

int SkipList :: insert(StudentEntry *studentEntry){
  int returnValue = 0;
  if(studentEntry == NULL)
    returnValue = 0;
  else{
    int searchKey = studentEntry->getStudid();
    if(searchKey >= this->maxValue){
      cout << "SkipList :: insert() ::cannot insert studentEntry - this studentEntry has higher or equal studid to maxvalue" << endl;
      returnValue = 0;
    }else{
      SkipNode** update = new SkipNode*[maxLevel];  //local
      for(int i = 0; i < maxLevel; i++)
	update[i] = NULL;
      SkipNode *x = header;
      for(int i = maxLevel-1; i >= 0; i--){
	while(x->forward[i]->key < searchKey)
	  x = x->forward[i];
	update[i] = x;
      }
      x = x->forward[0];
      if(x->key == searchKey)
	x->studentEntry = studentEntry;  //overwrite
      else{
	int lvl = randomLevel();
	if(lvl == 0)   
	  lvl = 1;  //make sure node gets in list 
	x = new SkipNode;
	makeNode(x, lvl, searchKey, studentEntry);
	for(int i = 0; i < lvl; i++){
	  x->forward[i] = update[i]->forward[i];
	  update[i]->forward[i] = x;
	}
	size++;
      }
      delete update;
      update = NULL;
      returnValue = 1;
    }
  }
  return returnValue;
}

void free(SkipNode *skipNode){
  if(skipNode == NULL)
    return;
  else{
    delete skipNode->forward;
    skipNode->forward = NULL;
  }
}

void SkipList :: remove(int studid){
  int searchKey = studid;
  SkipNode** update = new SkipNode*[maxLevel];  //local
  for(int i = 0; i < maxLevel; i++)
    update[i] = NULL;
  SkipNode *x = header;
  for(int i = maxLevel-1; i >= 0; i--){
    while(x->forward[i]->key < searchKey)
      x = x->forward[i];
    update[i] = x;
  }
  x = x->forward[0];
  if(x->key == searchKey){
    for(int i = 0; i < this->maxLevel; i++){
      if(update[i]->forward[i] != x)
	break;
      update[i]->forward[i] = x->forward[i];
    }
    free(x);
    delete x;
    x = NULL;
    size--;
  }
  delete update;
  update = NULL;
}

StudentEntry* SkipList :: search(int studid){
  int searchKey = studid;
  SkipNode *x = header;
   for(int i = maxLevel-1; i >= 0; i--){
     while(x->forward[i]->key < searchKey)
       x = x->forward[i];
   }
   x = x->forward[0];
   if(x->key == searchKey)
     return x->studentEntry;
   else
     return NULL;
}

SkipNode* SkipList ::  searchSkipNode(int studid){
  int searchKey = studid;
  SkipNode *x = header;
   for(int i = maxLevel-1; i >= 0; i--){
     while(x->forward[i]->key < searchKey)
       x = x->forward[i];
   }
   x = x->forward[0];
   if(x->key == searchKey)
     return x;
   else
     return NULL;
}

SkipNode* SkipList :: getFirst(){
  if(header->forward[0] != terminatingNode)
    return header->forward[0];
  else
    return NULL;
}

int SkipList :: getSize(){
  return size;
}

void SkipList :: print(){
  SkipNode * currNode = header;
  while(currNode != NULL){
    cout << currNode->key << " node -> next nodes : " << endl;
    for(int i = maxLevel-1; i >= 0; i--){
      if(currNode->forward[i] != NULL){
	cout <<"\t";
	cout << currNode->forward[i]->key << endl;
      }
    }
    cout << endl;
    currNode = currNode->forward[0];
  }
}

SkipIterator* SkipList ::iterator(int studida){
  SkipIterator *it = new SkipIterator(*this, studida);
  return it;
}

SkipIterator* SkipList :: iterator(){
  SkipIterator *it = new SkipIterator(*this);
  return it;
}

SkipIterator :: SkipIterator(SkipList& s, int studida){
  skipNode = new SkipNode;
  skipNode->studentEntry = NULL;
  skipNode->forward = new SkipNode*[1];
  skipNode->forward[0] = s.searchSkipNode(studida);
}

SkipIterator :: SkipIterator(SkipList& s){
  skipNode = new SkipNode;
  skipNode->studentEntry = NULL;
  skipNode->forward = new SkipNode*[1];
  skipNode->forward[0] = s.getFirst();
  firstNode = skipNode;
}

SkipIterator :: ~SkipIterator(){
  delete firstNode;
}

bool SkipIterator :: hasNext(int studidb){
  if(skipNode->forward[0] != NULL && skipNode->forward[0]->key <= studidb)
    return true;
  else
    return false;
}

bool SkipIterator :: hasNext(){
    if(skipNode->forward[0] != NULL && skipNode->forward[0]->forward[0] != NULL)
    return true;
  else
    return false;
}

StudentEntry* SkipIterator :: next(){
  skipNode = skipNode->forward[0];
  return skipNode->studentEntry;
}
