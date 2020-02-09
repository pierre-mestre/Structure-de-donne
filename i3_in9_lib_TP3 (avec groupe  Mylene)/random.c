#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "random.h"
#include <time.h>

//1.2.a
double random_double(double a, double b){
    return (double) ((b - a) * (rand() / (RAND_MAX + 1.0)) + a);
}

//1.2.b
float random_float(float a, float b){
    return (float) ((b - a) * (rand() / (RAND_MAX + 1.0)) + a);
}

//1.2.c
size_t random_size_t(size_t a, size_t b){
    return (size_t) ((b - a) * (rand() / (RAND_MAX + 1.0)) + a);
}

//1.2.d
int random_int(int a, int b){
    return (int) ((b - a) * (rand() / (RAND_MAX + 1.0)) + a);
}

//1.2.e
unsigned char random_uchar(unsigned char a, unsigned char b){
    return (unsigned char) ((b - a) * (rand() / (RAND_MAX + 1.0)) + a);
}

//1.2.f
void random_init_string(unsigned char * c, size_t n){
    for (int i = 0; i < n; ++i) {
        c[i] = random_uchar('A','Z');
    }
}
