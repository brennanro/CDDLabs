#Ronan Brennan   15/10/2017
#Semaphore MakeFile Lab2

CC=g++
CFLAGS= -std=c++11 -pthread
HFILES= Semaphore.h #.h files
CFILES= Semaphore.cpp rendezvous.cpp #.cpp files

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(HFILES) $(CFILES)  #When changes made to HFILES and CFILES this runs
	$(CC) -o rendezvous Semaphore.cpp rendezvous.cpp $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g 00
DEBUG: ALL


CLEAN:
	rm *.o  #Removes all previous .o files
