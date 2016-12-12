#ifndef MY_GETOPT_H
#define MY_GETOPT_H

#include <string>

using namespace std;

enum Command {
  minus_l,
  minus_b,
  minus_c,
  insert,
  query,
  modify,
  del,
  raverage,
  average,
  taverage,
  bottom,
  courses_to_take,
  find_,
  percentile,
  percentiles,
  exit_,
  print
};

Command hashCommand(string command);
int my_getopt(int argc, char* argv[], string *operationsfile, bool *operationsfile_set, int *hashentries, string *config_file);

#endif
