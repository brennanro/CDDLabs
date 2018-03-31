CC=g++
CFLAGS= -std=c++11 -pthread -I.
DOXYGEN = doxygen
INDEX_SRC = docs/html/index.html
INDEX = firefox $(INDEX_SRC)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(HFILES) $(CFILES) #When changes made to HFILES and CFILES this runs
	$(CC) -o Barrier Semaphore.cpp Barrier.cpp main.cpp $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -00
DEBUG: ALL

DOC: 
	$(DOXYGEN) DoxFile
	$(INDEX)
DOC: ALL

CLEAN:
	rm *.o