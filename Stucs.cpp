#include "Stucs.h"
#include <iostream>

using namespace std;

Stucs :: Stucs(int maxLevel, int maxValue , int size){
  skipList = new SkipList(maxLevel, maxValue);
  hashTable = new HashTable(size);
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

double Stucs :: raverage(int studida, int studidb){
  double gpaAverage = 0;
  if(skipList->search(studida) == NULL || skipList->search(studidb) == NULL){
    cout << "raverage :: studidx doesn't exist" << endl;
    gpaAverage = -1;
  }else{
    int i = 0;
    SkipIterator *it = skipList->iterator(studida);
    if(it != NULL){
      gpaAverage += it->current()->studentEntry->getGpa();
      i++;
      while(it->hasNext(studidb)){
	gpaAverage += it->next()->studentEntry->getGpa();
	i++;
      }
      gpaAverage = gpaAverage/(double)i;
    }
  }
  return gpaAverage;
}

void Stucs :: average(int postcode){
  string firstname;
  string lastname;
  float gpa;
  StuIterator *it = hashTable->getIter(postcode);
  cout << "average :" << endl;
  cout << "postcode : " << postcode <<endl;
  cout << "firstname\t" << "lastname\t" << "gpa" << endl;
  if(it != NULL){
    if(it->current()->studentEntry->getPostCode() == postcode){
      firstname = it->current()->studentEntry->getFirstname();
      lastname = it->current()->studentEntry->getLastname();
      gpa = it->current()->studentEntry->getGpa();
      cout << firstname << "\t"<< lastname << "\t" << gpa << endl;
    }
    while(it->hasNext()){
      it->next();
      if(it->current()->studentEntry->getPostCode() == postcode){
	firstname = it->current()->studentEntry->getFirstname();
	lastname =  it->current()->studentEntry->getLastname();
	gpa = it->current()->studentEntry->getGpa();
	cout << firstname << "\t"<< lastname << "\t" << gpa << endl;
      }
    }
  }
}

void Stucs :: taverage(int k, int postcode){
  StuIterator *it = hashTable->getIter(postcode);
  DoubleLinkedList l;
  if(it != NULL){
    if(it->current()->studentEntry->getPostCode() == postcode){
      l.add(it->current()->studentEntry);
    }
    while(it->hasNext()){
      it->next();
      if(it->current()->studentEntry->getPostCode() == postcode){
	l.add(it->current()->studentEntry);
      }
    }
    l.bubbleSort();
    l.print(k);
  }
}

void Stucs :: bottom(int k){
  DoubleLinkedList l;
  SkipIterator *it = skipList->iterator();
  if(it != NULL){
    l.add(it->current()->studentEntry);
    while(it->hasNext()){
      it->next();
      l.add(it->current()->studentEntry);
    }
    l.bubbleSort();
    l.printReverse(k);
  }
}

void Stucs :: coursesToTake(int postcode, string deprt){
  string firstname;
  string lastname;
  int numofcourses;
  StuIterator *it = hashTable->getIter(postcode);
  cout << "coursesToTake :" << endl;
  cout << "postcode : " << postcode << endl;
  cout << "deprt : " << deprt << endl;
  cout << "firstname\t" << "lastname\t" << "numofcourses" << endl;
  if(it != NULL){
    if(it->current()->studentEntry->getPostCode() == postcode && it->current()->studentEntry->getDeprt() == deprt){
      firstname = it->current()->studentEntry->getFirstname();
      lastname = it->current()->studentEntry->getLastname();
      numofcourses = it->current()->studentEntry->getNumofcourses();
      cout << firstname << "\t"<< lastname << "\t" << numofcourses << endl;
    }
    while(it->hasNext()){
      it->next();
      if(it->current()->studentEntry->getPostCode() == postcode && it->current()->studentEntry->getDeprt() == deprt){
	firstname = it->current()->studentEntry->getFirstname();
	lastname =  it->current()->studentEntry->getLastname();
	numofcourses = it->current()->studentEntry->getNumofcourses();
	cout << firstname << "\t"<< lastname << "\t" << numofcourses << endl;
      }
    }
  }
}

void Stucs :: find(float thresholdGpa){
  string firstname;
  string lastname;
  float gpa;
  SkipIterator *it = skipList->iterator();
  cout << "find :" << endl;
  cout << "they owe MAXNUM of courses : " << endl;
  cout << "and have gpa more than " << thresholdGpa << " : "  << endl;
  cout << "firstname\t" << "lastname\t" << "gpa" << endl;
  if(it != NULL){
    if(it->current()->studentEntry->getNumofcourses() == MAX_NUMOFCOURSES && it->current()->studentEntry->getGpa() >= thresholdGpa){
      firstname = it->current()->studentEntry->getFirstname();
      lastname = it->current()->studentEntry->getLastname();
      gpa = it->current()->studentEntry->getGpa();
      cout << firstname << "\t"<< lastname << "\t" << gpa << endl;
    }
    while(it->hasNext()){
      it->next();
      if(it->current()->studentEntry->getNumofcourses() == MAX_NUMOFCOURSES && it->current()->studentEntry->getGpa() >= thresholdGpa){
	firstname = it->current()->studentEntry->getFirstname();
	lastname =  it->current()->studentEntry->getLastname();
	gpa = it->current()->studentEntry->getGpa();
	cout << firstname << "\t"<< lastname << "\t" << gpa << endl;
      }
    }
  }
}

void Stucs :: percentile(int postcode){
  float percent = 0.0;
  int localStudents = 0;
  int allStudents = 0;
  StuIterator *it = hashTable->getIter(postcode);
  if(it != NULL){
    if(it->current()->studentEntry->getPostCode() == postcode)
      localStudents++;
    while(it->hasNext()){
      it->next();
      if(it->current()->studentEntry->getPostCode() == postcode)
	localStudents++;
    } 
  }
  allStudents = skipList->getSize();
  percent = (float)localStudents/(float)allStudents;
  cout << "percentile : " << endl;
  cout << "percent of students living in postocode " << postcode <<" : " << percent*100 << " %" << endl;
}

void Stucs :: print(){
  cout << endl;
  cout << "HashTable : " << endl;
  hashTable->print();
  cout << endl;
  cout << "SkipList : " << endl;
  skipList->print();
}
