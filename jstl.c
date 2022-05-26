#include <stdlib.h>
#include <stdio.h>
#include "jstl.h"
#include "tools.h"
//Note!! the arrays wont be with size 0
//create and empty jstl with both len and alloc set to the parameter len
jstl jstl_create(int len){
  if(len<=0){
    printf("jstl_create: Length cant be null or negative.\n");
    printf("We create an array with %d length.\n",STANDARD_TAB_LENGTH);
    len = STANDARD_TAB_LENGTH;
  }
  jstl p = malloc(sizeof(struct _jstl));
  p->len=len;
  p->alloc=len;
  p->data = malloc(sizeof(char)*len);
  int i;
  for(int i=0;i<len;i++){
    p->data[i]=0;
  }
  // printf("empty_jstl_create: len->%d and alloc->%d\n",p->len,p->alloc);
  return p;
}
// display the array
void jstl_debug(jstl tab){
  int i;
  printf("jstl_debug: Length %d, Alloc %d.\n",tab->len,tab->alloc);
  for(i=0;i<tab->len;i++){
      printf("%c",tab->data[i]);
  }
}
// create an empty jstl with alloc set to the parameter value and as len=0
jstl empty_jstl_create(int alloc){
  if(alloc<=0){
    printf("empty_jstl_create: Alloc cant be null or negative.\n");
    printf("We create an array with %d length.\n",STANDARD_TAB_LENGTH);
    alloc = STANDARD_TAB_ALLOC;
  }
  jstl p = malloc(sizeof(struct _jstl));
  p->len=0;
  p->alloc=alloc;
  p->data = malloc(sizeof(char)*alloc);
  int i;
  for(int i=0;i<alloc;i++){
    p->data[i]=0;
  }
  // printf("empty_jstl_create: len->%d and alloc->%d\n",p->len,p->alloc);
  return p;
}
//create an empty jstl with alloc equal to 0 it is like that
jstl standard_empty_jstl_create(void){
  jstl p = empty_jstl_create(STANDARD_TAB_ALLOC);
  // printf("empty_jstl_create: len->%d and alloc->%d\n",p->len,p->alloc);
  return p;
}
// free the memory allocated for both the jstl and data array
void jstl_destroy(jstl tab){
  free(tab->data);
  free(tab);
}
// get the element in the data array at the position index
int jstl_get(jstl tab, int index){
  if(index>tab->len || index<0){
    printf("The index %d is not between 0 and %d.\n",index, tab->len-1);
    printf("You will get the index 0\n");
    return 0;
  }
  return tab->data[index];
}
// set the value in the data array at position index
// the index need to be less then the lenth
void jstl_set(jstl tab, int index, char value){
  if(index>tab->len || index<0){
    printf("The index %d is not between 0 and %d.\n",index, tab->len-1);
    return;
  }
  tab->data[index]=value;
}
// same as the legacy jstl_set 
// the difference is that you can place the value 
// in any position you wouldlike because the array is resizable
void ext_jstl_set(jstl tab, int index, char value){
  if(index<0){
    printf("The index %d cant be negative\n",index);
    return;
  }
  if(index<tab->len){
    tab->data[index]=value;
    return;
  }
  if(index>=tab->alloc)
    jstl_resise(tab,2*tab->alloc+1);
  for(int i=tab->len;i<tab->alloc;i++){
    tab->data[i]=0;
  }
  tab->data[index]=value;
  if(index>=tab->len)
    tab->len++;
}
// add the element at the end of the array
void jstl_add(jstl tab, char value){
  ext_jstl_set(tab,tab->len,value);
}
// resize the  array with 2*old_alloc+1
void jstl_resise(jstl tab, int new_alloc){
  char* new_data = malloc(sizeof(char)*new_alloc);
  for(int i=0;i<tab->len;i++){
    new_data[i]=tab->data[i];
  }
  tab->alloc=new_alloc;
  free(tab->data);
  tab->data = new_data;

}
// return the length of the array
int jstl_len(jstl tab){
  return tab->len;
}
// print the positive values in the array
void jstl_print_positive_values(jstl tab){
  printf("[ ");
  for(int i=0;i<tab->len;i++){
    if(((int)tab->data[i])>0){
      int count = jstl_count_positive_numbers(tab,i+1);
      if(count>0){
        printf("%c, ",tab->data[i]);
      }else{
        printf("%c",tab->data[i]);
      }
    }
  }
  printf(" ]");
}
// search the value in the array
int jstl_search(jstl tab, char n){
  int i;
  for(i =0;i<tab->len;i++){
    if(tab->data[i]==n)
      return i;
  }
  printf("The element %d doenst exist in the array you get the index 0\n",n);
  return 0;
}
// search the occurence of the value in the array
int jstl_nb_occurences(jstl tab, char n){
  int count=0,i;
  for(i =0 ;i<tab->len;i++){
    if(tab->data[i]==n)
      count++;
  }
  return count;
}
// sort the array
jstl jstl_sort1(jstl tab){
  jstl clone = jstl_clone(tab);
  for(int i=0;i<clone->len-1;i++){
    int index = jstl_get_index_of_min_from(clone,i);
    character_interchange_values(clone->data+index,clone->data+i);//&clone->data[i]
  }
  return clone;
}
// clone the array
jstl jstl_clone(jstl tab){
  jstl clone = empty_jstl_create(tab->alloc);
  jstl_clone_tables(tab,clone);
  return clone;
}
// sum the element in the array
int jstl_sum(jstl tab){
  int sum=0;
  for(int i=0;i<tab->len;i++){
    sum+=(int)tab->data[i];
  }
  return sum;
}
// calculate the average of the values in the array
float jstl_average(jstl tab){
  return jstl_sum(tab)/(tab->len*1.0);
}
// calculate the median value of the array
float jstl_median(jstl tab){
  jstl clone = jstl_sort1(tab);
  int middle_index = clone->len/2;
  
  if(clone->len%2==1){ 
    return (int)clone->data[middle_index]/2.0;
  }else{
    return (((int)clone->data[middle_index])+((int)clone->data[middle_index-1]))/2.0;
  }
}
// concatenate two inarray
jstl jstl_concat (jstl T1, jstl T2){
  jstl tab = empty_jstl_create(2*(T1->alloc+T2->alloc));
  int i,j,k;
  for(i=0;i<T1->len;i++){
    jstl_add(tab,T1->data[i]);
  }
  for(j=0;j<T2->len;j++){
    jstl_add(tab,T2->data[j]);
  }
  return tab;
}
// return the min value in the array
int jstl_get_min(jstl tab){
  return tab->data[jstl_get_index_of_min(tab)];
}
// get the index of the min in the jstl
int jstl_get_index_of_min(jstl tab){
  return jstl_get_index_of_min_from(tab,0);
}
// get the index of the min in the array starting from a certain position
int jstl_get_index_of_min_from(jstl tab, int n){
  int min=(int)tab->data[n];
  int index=n;
  for(int i=n+1;i<tab->len;i++){
    if(tab->data[i]<min){
      min = (int)tab->data[i];
      index=i;
    }
  }
  return index;
}
// count the number of the positive numbers starting from a certain position
int jstl_count_positive_numbers(jstl tab, int start){
  int count =0;
  for(int i=start;i<tab->len;i++){
    if(tab->data[i]>0)
      count++;
  }
  return count;
}
// clone the table values
void jstl_clone_tables(jstl tab, jstl copy){
  int i;
  for(i=0;i<tab->len;i++){
    jstl_add(copy,tab->data[i]);
  }
}
// delete the element in the array and keep the order
void jstl_delete(jstl tab, int index){
  if(index < 0){
    printf("The index cant be negative.\n");
    return;
  }
  if(index>=tab->len){
    printf("The index need to be between the 0 and %d\n",tab->len-1);
    return;
  }
  int i;
  for(i = index+1;i<tab->len;i++){
    tab->data[i-1]=tab->data[i];
  }
  tab->len--;
}
// delete the element in the array 
void UNSORTED_jstl_delete(jstl tab, int index){
  if(index < 0){
    printf("The index cant be negative.\n");
    return;
  }
  if(index>=tab->len){
    printf("The index need to be between the 0 and %d\n",tab->len-1);
    return;
  }
  tab->data[index]=tab->data[tab->len-1];
  tab->len--;
}
void from_char_jstl(jstl tab, char** charTab, int length){
  for(int i=1,j=0;i<length;i++){
    int* ok = malloc(sizeof(int));
    int integer = safe_string_to_int(charTab[i],ok);
    if(*ok==1){
      jstl_add(tab,integer);
    }
    free(ok);
  }
}
// from regst to jstl
jstl regstr_to_jstl(regstr str){
  int len = strlen(str);
  jstl tab = empty_jstl_create(len);
  for(int i=0;str[i]!='\0';i++){
    jstl_add(tab,str[i]);
  }
  return tab;
}
regstr jstl_to_regstr(jstl tab){
  regstr word = malloc(sizeof(char)*tab->len+1);
  int i;
  for(i=0;i<tab->len;i++){
    word[i]=tab->data[i];
  }
  word[i]='\0';
  return word;
}