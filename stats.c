#include <stdlib.h>
#include <stdio.h>
#include "intarray.h"
#include "tools.h"

void from_char_intarray(intarray tab, char** charTab, int length){
  for(int i=1,j=0;i<length;i++){
    int* ok = malloc(sizeof(int));
    int integer = safe_string_to_int(charTab[i],ok);
    if(*ok==1){
      intarray_add(tab,integer);
    }
    free(ok);
  }
}
void stats(intarray tab){
  int sum = intarray_sum(tab);
  float median = intarray_median(tab);
  float average = intarray_average(tab);
  int positive_numbers =intarray_count_positive_numbers(tab,0); 
  int min = intarray_get_min(tab);
  intarray sorted_clone = intarray_sort1(tab);
  printf("The value of sum is %d\n",sum);
  printf("The value of median is %f\n",median);
  printf("The value of average is %f\n",average);
  printf("The count of positive numbers is %d\n",positive_numbers);
  printf("The List of positive number is :\n");
  intarray_print_positive_values(tab);
  printf("\n");
  printf("The value of the minimum is  %d\n",min);
  printf("The ascendent sorting :\n");
  intarray_debug(sorted_clone);
  free(sorted_clone);
}
int main(int argc, char** argv){
    intarray tab = standard_empty_intarray_create();
    from_char_intarray(tab,argv,argc);
    stats(tab);
    free(tab);
    
}