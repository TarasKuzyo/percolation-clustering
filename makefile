CC=gcc
CFLAGS=-c -g -Wall -O2 `pkg-config --cflags cairo`
LDFLAGS=-lm -export-dynamic `pkg-config --libs cairo`
HEADERS=$(wildcard *.h)
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=percolation-clustering


all: $(SOURCES) $(TARGET)
	
$(TARGET): $(OBJECTS) $(HEADERS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -rf *.o
