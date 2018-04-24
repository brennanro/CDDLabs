#Ronan Brennan   17/10/2017
#Customer Producer MakeFile Lab5

CC=g++
CFLAGS= -std=c++11 -pthread -I.
HFILES= Semaphore.h customer.h    #.h files
CFILES=Semaphore.cpp main.cpp customer.cpp #.cpp files
DOXYGEN = doxygen
INDEX_SRC = docs/html/index.html
INDEX = firefox $(INDEX_SRC)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(HFILES) $(CFILES) #When changes made to HFILES and CFILES this runs
	$(CC) -o Customer Semaphore.cpp customer.cpp main.cpp $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -00
DEBUG: ALL

DOC: 
	$(DOXYGEN) DoxFile
	$(INDEX)
DOC: ALL

CLEAN:
	rm *.o