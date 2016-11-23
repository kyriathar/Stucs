#include "StudentEntry.h"
#include <iostream>
#include <string>

using namespace std;

StudentEntry :: StudentEntry(){
  lastname = "";
  firstname = "";
  gpa = -1;
  numofcourses = -1;
  deprt = "";
  postcode = -1;
  cout << "Creating StudenEntry" << endl;
}

StudentEntry :: StudentEntry(string lastname){
  this->lastname = lastname;
  cout << "Creating StudentEntry : " << this->lastname << endl;
}

void StudentEntry :: setStudid(int studid){
  this->studid = studid;
}

void StudentEntry :: setLastname(string lastname){
  this->lastname = lastname;
}

void StudentEntry :: setFirstname(string firstname){
  this->firstname = firstname;
}

void StudentEntry :: setGpa(float gpa){
  this->gpa = gpa;
}

void StudentEntry :: setNumofcourses(int numofcourses){
  this->numofcourses = numofcourses;
}

void StudentEntry :: setDeprt(string deprt){
  this->deprt = deprt;
}

void StudentEntry :: setPostcode(int postcode){
  this->postcode = postcode;
}

void StudentEntry :: toString(){
  cout << studid << endl;
  cout << lastname << endl;
  cout << firstname << endl;
  cout << gpa << endl;
  cout << numofcourses << endl;
  cout << deprt << endl;
  cout << postcode << endl;
}

int StudentEntry :: getStudid(){
  return studid;
}

string StudentEntry :: getLastname(){
  return lastname;
}

string StudentEntry :: getFirstname(){
  return firstname;
}

int StudentEntry :: getPostCode(){
  return postcode;
}

float StudentEntry :: getGpa(){
  return gpa;
}

string StudentEntry :: getDeprt(){
  return deprt;
}

int StudentEntry ::  getNumofcourses(){
  return numofcourses;
}
