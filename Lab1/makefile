#Ronan Brennan   14/10/2017
#Semaphore MakeFile Lab1

CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: signal.o
	$(CC) -o signal Semaphore.cpp signal.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL


CLEAN:
	rm *.o
