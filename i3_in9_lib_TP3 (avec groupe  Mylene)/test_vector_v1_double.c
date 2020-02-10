#include <stdio.h>
#include <stdlib.h>
#include "vector_v1_double.h"

// Test changer index inexistant
int test_index_change_not_exists() {
    p_s_vector_v1_double p_vector = vector_v1_double_alloc(1);
    p_s_vector_v1_double p_vector_old = vector_v1_copy_vector(p_vector);
    vector_v1_double_set(p_vector, 2, 2.0);
    if(vector_v1_comp_vectors(p_vector_old,p_vector)) {
	vector_v1_double_free(p_vector);
	vector_v1_double_free(p_vector_old);
	return 1;
    }
    vector_v1_double_free(p_vector);
    vector_v1_double_free(p_vector_old);
    return 0;
}

// Test changer donnée d'un index existant (Mylène)
int test_set_index_existant(){
    p_s_vector_v1_double v1Double = vector_v1_double_alloc(5);
	vector_v1_double_set(v1Double, 3, 6); //test

	if (get(v1Double,3) == 6){
		vector_v1_double_free(v1Double);
		return 1; //bon
	} else {
		vector_v1_double_free(v1Double);
		return 0; //problème
	}
}

// Test récupérer donnée d'un index existant (Mylène)
int test_get_index_existant(){
    p_s_vector_v1_double v1Double = vector_v1_double_alloc(5);
    vector_v1_double_set(v1Double, 3, 7); //test
	if (get(v1Double, 3) == 7){ //test
		vector_v1_double_free(v1Double);
		return 1; //bon
	} else {
		vector_v1_double_free(v1Double);
		return 0; //problème
	}
}

// Test supprimer derniere valeur (Mylène)
int test_pop_back(){
    p_s_vector_v1_double v1Double = vector_v1_double_alloc(3);

	vector_v1_double_pop_back(v1Double); //test

	if (v1Double->size == 2){
		vector_v1_double_free(v1Double);
		return 1; //bon
	} else {
		vector_v1_double_free(v1Double);
		return 0; //problème
	}
}

// Test récupérer index inexistant
int test_get_index_inexistant(){
    p_s_vector_v1_double p_vector = vector_v1_double_alloc(1);
    if(get(p_vector,2)==-1){
	vector_v1_double_free(p_vector);
	return 1;
    }
    else{
	vector_v1_double_free(p_vector);
	return 0;
    }
}
// Test tableau vide
int test_init_tableau(){
    size_t size = 5;
    p_s_vector_v1_double p_vector = vector_v1_double_alloc(size);
    for(int i = 0; i < size; i++){
	if(get(p_vector,i)!=0){
	    vector_v1_double_free(p_vector);
	    return 0;
	}
    }
    vector_v1_double_free(p_vector);
    return 1;
}
// Test changer index existant
// Test récupérer index existant
// Test supprimer derniere valeur
// Test ajouter en dernier
int test_add_last() {
    p_s_vector_v1_double p_vector = vector_v1_double_alloc(0);
    vector_v1_double_push_back(p_vector, 25);
    if(get(p_vector, p_vector->size-1) == 25) {
	vector_v1_double_free(p_vector);
	return 1;
    }
    vector_v1_double_free(p_vector);
    return 0;
}
// Test ajouter à l'index 3 (rappel : le premier index est l'index 0)
int test_add_pos3() {
    p_s_vector_v1_double p_vector = vector_v1_double_alloc(5);
    vector_v1_double_insert(p_vector,3,40);
    if(get(p_vector, 3) == 40) {
	vector_v1_double_free(p_vector);	
	return 1;
    }
    vector_v1_double_free(p_vector);
    return 0;
}
// Test ajouter à l'index 10 dans un tableau trop petit (5)
int test_add_pos10() {
    p_s_vector_v1_double p_vector = vector_v1_double_alloc(5);
    p_s_vector_v1_double p_vector_copy = vector_v1_copy_vector(p_vector);
    vector_v1_double_insert(p_vector,10,40);
    if(vector_v1_comp_vectors(p_vector, p_vector_copy)) {
	vector_v1_double_free(p_vector);
	vector_v1_double_free(p_vector_copy);
	return 1;
    }
    vector_v1_double_free(p_vector);
    vector_v1_double_free(p_vector_copy);
    return 0;
}
// Test supprimer à la position 1000 (tableau trop petit)
int test_del_pos1000() {
    p_s_vector_v1_double p_vector = vector_v1_double_alloc(5);
    p_s_vector_v1_double p_vector_copy = vector_v1_copy_vector(p_vector);
    vector_v1_double_erase(p_vector,1000);
    if(vector_v1_comp_vectors(p_vector, p_vector_copy)) {
	vector_v1_double_free(p_vector);
	vector_v1_double_free(p_vector_copy);
	return 1;
    }
    vector_v1_double_free(p_vector_copy);
    vector_v1_double_free(p_vector);
    return 0;
}
// Test supprimer à la position 3
int test_del_pos3() {
    p_s_vector_v1_double p_vector = vector_v1_double_alloc(5);
    vector_v1_double_insert(p_vector,4,50);
    vector_v1_double_erase(p_vector,3);
    if(get(p_vector, 3) == 50) {
	vector_v1_double_free(p_vector);	
	return 1;
    }
    vector_v1_double_free(p_vector);
    return 0;
}
// Test vider le tableau
int test_shrink_array() {
    p_s_vector_v1_double p_vector = vector_v1_double_alloc(5);
    vector_v1_double_clear(p_vector);
    if(vector_v1_double_empty(p_vector)) {
	vector_v1_double_free(p_vector);	
	return 1;
    }
    vector_v1_double_free(p_vector);
    return 0;
}
// Test libération des éléments
int test_free_array() {
    p_s_vector_v1_double p_vector = vector_v1_double_alloc(5);
    vector_v1_double_free(p_vector);
    return 1;
}

int main(int argc, char* argv[]) {
    printf("Test %s : %s at %s\n",test_index_change_not_exists() ? "succeed" : "failed","test_index_change_not_exists", __FILE__);
    printf("Test %s : %s at %s\n",test_set_index_existant() ? "succeed" : "failed","test_set_index_existant", __FILE__);
    printf("Test %s : %s at %s\n",test_get_index_existant() ? "succeed" : "failed","test_get_index_existant", __FILE__);
    printf("Test %s : %s at %s\n",test_pop_back() ? "succeed" : "failed","test_pop_back", __FILE__);
    printf("Test %s : %s at %s\n",test_get_index_inexistant() ? "succeed" : "failed","test_get_index_inexistant", __FILE__);
    printf("Test %s : %s at %s\n",test_init_tableau() ? "succeed" : "failed","test_init_tableau", __FILE__);
    printf("Test %s : %s at %s\n",test_add_last() ? "succeed" : "failed","test_add_last", __FILE__);
    printf("Test %s : %s at %s\n",test_add_pos3() ? "succeed" : "failed","test_add_pos3", __FILE__);
    printf("Test %s : %s at %s\n",test_add_pos10() ? "succeed" : "failed","test_add_pos10", __FILE__);
    printf("Test %s : %s at %s\n",test_del_pos1000() ? "succeed" : "failed","test_del_pos1000", __FILE__);
    printf("Test %s : %s at %s\n",test_del_pos3() ? "succeed" : "failed","test_del_pos3", __FILE__);
    printf("Test %s : %s at %s\n",test_shrink_array() ? "succeed" : "failed","test_shrink_array", __FILE__);
    printf("Test %s : %s at %s\n",test_free_array() ? "succeed" : "failed","test_free_array", __FILE__);

    // Les tests retournent 1 si ils sont vrai, 0 sinon
    return 0;
}
