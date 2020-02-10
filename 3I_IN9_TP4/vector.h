#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef __vector_H__
#define __vector_H__

typedef struct struct_vector{
size_t nb_elements;
void** d;
size_t capacity;
void (*t_data_alloc)();
void (*t_data_free)(void *p_data);
void (*t_data_cpy)(void *p_data_dst, void *p_data_src);
} s_vector;

typedef s_vector* p_s_vector;

//p_s_vector vector_alloc(size_t n);
p_s_vector vector_alloc(size_t n, void (*t_data_alloc)(), void (*t_data_free)(void *p_data), void (*t_data_cpy)(void *p_data_dst, void *p_data_src));
void vector_free(p_s_vector p_vector);
void vector_set(p_s_vector p_vector, size_t i, void* v);
void vector_get(p_s_vector p_vector, size_t i, void* p_data);
//void* get(p_s_vector p_vector, size_t i);
void vector_insert(p_s_vector p_vector, size_t i, double v);
//void vector_insert(p_s_vector p_vector, size_t i, void* v);
void vector_erase(p_s_vector p_vector, size_t i);
void vector_push_back(p_s_vector p_vector, void* v); 
void vector_pop_back(p_s_vector p_vector);
void vector_clear(p_s_vector p_vector); 
int vector_empty(p_s_vector p_vector);
size_t vector_size(p_s_vector p_vector);
typedef void* (*t_data_alloc)();
typedef void (*t_data_free)(void *p_data);
typedef void (*t_data_cpy)(void *p_data_dst, void *p_data_src);

#endif //__vector_H__ 
