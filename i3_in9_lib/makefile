all : monprogramme
monprogramme : main.o complex.o
gcc complex.o main.o -o monprogramme
complex.o : complex.c complex.h
gcc complex.c -c -o complex.o
main.o : main.c
gcc main.c -c -o main.o
clean :
rm -f *.o monprogramme