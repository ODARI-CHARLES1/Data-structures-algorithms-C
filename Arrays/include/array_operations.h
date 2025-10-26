#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H
#include<stddef.h>

void tranverse_array(const int *array_pointer,size_t size);
int push(const int *array_pointer);
int insert(const int *array_pointer,size_t *value,size_t *position);
int delete_value(const int *array_pointer,size_t *position);

#endif
