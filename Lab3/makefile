#Ronan Brennan   14/10/2017
#Mutual MakeFile Lab3

CC=g++
CFLAGS= -std=c++11 -pthread
HFILES= Semaphore.h    #.h files
CFILES=Semaphore.cpp mutual.cpp #.cpp files
DOXYGEN = doxygen
INDEX_SRC = docs/html/index.html
BROW = firefox $(INDEX_SRC)

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(HFILES) $(CFILES) #When changes made to HFILES and CFILES this runs
	$(CC) -o mutual Semaphore.cpp mutual.cpp $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g 00
DEBUG: ALL

DOC: 
	$(DOXYGEN) Doxyfile
	$(BROW)
DOC: ALL

CLEAN:
	rm *.o #Removes all previous .o files

