#ifndef I3_IN9_LIB_vector_H
#define I3_IN9_LIB_vector_H

typedef void * (* t_data_alloc)();
typedef void (* t_data_free)(void* p_data);
typedef void (* t_data_cpy)(void* p_data_dst, void* p_data_src);


typedef struct struct_vector{
	int size;
	int capacity;
	void** p;
    t_data_free p_data_free;
    t_data_alloc p_data_alloc;
    t_data_cpy p_data_cpy;
}s_vector;

typedef s_vector *p_s_vector;


p_s_vector vector_alloc(size_t n);
void vector_free(p_s_vector p_vector);
void vector_set(p_s_vector p_vector, size_t i,double v);
double get(p_s_vector p_vector, size_t i);
void vector_insert(p_s_vector p_vector, size_t i, double v);
void vector_erase(p_s_vector p_vector, size_t i);
void vector_push_back(p_s_vector p_vector, double v);
void vector_pop_back(p_s_vector p_vector);
void vector_clear(p_s_vector p_vector);
int vector_empty(p_s_vector p_vector);
size_t vector_size(p_s_vector p_vector);

int vector_v2_comp_vectors(p_s_vector v1, p_s_vector v2);
int vector_v2_comp_vector_tabs(double* tab1, double* tab2, int size1, int size2);
p_s_vector vector_v2_copy_vector(p_s_vector p_vector);

#endif
