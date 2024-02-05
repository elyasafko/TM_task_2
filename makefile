# Flags and commands
CC = gcc

.PHONY: all clean

# Specify the target executable and dependencies
all: prog

# Rule to clean up object files, libraries, and the executable
clean:
	@rm -f *.o *.a prog

# Rule to build the executable 'prog'
prog: main.o libmy_mat.a
	$(CC) -Wall -g main.o -o prog -L. -lmy_mat -lm

# Rule to build the library 'libmy_mat.a'
libmy_mat.a: my_mat.o
	ar rcs libmy_mat.a my_mat.o

# Rule to build the object file 'main.o'
main.o: main.c my_mat.h
	$(CC) -Wall -g -c main.c

# Rule to build the object file 'my_mat.o'
my_mat.o: my_mat.c my_mat.h
	$(CC) -Wall -g -c my_mat.c
