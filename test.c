#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "intarray.h"
#include "tools.h"

int main(int argc, char** argv){
  srand(time(NULL));
  // intarray p = intarray_create(0);
  // intarray_debug(p);
  // printf("\n");
  // intarray p = empty_intarray_create(0);
  // intarray_debug(p);
  // printf("\n");
  // p = standard_empty_intarray_create();
  // intarray_debug(p);
  // printf("\n");
  // for(int i=0;i<10;i++){
  //   ext_intarray_set(p,i,i*i);
  //   if(i==7){
  //     intarray_debug(p);
  //     printf("\n");
  //   }else if(i==8){
  //     intarray_debug(p);
  //     printf("\n");
  //   }
  // }
  // for(int i=p->len;i<100;i++){
  //   ext_intarray_set(p,i,i*i);
  //   intarray_debug(p);
  //   printf("\n");
  // }
  
  // for(int i=0;i<5;i++){
  //   int n = rand() % (1001 - 21 + 1) + 20;
  //   if(n%2==1) 
  //     n*=-1;
  //   ext_intarray_set(p,i,n);
  // }
  // intarray_print_positive_values(p);
  // printf("\n");
  // intarray_debug(p);
  // printf("\n");
  // printf("The minimum is %d",intarray_get_min(p));
  // printf("\n");
  // intarray clone = intarray_sort1(p);
  // intarray clone = intarray_clone(p);
  // int index = intarray_get_index_of_min_from(clone,2);
  // intarray_debug(clone);
  // printf("the min from index 2 is %d\n",clone->data[index]);
  // printf("\n");

  intarray tab0 = empty_intarray_create(5);
  for(int i=0;i<tab0->alloc;i++){
    int n = rand() % (100 - 21 + 1) + 21;
    if(n%2==1) 
      n*=-1;
    ext_intarray_set(tab0,i,n);
  }
  intarray_debug(tab0);
  printf("\n");
  intarray tab1 = empty_intarray_create(3);
  for(int i=0;i<tab1->alloc;i++){
    int n = rand() % (100 - 21 + 1) + 21;
    if(n%2==1) 
      n*=-1;
    ext_intarray_set(tab1,i,n);
  }
  intarray_debug(tab1);
  printf("\n");
  intarray tab = intarray_concat(tab0,tab1);
  intarray_debug(tab);
  printf("\n");
  printf("The sum of the values is %d\n",intarray_sum(tab));
  printf("The median of the values is %f\n",intarray_median(tab));
  printf("The average of the values is %f\n",intarray_average(tab));
  printf("\n");
  // intarray_delete(tab,0);
  UNSORTED_intarray_delete(tab,7);
  intarray_debug(tab);
  intarray_destroy(tab);
  intarray_destroy(tab0);
  intarray_destroy(tab1);
}