#include <iostream>
#include <cstdlib>
#include "my_getopt.h"

using namespace std;

Command hashCommand(string command){
  Command retValue;
  if(command.compare("-l") == 0){
    retValue = minus_l;
  }else if(command.compare("-b") == 0){
    retValue = minus_b;
  }else if(command.compare("-c") == 0){
    retValue = minus_c;
  }else if(command.compare("i") == 0){
    retValue = insert;
  }else if(command.compare("q") == 0){
    retValue = query;
  }else if(command.compare("m") == 0){
    retValue = modify;
  }else if(command.compare("d") == 0){
    retValue = del;
  }else if(command.compare("ra") == 0){
    retValue = raverage;
  }else if(command.compare("a") == 0){
    retValue = average;
  }else if(command.compare("ta") == 0){
    retValue = taverage;
  }else if(command.compare("b") == 0){
    retValue = bottom;
  }else if(command.compare("ct") == 0){
    retValue = courses_to_take;
  }else if(command.compare("f") == 0){
    retValue = find_;
  }else if(command.compare("p") == 0){
    retValue = percentile;
  }else if(command.compare("pe") == 0){
    retValue = percentiles;
  }else if(command.compare("e") == 0){
    retValue = exit_;
  }else if(command.compare("print") == 0){
    retValue = print;
  }
  return retValue;
}

int my_getopt(int argc, char* argv[], string *operationsfile, bool *operationsfile_set, int *hashentries, string *config_file){
  Command command;
  int hashentries_i;
  for(int i = 1; i < argc; i+=2){
    command = hashCommand(argv[i]);
    if(argv[i+1] == NULL){
      cout << "my_getopt :: Argument missing" << endl;
      return -1;
    }else{
      switch(command){

      case minus_l:
	*operationsfile = argv[i+1];
	*operationsfile_set = true;
	break;

      case minus_b:
	hashentries_i = atoi(argv[i+1]);
	if(hashentries_i <= 0){
	  cout << "my_getopt :: hashentries <= 0" << endl;
	  return -1;
	}
	*hashentries = hashentries_i;
	break;

      case minus_c:
	*config_file = argv[i+1];
	break;

      default:
	cout << "my_getopt :: Wrong Argument" << endl;
	return -1;
      }
    }
  }
  return 0;
}
