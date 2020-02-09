#ifndef I3_IN9_LIB_VECTOR_V1_DOUBLE_H
#define I3_IN9_LIB_VECTOR_V1_DOUBLE_H

typedef struct struct_vector_v1_double{
	int size;
	double* p;
}s_vector_v1_double;

typedef s_vector_v1_double *p_s_vector_v1_double;

p_s_vector_v1_double vector_v1_double_alloc(size_t n);
void vector_v1_double_free(p_s_vector_v1_double p_vector);
void vector_v1_double_set(p_s_vector_v1_double p_vector, size_t i,double v);
double get(p_s_vector_v1_double p_vector, size_t i);
void vector_v1_double_insert(p_s_vector_v1_double p_vector, size_t i, double v);
void vector_v1_double_erase(p_s_vector_v1_double p_vector, size_t i);
void vector_v1_double_push_back(p_s_vector_v1_double p_vector, double v);
void vector_v1_double_pop_back(p_s_vector_v1_double p_vector);
void vector_v1_double_clear(p_s_vector_v1_double p_vector);
int vector_v1_double_empty(p_s_vector_v1_double p_vector);
size_t vector_v1_double_size(p_s_vector_v1_double p_vector);

int vector_v1_comp_vectors(p_s_vector_v1_double v1, p_s_vector_v1_double v2);
int vector_v1_comp_vector_tabs(double* tab1, double* tab2, int size1, int size2);
p_s_vector_v1_double vector_v1_copy_vector(p_s_vector_v1_double p_vector);

#endif
