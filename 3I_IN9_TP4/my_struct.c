#include <stddef.h>
#include <stdlib.h>
#include "my_struct.h"
p_s_vector_v1_double vector_v1_double_alloc(size_t n){

	p_s_vector_v1_double vecteur = malloc(sizeof(s_vector_v1_double));
	vecteur->nbElement = n;
	vecteur->pointeurDouble=malloc(sizeof(double)*n);
	for (int i = 0; i<n; i++){
		vecteur->pointeurDouble[i]=0.0;
	}

	return vecteur;

}

void vector_v1_double_free(p_s_vector_v1_double p_vector){
	free(p_vector->pointeurDouble);
	free(p_vector);
}