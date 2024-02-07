# Flags and commands
CC = gcc

.PHONY: all clean

# Specify the target executable and dependencies
all: my_graph my_Knapsack

# Rule to clean up object files, libraries, and the executable
clean:
	@rm -f *.o *.a my_graph my_Knapsack

# Rule to build the executable 'my_graph'
my_graph : my_graph.o libmy_mat.a
	$(CC) -Wall -g my_graph.o -o my_graph -L. -lmy_mat -lm

# Rule to build the executable 'my_Knapsack'
my_Knapsack: my_Knapsack.o libmy_mat.a
	$(CC) -Wall -g my_Knapsack.o -o my_Knapsack -L. -lmy_mat -lm

# Rule to build the executable 'my_Knapsack'
my_Knapsack.o: my_Knapsack.c
	$(CC) -Wall -g -c my_Knapsack.c

# Rule to build the library 'libmy_mat.a'
libmy_mat.a: my_mat.o
	ar rcs libmy_mat.a my_mat.o

# Rule to build the object file 'main.o'
my_graph.o: my_graph.c my_mat.h
	$(CC) -Wall -g -c my_graph.c

# Rule to build the object file 'my_mat.o'
my_mat.o: my_mat.c my_mat.h
	$(CC) -Wall -g -c my_mat.c


