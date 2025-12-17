CC = gcc
CFLAGS = -O1 -Wall

run: src/main
	./src/main

all: src/main.c
	$(CC) $(CFLAGS) src/main.c -o src/main
