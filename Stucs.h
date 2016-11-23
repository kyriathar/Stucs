#ifndef STUCS_H
#define STUCS_H

#include "SkipList.h"
#include "HashTable.h"
#include "DoubleLinkedList.h"

class Stucs{
 private:
  SkipList *skipList;
  HashTable *hashTable;

 public:
  Stucs(int maxLevel, int maxValue , int size);
  //~Stucs();
  void insert(int studid, string lastname, string firstname,
	      float gpa, int numofcourses, string deprt,
	      int postcode);
  void query(int studid);
  void modify(int studid, float gpa, int numcourses);
  void del(int studid);
  double raverage(int studida, int studidb);
  void average(int postcode);
  void taverage(int k, int postcode);
  void bottom(int k);
  void coursesToTake(int postcode, string deprt);
  void find(float thresholdGpa);
  void percentile(int postcode);
  void print();
};

#endif
