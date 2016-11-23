#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "HashTable.h"
#include "SkipList.h"
#include "Stucs.h"

using namespace std;

int main(){
  time_t seconds;
  time(&seconds);
  srand((unsigned int) seconds);

  Stucs s(5, 10, 5);
  s.insert(1, "Tharrouniatis", "Kyriakos", 10, 46, "Kapodistrian",
	   15342 );

  s.insert(2, "Gianoukakis", "Thanos", 5.0, 5, "Kapodistrian",
	   15342 );

  s.insert(3, "Gianakopoulos", "Panagiwtis", 7.5, 46, "Kapodistrian",
	   15777 );

  s.insert(4, "Euaggeliou", "Dimitris", 8.9, 7, "Kapodistrian",
	   15347 );
  
  s.percentile(15342);
  return 0;
}
