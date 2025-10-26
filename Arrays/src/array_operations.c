#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "array_operations.h"
#include<stddef.h>
#include <stdint.h>


extern int errno;
 void tranverse_array(const int *array_Pointer,size_t size){
    int8_t i=0;
    if(array_Pointer==NULL){
        perror("Error reading array");
    }
    else{
       for(i=0;i<size;i++){
        printf("Value[%d]=%d\n",i,array_Pointer[i]);
       }
    }
 }
