#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "StudentEntryList.h"
#include "PostCodeList.h"

class HashTable {
 private:
  StudentEntryList *array;
  int size;
  PostCodeList *postCodeList;
  
 public:
  HashTable(int size);
  ~HashTable();
  void add(StudentEntry *studentEntry);
  void remove(int postcode, int studid);
  StudentEntry* search(int postcode, int studid);
  StuIterator* getIter(int postcode);
  PostCodeIterator* getPostIter();
  void print();
};

#endif
