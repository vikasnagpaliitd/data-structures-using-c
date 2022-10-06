
CFLAGS = -c -Wall -g

output :  main.o list.o
	gcc -o output main.o list.o

main.o : main.c
	gcc $(CFLAGS) main.c


list.o : list.c
	gcc $(CFLAGS) list.c



clean :
	\rm *.o  output

