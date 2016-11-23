#ifndef STUDENTENTRY_H
#define STUDENTENTRY_H

#include <string>
using namespace std;

#define MAX_NUMOFCOURSES 52

class StudentEntry{
 private:
  int studid;
  string lastname;
  string firstname;
  float gpa;
  int numofcourses;
  string deprt;
  int postcode;

 public:
  StudentEntry();
  StudentEntry(string lastname);
  void setStudid(int studid);
  void setLastname(string lastname);
  void setFirstname(string firstname);
  void setGpa(float gpa);
  void setNumofcourses(int numofcourses);
  void setDeprt(string deprt);
  void setPostcode(int postcode);
  void toString();
  int getStudid();
  string getLastname();
  string getFirstname();
  int getPostCode();
  float getGpa();
  int getNumofcourses();
  string getDeprt();
};
#endif
