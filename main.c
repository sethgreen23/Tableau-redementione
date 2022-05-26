#include <stdlib.h>
#include <stdio.h>
#include "intarray.h"
#include "tools.h"
#include "jstl.h"

void jstl_concatenation_argvs(jstl tab, char** values, int length){
    int i;
    for(i=1;i<length;i++){
        regstr string = values[i];
        for(int j=0;string[j]!='\0';j++){
            jstl_add(tab,string[j]);
        }
    }
}
int main(int argc, char** argv){
    // get the string from the argv starting from 1
    //get the length of the all the elements
    //********************EXERCICE 1*************************

    jstl tab = standard_empty_jstl_create();
    jstl_concatenation_argvs(tab, argv,argc);
    jstl_debug(tab);

    //********************EXERCICE 2*************************
}