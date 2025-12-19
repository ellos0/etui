CC := gcc
CFLAGS := -O1 -Wall -Wextra -g

all: src/etui.c
	$(CC) $(CFLAGS) src/etui.c -o bin/etui

run: bin/etui
	./bin/etui

etui.o: src/etui.c
	$(CC) $(CFLAGS) -c src/etui.c -o bin/etui.o

#dynamic lib
libetui.so: src/etui.c include/etui.h
	$(CC) $(CFLAGS) -fPIC -shared -o bin/libetui.so src/etui.c 

#hello example
hello.c: examples/hello.c
	$(CC) $(CFLAGS) -o bin/hello examples/hello.c -Lbin -letui -Iinclude

clean:
	rm -rf bin
	mkdir bin
