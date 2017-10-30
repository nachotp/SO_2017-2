#ifndef HANDLER
#define HANDLER

#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class turnHandler {
  int turnoDe;
public:
  turnHandler(){
    turnoDe = 0;
  }
  int siguenteTurno(int n);
};

#endif
