#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector_v1_double.h"
int main(int argc, char *argv[]){

p_s_vector_v1_double a = vector_v1_double_alloc(10);
double variable = get(a, 2);
printf("TEST 1: %f\n", variable);

vector_v1_double_free(a);
variable = get(a, 2);
printf("TEST 2: %f\n", variable);

a = vector_v1_double_alloc(10);
vector_v1_double_set(a,  2,  3.00);
double test = get(a,0);
variable = get(a, 2);
printf("TEST 3: position 0: %f | position 2: %f\n",test, variable);

vector_v1_double_insert(a, 0, 5.00);
variable = get(a, 0);
printf("TEST 4: %f\n", variable);

vector_v1_double_erase(a, 0);
variable = get(a, 0);
printf("TEST 5: %f\n", variable);

vector_v1_double_push_back(a, 7.000);
size_t size = vector_v1_double_size(a);
variable = get(a, size-1);
printf("TEST 6: %f\n", variable);

vector_v1_double_pop_back(a);
variable = get(a, size-1);
printf("TEST 7: %f\n", variable);

vector_v1_double_clear(a);
size = vector_v1_double_size(a);
variable = get(a, size-1);
printf("TEST 9: ");
for (int i = 0; i< size ; i++){
	printf("position %d: %f\n",i, variable);	
}
printf("Taille : %f\n", size);

printf("TEST 10 : TABLEAU 1 : ");
int x = vector_v1_double_empty(a);
if (x == 0){
	printf("TABLEAU VIDE\n");
}else{
	printf("TABLEAU NON VIDE\n");
}
printf("TEST 10 : TABLEAU 2 : ");
a = vector_v1_double_alloc(10);
x = vector_v1_double_empty(a);
if (x  == 0){
	printf("TABLEAU VIDE\n");
}else{
	printf("TABLEAU NON VIDE\n");
}
return 0;

}

