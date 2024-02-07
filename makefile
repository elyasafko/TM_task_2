# Flags and commands
CC = gcc

.PHONY: all clean

# Specify the target executable and dependencies
all: my_graph my_Knapsack

# Rule to clean up object files, libraries, and the executable
clean:
	@rm -f *.o *.a my_graph my_Knapsack

# Rule to build the executable 'my_graph'
my_graph: my_graph.o libmy_mat.a
	$(CC) -Wall -g $^ -o $@ 

# Rule to build the object file 'my_graph.o'
my_graph.o: my_graph.c my_mat.h
	$(CC) -Wall -g -c my_graph.c -fPIC

# Rule to build the executable 'my_Knapsack'
my_Knapsack: my_Knapsack.o libmy_mat.a
	$(CC) -Wall -g $^ -o $@ 

# Rule to build the executable 'my_Knapsack'
my_Knapsack.o: my_Knapsack.c
	$(CC) -Wall -g -c my_Knapsack.c -fPIC

# Rule to build the object file 'my_mat.o'
my_mat.o: my_mat.c my_mat.h
	$(CC) -Wall -g -c my_mat.c -fPIC

# Rule to build the library 'libmy_mat.a'
libmy_mat.a: my_mat.o
	ar rcs libmy_mat.a my_mat.o