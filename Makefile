CC = gcc
CFLAGS = -O1 -Wall
LIBFLAGS = -c

lib: src/etui.c
	$(CC) $(CFLAGS) $(LIBFLAGS) src/etui.c -o bin/etui.o
	ar rcs bin/libetui bin/etui.o

run: bin/etui
	./bin/etui

all: src/etui.c
	$(CC) $(CFLAGS) src/etui.c -o bin/etui
