#include "vector.h"

p_s_vector vector_alloc(size_t n, void (*t_data_alloc)(), void (*t_data_free)(void *p_data),
 void (*t_data_cpy)(void *p_data_dst, void *p_data_src)){
	if(n > 0) {
	p_s_vector p = malloc(sizeof(s_vector));
	if (p !=NULL) {
		p->t_data_alloc=*t_data_alloc;
		p->t_data_cpy=*t_data_cpy;
		p->t_data_free=*t_data_free;
		p->capacity = 16;
		p->nb_elements = n;
		p->d = malloc(sizeof(void*) * p->capacity);
		for (int i = 0; i < n; i++) {
			p->d[i] = p->t_data_alloc;
		}
	}
	else {
		free(p);
		p = NULL;
	}

	return p;
	}
}


/*p_s_vector vector_alloc(size_t n){
	if(n > 0) {
	p_s_vector p = malloc(sizeof(s_vector));
	if (p !=NULL) {
		p->capacity = 16;
		p->nb_elements = n;
		p->d = malloc(sizeof(void*) * p->capacity);
		for (int i = 0; i < n; i++) {
			p->d[i] = NULL;
		}
	}
	else {
		free(p);
		p = NULL;
	}

	return p;
	}
}*/

void vector_free(p_s_vector p_vector) {
	if (p_vector !=NULL){
		if (p_vector->d !=NULL){
			//free(p_vector->d);
			p_vector->t_data_free(p_vector->d);
			
		}
		p_vector->t_data_free(p_vector);
		//free(p_vector);
	}
} 

void vector_set(p_s_vector p_vector, size_t i, void* v){
if (i>=0 && i< p_vector->nb_elements){
	p_vector->t_data_cpy(p_vector->d[i], v);
 	//p_vector->d[i] = v;
	}
}

/*void* get(p_s_vector p_vector, size_t i){
	if(i>= 0 && i< p_vector->nb_elements){
		return p_vector->d[i];}
	else {
	printf("rentre chez toi on veut un entier positif !");}
}*/

void vector_get(p_s_vector p_vector, size_t i, void* p_data){
	if(i>= 0 && i< p_vector->nb_elements){
		p_vector->t_data_cpy(p_data,p_vector->d[i]);
		}
	else {
	printf("rentre chez toi on veut un entier positif !");}
}

void vector_insert(p_s_vector p_vector, size_t i, double v){
	if (i>=0 && i<= p_vector->nb_elements){
		p_vector->nb_elements++;
		for (int j = p_vector->nb_elements-1; j > i; j--) {
			p_vector->t_data_cpy(p_vector->d[j], p_vector->d[j-1]);
			//p_vector->d[j] = p_vector->d[j-1];
			//printf("Test %lf \n",p_vector->d[j-1]);
		}
		p_vector->t_data_cpy(p_vector->d[i], v);
		//p_vector->d[i] = v;
	}

	if(p_vector->capacity == p_vector->nb_elements) {
		p_vector->capacity *=2;
		p_vector->d = realloc(p_vector->d, sizeof(void*)* p_vector->capacity);
	}
}

/*void vector_insert(p_s_vector p_vector, size_t i, void* v){

	if (i>=0 && i<= p_vector->nb_elements){
		p_vector->nb_elements++;
		for (int j = p_vector->nb_elements-1; j > i; j--) {
			p_vector->d[j] = p_vector->d[j-1];
			//printf("Test %lf \n",p_vector->d[j-1]);
		}
		
		p_vector->d[i] = v;
	}

	if(p_vector->capacity == p_vector->nb_elements) {
		p_vector->capacity *=2;
		p_vector->d = realloc(p_vector->d, sizeof(void*)* p_vector->capacity);
	}

}*/

void vector_erase(p_s_vector p_vector, size_t i){


	if (i>=0 && i< p_vector->nb_elements){
		for (int j = i; j<p_vector->nb_elements-1; j++){
			p_vector->t_data_cpy(p_vector->d[j],p_vector->d[j+1]);
			//p_vector->d[j] = p_vector->d[j+1];
		}
		p_vector->nb_elements--;
		
	}

	if(p_vector->nb_elements <= p_vector->capacity/4) {
		
		p_vector->capacity = p_vector->capacity/2;
		p_vector->d = realloc(p_vector->d, sizeof(void*)*p_vector->capacity);
	}

}

//ajoute à la fin 
void vector_push_back(p_s_vector p_vector, void* v){ 
	vector_insert(p_vector, p_vector->nb_elements, v);

}

//efface à la fin
void vector_pop_back(p_s_vector p_vector){
	vector_erase(p_vector, p_vector->nb_elements-1);
}

void vector_clear(p_s_vector p_vector){
//toucher à la capacité ?????
//free(p_vector->d);
	p_vector->t_data_free(p_vector->d);
	p_vector->capacity = 16;
	p_vector->nb_elements = 0;
	p_vector->d = NULL;
}


int vector_empty(p_s_vector p_vector){

	if(p_vector->d != NULL){
		return 1;
	} else {
		return 0;	
	}
}
size_t vector_size(p_s_vector p_vector){	
	return (size_t)p_vector->nb_elements;
}


