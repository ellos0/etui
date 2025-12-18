CC = gcc
CFLAGS = -O1 -Wall

run: src/etui
	./src/etui

all: src/etui.c
	$(CC) $(CFLAGS) src/etui.c -o src/etui
