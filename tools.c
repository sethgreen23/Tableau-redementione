#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

void interchange_values(int* p, int* c){
  int interchange;
  interchange=*p;
  *p=*c;
  *c=interchange;
}