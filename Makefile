# Macros

CC = g++
CFLAGS = -g -Wall
OBJ1 = words.o main.o

# Explicit rule
all: solution

solution: $(OBJ1)
	$(CC) $(CFLAGS) -o solution $(OBJ1)  

clean:
	rm -rf *.o solution

words.o: words.cc
	$(CC) $(CFLAGS) -c words.cc $(INC)
main.o: main.cc
	$(CC) $(CFLAGS) -c main.cc $(INC)
