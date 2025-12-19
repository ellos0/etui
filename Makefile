CC := gcc
CFLAGS := -O1 -Wall -Wextra -g
LIB_DIR := $(HOME)/lib

.PHONY: clean

all: src/etui.c
	$(CC) $(CFLAGS) src/etui.c -o bin/etui

run: bin/etui
	./bin/etui

etui.o: src/etui.c
	$(CC) $(CFLAGS) -c -o bin/etui.o src/etui.c

#dynamic lib
libetui.so: src/etui.c include/etui.h
	$(CC) $(CFLAGS) -fPIC -shared -o bin/libetui.so src/etui.c
	cp bin/libetui.so $(LIB_DIR)

#hello example
hello.c: examples/hello.c
	$(CC) $(CFLAGS) -o bin/hello examples/hello.c -L$(LIB_DIR) -letui -Iinclude

clean:
	rm -rf bin
	mkdir bin
