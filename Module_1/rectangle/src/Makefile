CC=g++
CFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic
SOURCES=main.cpp rectangle.cpp rectangle.hpp
OBJECTS=main.o rectangle.o
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ 

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: main
	./main
