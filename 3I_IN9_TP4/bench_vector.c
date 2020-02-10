#include "vector.h"
#include "random.h"
#include <string.h>

//repete n fois l'ajout puis la suppression d'un élément à des positions aléatoires : OK
void insert_erase_random(p_s_vector vecteur, size_t n) {
	for (size_t i =0; i < n; i++){
	size_t taille = random_size_t(0, vecteur->nb_elements-1);
		vector_insert(vecteur, taille, random_double(0, 50));
printf("Alain trop bg %lf \n", get(vecteur, taille));

	}
	for (size_t i =0; i < n; i++){
		vector_erase(vecteur, random_size_t(0, vecteur->nb_elements-1));
	}
}

//repete n fois l'ajout puis la suppression d'un élément en tete : OK
void insert_erase_head(p_s_vector vecteur, size_t n) {
	for (size_t i =0; i < n; i++){
		vector_insert(vecteur, 0, random_double(0, 50));
		printf("Alain trop bg %lf \n", get(vecteur, 0));
	}
	for (size_t i =0; i < n; i++){
		vector_erase(vecteur, 0);
	}
	
}
//repete n fois l'ajout puis la suppression d'un élément à la queue : OK
void insert_erase_tail(p_s_vector p_vector, size_t n) {
	for (size_t i =0; i < n; i++){
		vector_push_back(p_vector, random_double(0, 50)); 
		printf("Alain trop bg %lf \n", get(p_vector, p_vector->nb_elements-1));
	}
	for (size_t i =0; i < n; i++){
		vector_pop_back(p_vector);
	}
}

//répète n fois l'écriture puis la lecture d'un élément a des positions aléatoires : OK
void read_write_random(p_s_vector p_vector, size_t n){
	for (size_t i =0; i < n; i++){
		size_t taille = random_size_t(0, p_vector->nb_elements-1);
		vector_set(p_vector, taille, random_double(0,50));
		printf("Alain trop bg %lf \n", get(p_vector, taille));
		printf("indice : %zu \n", taille);
	}
	for (size_t i =0; i < n; i++){
		double d = get(p_vector, random_size_t(0, p_vector->nb_elements-1));
		printf("%lf \n",d);
	}
}

//répète n fois l'écriture de tous les éléments du vectuer puis la lecture de tous les éléments du vecteur toujours avec un parcours de la tête vers la queue : OK
void read_write_sequential(p_s_vector p_vector, size_t n){
	for (size_t i =0; i < n; i++){
		vector_set(p_vector, i, random_double(0,50));
		printf("Alain trop bg %lf \n", get(p_vector, i));
	}
	for (size_t i =0; i < n; i++){
		double d = get(p_vector, i);
		printf("%lf \n",d);
	}
}

//répète n fois l'écriture de tous les éléments du vecteur avec des valeurs aléatoires puis tri du vecteur avec le tri à bulles : OK
void bubble_sort(p_s_vector p_vector, size_t n){
	for (size_t i =0; i < n; i++){
		vector_set(p_vector, i, random_double(0,50));
		printf("Alain trop bg %lf \n", get(p_vector, i));
	}
	
	for (size_t i = p_vector->nb_elements; i > 1; i--){
		for(size_t j=0; j < i-1; j++){
			if (get(p_vector, j+1) < get(p_vector, j)){
				double temp = get(p_vector, j+1);
				vector_set(p_vector, j+1, get(p_vector, j));
				vector_set(p_vector, j, temp);
			}
		}
	}
	
}


int main(int argc, char *argv[]){

	if (argc > 0 && argc < 5) {
		size_t init_size = 0;
		sscanf(argv[2], "%zu", &init_size);
		size_t n = 0;
		sscanf(argv[3], "%zu", &n);
		//printf("%zu", n);
		//printf("%zu", init_size);
		p_s_vector vecteur = vector_alloc(init_size);
		
		for(size_t i =0; i < init_size; i++) {
			// INITIALISE TOUTES TES VALEURS AVEC UNE VALEUR RANDOM
			vector_set(vecteur, i, random_double(0, RAND_MAX));
			printf("%lf \n", get(vecteur, i));
			
		}

		/*vector_set(vecteur, 0, 80);
		vector_set(vecteur, 1, 5);
		vector_set(vecteur, 2, 23);
		vector_set(vecteur, 3, 99);
		vector_set(vecteur, 4, 38);*/

		if(strcmp(argv[1], "insert_erase_random") == 0){
		 	insert_erase_random(vecteur, n);
		} else if (strcmp(argv[1], "insert_erase_head") == 0){
		 	insert_erase_head(vecteur, n); 
		} else if (strcmp(argv[1], "insert_erase_tail") == 0){
		 	insert_erase_tail(vecteur, n);
		} else if (strcmp(argv[1], "read_write_random") == 0){
		 	read_write_random(vecteur, n);
		} else if (strcmp(argv[1], "read_write_sequential") == 0){
		 	read_write_sequential(vecteur, n);
		} else if (strcmp(argv[1], "bubble_sort") == 0){
		 	bubble_sort(vecteur, n);
		}
		
		for(size_t i =0; i < init_size; i++) {
			printf("Lydie trop belle %lf \n", get(vecteur, i));
			
		}
		
		// TON IF POUR COMPARER ARGV[1] AVEC TEST QUE TU VEUX
			// appel le test
	}
	
	
	
}
