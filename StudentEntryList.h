#ifndef STUDENTENTRYLIST_H
#define STUDENTENTRYLIST_H

#include "StudentEntry.h"

typedef struct StudentEntryNode StudentEntryNode ;

struct StudentEntryNode{
  StudentEntryNode *next;
  StudentEntry *studentEntry ;
};

class StuIterator;

class StudentEntryList{
 private :
  StudentEntryNode *first;
  int size;

 public :
  StudentEntryList();
  ~StudentEntryList();
  int getSize();
  void insert(StudentEntry *studentEntry);
  void remove(int studid);
  StudentEntry* search(int studid);
  StudentEntryNode* getFirst();
  void print();
  StuIterator* iterator();
};

class StuIterator{
 private:
  StudentEntryNode *currNode;

 public:
  StuIterator(StudentEntryList& studentEntryList);
  bool hasNext();
  StudentEntry* next();  
};

#endif
