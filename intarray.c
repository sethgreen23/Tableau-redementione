#include <stdlib.h>
#include <stdio.h>
#include "intarray.h"
#include "tools.h"

intarray intarray_create(int len){
  if(len<=0){
    printf("intarray_create: Length cant be null or negative.\n");
    printf("We create an array with %d length.\n",STANDARD_TAB_LENGTH);
    len = STANDARD_TAB_LENGTH;
  }
  intarray p = malloc(sizeof(struct _intarray));
  p->len=len;
  p->alloc=len;
  p->data = malloc(sizeof(int)*len);
  int i;
  for(int i=0;i<len;i++){
    p->data[i]=0;
  }
  // printf("empty_intarray_create: len->%d and alloc->%d\n",p->len,p->alloc);
  return p;
}
void intarray_debug(intarray tab){
  int i;
  printf("intarray_debug: Length %d, Alloc %d.\n",tab->len,tab->alloc);
  printf("[ ");
  for(i=0;i<tab->len;i++){
    if(i!=tab->len-1)
      printf("%d, ",tab->data[i]);
    else
      printf("%d",tab->data[i]);
  }
  printf(" ]");
}

intarray empty_intarray_create(int alloc){
  if(alloc<=0){
    printf("empty_intarray_create: Alloc cant be null or negative.\n");
    printf("We create an array with %d length.\n",STANDARD_TAB_LENGTH);
    alloc = STANDARD_TAB_ALLOC;
  }
  intarray p = malloc(sizeof(struct _intarray));
  p->len=0;
  p->alloc=alloc;
  p->data = malloc(sizeof(int)*alloc);
  int i;
  for(int i=0;i<alloc;i++){
    p->data[i]=0;
  }
  // printf("empty_intarray_create: len->%d and alloc->%d\n",p->len,p->alloc);
  return p;
}
intarray standard_empty_intarray_create(void){
  intarray p = empty_intarray_create(0);
  // printf("empty_intarray_create: len->%d and alloc->%d\n",p->len,p->alloc);
  return p;
}
void intarray_destroy(intarray tab){
  free(tab->data);
  free(tab);
}

int intarray_get(intarray tab, int index){
  if(index>tab->len || index<0){
    printf("The index %d is not between 0 and %d.\n",index, tab->len-1);
    printf("You will get the index 0\n");
    return 0;
  }
  return tab->data[index];
}
void intarray_set(intarray tab, int index, int value){
  if(index>tab->len || index<0){
    printf("The index %d is not between 0 and %d.\n",index, tab->len-1);
    return;
  }
  tab->data[index]=value;
}
void ext_intarray_set(intarray tab, int index, int value){
  if(index<0){
    printf("The index %d cant be negative\n",index);
    return;
  }
  if(index<tab->len){
    tab->data[index]=value;
    return;
  }
  if(index>=tab->alloc)
    intarray_resise(tab,2*tab->alloc+1);
  for(int i=tab->len;i<tab->alloc;i++){
    tab->data[i]=0;
  }
  tab->data[index]=value;
  if(index>=tab->len)
    tab->len++;
}

void intarray_add(intarray tab, int value){
  ext_intarray_set(tab,tab->len,value);
}
void intarray_resise(intarray tab, int new_alloc){
  int* new_data = malloc(sizeof(int)*new_alloc);
  for(int i=0;i<tab->len;i++){
    new_data[i]=tab->data[i];
  }
  tab->alloc=new_alloc;
  free(tab->data);
  tab->data = new_data;

}
int intarray_len(intarray tab){
  return tab->len;
}

void intarray_print_positive_values(intarray tab){
  printf("[ ");
  for(int i=0;i<tab->len;i++){
    if(tab->data[i]>0){
      int count = intarray_count_positive_numbers(tab,i+1);
      if(count>0){
        printf("%d, ",tab->data[i]);
      }else{
        printf("%d",tab->data[i]);
      }
    }
  }
  printf(" ]");
}
int intarray_search(intarray tab, int n){
  int i;
  for(i =0;i<tab->len;i++){
    if(tab->data[i]==n)
      return i;
  }
  printf("The element %d doenst exist in the array you get the index 0\n",n);
  return 0;
}
int intarray_nb_occurences(intarray tab, int n){
  int count=0,i;
  for(i =0 ;i<tab->len;i++){
    if(tab->data[i]==n)
      count++;
  }
  return count;
}
intarray intarray_sort1(intarray tab){
  intarray clone = intarray_clone(tab);
  for(int i=0;i<clone->len-1;i++){
    int index = intarray_get_index_of_min_from(clone,i);
    interchange_values(clone->data+index,clone->data+i);//&clone->data[i]
  }
  return clone;
}
intarray intarray_clone(intarray tab){
  intarray clone = empty_intarray_create(tab->alloc);
  intarray_clone_tables(tab,clone);
  return clone;
}
int intarray_sum(intarray tab){
  int sum=0;
  for(int i=0;i<tab->len;i++){
    sum+=tab->data[i];
  }
  return sum;
}
float intarray_average(intarray tab){
  return intarray_sum(tab)/(tab->len*1.0);
}
float intarray_median(intarray tab){
  int middle_index = tab->len/2;
  
  if(tab->len%2==1){ 
    return tab->data[middle_index]/2.0;
  }else{
    return (tab->data[middle_index]+tab->data[middle_index-1])/2.0;
  }
}
intarray intarray_concat (intarray T1, intarray T2){
  intarray tab = empty_intarray_create(2*(T1->alloc+T2->alloc));
  int i,j,k;
  for(i=0;i<T1->len;i++){
    intarray_add(tab,T1->data[i]);
  }
  for(j=0;j<T2->len;j++){
    intarray_add(tab,T2->data[j]);
  }
  return tab;
}
int intarray_get_min(intarray tab){
  return tab->data[intarray_get_index_of_min(tab)];
}
int intarray_get_index_of_min(intarray tab){
  return intarray_get_index_of_min_from(tab,0);
}
int intarray_get_index_of_min_from(intarray tab, int n){
  int min=tab->data[n];
  int index=n;
  for(int i=n+1;i<tab->len;i++){
    if(tab->data[i]<min){
      min = tab->data[i];
      index=i;
    }
  }
  return index;
}
int intarray_count_positive_numbers(intarray tab, int start){
  int count =0;
  for(int i=start;i<tab->len;i++){
    if(tab->data[i]>0)
      count++;
  }
  return count;
}
void intarray_clone_tables(intarray tab, intarray copy){
  int i;
  for(i=0;i<tab->len;i++){
    intarray_add(copy,tab->data[i]);
  }
}