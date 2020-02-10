#include <stdlib.h>
#include <stdio.h>
#include "vector_v2_double.h"

//2.3.a
/*p_s_vector_v2_double vector_v2_double_alloc(size_t n) {
    p_s_vector_v2_double v2Double = malloc(sizeof(p_s_vector_v2_double));
    v2Double->p = malloc(sizeof(double)*n);
    for (int i = 0; i < n; ++i) {
        v2Double->p[i] = 0;
    }
    v2Double->size = n;
    return v2Double;
}*/

p_s_vector_v2_double vector_v2_double_alloc(size_t n){
    p_s_vector_v2_double tab = (p_s_vector_v2_double) malloc(sizeof(s_vector_v2_double));
    if(tab != NULL){
	tab->size = n;
	tab->capacity = n > 16 ? n : 16;
	tab->p = (double*) malloc(sizeof(double)*tab->capacity);
	if(tab->p != NULL){
	    for(int i = 0; i < n; i++){
	   	tab->p[i] = 0.0;
	    }
	}
	else {
	   free(tab);
	   tab = NULL;
	}	        
    }   
    return tab; 
}

//2.3.b
void vector_v2_double_free(p_s_vector_v2_double p_vector) {
    free(p_vector->p);
    p_vector->p = NULL;
    free(p_vector);
}

//2.3.c.1 -  vector::at
void vector_v2_double_set(p_s_vector_v2_double p_vector, size_t i, double v){
	if(i >= 0 && i < p_vector->size){
		(p_vector->p)[i] = v;
	}
}

//2.3.c.2 -  vector::at
double get(p_s_vector_v2_double p_vector, size_t i){
	if(i >= 0 && i < p_vector->size){
		return (p_vector->p)[i];
	}
	return -1;
}

//2.3.d - vector::insert
void vector_v2_double_insert(p_s_vector_v2_double p_vector, size_t i, double v){
    if(i<=p_vector->size) {


        for (int j = p_vector->size; j > i; j--) {
            vector_v2_double_set(p_vector,j,get(p_vector,j-1));
        }

        vector_v2_double_set(p_vector,i,v);

        p_vector->size++;

        if(p_vector->capacity == p_vector->size-1) {
            p_vector->capacity *= 2;
            p_vector->p = (double*) realloc(p_vector->p,(p_vector->capacity)*sizeof(double));
        }
    }


}

//2.3.e - vector::erase
void vector_v2_double_erase(p_s_vector_v2_double p_vector, size_t i){
    if(i<p_vector->size) {
        for (int j = i; j < p_vector->size-1; j++) {
            vector_v2_double_set(p_vector,j,get(p_vector,j+1));
        }
        p_vector->size--;

        if(p_vector->capacity/4 >= p_vector->size) {
            p_vector->capacity /= 2;
            p_vector->p = (double*) realloc(p_vector->p,(p_vector->capacity)*sizeof(double));
        }
    }


}

//2.3.f - vector::push_back
void vector_v2_double_push_back(p_s_vector_v2_double p_vector, double v){
    p_vector->p[p_vector->size] = v;
    p_vector->size++;

    if(p_vector->capacity == p_vector->size-1) {
        p_vector->capacity *= 2;
        p_vector->p = (double*) realloc(p_vector->p,(p_vector->capacity)*sizeof(double));
    }
}

//2.3.g - vector::pop_back
void vector_v2_double_pop_back(p_s_vector_v2_double p_vector){
    p_vector->size--;

    if(p_vector->capacity/4 >= p_vector->size) {
        p_vector->capacity /= 2;
        p_vector->p = (double*) realloc(p_vector->p,(p_vector->capacity)*sizeof(double));
    }
}

//2.3.h - vector::clear
void vector_v2_double_clear(p_s_vector_v2_double p_vector){
	free(p_vector->p);
	p_vector->p = NULL;
	p_vector->size = 0;
}

//2.3.i - vector::empty
int vector_v2_double_empty(p_s_vector_v2_double p_vector){
    return p_vector->size == 0 ? 1 : 0;
}

//2.3.j - vector::size
size_t vector_v2_double_size(p_s_vector_v2_double p_vector){
    return p_vector->size;
}

int vector_v2_comp_vectors(p_s_vector_v2_double v1, p_s_vector_v2_double v2) {
    if(v2 == NULL && v2 == NULL) return 1;
    if(vector_v2_comp_vector_tabs(v2->p,v2->p,v2->size,v2->size)) return 1;
    return 0;
}

int vector_v2_comp_vector_tabs(double* tab1, double* tab2, int size1, int size2) {
    if(size1 != size2) return 0;

    for (int i = 0; i < size1; ++i) {
        if(tab1[i] != tab2[i]) return 0;
    }

    return 1;
}

// Deep copy vector
p_s_vector_v2_double vector_v2_copy_vector(p_s_vector_v2_double p_vector) {
    p_s_vector_v2_double v2Double = vector_v2_double_alloc(p_vector->size);
    for (int i = 0; i < p_vector->size; ++i) {
        vector_v2_double_set(v2Double,i,p_vector->p[i]);
    }
    v2Double->size = p_vector->size;
    return v2Double;
}












