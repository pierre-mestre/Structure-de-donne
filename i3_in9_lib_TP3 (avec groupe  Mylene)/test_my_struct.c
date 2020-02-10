#include "my_struct.h"
#include <stdlib.h>
#include <stdio.h>

// Init
// Free
// Comparaison
// Copy ET Comparaison

// Test init
int test_init(){
	p_s_my_struct p_vector = my_struct_alloc(); 
	my_struct_randoms_init(p_vector); //p_vector != NULL

	if (p_vector->p == 0 || p_vector->chaine == NULL){
		my_struct_free(p_vector);
		return 0;
	}
	my_struct_free(p_vector);
	return 1;
}

// Test free
int test_free() {
    p_s_my_struct p_vector = my_struct_alloc();
    my_struct_free(p_vector);
    return 1;
}

// Copy ET Comparaison
int test_copy_cmp(){
	p_s_my_struct p_vector1 = my_struct_alloc(); 
	my_struct_randoms_init(p_vector1);
	p_s_my_struct p_vector2 = my_struct_alloc();
	if(!my_struct_cmp(p_vector2,p_vector1)){
		my_struct_free(p_vector2);
		my_struct_free(p_vector1);
		return 0;
	}
	my_struct_copy(p_vector2,p_vector1);
	if(!my_struct_cmp(p_vector2,p_vector1)){
		my_struct_free(p_vector2);
		my_struct_free(p_vector1);
		return 1;
	}
	my_struct_free(p_vector2);
	my_struct_free(p_vector1);
	return 0;
}

int main(int argc, char* argv[]){
	printf("Test %s : %s at %s\n",test_init() ? "succeed" : "failed","test_init", __FILE__);
	printf("Test %s : %s at %s\n",test_free() ? "succeed" : "failed","test_free", __FILE__);
	printf("Test %s : %s at %s\n",test_copy_cmp() ? "succeed" : "failed","test_copy_cmp", __FILE__);
	// Les tests retournent 1 si ils sont vrai, 0 sinon
	return 0;
}
