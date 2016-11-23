#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "StudentEntry.h"

typedef struct SkipNode SkipNode;

struct SkipNode{
  int key;
  StudentEntry *studentEntry;
  SkipNode **forward;
};

class SkipIterator;

class SkipList{
 private:
  int size;
  int maxLevel;
  int maxValue;
  SkipNode *header;
  SkipNode *terminatingNode;

  //private functions
  int randomLevel();  
  void makeNode(SkipNode *skipNode,
		int lvl, int searchKey, StudentEntry *studentEntry);
  
 public:
  SkipList(int maxLevel, int maxValue);
  //~SkipList();
  int insert(StudentEntry *studentEntry);
  void remove(int studid);
  StudentEntry* search(int studid);
  SkipNode* searchSkipNode(int studid);
  SkipNode* getFirst();
  int getSize();
  void print();
  SkipIterator* iterator(int studida);
  SkipIterator* iterator();
};


class SkipIterator{
 private:
  SkipNode *skipNode;

 public:
  SkipIterator(SkipList& s, int studida);
  SkipIterator(SkipList& s);
  bool hasNext(int studidb);
  bool hasNext();
  StudentEntry* next();
};

#endif
