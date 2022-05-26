#include <stdlib.h>
#include <stdio.h>
#include "jstl.h"
#include "tools.h"
void stats(jstl tab){
  int sum = jstl_sum(tab);
  float median = jstl_median(tab);
  float average = jstl_average(tab);
  int positive_numbers =jstl_count_positive_numbers(tab,0); 
  int min = jstl_get_min(tab);
  jstl sorted_clone = jstl_sort1(tab);
  printf("The value of sum is %d\n",sum);
  printf("The value of median is %f\n",median);
  printf("The value of average is %f\n",average);
  printf("The count of positive numbers is %d\n",positive_numbers);
  printf("The List of positive number is :\n");
  jstl_print_positive_values(tab);
  printf("\n");
  printf("The value of the minimum is  %d\n",min);
  printf("The ascendent sorting :\n");
  jstl_debug(sorted_clone);
  free(sorted_clone);
}
int main(int argc, char** argv){
  // jstl tab = standard_empty_jstl_create();
  // from_char_jstl(tab,argv,argc);
  // stats(tab);
  // free(tab);
  // ******************************************
  jstl tab = regstr_to_jstl("Hello world!");
  jstl_debug(tab);
  printf("\n");
  tab = regstr_to_jstl("My name is chaith.\n");
  regstr word = jstl_to_regstr(tab);
  printf("%s",word);
}