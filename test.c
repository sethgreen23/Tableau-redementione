#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tools.h"

// int main(int argc, char** argv){
//   srand(time(NULL));
  // jstl p = jstl_create(0);
  // jstl_debug(p);
  // printf("\n");
  // jstl p = empty_jstl_create(0);
  // jstl_debug(p);
  // printf("\n");
  // jstl p = standard_empty_jstl_create();
  // jstl_debug(p);
  // printf("\n");
  // for(int i=0;i<10;i++){
  //   ext_jstl_set(p,i,i*i);
  //   if(i==7){
  //     jstl_debug(p);
  //     printf("\n");
  //   }else if(i==8){
  //     jstl_debug(p);
  //     printf("\n");
  //   }
  // }
  // jstl_debug(p);
  // for(int i=p->len;i<100;i++){
  //   ext_jstl_set(p,i,i+65);
  //   jstl_debug(p);
  //   printf("\n");
  // }
  
  // for(int i=0;i<5;i++){
  //   char n = rand() % (256 - 0 + 1) + 0;
  //   if(n%2==1) 
  //     n*=-1;
  //   printf("%d ,",n);
  //   ext_jstl_set(p,i,n);
  // }
  // printf("\n");
  // jstl_debug(p);
  // printf("\n");
  // jstl_print_positive_values(p);
  // printf("\n");
  // jstl_debug(p);
  // printf("\n");
  // printf("The minimum is %d",jstl_get_min(p));
  // printf("\n");
  // jstl clone = jstl_sort1(p);
  // jstl clone = jstl_clone(p);
  // int index = jstl_get_index_of_min_from(clone,2);
  // jstl_debug(clone);
  // printf("the min from index 2 is %d\n",clone->data[index]);
  // printf("\n");

  // jstl tab0 = empty_jstl_create(5);
  // for(int i=0;i<tab0->alloc;i++){
  //   int n = rand() % (100 - 21 + 1) + 21;
  //   if(n%2==1) 
  //     n*=-1;
  //   ext_jstl_set(tab0,i,n);
  // }
  // jstl_debug(tab0);
  // printf("\n");
  // jstl tab1 = empty_jstl_create(3);
  // for(int i=0;i<tab1->alloc;i++){
  //   int n = rand() % (100 - 21 + 1) + 21;
  //   if(n%2==1) 
  //     n*=-1;
  //   ext_jstl_set(tab1,i,n);
  // }
  // jstl_debug(tab1);
  // printf("\n");
  // jstl tab = jstl_concat(tab0,tab1);
  // jstl_debug(tab);
  // printf("\n");
  // printf("The sum of the values is %d\n",jstl_sum(tab));
  // printf("The median of the values is %f\n",jstl_median(tab));
  // printf("The average of the values is %f\n",jstl_average(tab));
  // jstl_delete(tab,0);
  // UNSORTED_jstl_delete(tab,7);
  // jstl_debug(tab);
  // jstl_destroy(tab);
  // jstl_destroy(tab0);
  // jstl_destroy(tab1);
  // int ok;
  // char* string = "-0";
  // int number = safe_string_to_int(string,&ok);
  // if(ok==1){
  //   printf("Number is %d\n",number);
  // }else if(ok==0){
  //   printf("%s is not a number\n",string);
  // }
  // printf("\n");
  // int number = string_to_int("-12a5");
  // printf("The result : %d",number);
// }
// void stats(jstl tab){
//   int sum = jstl_sum(tab);
//   float median = jstl_median(tab);
//   float average = jstl_average(tab);
//   int positive_numbers =jstl_count_positive_numbers(tab,0); 
//   int min = jstl_get_min(tab);
//   jstl sorted_clone = jstl_sort1(tab);
//   printf("The value of sum is %d\n",sum);
//   printf("The value of median is %f\n",median);
//   printf("The value of average is %f\n",average);
//   printf("The count of positive numbers is %d\n",positive_numbers);
//   printf("The List of positive number is :\n");
//   jstl_print_positive_values(tab);
//   printf("\n");
//   printf("The value of the minimum is  %d\n",min);
//   printf("The ascendent sorting :\n");
//   jstl_debug(sorted_clone);
//   free(sorted_clone);
// }
int main(int argc, char** argv){
    // jstl tab = standard_empty_jstl_create();
    // from_char_jstl(tab,argv,argc);
    // stats(tab);
    // free(tab);
    
}