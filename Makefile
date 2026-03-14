CFLAGS = -ansi

all: reaction_functions.o reaction_types.h
	gcc $(CFLAGS) main.c reaction_functions.o reaction_types.h -o main

reaction_functions.o: reaction_functions.c reaction_types.h
	gcc -c -ansi reaction_functions.c -o reaction_functions.o
