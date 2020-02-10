#include "random.h"

double random_double(double a, double b){
	double d = (double)((b-a)*(rand()/(RAND_MAX+1.0))+a);
	return d;
}


float random_float(float a, float b){
	float f = (float)((b-a)*(rand()/(RAND_MAX+1.0))+a);
	return f;
}
size_t random_size_t(size_t a, size_t b){
	size_t rs = (size_t)((b-a)*(rand()/(RAND_MAX+1.0))+a);
	return rs;
}
int random_int(int a, int b){
	int i = (int)((b-a)*(rand()/(RAND_MAX+1.0))+a);
	return i;
}

unsigned char random_uchar(unsigned char a, unsigned char b){
	unsigned char us = (unsigned char)((b-a)*(rand()/(RAND_MAX+1.0))+a);
	return us;

}

void random_init_string(unsigned char* c, size_t n){
	for(int i = 0; i<n; i++){ 
		c[i] = random_uchar(65,90);
		//printf("%c", c[i]);
	}
	
}

