//appel par : ./bench_vector_v2_double test_type init_size n
//test_type : type du teste à exécuter
//init_size : taille initial du tableau dynamique
//n 	    : nombre d’exécution du test

#include <stdio.h>
#include <string.h>
#include "vector_v2_double.h"
#include "random.h"
#include <time.h>


void insert_erase_random(p_s_vector_v2_double p_vector, size_t n){
	double element;
	size_t pos;
	//Ajout de n elements aleatoires
	for(int i = 0; i < n; i++){
		element = random_double(0,200);
		pos = random_size_t(0, p_vector->size);
		vector_v2_double_insert(p_vector,pos,element);
	}
	//Suppression de n elements aleatoires
	for(int i = 0; i < n; i++){
		pos = random_size_t(0, p_vector->size-1);
		vector_v2_double_erase(p_vector,pos);
	}
}

void insert_erase_head(p_s_vector_v2_double p_vector, size_t n){
	double element;
	size_t pos = 0;
	//Ajout de n elements en tête
	for(int i = 0; i < n; i++){
		element = random_double(0,200);
		vector_v2_double_insert(p_vector,pos,element);
	}
	//Suppression de n elements en tête
	for(int i = 0; i < n; i++){
		vector_v2_double_erase(p_vector,pos);
	}
}

void insert_erase_tail(p_s_vector_v2_double p_vector, size_t n){
	double element;
	size_t pos = vector_v2_double_size(p_vector) - 1;
	//Ajout de n elements en queue
	for(int i = 0; i < n; i++){
		element = random_double(0,200);
		vector_v2_double_insert(p_vector,pos,element);
	}
	//Suppression de n elements en queue
	for(int i = 0; i < n; i++){
		vector_v2_double_erase(p_vector,pos);
	}
}

void read_write_random(p_s_vector_v2_double p_vector, size_t n){
	double element;
	size_t pos;
	//Ecriture d'un element aleatoire a une position aleatoire
	for(int i = 0; i < n; i++){
		element = random_double(0,200);
		pos = random_size_t(0, p_vector->size-1);
		vector_v2_double_set(p_vector,pos,element);
	}
	//Lecture d'un element a une position aleatoire
	for(int i = 0; i < n; i++){
		pos = random_size_t(0, p_vector->size-1);
		element=get(p_vector,pos);
	}
}

void read_write_sequential(p_s_vector_v2_double p_vector, size_t n){
	double element;
	size_t size = p_vector->size;
	//Ecriture de tous les elements fr p_vector (aleatoire) de la tete vers la queue
	for(int i = 0; i < n; i++){
		for(int j = 0; j < size ; j++){	
			element = random_double(0,200);
			vector_v2_double_set(p_vector,j,element);
		}
	}
	//Lecture de tous les elements de la tete vers la queue
	for(int i = 0; i < n; i++){
		for(int j = 0; j < size ; j++)	
			element=get(p_vector,j);
	}
}

void tri_bulle(double* tableau,size_t longueur){
     int i, inversion;
     do
       {
       inversion=0;

       for(i=0;i<longueur-1;i++)
          {
          if (tableau[i]>tableau[i+1])
             {
	     double temp = tableau[i+1];
	     tableau[i+1] = tableau[i];
	     tableau[i] = temp;
             inversion=1;
             }
          }
       longueur--;
       }
     while(inversion);
}


void bubble_sort(p_s_vector_v2_double p_vector, size_t n){
	double element;
	size_t size = p_vector->size;
	//Ecriture de tous les elements p_vector aleatoire
	for(int i = 0; i < n; i++){
		for(int j = 0; j < size ; j++){	
			element = random_double(0,200);
			vector_v2_double_set(p_vector,j,element);
		}
	tri_bulle(p_vector->p, p_vector->size);
	}
}

int main(int argc, char* argv[]) {
	if(argc < 4) {
		printf("Usage : ./bench_vector_v2_double test_type init_size n\n");
		return 1; //Mauvais usage
	}

    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));

	size_t size;// Taille du vecteur
    sscanf(argv[2], "%ld", &size);
    size_t n; // Nombre de tests
    sscanf(argv[3], "%ld", &n);

    p_s_vector_v2_double v = vector_v2_double_alloc(size);

	for(int i=0; i<v->size; i++) {
	    vector_v2_double_set(v, i, random_double(0,1));
	}

    clock_t start, end;

	if(!strcmp(argv[1], "insert_erase_random")) {
        start = clock();
	    insert_erase_random(v, n);
        end = clock();
        printf("%s executed in %f seconds\n", "insert_erase_random", (double)(end-start)/CLOCKS_PER_SEC);
	}
	if(!strcmp(argv[1], "insert_erase_head")) {
        start = clock();
        insert_erase_head(v, n);
        end = clock();
        printf("%s executed in %f seconds\n", "insert_erase_head", (double)(end-start)/CLOCKS_PER_SEC);
	}
	if(!strcmp(argv[1], "insert_erase_tail")) {
        start = clock();
        insert_erase_tail(v, n);
        end = clock();
        printf("%s executed in %f seconds\n", "insert_erase_tail", (double)(end-start)/CLOCKS_PER_SEC);
	}
	if(!strcmp(argv[1], "read_write_random")) {
        start = clock();
        read_write_random(v, n);
        end = clock();
        printf("%s executed in %f seconds\n", "read_write_random", (double)(end-start)/CLOCKS_PER_SEC);
	}
	if(!strcmp(argv[1], "read_write_sequential")) {
        start = clock();
        read_write_sequential(v, n);
        end = clock();
        printf("%s executed in %f seconds\n", "read_write_sequential", (double)(end-start)/CLOCKS_PER_SEC);
	}
	if(!strcmp(argv[1], "bubble_sort")) {
        start = clock();
        bubble_sort(v, n);
        end = clock();
        printf("%s executed in %f seconds\n", "bubble_sort", (double)(end-start)/CLOCKS_PER_SEC);
	}
	vector_v2_double_free(v);
	return 0;
}
