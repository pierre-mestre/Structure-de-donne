#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_struct.h"
#include "random.h"

/*(a)*/
p_s_my_struct my_struct_alloc(){
	p_s_my_struct p_vector = (p_s_my_struct) malloc(sizeof(s_my_struct));
	p_vector-> p = 0;
	p_vector->chaine = NULL;
	return p_vector;
}

/*(b)*/
void my_struct_free(p_s_my_struct p_vector){
	p_vector->p = 0;
	free(p_vector->chaine);
	p_vector->chaine = NULL;
	free(p_vector);
}

/*(c)*/
void my_struct_randoms_init(p_s_my_struct p_vector){
	// double
	p_vector->p = random_double(0,200);

	// chaine
	int random = random_int(0,200); // taille aléatoire

	if(p_vector->chaine != NULL){
		p_vector->chaine = (char*) realloc(p_vector->chaine, sizeof(char) * random);
	} else {
		p_vector->chaine = (char*) malloc(sizeof(char)* random);
	}
	unsigned char element = 'A';

	//Ajout de x elements aleatoires dans la chaîne
	for(int i = 0; i < random-1; i++){
		element = random_uchar('A','Z');
		p_vector->chaine[i] = element;
	}
	p_vector->chaine[random-1] = '\0';
}

/*(d)*/
void my_struct_copy(p_s_my_struct p_dest, p_s_my_struct p_src){
	if(p_dest == NULL || p_src == NULL)
		return;
	p_dest->p = p_src->p;
	if(p_src->chaine == NULL)
		return;
	int len = strlen(p_src->chaine);
	if(p_dest->chaine != NULL)
		p_dest->chaine = (char *) realloc(p_dest->chaine,sizeof(char)*(len+1));
	else
		p_dest->chaine = (char *) malloc(sizeof(char)*(len+1));
	strcpy(p_dest->chaine,p_src->chaine);
}

/*(e)*/
int my_struct_cmp(p_s_my_struct p_vector_a, p_s_my_struct p_vector_b){
	if(p_vector_a == NULL && p_vector_b == NULL)
		return 0;
	if(p_vector_a == NULL)
		return -1;
	else if (p_vector_b == NULL)
		return 1;
	if(p_vector_a->chaine == NULL && p_vector_b->chaine == NULL)
		return 0;
	if(p_vector_a->chaine == NULL)
		return -1;
	if(p_vector_b->chaine == NULL)
		return 1;
	int res = strcmp(p_vector_a->chaine,p_vector_b->chaine);
	if(res == 0) // p_vector_a-> chaine == p_vector_b->chaine
		return 0;
	if(res > 0) // valeur positive -> p_vector_a->chaine est superieur a p_vector_b->chaine
		return -1;
	else
		return 1;
}
