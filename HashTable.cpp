#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable :: HashTable(int size){
  array = new StudentEntryList[size];
  this->size = size;
  postCodeList = new PostCodeList;
  cout << "Creating HashTable " << endl;
}

HashTable :: ~HashTable(){
  delete[] array;
  delete postCodeList;
  cout << "Deleted a HashTable" << endl;
}

int hashFunc(int postcode, int size){
  return postcode % size;
}

void HashTable :: add(StudentEntry *studentEntry){
  int postcode = studentEntry->getPostCode();
  int index = hashFunc(postcode, size);
  (*(array+index)).insert(studentEntry);
  if(!postCodeList->exists(postcode))
    postCodeList->add(postcode);
}

void HashTable :: remove(int postcode, int studid){
  int index = hashFunc(postcode, size);
  array[index].remove(studid);
  //...
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

PostCodeIterator* HashTable :: getPostIter(){
  PostCodeIterator *it = postCodeList->iterator();
  return it;
}

void HashTable :: print(){
  for(int i = 0; i < size; i++){
    cout << "cell "<< i <<" : " ;
    array[i].print();
  }
}
