#ifndef I3_IN9_LIB_VECTOR_V2_DOUBLE_H
#define I3_IN9_LIB_VECTOR_V2_DOUBLE_H

typedef struct struct_vector_v2_double{
	int size;
	int capacity;
	double* p;
}s_vector_v2_double;

typedef s_vector_v2_double *p_s_vector_v2_double;

p_s_vector_v2_double vector_v2_double_alloc(size_t n);
void vector_v2_double_free(p_s_vector_v2_double p_vector);
void vector_v2_double_set(p_s_vector_v2_double p_vector, size_t i,double v);
double get(p_s_vector_v2_double p_vector, size_t i);
void vector_v2_double_insert(p_s_vector_v2_double p_vector, size_t i, double v);
void vector_v2_double_erase(p_s_vector_v2_double p_vector, size_t i);
void vector_v2_double_push_back(p_s_vector_v2_double p_vector, double v);
void vector_v2_double_pop_back(p_s_vector_v2_double p_vector);
void vector_v2_double_clear(p_s_vector_v2_double p_vector);
int vector_v2_double_empty(p_s_vector_v2_double p_vector);
size_t vector_v2_double_size(p_s_vector_v2_double p_vector);

int vector_v2_comp_vectors(p_s_vector_v2_double v1, p_s_vector_v2_double v2);
int vector_v2_comp_vector_tabs(double* tab1, double* tab2, int size1, int size2);
p_s_vector_v2_double vector_v2_copy_vector(p_s_vector_v2_double p_vector);

#endif
