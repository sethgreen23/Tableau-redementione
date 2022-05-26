#include <stdlib.h>
#include <stdio.h>

typedef char* regstr;
typedef struct _jstl* jstl;
typedef struct _jstl S_jstl;

struct _jstl{
  char* data;
  int alloc;
  int len;
};
#define STANDARD_TAB_ALLOC 8
#define STANDARD_TAB_LENGTH 8

/*prototypes des fonction de manipulation des jstls*/

jstl jstl_create(int len);
void jstl_debug(jstl tab);
jstl empty_jstl_create(int allow);
jstl standard_empty_jstl_create(void);
void jstl_destroy(jstl tab);
int jstl_get(jstl tab, int index);
void jstl_set(jstl tab, int index, char value);
void ext_jstl_set(jstl tab, int index, char value);
void jstl_add(jstl tab, char value);
void jstl_resise(jstl tab, int new_alloc);
int jstl_len(jstl tab);
void jstl_print_positive_values(jstl tab);
int jstl_search(jstl tab, char value);
int jstl_nb_occurences(jstl tab, char value);
jstl jstl_sort1(jstl tab);
jstl jstl_clone(jstl tab);
int jstl_sum(jstl tab);
float jstl_average(jstl tab);
float jstl_median(jstl tab);
jstl jstl_concat (jstl T1, jstl T2);
int jstl_get_min(jstl tab);
int jstl_get_index_of_min(jstl tab);
int jstl_get_index_of_min_from(jstl tab, int n);
int jstl_count_positive_numbers(jstl tab, int start);
void jstl_clone_tables(jstl tab, jstl copy);
void jstl_delete(jstl tab, int index);
void UNSORTED_jstl_delete(jstl tab, int index);
void from_char_jstl(jstl tab, char** charTab, int length);
jstl regstr_to_jstl(regstr str);
regstr jstl_to_regstr(jstl tab);