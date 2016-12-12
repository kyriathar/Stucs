#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "process.h"

using namespace std;

void createArgv(int *argc, string **argv, Command command_C){
  int argument_no = -1;
  switch(command_C){
  case insert:
    argument_no = 7;
    break;
  case query:
    argument_no = 1;
    break;
  case modify:
    argument_no = 3;
    break;
  case del:
    argument_no = 1;
    break;
  case raverage:
    argument_no = 2;
    break;
  case average:
    argument_no = 1;
    break;  
  case taverage:
    argument_no = 2;
    break;
  case bottom:
    argument_no = 1;
    break;
  case courses_to_take:
    argument_no = 2;
    break;
  case find_:
    argument_no = 1;
    break;
  case percentile:
    argument_no = 1;
    break;
  case percentiles:
    argument_no = 0;
    break;
  case exit_:
    argument_no = 0;
    break;
  case print:
    argument_no = 0;
    break;
  }
  *argc = argument_no;
  *argv = new string[argument_no];
}

void doTheCommand(Stucs &s, int argc, string *argv, Command command_C){
  int studid = -1;
  float gpa;
  int numofcourses;
  int postcode;
  switch(command_C){

  case insert:
    stringstream(argv[0]) >> studid;
    gpa = ::atof(argv[3].c_str());
    stringstream(argv[4]) >> numofcourses;
    stringstream(argv[6]) >> postcode;
    s.insert(studid, argv[1], argv[2], gpa, numofcourses, argv[5], postcode);
    break;

  case query:
    stringstream(argv[0]) >> studid;
    s.query(studid);
    break;

  case modify:
    stringstream(argv[0]) >> studid;
    gpa = ::atof(argv[1].c_str());
    stringstream(argv[2]) >> numofcourses;
    s.modify(studid, gpa, numofcourses);
    break;

  case del:
    stringstream(argv[0]) >> studid;
    s.del(studid);
    break;

  case raverage:{
    int studida = -1;
    int studidb = -1;
    stringstream(argv[0]) >> studida;
    stringstream(argv[1]) >> studidb;
    s.raverage(studida, studidb);
    break;
  }

  case average:{
      stringstream(argv[0]) >> postcode;
      s.average(postcode);
      break;
    }
    
  case taverage:{
    int k = -1;
    stringstream(argv[0]) >> k;
    stringstream(argv[1]) >> postcode;
    s.taverage(k, postcode);
    break;
  }
    
  case bottom:{
    int k = -1;
    stringstream(argv[0]) >> k;
    s.bottom(k);
    break;
  }
    
  case courses_to_take:
    stringstream(argv[0]) >> postcode;
    s.coursesToTake(postcode, argv[1]);
    break;

  case find_:{
    float thresholdGpa = -1;
    thresholdGpa = ::atof(argv[0].c_str());
    s.find(thresholdGpa);
    break;
  }
    
  case percentile:
    stringstream(argv[0]) >> postcode;
    s.percentile(postcode);
    break;
    
  case percentiles:
    s.percentiles();
    break;
    
  case exit_:
    s.exit();
    cout << "Exiting stucs !" << endl;
    exit(0);
    break;

  case print:
    s.print();
    break;
  }
}

void process(Stucs& s, char *buffer, int bufferSize){
  string buffer_s = buffer;
  string delimiter = " ";
  string delimiter_newline = "\n";
  size_t pos = 0;
  string token;
  string command;
  Command command_C;

  int argc = 0;
  string *argv;  
  if ((pos = buffer_s.find(delimiter)) != std::string::npos || (pos = buffer_s.find(delimiter_newline)) != std::string::npos) {  //command : i,q,e,....
    command = buffer_s.substr(0, pos);
    cout << command << endl;
    command_C = hashCommand(command);
    createArgv(&argc, &argv, command_C);
    buffer_s.erase(0, pos + delimiter.length());
  }
  int i = 0;
  while ((pos = buffer_s.find(delimiter)) != std::string::npos) {  //command arguments
    token = buffer_s.substr(0, pos);
    cout << token << endl;
    argv[i] = token;
    i++;
    buffer_s.erase(0, pos + delimiter.length());
  }
  if(argc > 0){
    cout << buffer_s << endl;
    argv[i] = buffer_s;
    if(*argv[i].rbegin() == '\n')  //remove \n from last argument
      argv[i] = argv[i].substr(0, argv[i].size()-1);
  }
  //for(int i = 0; i < argc; i++)
  //  cout << argv[i] << endl;
  doTheCommand(s, argc, argv, command_C);
}
