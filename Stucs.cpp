#include "Stucs.h"
#include <iostream>

using namespace std;

Stucs :: Stucs(int maxLevel, int maxValue , int size){
  skipList = new SkipList(maxLevel, maxValue);
  hashTable = new HashTable(size);
}

Stucs :: ~Stucs(){
  delete skipList;
  skipList = NULL;
  delete hashTable;
  hashTable = NULL;
}

void Stucs :: insert(int studid, string lastname, string firstname,
		     float gpa, int numofcourses, string deprt,
		     int postcode){
  StudentEntry *studentEntry = new StudentEntry();
  studentEntry->setStudid(studid);
  studentEntry->setLastname(lastname);
  studentEntry->setFirstname(firstname);
  studentEntry->setGpa(gpa);
  studentEntry->setNumofcourses(numofcourses);
  studentEntry->setDeprt(deprt);
  studentEntry->setPostcode(postcode);
  //insert
  if(skipList->insert(studentEntry))
    hashTable->add(studentEntry);
}

void Stucs :: query(int studid){
  StudentEntry *studentEntry = skipList->search(studid);
  if(studentEntry != NULL)
    studentEntry->toString();
  else
    cout << "query :: No Student found !" << endl;
}

void Stucs :: modify(int studid, float gpa, int numcourses){
  StudentEntry *studentEntry = skipList->search(studid);
  if(studentEntry != NULL){
    studentEntry->setGpa(gpa);
    studentEntry->setNumofcourses(numcourses);
  }
  else
    cout << "modify :: No Student found !" << endl;
}

void Stucs :: del(int studid){
  StudentEntry *studentEntry = NULL;
  studentEntry = skipList->search(studid);
  if(studentEntry != NULL){
    skipList->remove(studid);
    int postcode = studentEntry->getPostCode();
    hashTable->remove(postcode, studid);
    delete studentEntry;
    studentEntry = NULL;
  }else
    cout << "delete :: No Student found !" << endl;
}

void Stucs :: raverage(int studida, int studidb){
  double gpaAverage = 0;
  StudentEntry *studentEntry;
  if(skipList->search(studida) == NULL || skipList->search(studidb) == NULL){
    cout << "raverage :: studidx doesn't exist" << endl;
    gpaAverage = -1;
  }else{
    int i = 0;
    SkipIterator *it = skipList->iterator(studida);
    while(it->hasNext(studidb)){
      studentEntry = it->next();
      gpaAverage += studentEntry->getGpa();
      i++;
    }
    delete it;
    gpaAverage = gpaAverage/(double)i;
  }
  cout << "raverage : " << endl;
  cout << "gpaAverage = " << gpaAverage << endl;
}

void Stucs :: average(int postcode){
  string firstname;
  string lastname;
  float gpa;
  StudentEntry *studentEntry;
  StuIterator *it = hashTable->getIter(postcode);
  cout << "average :" << endl;
  cout << "postcode : " << postcode <<endl;
  cout << "firstname\t" << "lastname\t" << "gpa" << endl;
  while(it->hasNext()){
    studentEntry = it->next();
    if(studentEntry->getPostCode() == postcode){
      firstname = studentEntry->getFirstname();
      lastname =  studentEntry->getLastname();
      gpa = studentEntry->getGpa();
      cout << firstname << "\t"<< lastname << "\t" << gpa << endl;
    }
  }
  delete it;
}

void Stucs :: taverage(int k, int postcode){
  StudentEntry *studentEntry;
  StuIterator *it = hashTable->getIter(postcode);
  DoubleLinkedList l;
  while(it->hasNext()){
    studentEntry = it->next();
    if(studentEntry->getPostCode() == postcode){
      l.add(studentEntry);
    }
  }
  delete it;
  l.bubbleSort();
  l.print(k);
}

void Stucs :: bottom(int k){
  DoubleLinkedList l;
  StudentEntry *studentEntry;
  SkipIterator *it = skipList->iterator();
  while(it->hasNext()){
    studentEntry = it->next();
    l.add(studentEntry);
  }
  delete it;
  l.bubbleSort();
  l.printReverse(k);
}

void Stucs :: coursesToTake(int postcode, string deprt){
  string firstname;
  string lastname;
  int numofcourses;
  StudentEntry *studentEntry;
  StuIterator *it = hashTable->getIter(postcode);
  cout << "coursesToTake :" << endl;
  cout << "postcode : " << postcode << endl;
  cout << "deprt : " << deprt << endl;
  cout << "firstname\t" << "lastname\t" << "numofcourses" << endl;
  while(it->hasNext()){
    studentEntry = it->next();
    if(studentEntry->getPostCode() == postcode && studentEntry->getDeprt() == deprt){
      firstname = studentEntry->getFirstname();
      lastname =  studentEntry->getLastname();
      numofcourses = studentEntry->getNumofcourses();
      cout << firstname << "\t"<< lastname << "\t" << numofcourses << endl;
    }
  }
  delete it;
}

void Stucs :: find(float thresholdGpa){
  string firstname;
  string lastname;
  float gpa;
  StudentEntry *studentEntry;
  SkipIterator *it = skipList->iterator();
  cout << "find :" << endl;
  cout << "they owe MAXNUM of courses : " << endl;
  cout << "and have gpa more than " << thresholdGpa << " : "  << endl;
  cout << "firstname\t" << "lastname\t" << "gpa" << endl;
  while(it->hasNext()){
    studentEntry = it->next();
    if(studentEntry->getNumofcourses() == MAX_NUMOFCOURSES && studentEntry->getGpa() >= thresholdGpa){
      firstname = studentEntry->getFirstname();
      lastname = studentEntry->getLastname();
      gpa = studentEntry->getGpa();
      cout << firstname << "\t"<< lastname << "\t" << gpa << endl;
    }
  }
  delete it;
}

void Stucs :: percentile(int postcode){
  float percent = 0.0;
  int localStudents = 0;
  int allStudents = 0;
  StudentEntry *studentEntry;
  StuIterator *it = hashTable->getIter(postcode);
  while(it->hasNext()){
    studentEntry = it->next();
    if(studentEntry->getPostCode() == postcode)
      localStudents++;
  }
  delete it;
  allStudents = skipList->getSize();
  percent = (float)localStudents/(float)allStudents;
  cout << "percentile : " << endl;
  cout << "percent of students living in postocode " << postcode <<" : " << percent*100 << " %" << endl;
}

void Stucs :: percentiles(){
  int postcode;
  PostCodeIterator *it = hashTable->getPostIter();
  cout << "percentiles : " << endl;
  while(it->hasNext()){
    postcode = it->next();
    percentile(postcode);
  }
  delete it;
}

void Stucs :: exit(){
  
}

void Stucs :: print(){
  cout << endl;
  cout << "HashTable : " << endl;
  hashTable->print();
  cout << endl;
  cout << "SkipList : " << endl;
  skipList->print();
}
