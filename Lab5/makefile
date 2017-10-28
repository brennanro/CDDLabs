#Ronan Brennan   /10/2017
#Producer/Customer MakeFile Lab5

CC=g++
CFLAGS= -std=c++11 -pthread
HFILES= Semaphore.h    #.h files
CFILES=Semaphore.cpp customer.cpp #.cpp files

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(HFILES) $(CFILES) #When changes made to HFILES and CFILES this runs
	$(CC) -o customer Semaphore.cpp customer.cpp $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g 00
DEBUG: ALL


CLEAN:
	rm *.o #Removes all previous .o files
