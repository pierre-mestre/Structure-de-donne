#include <stddef.h>
#include <stdlib.h>
#include "vector_v1_double.h"
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

void vector_v1_double_set(p_s_vector_v1_double p_vector, size_t i, double v){
	p_vector->pointeurDouble[i]=v;
}

double get(p_s_vector_v1_double p_vector, size_t i){
	return p_vector->pointeurDouble[i];;
}

void vector_v1_double_insert(p_s_vector_v1_double p_vector, size_t j, double v){
	double* variable = malloc(sizeof(double)*p_vector->nbElement+1);
	
	for (int i =0; i<j ; i++){
		variable[i] = p_vector->pointeurDouble[i];
	}
	variable[j] = v;
	for (int i =j+1; i<p_vector->nbElement ; i++){
		variable[i] = p_vector->pointeurDouble[i-1];
	}
	p_vector->nbElement = p_vector->nbElement +1;
	for (int i =0; i<p_vector->nbElement ; i++){
		p_vector->pointeurDouble[i] = variable[i];
	}

}

void vector_v1_double_erase(p_s_vector_v1_double p_vector, size_t j){
	double* variable = malloc(sizeof(double)*p_vector->nbElement-1);
	int compteur = 0; 
	for (int i =0; i< p_vector->nbElement-1; i++){
		if (i == j){
			compteur ++;
		}
		variable[i] = p_vector->pointeurDouble[compteur];
		compteur ++;
	}
	free(p_vector->pointeurDouble);
	p_vector->pointeurDouble = variable;
}

void vector_v1_double_push_back(p_s_vector_v1_double p_vector, double v){

	vector_v1_double_insert(p_vector, p_vector->nbElement, v);
}

void vector_v1_double_pop_back(p_s_vector_v1_double p_vector){
	double* variable = malloc(sizeof(double)*p_vector->nbElement-1);
	int compteur = 0; 
	for (int i =0; i< p_vector->nbElement-1; i++){
		variable[i] = p_vector->pointeurDouble[compteur];
		compteur ++;
	}
	free(p_vector->pointeurDouble);
	p_vector->pointeurDouble = variable;
}

void vector_v1_double_clear(p_s_vector_v1_double p_vector){
	free(p_vector->pointeurDouble);
	p_vector->nbElement = 0;
}
int vector_v1_double_empty(p_s_vector_v1_double p_vector){
	if(p_vector->nbElement>0){
		return 1;
	}else{
		return 0;
	}
}

size_t vector_v1_double_size(p_s_vector_v1_double p_vector){
	return p_vector->nbElement;
}

// A FAIRE QUESTION F DU 2.3 U TP2