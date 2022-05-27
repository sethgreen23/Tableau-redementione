#include <stdlib.h>
#include <stdio.h>
#include "intarray.h"
#include "tools.h"
#include "jstl.h"



int main(int argc, char** argv){
    // get the string from the argv starting from 1
    //get the length of the all the elements
    //********************EXERCICE 0*************************

    // jstl tab = standard_empty_jstl_create();
    // jstl_concatenation_argvs(tab, argv,argc);
    // jstl_debug(tab);

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
    // jstl tab = regstr_to_jstl("Hello world!");
    // jstl tab1 = regstr_to_jstl("Hello world");

    // int flag =  jstl_equal (tab1,tab);
    // if(flag == 0)
    //     printf("The words are diffrent");
    // else
    //     printf("The words are same");
    //********************EXERCICE 3*************************
    // jstl tab = regstr_to_jstl("totovaatotototolecoleto");
    // jstl tab1 = regstr_to_jstl("toto");
    // intarray indices = jstl_find_substr_indices(tab,tab1);
    // intarray_debug(indices);
    //********************EXERCICE 4*************************
    // jstl tab = regstr_to_jstl("totovaatotolecoletoto");
    // jstl tab1 = regstr_to_jstl("toto");
    // intarray indices = jstl_find_proper_substr_indices(tab,tab1);
    // intarray_debug(indices);
    //********************EXERCICE 4*************************
    jstl tab = regstr_to_jstl("toti");
    jstl lab = regstr_to_jstl("toto");
    int result = jstr_compare(tab,lab);
    if(result==0){
        printf("%s == %s",jstl_to_regstr(tab),jstl_to_regstr(lab));
    }else if(result==1){
        printf("%s > %s",jstl_to_regstr(tab),jstl_to_regstr(lab));
    }else if(result == -1){
        printf("%s < %s",jstl_to_regstr(tab),jstl_to_regstr(lab));
    }
}