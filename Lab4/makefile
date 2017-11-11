#Ronan Brennan   25/10/2017
#Reusable Barriers MakeFile Lab4

CC=g++
CFLAGS= -std=c++11 -pthread
HFILES= Semaphore.h    #.h files
CFILES=Semaphore.cpp Barrier.cpp #.cpp files

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(HFILES) $(CFILES) #When changes made to HFILES and CFILES this runs
	$(CC) -o  Barrier Semaphore.cpp Barrier.cpp $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g 00
DEBUG: ALL


CLEAN:
	rm *.o #Removes all previous .o files
