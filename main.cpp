#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <time.h>
#include <cstdlib>
#include "HashTable.h"
#include "SkipList.h"
#include "Stucs.h"
#include "my_getopt.h"
#include "process.h"

//#define DEBUG 1

using namespace std;

int main(int argc, char *argv[]){
  int retValue;
  int hashentries = -1;
  string operationsfile;
  bool operationsfile_set = false;
  string config_file = "";

#ifdef DEBUG
  Stucs s(5, 200000, 5);
  s.insert(1,"Tharrouniatis","Kyriakos",8.07,0,"PLI",15342);
  s.insert(2,"Gianakopoulos","Panagiwtis",9.07,2,"PLI",15342);
  s.coursesToTake(15342, "PLI");
  s.exit();
#endif
#ifndef DEBUG  
  if(argc < 3) {
    cout << "main : Too few Arguments" << endl;
    retValue = -1;
  }else{
    if(my_getopt(argc, argv, &operationsfile, &operationsfile_set, &hashentries, &config_file) == -1) {
      retValue = -1;
    }else{
      time_t seconds;
      time(&seconds);
      srand((unsigned int) seconds);
      Stucs s(5, 200000, hashentries);
      //PROMPT
      char buffer[128];
      while(1){
	cout << endl <<  "Give next command :" << endl;
	memset(buffer, '\0', 128);
	fgets(buffer, 128, stdin);
	process(s, buffer, 128);
      }
    }
  }
  return retValue;
#endif
}

