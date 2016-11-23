#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable :: HashTable(int size){
  array = new StudentEntryList[size];
  this->size = size;
  cout << "Creating HashTable " << endl;
}

int hashFunc(int postcode, int size){
  return postcode % size;
}

void HashTable :: add(StudentEntry *studentEntry){
  int postcode = studentEntry->getPostCode();
  int index = hashFunc(postcode, size);
  (*(array+index)).insert(studentEntry);
}

void HashTable :: remove(int postcode, int studid){
  int index = hashFunc(postcode, size);
  array[index].remove(studid);
}

StudentEntry* HashTable :: search(int postcode, int studid){  
  int index = hashFunc(postcode, size);
  return array[index].search(studid);
}

StuIterator* HashTable :: getIter(int postcode){
  int index = hashFunc(postcode, size);
  StuIterator *it = array[index].iterator();
  return it;
}

void HashTable :: print(){
  for(int i = 0; i < size; i++){
    cout << "cell "<< i <<" : " ;
    array[i].print();
  }
}
