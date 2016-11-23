#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "StudentEntryList.h"

class HashTable {
 private:
  StudentEntryList *array;
  int size;
  
 public:
  HashTable(int size);
  void add(StudentEntry *studentEntry);
  void remove(int postcode, int studid);
  StudentEntry* search(int postcode, int studid);
  StuIterator* getIter(int postcode);
  void print();
};

#endif
