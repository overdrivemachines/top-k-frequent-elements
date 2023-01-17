
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

top-k-frequent-elements: top-k-frequent-elements.o
	$(CC) $(CFLAGS) -o top-k-frequent-elements top-k-frequent-elements.o

top-k-frequent-elements.o: top-k-frequent-elements.cpp
	$(CC) $(CFLAGS) -c top-k-frequent-elements.cpp

clean:
	rm -rf top-k-frequent-elements top-k-frequent-elements.o
