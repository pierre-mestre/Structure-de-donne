all :  monprogramme

monprogramme :  my_struct.o
	gcc my_struct.o -o monprogramme

my_struct.o :  my_struct.c
	gcc my_struct.c -c -o my_struct.o

clean :
	rm -f *.o monprogramme
