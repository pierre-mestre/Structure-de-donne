#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include <time.h>
#include <string.h>

//1.2.a
int test_random_double(){
    size_t rnd = random_double((double) 0, (double) 1);
    return (rnd >= 0.0 && rnd <= 1.0);
}

//1.2.b
int test_random_float(){
	float f = random_float(3.0,121.8);
	return (f>=3.0 && f<=121.8);

}

//1.2.c
int test_random_size_t(){
	size_t rnd = random_size_t((size_t) 5, (size_t) 20);
	return (rnd >= 5 && rnd <= 20);
}

//1.2.d
int test_random_int(){
	int rnd = random_int(5, 20);
	return (rnd >= 5 && rnd <= 20);
}

//1.2.e
int test_random_uchar(){
    unsigned char rnd = random_uchar('A','Z');
    return (rnd >= 'A' && rnd <= 'Z');
}

//1.2.f
int test_random_init_string(){
    int SIZE = 4;
    unsigned char* str = malloc(sizeof(unsigned char) * SIZE);
    random_init_string(str,SIZE);
    if(strlen(str) == 0) return 0;
    unsigned char test_notsame = str[0];
    int diff = 0;
    for (int i = 1; i < 4; ++i) {
        if(str[0] != str[i])
            diff = 1;
    } 
    free(str);
    return diff;
}

//MAIN*********************************
int main(int argc, char* argv[]) {
   time_t t;
   /* Intializes random number generator */
   srand((unsigned) time(&t));

    printf("Test %s : %s at %s\n",test_random_double() ? "succeed" : "failed","test_random_double()", __FILE__);
    printf("Test %s : %s at %s\n",test_random_float() ? "succeed" : "failed","test_random_float()", __FILE__);
    printf("Test %s : %s at %s\n",test_random_size_t() ? "succeed" : "failed","test_random_size_t()", __FILE__);
    printf("Test %s : %s at %s\n",test_random_int() ? "succeed" : "failed","test_random_int()", __FILE__);
    printf("Test %s : %s at %s\n",test_random_uchar() ? "succeed" : "failed","test_random_uchar()", __FILE__);
    printf("Test %s : %s at %s\n",test_random_init_string() ? "succeed" : "failed","test_random_init_string()", __FILE__);

//Les tests retournent 1 si ils sont vrai, 0 sinon
    return 0;
}
