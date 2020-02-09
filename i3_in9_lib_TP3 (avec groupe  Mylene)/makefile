all : vector_v1_double random bench_vector_v1_double bench_vector_v2_double vector_v2_double my_struct test_vector test_my_struct test_random test_vector_v1_double test_vector_v2_double

bench_vector_v1_double : bench_vector_v1_double.o random.o vector_v1_double.o
	gcc bench_vector_v1_double.o random.o vector_v1_double.o -g -o bench_vector_v1_double

bench_vector_v1_double.o : bench_vector_v1_double.c
	gcc -c bench_vector_v1_double.c -g -o bench_vector_v1_double.o

vector_v1_double : vector_v1_double.o test_vector_v1_double.o
	gcc vector_v1_double.o test_vector_v1_double.o -g -o vector_v1_double

random : random.o test_random.o
	gcc random.o test_random.o -g -o random

vector_v1_double.o : vector_v1_double.c vector_v1_double.h
	gcc -c vector_v1_double.c -g -o vector_v1_double.o

random.o : random.c random.h
	gcc -c random.c -g -o random.o

test_vector_v1_double.o : test_vector_v1_double.c
	gcc -c test_vector_v1_double.c -g -o test_vector_v1_double.o

test_random.o : test_random.c
	gcc -c test_random.c -g -o test_random.o

vector_v2_double : vector_v2_double.o test_vector_v2_double.o
	gcc vector_v2_double.o test_vector_v2_double.o -g -o vector_v2_double

vector_v2_double.o : vector_v2_double.c vector_v2_double.h
	gcc -c vector_v2_double.c -g -o vector_v2_double.o

test_vector_v2_double.o : test_vector_v2_double.c
	gcc -c test_vector_v2_double.c -g -o test_vector_v2_double.o

bench_vector_v2_double : bench_vector_v2_double.o random.o vector_v2_double.o
	gcc bench_vector_v2_double.o random.o vector_v2_double.o -g -o bench_vector_v2_double

bench_vector_v2_double.o : bench_vector_v2_double.c
	gcc -c bench_vector_v2_double.c -g -o bench_vector_v2_double.o

my_struct : my_struct.o test_my_struct.o random.o
	gcc my_struct.o test_my_struct.o random.o -g -o my_struct

my_struct.o : my_struct.c my_struct.h random.o
	gcc -c my_struct.c random.o -g -o my_struct.o

test_my_struct.o : test_my_struct.c
	gcc -c test_my_struct.c -g -o test_my_struct.o

vector : vector.o test_vector.o
	gcc vector.o test_vector.o -g -o vector

vector.o : vector.c vector.h
	gcc -c vector.c -g -o vector.o

test_vector.o : test_vector.c
	gcc -c test_vector.c -g -o test_vector.o

bench_vector : bench_vector.o random.o vector.o
	gcc bench_vector.o random.o vector.o -g -o bench_vector

bench_vector.o : bench_vector.c
	gcc -c bench_vector.c -g -o bench_vector.o

clean :
	rm -f *.o random bench_vector_v1_double vector_v1_double  vector_v2_double bench_vector_v2_double my_struct test_my_struct test_vector vector
