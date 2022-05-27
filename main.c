#include <stdlib.h>
#include <stdio.h>
#include "intarray.h"
#include "tools.h"
#include "jstl.h"



int main(int argc, char** argv){
    // get the string from the argv starting from 1
    //get the length of the all the elements
    //********************EXERCICE 0*************************

    jstl tab = standard_empty_jstl_create();
    jstl_concatenation_argvs(tab, argv,argc);
    jstl_debug(tab);

    //********************EXERCICE 1*************************
    // jstl tab1 = regstr_to_jstl("le soleil brille.");
    // jstl tab2 = regstr_to_jstl("sole");
    // int numb = jstl_equal_substr(tab1,4,6,tab2,1);
    // jstl word = jstl_substr(tab2,0,3);
    // printf("word : \"%s\"",jstl_to_regstr(word) );
    // if(numb==1){
    //     printf("The selection match\n");
    // }else{
    //     printf("The selection doesnt match\n");
    // }

    //********************EXERCICE 2*************************
}