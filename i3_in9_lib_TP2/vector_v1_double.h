#include <stddef.h>
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct struct_vector_v1_double{
	int nbElement;
	double* pointeurDouble;
}s_vector_v1_double;

typedef s_vector_v1_double *p_s_vector_v1_double;


p_s_vector_v1_double vector_v1_double_alloc(size_t n);
void vector_v1_double_free(p_s_vector_v1_double p_vector);
void vector_v1_double_set(p_s_vector_v1_double p_vector, size_t i, double v);
void vector_v1_double_insert(p_s_vector_v1_double p_vector, size_t j, double v);
void vector_v1_double_pop_back(p_s_vector_v1_double p_vector);
void vector_v1_double_erase(p_s_vector_v1_double p_vector, size_t j);
void vector_v1_double_clear(p_s_vector_v1_double p_vector);
double get(p_s_vector_v1_double p_vector, size_t i);
void vector_v1_double_push_back(p_s_vector_v1_double p_vector, double v);
int vector_v1_double_empty(p_s_vector_v1_double p_vector);
size_t vector_v1_double_size(p_s_vector_v1_double p_vector);

#endif
