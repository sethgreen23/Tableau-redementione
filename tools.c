#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
// interchange the values of two variables
void interchange_values(int* p, int* c){
  int interchange;
  interchange=*p;
  *p=*c;
  *c=interchange;
}